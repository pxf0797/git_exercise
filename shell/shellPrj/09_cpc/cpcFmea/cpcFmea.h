/*
 * cpcFmea.h
 *
 *  Created on: 2018��8��22��
 *      Author: pxf
 */

#ifndef CPCFMEA_H_
#define CPCFMEA_H_

#include "..\..\01_std\std.h"
#include "..\..\02_bm\fifo\fifo.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "cpcFmeaCfg.h"

// --------------------------------------------------------------
// �����ʼ��
// --------------------------------------------------------------
// ��������ʼ��------------------------
// 0�ɹ���-1ʧ��
int16 vfbIcpcFmeaInit(void);

// �����ʼ��----------------------------
int16 cpcFmeaInit(void);

// ��������ʼ��------------------------
int16 vfbOcpcFmeaInit(void);

// ���������ʼ���ⲿ����----------------
extern int16 vfbMcpcFmeaInit(void);

// --------------------------------------------------------------
// �������
// --------------------------------------------------------------
// ������е���--------------------------
void cpcFmeaSch(void);

// --------------------------------------------------------------
// ����������ͨ����������
// --------------------------------------------------------------

// --------------------------------------------------------------
// ���������ͨ����������
// --------------------------------------------------------------

// --------------------------------------------------------------
// ��������ඨ��
// --------------------------------------------------------------
// �������������------------------------
CL(vfbOcpcFmea)
{
    hvfbOcpcFmea self;
    hvfbOcpcFmea (*init)(hvfbOcpcFmea cthis);

    schParam schParam;
};

// �ⲿ�ӿ�����--------------------------

// ���������ʵ��------------------------
extern vfbOcpcFmea vfbOcpcFmeaA;

// --------------------------------------------------------------
// ����ඨ��
// --------------------------------------------------------------
// ������״̬������--------------------
#define ERR_DISPOSE_SM_LIST(_) \
    _(errDisposeSm, polling)   \
    _(errDisposeSm, dispose)
SMDC(errDisposeSm, ERR_DISPOSE_SM_LIST)
{
    sta next;
    void *cpcFmea;
};
// ���󻺴���ж���----------------------
#define ERR_FIFO_LEN     ERR_FIFO_LEN_CFG  // һ�δ������洢������Ϣ
extern errCode errCodeBuff[ERR_FIFO_LEN];
extern fifo errCodeFifo;

// ���������----------------------------
CL(cpcFmea)
{
    hcpcFmea self;
    hcpcFmea (*init)(hcpcFmea cthis, hvfbOcpcFmea vfbOcpcFmea,
            hfifo errCodeFifo, void *listBuffer, int16 listBuffSize, int16 fifoObjSize,
            hstaAct errDisposeSm);

    uint32 errCnt;
    // 0  ignore    �ɺ���
    // 1  warning   ����
    // 2  serious   ���ش���
    // 3  fatal     ��������
    uint32 errIgnoreCnt;
    uint32 errWarningCnt;
    uint32 errSeriousCnt;
    uint32 errFatalCnt;
    // 0  communicationInputErr  ͨ���������
    // 1  communicationOutputErr ͨ���������
    // 2  schedularErr           ������ȴ���
    // 3  functionErr            ���ܴ���
    uint32 errCieCnt;
    uint32 errCoeCnt;
    uint32 errSeCnt;
    uint32 errFeCnt;

    errDisposeSmRec errDisposeSmRec;
    hstaAct errDisposeSm;

//    schParam schParam;

    void (*saveErrCode)(hcpcFmea t, herrCode code);
    void (*run)(hcpcFmea t);

    INJ(vfbOcpcFmea, vfbOcpcFmea);
    EXT(fifo);
};

// �첽���ȹ��ܺ���----------------------


// �����ʵ��----------------------------
extern cpcFmea cpcFmeaA;

// --------------------------------------------------------------
// ���������ඨ��
// --------------------------------------------------------------
// ��������������------------------------
CL(vfbIcpcFmea)
{
    hvfbIcpcFmea self;
    hvfbIcpcFmea (*init)(hvfbIcpcFmea cthis, hcpcFmea cpcFmea);

//    schParam schParam;

    void (*saveErrCode)(hvfbIcpcFmea t, herrCode code);

    INJ(cpcFmea, cpcFmea);
};

// ����������ʵ��------------------------
extern vfbIcpcFmea vfbIcpcFmeaA;

#endif /* CPCFMEA_H_ */
