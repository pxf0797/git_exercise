/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cpcLedEncode.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :组件cpcLedEncode 输入类、组件类、输出类数据类型声明头文件
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#ifndef CPCLEDENCODE_H_
#define CPCLEDENCODE_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "cpcLedEncodeCfg.h"
#include "cpcLedEncodeErrCode.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcpcLedEncodeInit(void);

/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 cpcLedEncodeInit(void);

/*组件输出初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbOcpcLedEncodeInit(void);

/*管理组件初始化外部声明
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
extern int16 vfbMcpcLedEncodeInit(void);


/***********************************************************
* 组件调度
***********************************************************/
/*组件进行调度
* 输入: 无
* 输出: 无
***********************************************/
void cpcLedEncodeSch(void);


/***********************************************************
* 组件输入类通用数据类型
***********************************************************/


/***********************************************************
* 组件输出类通用数据类型
***********************************************************/


/***********************************************************
* 组件输出类定义
***********************************************************/
/*组件输出类声明
***********************************************/
CL(vfbOcpcLedEncode){
    hvfbOcpcLedEncode self;
    hvfbOcpcLedEncode (*init)(hvfbOcpcLedEncode cthis);

    // 组件调度参数
    schParam schParam;

    // 示例组件输出类功能函数
    //void (*example)(hvfbOcpcLedEncode t);
    //TODO
};

/*组件输出类外部接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//extern void vfbMcpcLedEncode_vfbOcpcLedEncode_example(hvfbOcpcLedEncode t);
//TODO

/*组件输出类实例
***********************************************/
extern vfbOcpcLedEncode vfbOcpcLedEncodeA;


/***********************************************************
* 组件类定义
***********************************************************/
/*组件状态机状态
* 有两个状态init/default，状态list不显示，默认给出
* 状态list需根据实际应用进行重写，list修改后相应状态函数得对应修改
***********************************************/
#define SM_CPCLEDENCODE_STA_LIST(_) \
    _(smcpcLedEncode, sta1)\
    _(smcpcLedEncode, sta2)

/*组件状态机定义
***********************************************/
SMDC(smcpcLedEncode, SM_CPCLEDENCODE_STA_LIST)
{
    sta next;
    //TODO

    // 注入组件类
    void *cpcLedEncode;
};


/*组件类声明
***********************************************/
CL(cpcLedEncode){
    hcpcLedEncode self;
    hcpcLedEncode (*init)(hcpcLedEncode cthis, hstaAct smcpcLedEncode, hvfbOcpcLedEncode vfbOcpcLedEncode);

    // 组件运行状态机
    smcpcLedEncodeRec smcpcLedEncodeRec;
    hstaAct smcpcLedEncode;

    // 组件运行功能函数
    void (*run)(hcpcLedEncode t);
    //void (*example)(hcpcLedEncode t);
    //TODO

    // 注入组件输出类
    INJ(vfbOcpcLedEncode, vfbOcpcLedEncode);
};

/*异步调度功能函数
* 命名方式: 存放类+实际类+实际类功能
* 只有cas类型组件才有此函数
***********************************************/
//void cpcLedEncode_abi_example(void);
//TODO

/*组件类实例
***********************************************/
extern cpcLedEncode cpcLedEncodeA;


/***********************************************************
* 组件输入类定义
***********************************************************/
/*组件输入类声明
***********************************************/
CL(vfbIcpcLedEncode){
    hvfbIcpcLedEncode self;
    hvfbIcpcLedEncode (*init)(hvfbIcpcLedEncode cthis, hcpcLedEncode cpcLedEncode);

    //void (*example)(hvfbIcpcLedEncode t);
    //TODO

    // 注入组件类
    INJ(cpcLedEncode, cpcLedEncode);
};

/*组件输入类实例
***********************************************/
extern vfbIcpcLedEncode vfbIcpcLedEncodeA;


#endif

/**************************** Copyright(C) pxf ****************************/
