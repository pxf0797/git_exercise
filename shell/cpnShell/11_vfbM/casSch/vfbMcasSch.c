/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcasSch.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/27 22:43:29
* @brief        :组件casSch 管理类定义
* @others       :
* @history      :180827 pxf 初次建立
***************************************************************************/

#include "casSch.h"

/*组件调度id临时配置，组件实际使用时必须在vbfMCfg.h中配置
***********************************************************/
#define casSch_id_priority_cfg   0


/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcasSchInit(void){
    int16 rtv = 0;

    CN(vfbMcasSch, &vfbMcasSchA, &vfbOcasSchA, &vfbIcasSchA);
    if(OPRS(vfbMcasSchA) != OOPC_NULL){
        vfbMcasSchA.vfbOcasSch->schParam.id = casSch_id_priority_cfg;
        vfbMcasSchA.vfbOcasSch->schParam.prdTick = (CASSCH_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcasSchA.vfbOcasSch->schParam.startTick = (CASSCH_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcasSchA.vfbIcasSchA->addTask(vfbIcasSchA.self,
            vfbMcasSchA.vfbOcasSch->schParam.id, vfbMcasSchA.vfbOcasSch->schParam.schTask,
            vfbMcasSchA.vfbOcasSch->schParam.prdTick, vfbMcasSchA.vfbOcasSch->schParam.startTick)

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
* 输入: cthis vfbMcasSch类指针
* 输出: hvfbMcasSch cthis/OOPC_NULL
***********************************************/
hvfbMcasSch vfbMcasSch_init(hvfbMcasSch cthis, hvfbOcasSch vfbOcasSch, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcasSch = vfbOcasSch;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*组件管理类构造函数
* 输入: cthis vfbMcasSch类指针
* 输出: hvfbMcasSch cthis/OOPC_NULL
***********************************************/
CC(vfbMcasSch){
    cthis->init = vfbMcasSch_init;
    //TODO

    return cthis;
}
/*组件管理类析构函数
* 输入: cthis vfbMcasSch类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcasSch){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出类接口定义
***********************************************************/
/*组件输出类功能函数
***********************************************/
//void vfbMcasSch_vfbOcasSch_example(hvfbOcasSch t){
//  //TODO
//}


/***********************************************************
* 组件管理实例化
***********************************************************/
/*组件管理类实例
***********************************************/
vfbMcasSch vfbMcasSchA;


/**************************** Copyright(C) pxf ****************************/
