/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cufLedUsrCtrl.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :组件cufLedUsrCtrl 输入类、组件类、输出类数据类型声明头文件
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#ifndef CUFLEDUSRCTRL_H_
#define CUFLEDUSRCTRL_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "cufLedUsrCtrlCfg.h"
#include "cufLedUsrCtrlErrCode.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcufLedUsrCtrlInit(void);

/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 cufLedUsrCtrlInit(void);

/*组件输出初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbOcufLedUsrCtrlInit(void);

/*管理组件初始化外部声明
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
extern int16 vfbMcufLedUsrCtrlInit(void);


/***********************************************************
* 组件调度
***********************************************************/
/*组件进行调度
* 输入: 无
* 输出: 无
***********************************************/
void cufLedUsrCtrlSch(void);


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
CL(vfbOcufLedUsrCtrl){
    hvfbOcufLedUsrCtrl self;
    hvfbOcufLedUsrCtrl (*init)(hvfbOcufLedUsrCtrl cthis);

    // 组件调度参数
    schParam schParam;

    // 示例组件输出类功能函数
    //void (*example)(hvfbOcufLedUsrCtrl t);
    //TODO
};

/*组件输出类外部接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//extern void vfbMcufLedUsrCtrl_vfbOcufLedUsrCtrl_example(hvfbOcufLedUsrCtrl t);
//TODO

/*组件输出类实例
***********************************************/
extern vfbOcufLedUsrCtrl vfbOcufLedUsrCtrlA;


/***********************************************************
* 组件类定义
***********************************************************/
/*组件状态机状态
* 有两个状态init/default，状态list不显示，默认给出
* 状态list需根据实际应用进行重写，list修改后相应状态函数得对应修改
***********************************************/
#define SM_CUFLEDUSRCTRL_STA_LIST(_) \
    _(smcufLedUsrCtrl, sta1)\
    _(smcufLedUsrCtrl, sta2)

/*组件状态机定义
***********************************************/
SMDC(smcufLedUsrCtrl, SM_CUFLEDUSRCTRL_STA_LIST)
{
    sta next;
    //TODO

    // 注入组件类
    void *cufLedUsrCtrl;
};


/*组件类声明
***********************************************/
CL(cufLedUsrCtrl){
    hcufLedUsrCtrl self;
    hcufLedUsrCtrl (*init)(hcufLedUsrCtrl cthis, hstaAct smcufLedUsrCtrl, hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl);

    // 组件运行状态机
    smcufLedUsrCtrlRec smcufLedUsrCtrlRec;
    hstaAct smcufLedUsrCtrl;

    // 组件运行功能函数
    void (*run)(hcufLedUsrCtrl t);
    //void (*example)(hcufLedUsrCtrl t);
    //TODO

    // 注入组件输出类
    INJ(vfbOcufLedUsrCtrl, vfbOcufLedUsrCtrl);
};

/*异步调度功能函数
* 命名方式: 存放类+实际类+实际类功能
* 只有cas类型组件才有此函数
***********************************************/
//void cufLedUsrCtrl_abi_example(void);
//TODO

/*组件类实例
***********************************************/
extern cufLedUsrCtrl cufLedUsrCtrlA;


/***********************************************************
* 组件输入类定义
***********************************************************/
/*组件输入类声明
***********************************************/
CL(vfbIcufLedUsrCtrl){
    hvfbIcufLedUsrCtrl self;
    hvfbIcufLedUsrCtrl (*init)(hvfbIcufLedUsrCtrl cthis, hcufLedUsrCtrl cufLedUsrCtrl);

    //void (*example)(hvfbIcufLedUsrCtrl t);
    //TODO

    // 注入组件类
    INJ(cufLedUsrCtrl, cufLedUsrCtrl);
};

/*组件输入类实例
***********************************************/
extern vfbIcufLedUsrCtrl vfbIcufLedUsrCtrlA;


#endif

/**************************** Copyright(C) pxf ****************************/
