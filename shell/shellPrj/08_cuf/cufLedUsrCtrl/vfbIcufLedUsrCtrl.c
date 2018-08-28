/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcufLedUsrCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :组件cufLedUsrCtrl 输入类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "cufLedUsrCtrl.h"

/***********************************************************
* 组件输入初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcufLedUsrCtrlInit(void){
    int16 rtv = 0;

    CN(vfbIcufLedUsrCtrl, &vfbIcufLedUsrCtrlA, &cufLedUsrCtrlA);
    if(OPRS(vfbIcufLedUsrCtrlA) != OOPC_NULL){
        rtv = cufLedUsrCtrlInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输入定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbIcufLedUsrCtrl类指针
* 输出: hvfbIcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
hvfbIcufLedUsrCtrl vfbIcufLedUsrCtrl_init(hvfbIcufLedUsrCtrl cthis, hcufLedUsrCtrl cufLedUsrCtrl){
    cthis->cufLedUsrCtrl = cufLedUsrCtrl;
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbIcufLedUsrCtrl类指针
* 输出: hvfbIcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbIcufLedUsrCtrl){
    cthis->init = vfbIcufLedUsrCtrl_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbIcufLedUsrCtrl类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcufLedUsrCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输入实例化
***********************************************************/
/*组件输入类实例
***********************************************/
vfbIcufLedUsrCtrl vfbIcufLedUsrCtrlA;


/**************************** Copyright(C) pxf ****************************/
