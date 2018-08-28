/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcsLedServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 21:05:29
* @brief        :组件csLedServ 输入类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "csLedServ.h"

/***********************************************************
* 组件输入初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcsLedServInit(void){
    int16 rtv = 0;

    CN(vfbIcsLedServ, &vfbIcsLedServA, &csLedServA);
    if(OPRS(vfbIcsLedServA) != OOPC_NULL){
        rtv = csLedServInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输入定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbIcsLedServ类指针
* 输出: hvfbIcsLedServ cthis/OOPC_NULL
***********************************************/
hvfbIcsLedServ vfbIcsLedServ_init(hvfbIcsLedServ cthis, hcsLedServ csLedServ){
    cthis->csLedServ = csLedServ;
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbIcsLedServ类指针
* 输出: hvfbIcsLedServ cthis/OOPC_NULL
***********************************************/
CC(vfbIcsLedServ){
    cthis->init = vfbIcsLedServ_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbIcsLedServ类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcsLedServ){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输入实例化
***********************************************************/
/*组件输入类实例
***********************************************/
vfbIcsLedServ vfbIcsLedServA;


/**************************** Copyright(C) pxf ****************************/
