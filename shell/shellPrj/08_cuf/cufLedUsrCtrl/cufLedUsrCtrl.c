/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cufLedUsrCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :组件cufLedUsrCtrl 组件类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "cufLedUsrCtrl.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 cufLedUsrCtrlInit(void){
    int16 rtv = 0;

    CN(cufLedUsrCtrl, &cufLedUsrCtrlA, &smcufLedUsrCtrl[0], &vfbOcufLedUsrCtrlA);
    if(OPRS(cufLedUsrCtrlA) != OOPC_NULL){
        rtv = vfbOcufLedUsrCtrlInit();
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
void cufLedUsrCtrlSch(void){
    cufLedUsrCtrlA.run(cufLedUsrCtrlA.self);
}


/***********************************************************
* 组件通用功能函数
***********************************************************/


/***********************************************************
* 组件状态机
***********************************************************/
/*组件状态机定义
***********************************************/
SMDF(smcufLedUsrCtrl, SM_CUFLEDUSRCTRL_STA_LIST);

/*smcufLedUsrCtrl_act_init
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcufLedUsrCtrl_act_init(void *hStaRec){
    hsmcufLedUsrCtrlRec rec = (hsmcufLedUsrCtrlRec)hStaRec;

    rec->cufLedUsrCtrl = (void *)&cufLedUsrCtrlA;
    //TODO

    rec->next = smcufLedUsrCtrl_sta_default;
}

/*smcufLedUsrCtrl_act_sta1
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcufLedUsrCtrl_act_sta1(void *hStaRec){
    hsmcufLedUsrCtrlRec rec = (hsmcufLedUsrCtrlRec)hStaRec;
    //((hcufLedUsrCtrl)(rec->cufLedUsrCtrl))->

    //TODO

    rec->next = smcufLedUsrCtrl_sta_default;
}

/*smcufLedUsrCtrl_act_sta2
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcufLedUsrCtrl_act_sta2(void *hStaRec){
    hsmcufLedUsrCtrlRec rec = (hsmcufLedUsrCtrlRec)hStaRec;
    //((hcufLedUsrCtrl)(rec->cufLedUsrCtrl))->

    //TODO

    rec->next = smcufLedUsrCtrl_sta_default;
}

/*smcufLedUsrCtrl_act_default
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcufLedUsrCtrl_act_default(void *hStaRec){
    hsmcufLedUsrCtrlRec rec = (hsmcufLedUsrCtrlRec)hStaRec;
    //((hcufLedUsrCtrl)(rec->cufLedUsrCtrl))->

    //TODO

    rec->next = smcufLedUsrCtrl_sta_default;
}


/***********************************************************
* 组件定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis cufLedUsrCtrl类指针
* 输出: hcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
hcufLedUsrCtrl cufLedUsrCtrl_init(hcufLedUsrCtrl cthis, hstaAct smcufLedUsrCtrl, hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl){
    cthis->smcufLedUsrCtrl = smcufLedUsrCtrl;
    cthis->vfbOcufLedUsrCtrl = vfbOcufLedUsrCtrl;
    //TODO

    return cthis;
}

/*组件运行函数
* 输入: t cufLedUsrCtrl类指针
* 输出: 无
***********************************************/
void cufLedUsrCtrl_run(hcufLedUsrCtrl t){
    SMRE(t->smcufLedUsrCtrl, t->smcufLedUsrCtrlRec);
}

/*组件类构造函数
* 输入: cthis cufLedUsrCtrl类指针
* 输出: hcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
CC(cufLedUsrCtrl){
    cthis->init = cufLedUsrCtrl_init;
    cthis->run = cufLedUsrCtrl_run;
    //TODO

    cthis->smcufLedUsrCtrlRec.next = smcufLedUsrCtrl_sta_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis cufLedUsrCtrl类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(cufLedUsrCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* 组件异步调度功能函数
***********************************************************/
/*异步调度功能函数
***********************************************/
//void cufLedUsrCtrl_abi_example(void){
//  //TODO
//}


/***********************************************************
* 组件实例化
***********************************************************/
/*组件类实例
***********************************************/
cufLedUsrCtrl cufLedUsrCtrlA;


/**************************** Copyright(C) pxf ****************************/
