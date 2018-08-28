/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcasLedAServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :组件casLedAServ 输入类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "casLedAServ.h"

/***********************************************************
* 组件输入初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcasLedAServInit(void){
    int16 rtv = 0;

    CN(vfbIcasLedAServ, &vfbIcasLedAServA, &casLedAServA);
    if(OPRS(vfbIcasLedAServA) != OOPC_NULL){
        rtv = casLedAServInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输入定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbIcasLedAServ类指针
* 输出: hvfbIcasLedAServ cthis/OOPC_NULL
***********************************************/
hvfbIcasLedAServ vfbIcasLedAServ_init(hvfbIcasLedAServ cthis, hcasLedAServ casLedAServ){
    cthis->casLedAServ = casLedAServ;
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbIcasLedAServ类指针
* 输出: hvfbIcasLedAServ cthis/OOPC_NULL
***********************************************/
CC(vfbIcasLedAServ){
    cthis->init = vfbIcasLedAServ_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbIcasLedAServ类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcasLedAServ){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输入实例化
***********************************************************/
/*组件输入类实例
***********************************************/
vfbIcasLedAServ vfbIcasLedAServA;


/**************************** Copyright(C) pxf ****************************/
