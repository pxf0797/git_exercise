/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcccLedCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :组件cccLedCtrl 输入类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "cccLedCtrl.h"

/***********************************************************
* 组件输入初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcccLedCtrlInit(void){
    int16 rtv = 0;

    CN(vfbIcccLedCtrl, &vfbIcccLedCtrlA, &cccLedCtrlA);
    if(OPRS(vfbIcccLedCtrlA) != OOPC_NULL){
        rtv = cccLedCtrlInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输入定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbIcccLedCtrl类指针
* 输出: hvfbIcccLedCtrl cthis/OOPC_NULL
***********************************************/
hvfbIcccLedCtrl vfbIcccLedCtrl_init(hvfbIcccLedCtrl cthis, hcccLedCtrl cccLedCtrl){
    cthis->cccLedCtrl = cccLedCtrl;
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbIcccLedCtrl类指针
* 输出: hvfbIcccLedCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbIcccLedCtrl){
    cthis->init = vfbIcccLedCtrl_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbIcccLedCtrl类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcccLedCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输入实例化
***********************************************************/
/*组件输入类实例
***********************************************/
vfbIcccLedCtrl vfbIcccLedCtrlA;


/**************************** Copyright(C) pxf ****************************/
