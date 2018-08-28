/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcasLedAServ.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :组件casLedAServ 管理类数据类型声明
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#ifndef VFBMCASLEDASERV_H_
#define VFBMCASLEDASERV_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\06_cas\casLedAServ\casLedAServ.h"
#include "..\vfbMCfg.h"

/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcasLedAServInit(void);


/***********************************************************
* 组件管理类定义
***********************************************************/
/*组件管理类声明
***********************************************/
CL(vfbMcasLedAServ){
    hvfbMcasLedAServ self;
    hvfbMcasLedAServ (*init)(hvfbMcasLedAServ cthis, hvfbOcasLedAServ vfbOcasLedAServ, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcasLedAServ t);
    //TODO

    // 注入组件类
    INJ(vfbOcasLedAServ, vfbOcasLedAServ);
    INJ(vfbIcasSch, vfbIcasSch);
};

/*组件输出类接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//void vfbMcasLedAServ_vfbOcasLedAServ_example(hvfbOcasLedAServ t);

/*组件管理类实例
***********************************************/
extern vfbMcasLedAServ vfbMcasLedAServA;


#endif

/**************************** Copyright(C) pxf ****************************/
