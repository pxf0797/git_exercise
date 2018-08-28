/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcufLedUsrCtrl.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :组件cufLedUsrCtrl 管理类数据类型声明
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#ifndef VFBMCUFLEDUSRCTRL_H_
#define VFBMCUFLEDUSRCTRL_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\08_cuf\cufLedUsrCtrl\cufLedUsrCtrl.h"
#include "..\vfbMCfg.h"

/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcufLedUsrCtrlInit(void);


/***********************************************************
* 组件管理类定义
***********************************************************/
/*组件管理类声明
***********************************************/
CL(vfbMcufLedUsrCtrl){
    hvfbMcufLedUsrCtrl self;
    hvfbMcufLedUsrCtrl (*init)(hvfbMcufLedUsrCtrl cthis, hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcufLedUsrCtrl t);
    //TODO

    // 注入组件类
    INJ(vfbOcufLedUsrCtrl, vfbOcufLedUsrCtrl);
    INJ(vfbIcasSch, vfbIcasSch);
};

/*组件输出类接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//void vfbMcufLedUsrCtrl_vfbOcufLedUsrCtrl_example(hvfbOcufLedUsrCtrl t);

/*组件管理类实例
***********************************************/
extern vfbMcufLedUsrCtrl vfbMcufLedUsrCtrlA;


#endif

/**************************** Copyright(C) pxf ****************************/
