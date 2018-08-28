/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcasLedAServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :���casLedAServ �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "vfbMcasLedAServ.h"

/*�������id��ʱ���ã����ʵ��ʹ��ʱ������vbfMCfg.h������
***********************************************************/
#define casLedAServ_id_priority_cfg   0


/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbMcasLedAServInit(void){
    int16 rtv = 0;

    CN(vfbMcasLedAServ, &vfbMcasLedAServA, &vfbOcasLedAServA, &vfbIcasSchA);
    if(OPRS(vfbMcasLedAServA) != OOPC_NULL){
        vfbMcasLedAServA.vfbOcasLedAServ->schParam.id = casLedAServ_id_priority_cfg;
        vfbMcasLedAServA.vfbOcasLedAServ->schParam.prdTick = (CASLEDASERV_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcasLedAServA.vfbOcasLedAServ->schParam.startTick = (CASLEDASERV_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcasLedAServA.vfbIcasSch->addTask(vfbMcasLedAServA.vfbIcasSch,
            vfbMcasLedAServA.vfbOcasLedAServ->schParam.id, vfbMcasLedAServA.vfbOcasLedAServ->schParam.schTask,
            vfbMcasLedAServA.vfbOcasLedAServ->schParam.prdTick, vfbMcasLedAServA.vfbOcasLedAServ->schParam.startTick);

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
* ����: cthis vfbMcasLedAServ��ָ��
* ���: hvfbMcasLedAServ cthis/OOPC_NULL
***********************************************/
hvfbMcasLedAServ vfbMcasLedAServ_init(hvfbMcasLedAServ cthis, hvfbOcasLedAServ vfbOcasLedAServ, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcasLedAServ = vfbOcasLedAServ;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*��������๹�캯��
* ����: cthis vfbMcasLedAServ��ָ��
* ���: hvfbMcasLedAServ cthis/OOPC_NULL
***********************************************/
CC(vfbMcasLedAServ){
    cthis->init = vfbMcasLedAServ_init;
    //TODO

    return cthis;
}
/*�����������������
* ����: cthis vfbMcasLedAServ��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcasLedAServ){
    return OOPC_TRUE;
}


/***********************************************************
* ��������ӿڶ���
***********************************************************/
/*�������๦�ܺ���
***********************************************/
//void vfbMcasLedAServ_vfbOcasLedAServ_example(hvfbOcasLedAServ t){
//  //TODO
//}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbMcasLedAServ vfbMcasLedAServA;


/**************************** Copyright(C) pxf ****************************/
