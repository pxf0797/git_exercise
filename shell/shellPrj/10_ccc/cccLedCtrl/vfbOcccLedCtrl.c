/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcccLedCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :���cccLedCtrl ����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "cccLedCtrl.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbOcccLedCtrlInit(void){
    int16 rtv = 0;

    CNNP(vfbOcccLedCtrl, &vfbOcccLedCtrlA);
    if(OPRS(vfbOcccLedCtrlA) != OOPC_NULL){
        rtv = vfbMcccLedCtrlInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ����������
***********************************************************/
/*������ʼ������
* ����: cthis vfbOcccLedCtrl��ָ��
* ���: hvfbOcccLedCtrl cthis/OOPC_NULL
***********************************************/
hvfbOcccLedCtrl vfbOcccLedCtrl_init(hvfbOcccLedCtrl cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = cccLedCtrlSch;
    cthis->schParam.startTick = (CCCLEDCTRL_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CCCLEDCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbOcccLedCtrl��ָ��
* ���: hvfbOcccLedCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbOcccLedCtrl){
    cthis->init = vfbOcccLedCtrl_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbOcccLedCtrl��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcccLedCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* ������ʵ����
***********************************************************/
/*��������ʵ��
***********************************************/
vfbOcccLedCtrl vfbOcccLedCtrlA;


/**************************** Copyright(C) pxf ****************************/
