/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : mySm.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/01/12 23:11:27
* Description  : 状态机mySm声明及状态机使用示例头文件
* Others       : 
* History      : 190112 pxf 初次建立
***************************************************************************/

#ifndef MYSM_H_
#define MYSM_H_

/*头文件包含*/
#include "../sm_v1.01/sm.h"

/*状态机mySm使用示例：
* 当前状态机已在SMDF中定义出实体mySm，需要做的只是让其运行起来
* 状态机运行方式有两种直接给时钟驱动的SMR和使用自定义记录状态后进驱动的SMRE
***********************************************
* SMR方式
***********************************************
void test(void){
    while(1){SMR(mySm);};
}
***********************************************
* SMRE方式
***********************************************
void test2(void){
    static mySmRec mySmRunRec = {mySm_sta_init};
    while(1){SMRE(mySm, mySmRunRec);};
}
***********************************************/


/*状态机mySm状态序列定义
* 注意其中mySm_init,mySm_default未在此定义，默认会给出
***********************************************/
#define MYSM_LIST(_)        \
    _(mySm, firsState)      \
    _(mySm, secondState)


/*状态机mySm声明
* 已给出状态记录next,及上一状态last，其他参数需自行添加
***********************************************/
SMDC(mySm, MYSM_LIST){
    sta next; // 运行状态记录
    sta last; // 上一状态记录
    // TODO
};

#endif /*MYSM_H_*/

/**************************** Copyright(C) pxf ****************************/
