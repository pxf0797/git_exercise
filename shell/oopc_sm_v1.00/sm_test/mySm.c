/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : mySm.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/01/12 23:11:27
* Description  : 状态机mySm定义及各状态动作定义源文件
* Others       : 
* History      : 190112 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./mySm.h"

/*状态机mySm定义
* 配置状态机相关处理状态
***********************************************/
SMDF(mySm, MYSM_LIST);

/*名称 : mySm_act_init()
* 输入 : mySmRec - 状态记录参数指针
* 输出 : 无
* 其他 : 初始状态操作函数
***********************************************/
void mySm_act_init(void *mySmRec){
    hmySmRec hRec = (hmySmRec)mySmRec;

    // TODO

    hRec->next = mySm_sta_default;
    hRec->last = mySm_sta_init;
}

/*名称 : mySm_act_default()
* 输入 : mySmRec - 状态记录参数指针
* 输出 : 无
* 其他 : 默认状态操作函数
***********************************************/
void mySm_act_default(void *mySmRec){
    hmySmRec hRec = (hmySmRec)mySmRec;

    // TODO

    hRec->next = mySm_sta_default;
    hRec->last = mySm_sta_default;
}

/*名称 : mySm_act_firsState()
* 输入 : mySmRec - 状态记录参数指针
* 输出 : 无
* 其他 : 状态firsState操作函数
***********************************************/
void mySm_act_firsState(void *mySmRec){
    hmySmRec hRec = (hmySmRec)mySmRec;

    // TODO

    hRec->next = mySm_sta_default;
    hRec->last = mySm_sta_firsState;
}

/*名称 : mySm_act_secondState()
* 输入 : mySmRec - 状态记录参数指针
* 输出 : 无
* 其他 : 状态secondState操作函数
***********************************************/
void mySm_act_secondState(void *mySmRec){
    hmySmRec hRec = (hmySmRec)mySmRec;

    // TODO

    hRec->next = mySm_sta_default;
    hRec->last = mySm_sta_secondState;
}

/**************************** Copyright(C) pxf ****************************/
