/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :abicasLedAServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :组件casLedAServ 抽象接口类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "abicasLedAServ.h"
#include "..\..\03_bsp\bsp.h"

/***********************************************************
* 组件抽象接口初始化
***********************************************************/
/*组件抽象接口初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 abicasLedAServInit(void){
    int16 rtv = 0;

    //CN(isr, &timer, casLedAServ_abi_timer);
    //if(OPRS(timer) == OOPC_NULL){
    //    rtv -= 1;
    //}
    //CN(isr, &mainLoop, casLedAServ_abi_mainLoop);
    //if(OPRS(mainLoop) == OOPC_NULL){
    //    rtv -= 1;
    //}
    //CN(measure, &time, bspMeasureStart, bspMeasureEnd);
    //if(OPRS(time) == OOPC_NULL){
    //    rtv -= 1;
    //}
    //CN(gi, &err, bspErr);
    //if(OPRS(err) == OOPC_NULL){
    //    rtv -= 1;
    //}
    //CN(go, &led, bspLed);
    //if(OPRS(led) == OOPC_NULL){
    //    rtv -= 1;
    //}

    return rtv;
}


/***********************************************************
* 组件抽象接口实例
***********************************************************/
/*线程类抽象实例
***********************************************/
//isr timer;
//isr mainLoop;

/*时间测量类抽象实例
***********************************************/
//measure time;

/*GIO输入类抽象实例
***********************************************/
//gi err;

/*GIO输出类抽象实例
***********************************************/
//go led;


/**************************** Copyright(C) pxf ****************************/
