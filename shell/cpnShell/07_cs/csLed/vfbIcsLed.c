/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcsLed.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/26 21:32:19
* @brief        :
* @others       :
* @history      :180826 pxf 初次建立
***************************************************************************/

#include "csLed.h"

/***********************************************************
* 组件输入初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcsLedInit(void){
    int16 rtv = 0;

    CN(vfbIcsLed, &vfbIcsLedA, &csLedA);
    if(OPRS(vfbIcsLedA) != OOPC_NULL){
        rtv = csLedInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输入定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbIcsLed类指针
* 输出: hvfbIcsLed cthis/OOPC_NULL
***********************************************/
hvfbIcsLed vfbIcsLed_init(hvfbIcsLed cthis, csLed csLed){
    cthis->csLed = csLed;
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbIcsLed类指针
* 输出: hvfbIcsLed cthis/OOPC_NULL
***********************************************/
CC(vfbIcsLed){
    cthis->init = vfbIcsLed_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbIcsLed类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcsLed){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输入实例化
***********************************************************/
/*组件输入类实例
***********************************************/
vfbIcsLed vfbIcsLedA;


/**************************** Copyright(C) pxf ****************************/
