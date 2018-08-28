/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cccLedCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :组件cccLedCtrl 组件类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "cccLedCtrl.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 cccLedCtrlInit(void){
    int16 rtv = 0;

    CN(cccLedCtrl, &cccLedCtrlA, &smcccLedCtrl[0], &vfbOcccLedCtrlA);
    if(OPRS(cccLedCtrlA) != OOPC_NULL){
        rtv = vfbOcccLedCtrlInit();
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
void cccLedCtrlSch(void){
    cccLedCtrlA.run(cccLedCtrlA.self);
}


/***********************************************************
* 组件通用功能函数
***********************************************************/


/***********************************************************
* 组件状态机
***********************************************************/
/*组件状态机定义
***********************************************/
SMDF(smcccLedCtrl, SM_CCCLEDCTRL_STA_LIST);

/*smcccLedCtrl_act_init
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcccLedCtrl_act_init(void *hStaRec){
    hsmcccLedCtrlRec rec = (hsmcccLedCtrlRec)hStaRec;

    rec->cccLedCtrl = (void *)&cccLedCtrlA;
    //TODO

    rec->next = smcccLedCtrl_sta_default;
}

/*smcccLedCtrl_act_sta1
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcccLedCtrl_act_sta1(void *hStaRec){
    hsmcccLedCtrlRec rec = (hsmcccLedCtrlRec)hStaRec;
    //((hcccLedCtrl)(rec->cccLedCtrl))->

    //TODO

    rec->next = smcccLedCtrl_sta_default;
}

/*smcccLedCtrl_act_sta2
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcccLedCtrl_act_sta2(void *hStaRec){
    hsmcccLedCtrlRec rec = (hsmcccLedCtrlRec)hStaRec;
    //((hcccLedCtrl)(rec->cccLedCtrl))->

    //TODO

    rec->next = smcccLedCtrl_sta_default;
}

/*smcccLedCtrl_act_default
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcccLedCtrl_act_default(void *hStaRec){
    hsmcccLedCtrlRec rec = (hsmcccLedCtrlRec)hStaRec;
    //((hcccLedCtrl)(rec->cccLedCtrl))->

    //TODO

    rec->next = smcccLedCtrl_sta_default;
}


/***********************************************************
* 组件定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis cccLedCtrl类指针
* 输出: hcccLedCtrl cthis/OOPC_NULL
***********************************************/
hcccLedCtrl cccLedCtrl_init(hcccLedCtrl cthis, hstaAct smcccLedCtrl, hvfbOcccLedCtrl vfbOcccLedCtrl){
    cthis->smcccLedCtrl = smcccLedCtrl;
    cthis->vfbOcccLedCtrl = vfbOcccLedCtrl;
    //TODO

    return cthis;
}

/*组件运行函数
* 输入: t cccLedCtrl类指针
* 输出: 无
***********************************************/
void cccLedCtrl_run(hcccLedCtrl t){
    SMRE(t->smcccLedCtrl, t->smcccLedCtrlRec);
}

/*组件类构造函数
* 输入: cthis cccLedCtrl类指针
* 输出: hcccLedCtrl cthis/OOPC_NULL
***********************************************/
CC(cccLedCtrl){
    cthis->init = cccLedCtrl_init;
    cthis->run = cccLedCtrl_run;
    //TODO

    cthis->smcccLedCtrlRec.next = smcccLedCtrl_sta_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis cccLedCtrl类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(cccLedCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* 组件异步调度功能函数
***********************************************************/
/*异步调度功能函数
***********************************************/
//void cccLedCtrl_abi_example(void){
//  //TODO
//}


/***********************************************************
* 组件实例化
***********************************************************/
/*组件类实例
***********************************************/
cccLedCtrl cccLedCtrlA;


/**************************** Copyright(C) pxf ****************************/
