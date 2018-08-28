/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcsLedServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 21:05:29
* @brief        :���csLedServ ����ඨ��
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
int16 vfbOcsLedServInit(void){
    int16 rtv = 0;

    CNNP(vfbOcsLedServ, &vfbOcsLedServA);
    if(OPRS(vfbOcsLedServA) != OOPC_NULL){
        rtv = vfbMcsLedServInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ����������
***********************************************************/
/*������ʼ������
* ����: cthis vfbOcsLedServ��ָ��
* ���: hvfbOcsLedServ cthis/OOPC_NULL
***********************************************/
hvfbOcsLedServ vfbOcsLedServ_init(hvfbOcsLedServ cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = csLedServSch;
    cthis->schParam.startTick = (CSLEDSERV_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CSLEDSERV_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbOcsLedServ��ָ��
* ���: hvfbOcsLedServ cthis/OOPC_NULL
***********************************************/
CC(vfbOcsLedServ){
    cthis->init = vfbOcsLedServ_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbOcsLedServ��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcsLedServ){
    return OOPC_TRUE;
}


/***********************************************************
* ������ʵ����
***********************************************************/
/*��������ʵ��
***********************************************/
vfbOcsLedServ vfbOcsLedServA;


/**************************** Copyright(C) pxf ****************************/
