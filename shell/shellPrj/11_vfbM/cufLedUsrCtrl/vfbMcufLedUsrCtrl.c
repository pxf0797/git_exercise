/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcufLedUsrCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :组件cufLedUsrCtrl 管理类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "vfbMcufLedUsrCtrl.h"

/*组件调度id临时配置，组件实际使用时必须在vbfMCfg.h中配置
***********************************************************/
#define cufLedUsrCtrl_id_priority_cfg   0


/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcufLedUsrCtrlInit(void){
    int16 rtv = 0;

    CN(vfbMcufLedUsrCtrl, &vfbMcufLedUsrCtrlA, &vfbOcufLedUsrCtrlA, &vfbIcasSchA);
    if(OPRS(vfbMcufLedUsrCtrlA) != OOPC_NULL){
        vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.id = cufLedUsrCtrl_id_priority_cfg;
        vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.prdTick = (CUFLEDUSRCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.startTick = (CUFLEDUSRCTRL_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcufLedUsrCtrlA.vfbIcasSch->addTask(vfbMcufLedUsrCtrlA.vfbIcasSch,
            vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.id, vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.schTask,
            vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.prdTick, vfbMcufLedUsrCtrlA.vfbOcufLedUsrCtrl->schParam.startTick);

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
* 输入: cthis vfbMcufLedUsrCtrl类指针
* 输出: hvfbMcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
hvfbMcufLedUsrCtrl vfbMcufLedUsrCtrl_init(hvfbMcufLedUsrCtrl cthis, hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcufLedUsrCtrl = vfbOcufLedUsrCtrl;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*组件管理类构造函数
* 输入: cthis vfbMcufLedUsrCtrl类指针
* 输出: hvfbMcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbMcufLedUsrCtrl){
    cthis->init = vfbMcufLedUsrCtrl_init;
    //TODO

    return cthis;
}
/*组件管理类析构函数
* 输入: cthis vfbMcufLedUsrCtrl类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcufLedUsrCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出类接口定义
***********************************************************/
/*组件输出类功能函数
***********************************************/
//void vfbMcufLedUsrCtrl_vfbOcufLedUsrCtrl_example(hvfbOcufLedUsrCtrl t){
//  //TODO
//}


/***********************************************************
* 组件管理实例化
***********************************************************/
/*组件管理类实例
***********************************************/
vfbMcufLedUsrCtrl vfbMcufLedUsrCtrlA;


/**************************** Copyright(C) pxf ****************************/
