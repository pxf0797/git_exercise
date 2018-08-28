/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcufLedUsrCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :���cufLedUsrCtrl �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "vfbMcufLedUsrCtrl.h"

/*�������id��ʱ���ã����ʵ��ʹ��ʱ������vbfMCfg.h������
***********************************************************/
#define cufLedUsrCtrl_id_priority_cfg   0


/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbMcufLedUsrCtrlInit(void){
    int16 rtv = 0;

    CN(vfbMcufLedUsrCtrl, &vfbMcufLedUsrCtrlA, &vfbOcufLedUsrCtrlA, &vfbIcasSchA);
    if(OPRS(vfbMcufLedUsrCtrlA) != OOPC_NULL){
        vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.id = cufLedUsrCtrl_id_priority_cfg;
        vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.prdTick = (CUFLEDUSRCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.startTick = (CUFLEDUSRCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcufLedUsrCtrlA.vfbIcasSch->addTask(vfbMcufLedUsrCtrlA.vfbIcasSch,
            vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.id, vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.schTask,
            vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.prdTick, vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.startTick);

        rtv = 0;
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ���������
***********************************************************/
/*����������ʼ������
* ����: cthis vfbMcufLedUsrCtrl��ָ��
* ���: hvfbMcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
hvfbMcufLedUsrCtrl vfbMcufLedUsrCtrl_init(hvfbMcufLedUsrCtrl cthis, hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcufLedUsrCtrl = vfbOcufLedUsrCtrl;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*��������๹�캯��
* ����: cthis vfbMcufLedUsrCtrl��ָ��
* ���: hvfbMcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbMcufLedUsrCtrl){
    cthis->init = vfbMcufLedUsrCtrl_init;
    //TODO

    return cthis;
}
/*�����������������
* ����: cthis vfbMcufLedUsrCtrl��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcufLedUsrCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* ��������ӿڶ���
***********************************************************/
/*�������๦�ܺ���
***********************************************/
//void vfbMcufLedUsrCtrl_vfbOcufLedUsrCtrl_example(hvfbOcufLedUsrCtrl t){
//  //TODO
//}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbMcufLedUsrCtrl vfbMcufLedUsrCtrlA;


/**************************** Copyright(C) pxf ****************************/
