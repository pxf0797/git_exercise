/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcccLedCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :组件cccLedCtrl 输出类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "cccLedCtrl.h"

/***********************************************************
* 组件输出初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
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
* 组件输出定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbOcccLedCtrl类指针
* 输出: hvfbOcccLedCtrl cthis/OOPC_NULL
***********************************************/
hvfbOcccLedCtrl vfbOcccLedCtrl_init(hvfbOcccLedCtrl cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = cccLedCtrlSch;
    cthis->schParam.startTick = (CCCLEDCTRL_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CCCLEDCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbOcccLedCtrl类指针
* 输出: hvfbOcccLedCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbOcccLedCtrl){
    cthis->init = vfbOcccLedCtrl_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbOcccLedCtrl类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcccLedCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出实例化
***********************************************************/
/*组件输出类实例
***********************************************/
vfbOcccLedCtrl vfbOcccLedCtrlA;


/**************************** Copyright(C) pxf ****************************/
