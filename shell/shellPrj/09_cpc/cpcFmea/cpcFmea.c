/*
 * cpcFmea.c
 *
 *  Created on: 2018��8��22��
 *      Author: pxf
 */

#include "cpcFmea.h"

// --------------------------------------------------------------
// �����ʼ��
// --------------------------------------------------------------
// �����ʼ��------------------------
int16 cpcFmeaInit(void)
{
    int16 rtv = 0;

    CN(cpcFmea, &cpcFmeaA, &vfbOcpcFmeaA,
            &errCodeFifo, errCodeBuff, sizeof(errCodeBuff), sizeof(errCode),
            &errDisposeSm[0]);
    if (OPRS(cpcFmeaA) != OOPC_NULL)
    {
        rtv = vfbOcpcFmeaInit();
    }
    else
    {
        rtv = -1;
    }

    return rtv;
}

// --------------------------------------------------------------
// �������
// --------------------------------------------------------------
// ������е���--------------------------
void cpcFmeaSch(void)
{
    cpcFmeaA.run(cpcFmeaA.self);
}



// --------------------------------------------------------------
// ͨ�ù��ܺ���
// --------------------------------------------------------------


// --------------------------------------------------------------
// ������״̬������
// --------------------------------------------------------------
SMDF(errDisposeSm, ERR_DISPOSE_SM_LIST);

void errDisposeSm_act_init(void *hStaRec)
{
    herrDisposeSmRec rec = (herrDisposeSmRec)hStaRec;

    rec->cpcFmea = (void *)&cpcFmeaA;
    rec->next = errDisposeSm_sta_polling;
}
void errDisposeSm_act_polling(void *hStaRec)
{
    herrDisposeSmRec rec = (herrDisposeSmRec)hStaRec;

    if (((hcpcFmea)rec->cpcFmea)->fifo->currLen != 0)
    {
        rec->next = errDisposeSm_sta_dispose;
    }
    else
    {
        rec->next = errDisposeSm_sta_polling;
    }
}
void errDisposeSm_act_dispose(void *hStaRec)
{
    herrDisposeSmRec rec = (herrDisposeSmRec)hStaRec;
    errCode code;

    while (((hcpcFmea)rec->cpcFmea)->fifo->currLen != 0)
    {
        ((hcpcFmea)rec->cpcFmea)->fifo->pop(((hcpcFmea)rec->cpcFmea)->fifo, &code);
        ((hcpcFmea)rec->cpcFmea)->errCnt++;

        // ���¸�����ȼ�����
        if (code.errRanking == EC_ER_ignore)
        {
            ((hcpcFmea)rec->cpcFmea)->errIgnoreCnt++;
        }
        else if (code.errRanking == EC_ER_warning)
        {
            ((hcpcFmea)rec->cpcFmea)->errWarningCnt++;
        }
        else if (code.errRanking == EC_ER_serious)
        {
            ((hcpcFmea)rec->cpcFmea)->errSeriousCnt++;
        }
        else if (code.errRanking == EC_ER_fatal)
        {
            ((hcpcFmea)rec->cpcFmea)->errFatalCnt++;
        }
        else
        {
            ;
        }

        // ���¸�����������
        if (code.errClassify == EC_EC_cie)
        {
            ((hcpcFmea)rec->cpcFmea)->errCieCnt++;
        }
        else if (code.errClassify == EC_EC_coe)
        {
            ((hcpcFmea)rec->cpcFmea)->errCoeCnt++;
        }
        else if (code.errClassify == EC_EC_se)
        {
            ((hcpcFmea)rec->cpcFmea)->errSeCnt++;
        }
        else if (code.errClassify == EC_EC_fe)
        {
            ((hcpcFmea)rec->cpcFmea)->errFeCnt++;
        }
        else
        {
            ;
        }
    }

    // ���ز�ѯ״̬
    rec->next = errDisposeSm_sta_polling;
}
void errDisposeSm_act_default(void *hStaRec)
{
    herrDisposeSmRec rec = (herrDisposeSmRec)hStaRec;

    rec->next = errDisposeSm_sta_polling;
}

// --------------------------------------------------------------
// ����ඨ��
// --------------------------------------------------------------
errCode errCodeBuff[ERR_FIFO_LEN];
fifo errCodeFifo;

hcpcFmea cpcFmea_init(hcpcFmea cthis, hvfbOcpcFmea vfbOcpcFmea,
        hfifo errCodeFifo, void *listBuffer, int16 listBuffSize, int16 fifoObjSize,
        hstaAct errDisposeSm)
{
    cthis->vfbOcpcFmea = vfbOcpcFmea;
    cthis->errDisposeSm = errDisposeSm;

    CCC(fifo, errCodeFifo, listBuffer, listBuffSize, fifoObjSize);
    if (OPRS(*errCodeFifo) == OOPC_NULL)
    {
        return OOPC_NULL;
    }
    cthis->fifo = errCodeFifo;

    return cthis;
}

void cpcFmea_saveErrCode(hcpcFmea t, herrCode code)
{
    t->fifo->push(t->fifo, code);
}
void cpcFmea_run(hcpcFmea t)
{
    SMRE(t->errDisposeSm, t->errDisposeSmRec);
}

CC(cpcFmea)
{
    cthis->init = cpcFmea_init;
    cthis->saveErrCode = cpcFmea_saveErrCode;
    cthis->run = cpcFmea_run;

    cthis->errCnt = 0;
    cthis->errIgnoreCnt = 0;
    cthis->errWarningCnt = 0;
    cthis->errSeriousCnt = 0;
    cthis->errFatalCnt = 0;

    cthis->errCieCnt = 0;
    cthis->errCoeCnt = 0;
    cthis->errSeCnt = 0;
    cthis->errFeCnt = 0;

    cthis->errDisposeSmRec.next = errDisposeSm_sta_init;

//    cthis->schParam.id = 0;
//    cthis->schParam.schTask = cpcFmeaSch;
//    cthis->schParam.startTick = (CPCFDAM_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
//    cthis->schParam.prdTick = (CPCFDAM_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);

    return cthis;
}
CD(cpcFmea)
{
    return OOPC_TRUE;
}

// --------------------------------------------------------------
// �첽���ȹ��ܺ���
// --------------------------------------------------------------


// --------------------------------------------------------------
// �����ʵ����
// --------------------------------------------------------------
cpcFmea cpcFmeaA;
