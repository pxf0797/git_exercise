/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcpcLedEncode.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :组件cpcLedEncode 输出类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "cpcLedEncode.h"

/***********************************************************
* 组件输出初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbOcpcLedEncodeInit(void){
    int16 rtv = 0;

    CNNP(vfbOcpcLedEncode, &vfbOcpcLedEncodeA);
    if(OPRS(vfbOcpcLedEncodeA) != OOPC_NULL){
        rtv = vfbMcpcLedEncodeInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输出定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbOcpcLedEncode类指针
* 输出: hvfbOcpcLedEncode cthis/OOPC_NULL
***********************************************/
hvfbOcpcLedEncode vfbOcpcLedEncode_init(hvfbOcpcLedEncode cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = cpcLedEncodeSch;
    cthis->schParam.startTick = (CPCLEDENCODE_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CPCLEDENCODE_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbOcpcLedEncode类指针
* 输出: hvfbOcpcLedEncode cthis/OOPC_NULL
***********************************************/
CC(vfbOcpcLedEncode){
    cthis->init = vfbOcpcLedEncode_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbOcpcLedEncode类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcpcLedEncode){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出实例化
***********************************************************/
/*组件输出类实例
***********************************************/
vfbOcpcLedEncode vfbOcpcLedEncodeA;


/**************************** Copyright(C) pxf ****************************/
