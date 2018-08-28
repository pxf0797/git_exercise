/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :casLedAServ.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :组件casLedAServ 输入类、组件类、输出类数据类型声明头文件
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#ifndef CASLEDASERV_H_
#define CASLEDASERV_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "casLedAServCfg.h"
#include "casLedAServErrCode.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件输入初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbIcasLedAServInit(void);

/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 casLedAServInit(void);

/*组件输出初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 vfbOcasLedAServInit(void);

/*管理组件初始化外部声明
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
extern int16 vfbMcasLedAServInit(void);


/***********************************************************
* 组件调度
***********************************************************/
/*组件进行调度
* 输入: 无
* 输出: 无
***********************************************/
void casLedAServSch(void);


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
CL(vfbOcasLedAServ){
    hvfbOcasLedAServ self;
    hvfbOcasLedAServ (*init)(hvfbOcasLedAServ cthis);

    // 组件调度参数
    schParam schParam;

    // 示例组件输出类功能函数
    //void (*example)(hvfbOcasLedAServ t);
    //TODO
};

/*组件输出类外部接口声明
* 命名方式: 存放类+实际类+实际类功能
***********************************************/
//extern void vfbMcasLedAServ_vfbOcasLedAServ_example(hvfbOcasLedAServ t);
//TODO

/*组件输出类实例
***********************************************/
extern vfbOcasLedAServ vfbOcasLedAServA;


/***********************************************************
* 组件类定义
***********************************************************/
/*组件状态机状态
* 有两个状态init/default，状态list不显示，默认给出
* 状态list需根据实际应用进行重写，list修改后相应状态函数得对应修改
***********************************************/
#define SM_CASLEDASERV_STA_LIST(_) \
    _(smcasLedAServ, sta1)\
    _(smcasLedAServ, sta2)

/*组件状态机定义
***********************************************/
SMDC(smcasLedAServ, SM_CASLEDASERV_STA_LIST)
{
    sta next;
    //TODO

    // 注入组件类
    void *casLedAServ;
};


/*组件类声明
***********************************************/
CL(casLedAServ){
    hcasLedAServ self;
    hcasLedAServ (*init)(hcasLedAServ cthis, hstaAct smcasLedAServ, hvfbOcasLedAServ vfbOcasLedAServ);

    // 组件运行状态机
    smcasLedAServRec smcasLedAServRec;
    hstaAct smcasLedAServ;

    // 组件运行功能函数
    void (*run)(hcasLedAServ t);
    //void (*example)(hcasLedAServ t);
    //TODO

    // 注入组件输出类
    INJ(vfbOcasLedAServ, vfbOcasLedAServ);
};

/*异步调度功能函数
* 命名方式: 存放类+实际类+实际类功能
* 只有cas类型组件才有此函数
***********************************************/
//void casLedAServ_abi_example(void);
//TODO

/*组件类实例
***********************************************/
extern casLedAServ casLedAServA;


/***********************************************************
* 组件输入类定义
***********************************************************/
/*组件输入类声明
***********************************************/
CL(vfbIcasLedAServ){
    hvfbIcasLedAServ self;
    hvfbIcasLedAServ (*init)(hvfbIcasLedAServ cthis, hcasLedAServ casLedAServ);

    //void (*example)(hvfbIcasLedAServ t);
    //TODO

    // 注入组件类
    INJ(casLedAServ, casLedAServ);
};

/*组件输入类实例
***********************************************/
extern vfbIcasLedAServ vfbIcasLedAServA;


#endif

/**************************** Copyright(C) pxf ****************************/
