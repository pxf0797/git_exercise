/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcasSch.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/27 22:43:29
* @brief        :组件casSch 输入类定义
* @others       :
* @history      :180827 pxf 初次建立
***************************************************************************/

#include "casSch.h"

/***********************************************************
* 组件输入初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcasSchInit(void){
    int16 rtv = 0;

    CN(vfbIcasSch, &vfbIcasSchA, &casSchA);
    if(OPRS(vfbIcasSchA) != OOPC_NULL){
        rtv = casSchInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件输入定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis vfbIcasSch类指针
* 输出: hvfbIcasSch cthis/OOPC_NULL
***********************************************/
hvfbIcasSch vfbIcasSch_init(hvfbIcasSch cthis, hcasSch casSch){
    cthis->casSch = casSch;
    //TODO

    return cthis;
}

/*组件类构造函数
* 输入: cthis vfbIcasSch类指针
* 输出: hvfbIcasSch cthis/OOPC_NULL
***********************************************/
CC(vfbIcasSch){
    cthis->init = vfbIcasSch_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis vfbIcasSch类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcasSch){
    return OOPC_TRUE;
}


/***********************************************************
* 组件输入实例化
***********************************************************/
/*组件输入类实例
***********************************************/
vfbIcasSch vfbIcasSchA;


/**************************** Copyright(C) pxf ****************************/
