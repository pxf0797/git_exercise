/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : myClass.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/01/12 23:10:48
* Description  : myClass类各功能函数定义源文件
* Others       : 
* History      : 190112 pxf 初次建立
***************************************************************************/

/*头文件包含*/
#include "./myClass.h"

/***********************************************************
* myClass类定义
***********************************************************/
/*名称 : myClass_firsFunc(hmyClass t)
* 输入 : t - myClass类指针
* 输出 : 无
* 其他 : myClass类功能函数
***********************************************/
void myClass_firsFunc(hmyClass t){
    //TODO
}

/*名称 : myClass_secondFunc(hmyClass t)
* 输入 : t - myClass类指针
* 输出 : 无
* 其他 : myClass类功能函数
***********************************************/
void myClass_secondFunc(hmyClass t){
    //TODO
}

/*名称 : hmyClass myClass_init(hmyClass cthis)
* 输入 : cthis - myClass类指针
* 输出 : hmyClass - cthis/OOPC_NULL
* 其他 : myClass类初始化函数
***********************************************/
hmyClass myClass_init(hmyClass cthis){
    // 功能函数配置
    //cthis->firsFunc = myClass_firsFunc;
    //TODO

    // 参数配置
    //TODO

    return cthis;
}

/*名称 : hmyClass myClass_ctor(hmyClass cthis)
* 输入 : cthis - myClass类指针
* 输出 : hmyClass - cthis/OOPC_NULL
* 其他 : myClass类构造函数
***********************************************/
CC(myClass){
    cthis->init = myClass_init;
    cthis->firsFunc = myClass_firsFunc;
    cthis->secondFunc = myClass_secondFunc;
    //TODO

    // 参数配置
    //TODO
    return cthis;
}

/*名称 : hmyClass myClass_dtor(hmyClass cthis)
* 输入 : cthis - myClass类指针
* 输出 : OOPC_RETURN_DATATYPE - OOPC_TRUE/OOPC_FALSE
* 其他 : myClass类析构函数
***********************************************/
CD(myClass){
    return OOPC_TRUE;
}

/**************************** Copyright(C) pxf ****************************/
