/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcasSch.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/27 22:43:29
* @brief        :组件casSch 管理类数据类型声明
* @others       :
* @history      :180827 pxf 初次建立
***************************************************************************/

#ifndef VFBMCASSCH_H_
#define VFBMCASSCH_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\vfbMCfg.h"

/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcasSchInit(void);


/***********************************************************
* 组件管理类定义
***********************************************************/
/*组件管理类声明
***********************************************/
CL(vfbMcasSch){
    hvfbMcasSch self;
    hvfbMcasSch (*init)(hvfbMcasSch cthis, hvfbOcasSch vfbOcasSch, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcasSch t);
    //TODO

    // 注入组件类
    INJ(vfbOcasSch, vfbOcasSch);
    INJ(vfbIcasSch, vfbIcasSch);
}

/*组件输出类接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//void vfbMcasSch_vfbOcasSch_example(hvfbOcasSch t);

/*组件管理类实例
***********************************************/
extern vfbMcasSch vfbMcasSchA;


#endif

/**************************** Copyright(C) pxf ****************************/
