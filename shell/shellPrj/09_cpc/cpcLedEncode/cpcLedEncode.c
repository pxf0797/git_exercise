/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cpcLedEncode.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :���cpcLedEncode ����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "cpcLedEncode.h"

/***********************************************************
* �����ʼ��
***********************************************************/
/*�����ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 cpcLedEncodeInit(void){
    int16 rtv = 0;

    CN(cpcLedEncode, &cpcLedEncodeA, &smcpcLedEncode[0], &vfbOcpcLedEncodeA);
    if(OPRS(cpcLedEncodeA) != OOPC_NULL){
        rtv = vfbOcpcLedEncodeInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* �������
***********************************************************/
/*������е���
* ����: ��
* ���: ��
***********************************************/
void cpcLedEncodeSch(void){
    cpcLedEncodeA.run(cpcLedEncodeA.self);
}


/***********************************************************
* ���ͨ�ù��ܺ���
***********************************************************/


/***********************************************************
* ���״̬��
***********************************************************/
/*���״̬������
***********************************************/
SMDF(smcpcLedEncode, SM_CPCLEDENCODE_STA_LIST);

/*smcpcLedEncode_act_init
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcpcLedEncode_act_init(void *hStaRec){
    hsmcpcLedEncodeRec rec = (hsmcpcLedEncodeRec)hStaRec;

    rec->cpcLedEncode = (void *)&cpcLedEncodeA;
    //TODO

    rec->next = smcpcLedEncode_sta_default;
}

/*smcpcLedEncode_act_sta1
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcpcLedEncode_act_sta1(void *hStaRec){
    hsmcpcLedEncodeRec rec = (hsmcpcLedEncodeRec)hStaRec;
    //((hcpcLedEncode)(rec->cpcLedEncode))->

    //TODO

    rec->next = smcpcLedEncode_sta_default;
}

/*smcpcLedEncode_act_sta2
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcpcLedEncode_act_sta2(void *hStaRec){
    hsmcpcLedEncodeRec rec = (hsmcpcLedEncodeRec)hStaRec;
    //((hcpcLedEncode)(rec->cpcLedEncode))->

    //TODO

    rec->next = smcpcLedEncode_sta_default;
}

/*smcpcLedEncode_act_default
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcpcLedEncode_act_default(void *hStaRec){
    hsmcpcLedEncodeRec rec = (hsmcpcLedEncodeRec)hStaRec;
    //((hcpcLedEncode)(rec->cpcLedEncode))->

    //TODO

    rec->next = smcpcLedEncode_sta_default;
}


/***********************************************************
* �������
***********************************************************/
/*������ʼ������
* ����: cthis cpcLedEncode��ָ��
* ���: hcpcLedEncode cthis/OOPC_NULL
***********************************************/
hcpcLedEncode cpcLedEncode_init(hcpcLedEncode cthis, hstaAct smcpcLedEncode, hvfbOcpcLedEncode vfbOcpcLedEncode){
    cthis->smcpcLedEncode = smcpcLedEncode;
    cthis->vfbOcpcLedEncode = vfbOcpcLedEncode;
    //TODO

    return cthis;
}

/*������к���
* ����: t cpcLedEncode��ָ��
* ���: ��
***********************************************/
void cpcLedEncode_run(hcpcLedEncode t){
    SMRE(t->smcpcLedEncode, t->smcpcLedEncodeRec);
}

/*����๹�캯��
* ����: cthis cpcLedEncode��ָ��
* ���: hcpcLedEncode cthis/OOPC_NULL
***********************************************/
CC(cpcLedEncode){
    cthis->init = cpcLedEncode_init;
    cthis->run = cpcLedEncode_run;
    //TODO

    cthis->smcpcLedEncodeRec.next = smcpcLedEncode_sta_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis cpcLedEncode��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(cpcLedEncode){
    return OOPC_TRUE;
}


/***********************************************************
* ����첽���ȹ��ܺ���
***********************************************************/
/*�첽���ȹ��ܺ���
***********************************************/
//void cpcLedEncode_abi_example(void){
//  //TODO
//}


/***********************************************************
* ���ʵ����
***********************************************************/
/*�����ʵ��
***********************************************/
cpcLedEncode cpcLedEncodeA;


/**************************** Copyright(C) pxf ****************************/
