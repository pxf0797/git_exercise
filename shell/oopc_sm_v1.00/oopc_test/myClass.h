/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : myClass.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/01/12 23:10:48
* Description  : myClass类及接口声明头文件
* Others       : 
* History      : 190112 pxf 初次建立
***************************************************************************/

#ifndef MYCLASS_H_
#define MYCLASS_H_

/*头文件包含*/
#include "../oopc_v1.02/oopc.h"

/***********************************************************
* 接口定义
***********************************************************/
/*接口声明
***********************************************/
//INF(get){
//  uint16(*get)(void);
//};
//TODO

/***********************************************************
* myClass类定义
***********************************************************/
/*myClass类声明
***********************************************/
CL(myClass){
    hmyClass self;
    hmyClass (*init)(hmyClass cthis);

    // myClass类参数
    //TODO

    // myClass类功能函数
    void (*firsFunc)(hmyClass t);
    void (*secondFunc)(hmyClass t);
    //TODO
};

#endif /*MYCLASS_H_*/

/**************************** Copyright(C) pxf ****************************/
