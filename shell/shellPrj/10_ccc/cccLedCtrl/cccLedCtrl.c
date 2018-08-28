/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cccLedCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :���cccLedCtrl ����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "cccLedCtrl.h"

/***********************************************************
* �����ʼ��
***********************************************************/
/*�����ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 cccLedCtrlInit(void){
    int16 rtv = 0;

    CN(cccLedCtrl, &cccLedCtrlA, &smcccLedCtrl[0], &vfbOcccLedCtrlA);
    if(OPRS(cccLedCtrlA) != OOPC_NULL){
        rtv = vfbOcccLedCtrlInit();
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
void cccLedCtrlSch(void){
    cccLedCtrlA.run(cccLedCtrlA.self);
}


/***********************************************************
* ���ͨ�ù��ܺ���
***********************************************************/


/***********************************************************
* ���״̬��
***********************************************************/
/*���״̬������
***********************************************/
SMDF(smcccLedCtrl, SM_CCCLEDCTRL_STA_LIST);

/*smcccLedCtrl_act_init
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcccLedCtrl_act_init(void *hStaRec){
    hsmcccLedCtrlRec rec = (hsmcccLedCtrlRec)hStaRec;

    rec->cccLedCtrl = (void *)&cccLedCtrlA;
    //TODO

    rec->next = smcccLedCtrl_sta_default;
}

/*smcccLedCtrl_act_sta1
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcccLedCtrl_act_sta1(void *hStaRec){
    hsmcccLedCtrlRec rec = (hsmcccLedCtrlRec)hStaRec;
    //((hcccLedCtrl)(rec->cccLedCtrl))->

    //TODO

    rec->next = smcccLedCtrl_sta_default;
}

/*smcccLedCtrl_act_sta2
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcccLedCtrl_act_sta2(void *hStaRec){
    hsmcccLedCtrlRec rec = (hsmcccLedCtrlRec)hStaRec;
    //((hcccLedCtrl)(rec->cccLedCtrl))->

    //TODO

    rec->next = smcccLedCtrl_sta_default;
}

/*smcccLedCtrl_act_default
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcccLedCtrl_act_default(void *hStaRec){
    hsmcccLedCtrlRec rec = (hsmcccLedCtrlRec)hStaRec;
    //((hcccLedCtrl)(rec->cccLedCtrl))->

    //TODO

    rec->next = smcccLedCtrl_sta_default;
}


/***********************************************************
* �������
***********************************************************/
/*������ʼ������
* ����: cthis cccLedCtrl��ָ��
* ���: hcccLedCtrl cthis/OOPC_NULL
***********************************************/
hcccLedCtrl cccLedCtrl_init(hcccLedCtrl cthis, hstaAct smcccLedCtrl, hvfbOcccLedCtrl vfbOcccLedCtrl){
    cthis->smcccLedCtrl = smcccLedCtrl;
    cthis->vfbOcccLedCtrl = vfbOcccLedCtrl;
    //TODO

    return cthis;
}

/*������к���
* ����: t cccLedCtrl��ָ��
* ���: ��
***********************************************/
void cccLedCtrl_run(hcccLedCtrl t){
    SMRE(t->smcccLedCtrl, t->smcccLedCtrlRec);
}

/*����๹�캯��
* ����: cthis cccLedCtrl��ָ��
* ���: hcccLedCtrl cthis/OOPC_NULL
***********************************************/
CC(cccLedCtrl){
    cthis->init = cccLedCtrl_init;
    cthis->run = cccLedCtrl_run;
    //TODO

    cthis->smcccLedCtrlRec.next = smcccLedCtrl_sta_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis cccLedCtrl��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(cccLedCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* ����첽���ȹ��ܺ���
***********************************************************/
/*�첽���ȹ��ܺ���
***********************************************/
//void cccLedCtrl_abi_example(void){
//  //TODO
//}


/***********************************************************
* ���ʵ����
***********************************************************/
/*�����ʵ��
***********************************************/
cccLedCtrl cccLedCtrlA;


/**************************** Copyright(C) pxf ****************************/
