/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcufLedUsrCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :组件cufLedUsrCtrl 输出类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "cufLedUsrCtrl.h"

/***********************************************************
* 组件输出初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
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
* 组件输出定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbOcufLedUsrCtrl类指针
* 输出: hvfbOcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl_init(hvfbOcufLedUsrCtrl cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = cufLedUsrCtrlSch;
    cthis->schParam.startTick = (CUFLEDUSRCTRL_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CUFLEDUSRCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbOcufLedUsrCtrl类指针
* 输出: hvfbOcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbOcufLedUsrCtrl){
    cthis->init = vfbOcufLedUsrCtrl_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbOcufLedUsrCtrl类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcufLedUsrCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出实例化
***********************************************************/
/*组件输出类实例
***********************************************/
vfbOcufLedUsrCtrl vfbOcufLedUsrCtrlA;


/**************************** Copyright(C) pxf ****************************/
