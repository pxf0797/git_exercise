/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcsLedServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 21:05:29
* @brief        :���csLedServ �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "vfbMcsLedServ.h"

/*�������id��ʱ���ã����ʵ��ʹ��ʱ������vbfMCfg.h������
***********************************************************/
#define csLedServ_id_priority_cfg   0


/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbMcsLedServInit(void){
    int16 rtv = 0;

    CN(vfbMcsLedServ, &vfbMcsLedServA, &vfbOcsLedServA, &vfbIcasSchA);
    if(OPRS(vfbMcsLedServA) != OOPC_NULL){
        vfbMcsLedServA.vfbOcsLedServ->schParam.id = csLedServ_id_priority_cfg;
        vfbMcsLedServA.vfbOcsLedServ->schParam.prdTick = (CSLEDSERV_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcsLedServA.vfbOcsLedServ->schParam.startTick = (CSLEDSERV_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcsLedServA.vfbIcasSch->addTask(vfbMcsLedServA.vfbIcasSch,
            vfbMcsLedServA.vfbOcsLedServ->schParam.id, vfbMcsLedServA.vfbOcsLedServ->schParam.schTask,
            vfbMcsLedServA.vfbOcsLedServ->schParam.prdTick, vfbMcsLedServA.vfbOcsLedServ->schParam.startTick);

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
* ����: cthis vfbMcsLedServ��ָ��
* ���: hvfbMcsLedServ cthis/OOPC_NULL
***********************************************/
hvfbMcsLedServ vfbMcsLedServ_init(hvfbMcsLedServ cthis, hvfbOcsLedServ vfbOcsLedServ, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcsLedServ = vfbOcsLedServ;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*��������๹�캯��
* ����: cthis vfbMcsLedServ��ָ��
* ���: hvfbMcsLedServ cthis/OOPC_NULL
***********************************************/
CC(vfbMcsLedServ){
    cthis->init = vfbMcsLedServ_init;
    //TODO

    return cthis;
}
/*�����������������
* ����: cthis vfbMcsLedServ��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcsLedServ){
    return OOPC_TRUE;
}


/***********************************************************
* ��������ӿڶ���
***********************************************************/
/*�������๦�ܺ���
***********************************************/
//void vfbMcsLedServ_vfbOcsLedServ_example(hvfbOcsLedServ t){
//  //TODO
//}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbMcsLedServ vfbMcsLedServA;


/**************************** Copyright(C) pxf ****************************/
