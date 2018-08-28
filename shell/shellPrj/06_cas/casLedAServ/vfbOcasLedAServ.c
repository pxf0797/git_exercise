/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcasLedAServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :组件casLedAServ 输出类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "casLedAServ.h"

/***********************************************************
* 组件输出初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
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
* 组件输出定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbOcasLedAServ类指针
* 输出: hvfbOcasLedAServ cthis/OOPC_NULL
***********************************************/
hvfbOcasLedAServ vfbOcasLedAServ_init(hvfbOcasLedAServ cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = casLedAServSch;
    cthis->schParam.startTick = (CASLEDASERV_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CASLEDASERV_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbOcasLedAServ类指针
* 输出: hvfbOcasLedAServ cthis/OOPC_NULL
***********************************************/
CC(vfbOcasLedAServ){
    cthis->init = vfbOcasLedAServ_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbOcasLedAServ类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcasLedAServ){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出实例化
***********************************************************/
/*组件输出类实例
***********************************************/
vfbOcasLedAServ vfbOcasLedAServA;


/**************************** Copyright(C) pxf ****************************/
