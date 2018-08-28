/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcpcLedEncode.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :组件cpcLedEncode 输入类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "cpcLedEncode.h"

/***********************************************************
* 组件输入初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcpcLedEncodeInit(void){
    int16 rtv = 0;

    CN(vfbIcpcLedEncode, &vfbIcpcLedEncodeA, &cpcLedEncodeA);
    if(OPRS(vfbIcpcLedEncodeA) != OOPC_NULL){
        rtv = cpcLedEncodeInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输入定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbIcpcLedEncode类指针
* 输出: hvfbIcpcLedEncode cthis/OOPC_NULL
***********************************************/
hvfbIcpcLedEncode vfbIcpcLedEncode_init(hvfbIcpcLedEncode cthis, hcpcLedEncode cpcLedEncode){
    cthis->cpcLedEncode = cpcLedEncode;
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbIcpcLedEncode类指针
* 输出: hvfbIcpcLedEncode cthis/OOPC_NULL
***********************************************/
CC(vfbIcpcLedEncode){
    cthis->init = vfbIcpcLedEncode_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbIcpcLedEncode类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcpcLedEncode){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输入实例化
***********************************************************/
/*组件输入类实例
***********************************************/
vfbIcpcLedEncode vfbIcpcLedEncodeA;


/**************************** Copyright(C) pxf ****************************/
