/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcasLedAServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :组件casLedAServ 管理类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "vfbMcasLedAServ.h"

/*组件调度id临时配置，组件实际使用时必须在vbfMCfg.h中配置
***********************************************************/
#define casLedAServ_id_priority_cfg   0


/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
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
* 组件管理定义
***********************************************************/
/*组件管理类初始化函数
* 输入: cthis vfbMcasLedAServ类指针
* 输出: hvfbMcasLedAServ cthis/OOPC_NULL
***********************************************/
hvfbMcasLedAServ vfbMcasLedAServ_init(hvfbMcasLedAServ cthis, hvfbOcasLedAServ vfbOcasLedAServ, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcasLedAServ = vfbOcasLedAServ;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*组件管理类构造函数
* 输入: cthis vfbMcasLedAServ类指针
* 输出: hvfbMcasLedAServ cthis/OOPC_NULL
***********************************************/
CC(vfbMcasLedAServ){
    cthis->init = vfbMcasLedAServ_init;
    //TODO

    return cthis;
}
/*组件管理类析构函数
* 输入: cthis vfbMcasLedAServ类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcasLedAServ){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出类接口定义
***********************************************************/
/*组件输出类功能函数
***********************************************/
//void vfbMcasLedAServ_vfbOcasLedAServ_example(hvfbOcasLedAServ t){
//  //TODO
//}


/***********************************************************
* 组件管理实例化
***********************************************************/
/*组件管理类实例
***********************************************/
vfbMcasLedAServ vfbMcasLedAServA;


/**************************** Copyright(C) pxf ****************************/
