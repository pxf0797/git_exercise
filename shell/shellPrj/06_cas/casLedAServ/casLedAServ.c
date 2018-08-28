/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :casLedAServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :组件casLedAServ 组件类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "casLedAServ.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 casLedAServInit(void){
    int16 rtv = 0;

    CN(casLedAServ, &casLedAServA, &smcasLedAServ[0], &vfbOcasLedAServA);
    if(OPRS(casLedAServA) != OOPC_NULL){
        rtv = vfbOcasLedAServInit();
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
void casLedAServSch(void){
    casLedAServA.run(casLedAServA.self);
}


/***********************************************************
* 组件通用功能函数
***********************************************************/


/***********************************************************
* 组件状态机
***********************************************************/
/*组件状态机定义
***********************************************/
SMDF(smcasLedAServ, SM_CASLEDASERV_STA_LIST);

/*smcasLedAServ_act_init
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcasLedAServ_act_init(void *hStaRec){
    hsmcasLedAServRec rec = (hsmcasLedAServRec)hStaRec;

    rec->casLedAServ = (void *)&casLedAServA;
    //TODO

    rec->next = smcasLedAServ_sta_default;
}

/*smcasLedAServ_act_sta1
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcasLedAServ_act_sta1(void *hStaRec){
    hsmcasLedAServRec rec = (hsmcasLedAServRec)hStaRec;
    //((hcasLedAServ)(rec->casLedAServ))->

    //TODO

    rec->next = smcasLedAServ_sta_default;
}

/*smcasLedAServ_act_sta2
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcasLedAServ_act_sta2(void *hStaRec){
    hsmcasLedAServRec rec = (hsmcasLedAServRec)hStaRec;
    //((hcasLedAServ)(rec->casLedAServ))->

    //TODO

    rec->next = smcasLedAServ_sta_default;
}

/*smcasLedAServ_act_default
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcasLedAServ_act_default(void *hStaRec){
    hsmcasLedAServRec rec = (hsmcasLedAServRec)hStaRec;
    //((hcasLedAServ)(rec->casLedAServ))->

    //TODO

    rec->next = smcasLedAServ_sta_default;
}


/***********************************************************
* 组件定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis casLedAServ类指针
* 输出: hcasLedAServ cthis/OOPC_NULL
***********************************************/
hcasLedAServ casLedAServ_init(hcasLedAServ cthis, hstaAct smcasLedAServ, hvfbOcasLedAServ vfbOcasLedAServ){
    cthis->smcasLedAServ = smcasLedAServ;
    cthis->vfbOcasLedAServ = vfbOcasLedAServ;
    //TODO

    return cthis;
}

/*组件运行函数
* 输入: t casLedAServ类指针
* 输出: 无
***********************************************/
void casLedAServ_run(hcasLedAServ t){
    SMRE(t->smcasLedAServ, t->smcasLedAServRec);
}

/*组件类构造函数
* 输入: cthis casLedAServ类指针
* 输出: hcasLedAServ cthis/OOPC_NULL
***********************************************/
CC(casLedAServ){
    cthis->init = casLedAServ_init;
    cthis->run = casLedAServ_run;
    //TODO

    cthis->smcasLedAServRec.next = smcasLedAServ_sta_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis casLedAServ类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(casLedAServ){
    return OOPC_TRUE;
}


/***********************************************************
* 组件异步调度功能函数
***********************************************************/
/*异步调度功能函数
***********************************************/
//void casLedAServ_abi_example(void){
//  //TODO
//}


/***********************************************************
* 组件实例化
***********************************************************/
/*组件类实例
***********************************************/
casLedAServ casLedAServA;


/**************************** Copyright(C) pxf ****************************/
