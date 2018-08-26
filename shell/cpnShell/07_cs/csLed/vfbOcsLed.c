/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcsLed.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/26 21:32:19
* @brief        :
* @others       :
* @history      :180826 pxf 初次建立
***************************************************************************/

#include "csLed.h"

/***********************************************************
* 组件输出初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbOcsLedInit(void){
    int16 rtv = 0;

    CNNP(vfbOcsLed, &vfbOcsLedA);
    if(OPRS(vfbOcsLedA) != OOPC_NULL){
        rtv = vfbMcsLedInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输出定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbOcsLed类指针
* 输出: hvfbOcsLed cthis/OOPC_NULL
***********************************************/
hvfbOcsLed vfbOcsLed_init(hvfbOcsLed cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = csLedSch;
    cthis->schParam.startTick = (CSLED_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CSLED_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbOcsLed类指针
* 输出: hvfbOcsLed cthis/OOPC_NULL
***********************************************/
CC(vfbOcsLed){
    cthis->init = vfbOcsLed_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbOcsLed类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcsLed){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出实例化
***********************************************************/
/*组件输出类实例
***********************************************/
vfbOcsLed vfbOcsLedA;


/**************************** Copyright(C) pxf ****************************/
