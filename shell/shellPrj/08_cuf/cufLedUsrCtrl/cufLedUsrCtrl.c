/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cufLedUsrCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :���cufLedUsrCtrl ����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "cufLedUsrCtrl.h"

/***********************************************************
* �����ʼ��
***********************************************************/
/*�����ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 cufLedUsrCtrlInit(void){
    int16 rtv = 0;

    CN(cufLedUsrCtrl, &cufLedUsrCtrlA, &smcufLedUsrCtrl[0], &vfbOcufLedUsrCtrlA);
    if(OPRS(cufLedUsrCtrlA) != OOPC_NULL){
        rtv = vfbOcufLedUsrCtrlInit();
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
void cufLedUsrCtrlSch(void){
    cufLedUsrCtrlA.run(cufLedUsrCtrlA.self);
}


/***********************************************************
* ���ͨ�ù��ܺ���
***********************************************************/


/***********************************************************
* ���״̬��
***********************************************************/
/*���״̬������
***********************************************/
SMDF(smcufLedUsrCtrl, SM_CUFLEDUSRCTRL_STA_LIST);

/*smcufLedUsrCtrl_act_init
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcufLedUsrCtrl_act_init(void *hStaRec){
    hsmcufLedUsrCtrlRec rec = (hsmcufLedUsrCtrlRec)hStaRec;

    rec->cufLedUsrCtrl = (void *)&cufLedUsrCtrlA;
    //TODO

    rec->next = smcufLedUsrCtrl_sta_default;
}

/*smcufLedUsrCtrl_act_sta1
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcufLedUsrCtrl_act_sta1(void *hStaRec){
    hsmcufLedUsrCtrlRec rec = (hsmcufLedUsrCtrlRec)hStaRec;
    //((hcufLedUsrCtrl)(rec->cufLedUsrCtrl))->

    //TODO

    rec->next = smcufLedUsrCtrl_sta_default;
}

/*smcufLedUsrCtrl_act_sta2
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcufLedUsrCtrl_act_sta2(void *hStaRec){
    hsmcufLedUsrCtrlRec rec = (hsmcufLedUsrCtrlRec)hStaRec;
    //((hcufLedUsrCtrl)(rec->cufLedUsrCtrl))->

    //TODO

    rec->next = smcufLedUsrCtrl_sta_default;
}

/*smcufLedUsrCtrl_act_default
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcufLedUsrCtrl_act_default(void *hStaRec){
    hsmcufLedUsrCtrlRec rec = (hsmcufLedUsrCtrlRec)hStaRec;
    //((hcufLedUsrCtrl)(rec->cufLedUsrCtrl))->

    //TODO

    rec->next = smcufLedUsrCtrl_sta_default;
}


/***********************************************************
* �������
***********************************************************/
/*������ʼ������
* ����: cthis cufLedUsrCtrl��ָ��
* ���: hcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
hcufLedUsrCtrl cufLedUsrCtrl_init(hcufLedUsrCtrl cthis, hstaAct smcufLedUsrCtrl, hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl){
    cthis->smcufLedUsrCtrl = smcufLedUsrCtrl;
    cthis->vfbOcufLedUsrCtrl = vfbOcufLedUsrCtrl;
    //TODO

    return cthis;
}

/*������к���
* ����: t cufLedUsrCtrl��ָ��
* ���: ��
***********************************************/
void cufLedUsrCtrl_run(hcufLedUsrCtrl t){
    SMRE(t->smcufLedUsrCtrl, t->smcufLedUsrCtrlRec);
}

/*����๹�캯��
* ����: cthis cufLedUsrCtrl��ָ��
* ���: hcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
CC(cufLedUsrCtrl){
    cthis->init = cufLedUsrCtrl_init;
    cthis->run = cufLedUsrCtrl_run;
    //TODO

    cthis->smcufLedUsrCtrlRec.next = smcufLedUsrCtrl_sta_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis cufLedUsrCtrl��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(cufLedUsrCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* ����첽���ȹ��ܺ���
***********************************************************/
/*�첽���ȹ��ܺ���
***********************************************/
//void cufLedUsrCtrl_abi_example(void){
//  //TODO
//}


/***********************************************************
* ���ʵ����
***********************************************************/
/*�����ʵ��
***********************************************/
cufLedUsrCtrl cufLedUsrCtrlA;


/**************************** Copyright(C) pxf ****************************/
