/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcpcLedEncode.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :组件cpcLedEncode 管理类数据类型声明
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#ifndef VFBMCPCLEDENCODE_H_
#define VFBMCPCLEDENCODE_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\09_cpc\cpcLedEncode\cpcLedEncode.h"
#include "..\vfbMCfg.h"

/***********************************************************
* 组件管理初始化
***********************************************************/
/*组件管理初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbMcpcLedEncodeInit(void);


/***********************************************************
* 组件管理类定义
***********************************************************/
/*组件管理类声明
***********************************************/
CL(vfbMcpcLedEncode){
    hvfbMcpcLedEncode self;
    hvfbMcpcLedEncode (*init)(hvfbMcpcLedEncode cthis, hvfbOcpcLedEncode vfbOcpcLedEncode, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcpcLedEncode t);
    //TODO

    // 注入组件类
    INJ(vfbOcpcLedEncode, vfbOcpcLedEncode);
    INJ(vfbIcasSch, vfbIcasSch);
};

/*组件输出类接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//void vfbMcpcLedEncode_vfbOcpcLedEncode_example(hvfbOcpcLedEncode t);

/*组件管理类实例
***********************************************/
extern vfbMcpcLedEncode vfbMcpcLedEncodeA;


#endif

/**************************** Copyright(C) pxf ****************************/
