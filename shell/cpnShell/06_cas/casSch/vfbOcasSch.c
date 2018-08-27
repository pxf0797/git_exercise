/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcasSch.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/27 22:43:29
* @brief        :组件casSch 输出类定义
* @others       :
* @history      :180827 pxf 初次建立
***************************************************************************/

#include "casSch.h"

/***********************************************************
* 组件输出初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbOcasSchInit(void){
    int16 rtv = 0;

    CNNP(vfbOcasSch, &vfbOcasSchA);
    if(OPRS(vfbOcasSchA) != OOPC_NULL){
        rtv = vfbMcasSchInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输出定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbOcasSch类指针
* 输出: hvfbOcasSch cthis/OOPC_NULL
***********************************************/
hvfbOcasSch vfbOcasSch_init(hvfbOcasSch cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = casSchSch;
    cthis->schParam.startTick = (CASSCH_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CASSCH_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbOcasSch类指针
* 输出: hvfbOcasSch cthis/OOPC_NULL
***********************************************/
CC(vfbOcasSch){
    cthis->init = vfbOcasSch_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbOcasSch类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcasSch){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输出实例化
***********************************************************/
/*组件输出类实例
***********************************************/
vfbOcasSch vfbOcasSchA;


/**************************** Copyright(C) pxf ****************************/
