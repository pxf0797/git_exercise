/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :csLed.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/26 21:32:19
* @brief        :
* @others       :
* @history      :180826 pxf 初次建立
***************************************************************************/

#include "csLed.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 csLedInit(void){
    int16 rtv = 0;

    CN(csLed, &csLedA, &vfbOcsLedA, &smcsLed[0]);
    if(OPRS(csLedA) != OOPC_NULL){
        rtv = vfbOcsLedInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* 组件调度
***********************************************************/
/*组件进行调度
* 输入: 无
* 输出: 无
***********************************************/
void csLedSch(void){
    csLedA.run(csLedA.self);
}


/***********************************************************
* 组件通用功能函数
***********************************************************/


/***********************************************************
* 组件状态机
***********************************************************/
/*组件状态机定义
***********************************************/
SMDC(smcsLed, SM_CSLED_STA_LIST);

/*smcsLed_act_init
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcsLed_act_init(void *hStaRec){
    hsmcsLedRec rec = (hsmcsLedRec)hStaRec;

    rec->csLed = (void *)&csLedA;
    //TODO

    rec->next = smcsLed_sta_sta1;
}

/*smcsLed_act_sta1
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcsLed_act_sta1(void *hStaRec){
    hsmcsLedRec rec = (hsmcsLedRec)hStaRec;
    //TODO
}

/*smcsLed_act_sta2
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcsLed_act_sta2(void *hStaRec){
    hsmcsLedRec rec = (hsmcsLedRec)hStaRec;
    //TODO
}

/*smcsLed_act_default
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcsLed_act_default(void *hStaRec){
    hsmcsLedRec rec = (hsmcsLedRec)hStaRec;
    //TODO
}


/***********************************************************
* 组件定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis csLed类指针
* 输出: hcsLed cthis/OOPC_NULL
***********************************************/
hcsLed csLed_init(hcsLed cthis, hvfbOcsLed vfbOcsLed, hstaAct smcsLed){
    cthis->vfbOcsLed = vfbOcsLed;
    cthis->smcsLed = smcsLed;
    //TODO

    return cthis;
}

/*组件运行函数
* 输入: t csLed类指针
* 输出: 无
***********************************************/
hcsLed csLed_run(hcsLed t){
    SMRE(t->smcsLed, t->smcsLedRec);
}

/*组件类构造函数
* 输入: cthis csLed类指针
* 输出: hcsLed cthis/OOPC_NULL
***********************************************/
CC(csLed){
    cthis->init = csLed_init;
    cthis->run = csLed_run;
    //TODO

    cthis->smcsLedRec.next = smcsLed_sta_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis csLed类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(csLed){
    return OOPC_TRUE;
}


/***********************************************************
* 组件实例化
***********************************************************/
/*组件类实例
***********************************************/
csLed csLedA;


/**************************** Copyright(C) pxf ****************************/
