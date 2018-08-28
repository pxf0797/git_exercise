/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcccLedCtrl.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :组件cccLedCtrl 管理类数据类型声明
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#ifndef VFBMCCCLEDCTRL_H_
#define VFBMCCCLEDCTRL_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\10_ccc\cccLedCtrl\cccLedCtrl.h"
#include "..\vfbMCfg.h"

/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcccLedCtrlInit(void);


/***********************************************************
* 组件管理类定义
***********************************************************/
/*组件管理类声明
***********************************************/
CL(vfbMcccLedCtrl){
    hvfbMcccLedCtrl self;
    hvfbMcccLedCtrl (*init)(hvfbMcccLedCtrl cthis, hvfbOcccLedCtrl vfbOcccLedCtrl, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcccLedCtrl t);
    //TODO

    // 注入组件类
    INJ(vfbOcccLedCtrl, vfbOcccLedCtrl);
    INJ(vfbIcasSch, vfbIcasSch);
};

/*组件输出类接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//void vfbMcccLedCtrl_vfbOcccLedCtrl_example(hvfbOcccLedCtrl t);

/*组件管理类实例
***********************************************/
extern vfbMcccLedCtrl vfbMcccLedCtrlA;


#endif

/**************************** Copyright(C) pxf ****************************/
