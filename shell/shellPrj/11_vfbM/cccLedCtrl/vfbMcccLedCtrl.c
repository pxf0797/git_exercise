/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcccLedCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :���cccLedCtrl �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "vfbMcccLedCtrl.h"

/*�������id��ʱ���ã����ʵ��ʹ��ʱ������vbfMCfg.h������
***********************************************************/
#define cccLedCtrl_id_priority_cfg   0


/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbMcccLedCtrlInit(void){
    int16 rtv = 0;

    CN(vfbMcccLedCtrl, &vfbMcccLedCtrlA, &vfbOcccLedCtrlA, &vfbIcasSchA);
    if(OPRS(vfbMcccLedCtrlA) != OOPC_NULL){
        vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.id = cccLedCtrl_id_priority_cfg;
        vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.prdTick = (CCCLEDCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.startTick = (CCCLEDCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcccLedCtrlA.vfbIcasSch->addTask(vfbMcccLedCtrlA.vfbIcasSch,
            vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.id, vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.schTask,
            vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.prdTick, vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.startTick);

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
* ����: cthis vfbMcccLedCtrl��ָ��
* ���: hvfbMcccLedCtrl cthis/OOPC_NULL
***********************************************/
hvfbMcccLedCtrl vfbMcccLedCtrl_init(hvfbMcccLedCtrl cthis, hvfbOcccLedCtrl vfbOcccLedCtrl, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcccLedCtrl = vfbOcccLedCtrl;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*��������๹�캯��
* ����: cthis vfbMcccLedCtrl��ָ��
* ���: hvfbMcccLedCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbMcccLedCtrl){
    cthis->init = vfbMcccLedCtrl_init;
    //TODO

    return cthis;
}
/*�����������������
* ����: cthis vfbMcccLedCtrl��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcccLedCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* ��������ӿڶ���
***********************************************************/
/*�������๦�ܺ���
***********************************************/
//void vfbMcccLedCtrl_vfbOcccLedCtrl_example(hvfbOcccLedCtrl t){
//  //TODO
//}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbMcccLedCtrl vfbMcccLedCtrlA;


/**************************** Copyright(C) pxf ****************************/
