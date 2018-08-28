/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :casLedAServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :���casLedAServ ����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "casLedAServ.h"

/***********************************************************
* �����ʼ��
***********************************************************/
/*�����ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 casLedAServInit(void){
    int16 rtv = 0;

    CN(casLedAServ, &casLedAServA, &smcasLedAServ[0], &vfbOcasLedAServA);
    if(OPRS(casLedAServA) != OOPC_NULL){
        rtv = vfbOcasLedAServInit();
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
void casLedAServSch(void){
    casLedAServA.run(casLedAServA.self);
}


/***********************************************************
* ���ͨ�ù��ܺ���
***********************************************************/


/***********************************************************
* ���״̬��
***********************************************************/
/*���״̬������
***********************************************/
SMDF(smcasLedAServ, SM_CASLEDASERV_STA_LIST);

/*smcasLedAServ_act_init
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcasLedAServ_act_init(void *hStaRec){
    hsmcasLedAServRec rec = (hsmcasLedAServRec)hStaRec;

    rec->casLedAServ = (void *)&casLedAServA;
    //TODO

    rec->next = smcasLedAServ_sta_default;
}

/*smcasLedAServ_act_sta1
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcasLedAServ_act_sta1(void *hStaRec){
    hsmcasLedAServRec rec = (hsmcasLedAServRec)hStaRec;
    //((hcasLedAServ)(rec->casLedAServ))->

    //TODO

    rec->next = smcasLedAServ_sta_default;
}

/*smcasLedAServ_act_sta2
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcasLedAServ_act_sta2(void *hStaRec){
    hsmcasLedAServRec rec = (hsmcasLedAServRec)hStaRec;
    //((hcasLedAServ)(rec->casLedAServ))->

    //TODO

    rec->next = smcasLedAServ_sta_default;
}

/*smcasLedAServ_act_default
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcasLedAServ_act_default(void *hStaRec){
    hsmcasLedAServRec rec = (hsmcasLedAServRec)hStaRec;
    //((hcasLedAServ)(rec->casLedAServ))->

    //TODO

    rec->next = smcasLedAServ_sta_default;
}


/***********************************************************
* �������
***********************************************************/
/*������ʼ������
* ����: cthis casLedAServ��ָ��
* ���: hcasLedAServ cthis/OOPC_NULL
***********************************************/
hcasLedAServ casLedAServ_init(hcasLedAServ cthis, hstaAct smcasLedAServ, hvfbOcasLedAServ vfbOcasLedAServ){
    cthis->smcasLedAServ = smcasLedAServ;
    cthis->vfbOcasLedAServ = vfbOcasLedAServ;
    //TODO

    return cthis;
}

/*������к���
* ����: t casLedAServ��ָ��
* ���: ��
***********************************************/
void casLedAServ_run(hcasLedAServ t){
    SMRE(t->smcasLedAServ, t->smcasLedAServRec);
}

/*����๹�캯��
* ����: cthis casLedAServ��ָ��
* ���: hcasLedAServ cthis/OOPC_NULL
***********************************************/
CC(casLedAServ){
    cthis->init = casLedAServ_init;
    cthis->run = casLedAServ_run;
    //TODO

    cthis->smcasLedAServRec.next = smcasLedAServ_sta_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis casLedAServ��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(casLedAServ){
    return OOPC_TRUE;
}


/***********************************************************
* ����첽���ȹ��ܺ���
***********************************************************/
/*�첽���ȹ��ܺ���
***********************************************/
//void casLedAServ_abi_example(void){
//  //TODO
//}


/***********************************************************
* ���ʵ����
***********************************************************/
/*�����ʵ��
***********************************************/
casLedAServ casLedAServA;


/**************************** Copyright(C) pxf ****************************/
