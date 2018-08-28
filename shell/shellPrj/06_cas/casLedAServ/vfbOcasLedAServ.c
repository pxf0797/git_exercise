/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcasLedAServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :���casLedAServ ����ඨ��
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
int16 vfbOcasLedAServInit(void){
    int16 rtv = 0;

    CNNP(vfbOcasLedAServ, &vfbOcasLedAServA);
    if(OPRS(vfbOcasLedAServA) != OOPC_NULL){
        rtv = vfbMcasLedAServInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ����������
***********************************************************/
/*������ʼ������
* ����: cthis vfbOcasLedAServ��ָ��
* ���: hvfbOcasLedAServ cthis/OOPC_NULL
***********************************************/
hvfbOcasLedAServ vfbOcasLedAServ_init(hvfbOcasLedAServ cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = casLedAServSch;
    cthis->schParam.startTick = (CASLEDASERV_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CASLEDASERV_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbOcasLedAServ��ָ��
* ���: hvfbOcasLedAServ cthis/OOPC_NULL
***********************************************/
CC(vfbOcasLedAServ){
    cthis->init = vfbOcasLedAServ_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbOcasLedAServ��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcasLedAServ){
    return OOPC_TRUE;
}


/***********************************************************
* ������ʵ����
***********************************************************/
/*��������ʵ��
***********************************************/
vfbOcasLedAServ vfbOcasLedAServA;


/**************************** Copyright(C) pxf ****************************/
