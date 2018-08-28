/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcsLedServ.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:07
* @brief        :组件csLedServ 管理类数据类型声明
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#ifndef VFBMCSLEDSERV_H_
#define VFBMCSLEDSERV_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\07_cs\csLedServ\csLedServ.h"
#include "..\vfbMCfg.h"

/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcsLedServInit(void);


/***********************************************************
* 组件管理类定义
***********************************************************/
/*组件管理类声明
***********************************************/
CL(vfbMcsLedServ){
    hvfbMcsLedServ self;
    hvfbMcsLedServ (*init)(hvfbMcsLedServ cthis, hvfbOcsLedServ vfbOcsLedServ, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcsLedServ t);
    //TODO

    // 注入组件类
    INJ(vfbOcsLedServ, vfbOcsLedServ);
    INJ(vfbIcasSch, vfbIcasSch);
};

/*组件输出类接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//void vfbMcsLedServ_vfbOcsLedServ_example(hvfbOcsLedServ t);

/*组件管理类实例
***********************************************/
extern vfbMcsLedServ vfbMcsLedServA;


#endif

/**************************** Copyright(C) pxf ****************************/
