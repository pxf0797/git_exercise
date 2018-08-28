/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcccLedCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :组件cccLedCtrl 管理类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "vfbMcccLedCtrl.h"

/*组件调度id临时配置，组件实际使用时必须在vbfMCfg.h中配置
***********************************************************/
#define cccLedCtrl_id_priority_cfg   0


/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcccLedCtrlInit(void){
    int16 rtv = 0;

    CN(vfbMcccLedCtrl, &vfbMcccLedCtrlA, &vfbOcccLedCtrlA, &vfbIcasSchA);
    if(OPRS(vfbMcccLedCtrlA) != OOPC_NULL){
        vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.id = cccLedCtrl_id_priority_cfg;
        vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.prdTick = (CCCLEDCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.startTick = (CCCLEDCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcccLedCtrlA.vfbIcasSch->addTask(vfbMcccLedCtrlA.vfbIcasSch,
            vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.id, vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.schTask,
            vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.prdTick, vfbMcccLedCtrlA.vfbOcccLedCtrl->schParam.startTick);

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
* 输入: cthis vfbMcccLedCtrl类指针
* 输出: hvfbMcccLedCtrl cthis/OOPC_NULL
***********************************************/
hvfbMcccLedCtrl vfbMcccLedCtrl_init(hvfbMcccLedCtrl cthis, hvfbOcccLedCtrl vfbOcccLedCtrl, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcccLedCtrl = vfbOcccLedCtrl;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*组件管理类构造函数
* 输入: cthis vfbMcccLedCtrl类指针
* 输出: hvfbMcccLedCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbMcccLedCtrl){
    cthis->init = vfbMcccLedCtrl_init;
    //TODO

    return cthis;
}
/*组件管理类析构函数
* 输入: cthis vfbMcccLedCtrl类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcccLedCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出类接口定义
***********************************************************/
/*组件输出类功能函数
***********************************************/
//void vfbMcccLedCtrl_vfbOcccLedCtrl_example(hvfbOcccLedCtrl t){
//  //TODO
//}


/***********************************************************
* 组件管理实例化
***********************************************************/
/*组件管理类实例
***********************************************/
vfbMcccLedCtrl vfbMcccLedCtrlA;


/**************************** Copyright(C) pxf ****************************/
