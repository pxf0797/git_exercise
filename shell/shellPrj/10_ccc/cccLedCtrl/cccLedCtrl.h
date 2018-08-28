/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cccLedCtrl.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :组件cccLedCtrl 输入类、组件类、输出类数据类型声明头文件
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#ifndef CCCLEDCTRL_H_
#define CCCLEDCTRL_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "cccLedCtrlCfg.h"
#include "cccLedCtrlErrCode.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcccLedCtrlInit(void);

/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 cccLedCtrlInit(void);

/*组件输出初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbOcccLedCtrlInit(void);

/*管理组件初始化外部声明
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
extern int16 vfbMcccLedCtrlInit(void);


/***********************************************************
* 组件调度
***********************************************************/
/*组件进行调度
* 输入: 无
* 输出: 无
***********************************************/
void cccLedCtrlSch(void);


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
CL(vfbOcccLedCtrl){
    hvfbOcccLedCtrl self;
    hvfbOcccLedCtrl (*init)(hvfbOcccLedCtrl cthis);

    // 组件调度参数
    schParam schParam;

    // 示例组件输出类功能函数
    //void (*example)(hvfbOcccLedCtrl t);
    //TODO
};

/*组件输出类外部接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//extern void vfbMcccLedCtrl_vfbOcccLedCtrl_example(hvfbOcccLedCtrl t);
//TODO

/*组件输出类实例
***********************************************/
extern vfbOcccLedCtrl vfbOcccLedCtrlA;


/***********************************************************
* 组件类定义
***********************************************************/
/*组件状态机状态
* 有两个状态init/default，状态list不显示，默认给出
* 状态list需根据实际应用进行重写，list修改后相应状态函数得对应修改
***********************************************/
#define SM_CCCLEDCTRL_STA_LIST(_) \
    _(smcccLedCtrl, sta1)\
    _(smcccLedCtrl, sta2)

/*组件状态机定义
***********************************************/
SMDC(smcccLedCtrl, SM_CCCLEDCTRL_STA_LIST)
{
    sta next;
    //TODO

    // 注入组件类
    void *cccLedCtrl;
};


/*组件类声明
***********************************************/
CL(cccLedCtrl){
    hcccLedCtrl self;
    hcccLedCtrl (*init)(hcccLedCtrl cthis, hstaAct smcccLedCtrl, hvfbOcccLedCtrl vfbOcccLedCtrl);

    // 组件运行状态机
    smcccLedCtrlRec smcccLedCtrlRec;
    hstaAct smcccLedCtrl;

    // 组件运行功能函数
    void (*run)(hcccLedCtrl t);
    //void (*example)(hcccLedCtrl t);
    //TODO

    // 注入组件输出类
    INJ(vfbOcccLedCtrl, vfbOcccLedCtrl);
};

/*异步调度功能函数
* 命名方式: 存放类+实际类+实际类功能
* 只有cas类型组件才有此函数
***********************************************/
//void cccLedCtrl_abi_example(void);
//TODO

/*组件类实例
***********************************************/
extern cccLedCtrl cccLedCtrlA;


/***********************************************************
* 组件输入类定义
***********************************************************/
/*组件输入类声明
***********************************************/
CL(vfbIcccLedCtrl){
    hvfbIcccLedCtrl self;
    hvfbIcccLedCtrl (*init)(hvfbIcccLedCtrl cthis, hcccLedCtrl cccLedCtrl);

    //void (*example)(hvfbIcccLedCtrl t);
    //TODO

    // 注入组件类
    INJ(cccLedCtrl, cccLedCtrl);
};

/*组件输入类实例
***********************************************/
extern vfbIcccLedCtrl vfbIcccLedCtrlA;


#endif

/**************************** Copyright(C) pxf ****************************/
