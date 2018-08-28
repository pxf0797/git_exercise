/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcsLedServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:07
* @brief        :���csLedServ �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "csLedServ.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbIcsLedServInit(void){
    int16 rtv = 0;

    CN(vfbIcsLedServ, &vfbIcsLedServA, &csLedServA);
    if(OPRS(vfbIcsLedServA) != OOPC_NULL){
        rtv = csLedServInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ������붨��
***********************************************************/
/*������ʼ������
* ����: cthis vfbIcsLedServ��ָ��
* ���: hvfbIcsLedServ cthis/OOPC_NULL
***********************************************/
hvfbIcsLedServ vfbIcsLedServ_init(hvfbIcsLedServ cthis, hcsLedServ csLedServ){
    cthis->csLedServ = csLedServ;
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbIcsLedServ��ָ��
* ���: hvfbIcsLedServ cthis/OOPC_NULL
***********************************************/
CC(vfbIcsLedServ){
    cthis->init = vfbIcsLedServ_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbIcsLedServ��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcsLedServ){
    return OOPC_TRUE;
}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbIcsLedServ vfbIcsLedServA;


/**************************** Copyright(C) pxf ****************************/
