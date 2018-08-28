/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcufLedUsrCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :���cufLedUsrCtrl ����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "cufLedUsrCtrl.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbOcufLedUsrCtrlInit(void){
    int16 rtv = 0;

    CNNP(vfbOcufLedUsrCtrl, &vfbOcufLedUsrCtrlA);
    if(OPRS(vfbOcufLedUsrCtrlA) != OOPC_NULL){
        rtv = vfbMcufLedUsrCtrlInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ����������
***********************************************************/
/*������ʼ������
* ����: cthis vfbOcufLedUsrCtrl��ָ��
* ���: hvfbOcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl_init(hvfbOcufLedUsrCtrl cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = cufLedUsrCtrlSch;
    cthis->schParam.startTick = (CUFLEDUSRCTRL_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CUFLEDUSRCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbOcufLedUsrCtrl��ָ��
* ���: hvfbOcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbOcufLedUsrCtrl){
    cthis->init = vfbOcufLedUsrCtrl_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbOcufLedUsrCtrl��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcufLedUsrCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* ������ʵ����
***********************************************************/
/*��������ʵ��
***********************************************/
vfbOcufLedUsrCtrl vfbOcufLedUsrCtrlA;


/**************************** Copyright(C) pxf ****************************/
