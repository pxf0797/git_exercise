/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcpcLedEncode.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :组件cpcLedEncode 管理类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "vfbMcpcLedEncode.h"

/*组件调度id临时配置，组件实际使用时必须在vbfMCfg.h中配置
***********************************************************/
#define cpcLedEncode_id_priority_cfg   0


/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcpcLedEncodeInit(void){
    int16 rtv = 0;

    CN(vfbMcpcLedEncode, &vfbMcpcLedEncodeA, &vfbOcpcLedEncodeA, &vfbIcasSchA);
    if(OPRS(vfbMcpcLedEncodeA) != OOPC_NULL){
        vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.id = cpcLedEncode_id_priority_cfg;
        vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.prdTick = (CPCLEDENCODE_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.startTick = (CPCLEDENCODE_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcpcLedEncodeA.vfbIcasSch->addTask(vfbMcpcLedEncodeA.vfbIcasSch,
            vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.id, vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.schTask,
            vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.prdTick, vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.startTick);

        rtv = 0;
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件管理定义
***********************************************************/
/*组件管理类初始化函数
* 输入: cthis vfbMcpcLedEncode类指针
* 输出: hvfbMcpcLedEncode cthis/OOPC_NULL
***********************************************/
hvfbMcpcLedEncode vfbMcpcLedEncode_init(hvfbMcpcLedEncode cthis, hvfbOcpcLedEncode vfbOcpcLedEncode, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcpcLedEncode = vfbOcpcLedEncode;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*组件管理类构造函数
* 输入: cthis vfbMcpcLedEncode类指针
* 输出: hvfbMcpcLedEncode cthis/OOPC_NULL
***********************************************/
CC(vfbMcpcLedEncode){
    cthis->init = vfbMcpcLedEncode_init;
    //TODO

    return cthis;
}
/*组件管理类析构函数
* 输入: cthis vfbMcpcLedEncode类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcpcLedEncode){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出类接口定义
***********************************************************/
/*组件输出类功能函数
***********************************************/
//void vfbMcpcLedEncode_vfbOcpcLedEncode_example(hvfbOcpcLedEncode t){
//  //TODO
//}


/***********************************************************
* 组件管理实例化
***********************************************************/
/*组件管理类实例
***********************************************/
vfbMcpcLedEncode vfbMcpcLedEncodeA;


/**************************** Copyright(C) pxf ****************************/
