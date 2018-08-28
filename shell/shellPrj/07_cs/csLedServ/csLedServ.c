/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :csLedServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:07
* @brief        :���csLedServ ����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "csLedServ.h"

/***********************************************************
* �����ʼ��
***********************************************************/
/*�����ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 csLedServInit(void){
    int16 rtv = 0;

    CN(csLedServ, &csLedServA, &smcsLedServ[0], &vfbOcsLedServA);
    if(OPRS(csLedServA) != OOPC_NULL){
        rtv = vfbOcsLedServInit();
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
void csLedServSch(void){
    csLedServA.run(csLedServA.self);
}


/***********************************************************
* ���ͨ�ù��ܺ���
***********************************************************/


/***********************************************************
* ���״̬��
***********************************************************/
/*���״̬������
***********************************************/
SMDF(smcsLedServ, SM_CSLEDSERV_STA_LIST);

/*smcsLedServ_act_init
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcsLedServ_act_init(void *hStaRec){
    hsmcsLedServRec rec = (hsmcsLedServRec)hStaRec;

    rec->csLedServ = (void *)&csLedServA;
    //TODO

    rec->next = smcsLedServ_sta_default;
}

/*smcsLedServ_act_sta1
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcsLedServ_act_sta1(void *hStaRec){
    hsmcsLedServRec rec = (hsmcsLedServRec)hStaRec;
    //((hcsLedServ)(rec->csLedServ))->

    //TODO

    rec->next = smcsLedServ_sta_default;
}

/*smcsLedServ_act_sta2
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcsLedServ_act_sta2(void *hStaRec){
    hsmcsLedServRec rec = (hsmcsLedServRec)hStaRec;
    //((hcsLedServ)(rec->csLedServ))->

    //TODO

    rec->next = smcsLedServ_sta_default;
}

/*smcsLedServ_act_default
* ����: hStaRec ״̬��¼�ṹ��ָ��
* ���: ��
***********************************************/
void smcsLedServ_act_default(void *hStaRec){
    hsmcsLedServRec rec = (hsmcsLedServRec)hStaRec;
    //((hcsLedServ)(rec->csLedServ))->

    //TODO

    rec->next = smcsLedServ_sta_default;
}


/***********************************************************
* �������
***********************************************************/
/*������ʼ������
* ����: cthis csLedServ��ָ��
* ���: hcsLedServ cthis/OOPC_NULL
***********************************************/
hcsLedServ csLedServ_init(hcsLedServ cthis, hstaAct smcsLedServ, hvfbOcsLedServ vfbOcsLedServ){
    cthis->smcsLedServ = smcsLedServ;
    cthis->vfbOcsLedServ = vfbOcsLedServ;
    //TODO

    return cthis;
}

/*������к���
* ����: t csLedServ��ָ��
* ���: ��
***********************************************/
void csLedServ_run(hcsLedServ t){
    SMRE(t->smcsLedServ, t->smcsLedServRec);
}

/*����๹�캯��
* ����: cthis csLedServ��ָ��
* ���: hcsLedServ cthis/OOPC_NULL
***********************************************/
CC(csLedServ){
    cthis->init = csLedServ_init;
    cthis->run = csLedServ_run;
    //TODO

    cthis->smcsLedServRec.next = smcsLedServ_sta_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis csLedServ��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(csLedServ){
    return OOPC_TRUE;
}


/***********************************************************
* ����첽���ȹ��ܺ���
***********************************************************/
/*�첽���ȹ��ܺ���
***********************************************/
//void csLedServ_abi_example(void){
//  //TODO
//}


/***********************************************************
* ���ʵ����
***********************************************************/
/*�����ʵ��
***********************************************/
csLedServ csLedServA;


/**************************** Copyright(C) pxf ****************************/
