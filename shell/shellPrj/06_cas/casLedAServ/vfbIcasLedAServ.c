/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcasLedAServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :���casLedAServ �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "casLedAServ.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbIcasLedAServInit(void){
    int16 rtv = 0;

    CN(vfbIcasLedAServ, &vfbIcasLedAServA, &casLedAServA);
    if(OPRS(vfbIcasLedAServA) != OOPC_NULL){
        rtv = casLedAServInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ������붨��
***********************************************************/
/*������ʼ������
* ����: cthis vfbIcasLedAServ��ָ��
* ���: hvfbIcasLedAServ cthis/OOPC_NULL
***********************************************/
hvfbIcasLedAServ vfbIcasLedAServ_init(hvfbIcasLedAServ cthis, hcasLedAServ casLedAServ){
    cthis->casLedAServ = casLedAServ;
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbIcasLedAServ��ָ��
* ���: hvfbIcasLedAServ cthis/OOPC_NULL
***********************************************/
CC(vfbIcasLedAServ){
    cthis->init = vfbIcasLedAServ_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbIcasLedAServ��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcasLedAServ){
    return OOPC_TRUE;
}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbIcasLedAServ vfbIcasLedAServA;


/**************************** Copyright(C) pxf ****************************/
