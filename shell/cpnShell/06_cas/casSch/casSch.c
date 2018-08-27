/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :casSch.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/27 22:43:29
* @brief        :组件casSch 组件类定义
* @others       :
* @history      :180827 pxf 初次建立
***************************************************************************/

#include "casSch.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 casSchInit(void){
    int16 rtv = 0;

    CN(casSch, &casSchA, &smcasSch[0], &vfbOcasSchA);
    if(OPRS(casSchA) != OOPC_NULL){
        rtv = vfbOcasSchInit();
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
void casSchSch(void){
    casSchA.run(casSchA.self);
}


/***********************************************************
* 组件通用功能函数
***********************************************************/


/***********************************************************
* 组件状态机
***********************************************************/
/*组件状态机定义
***********************************************/
SMDC(smcasSch, SM_CASSCH_STA_LIST);

/*smcasSch_act_init
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcasSch_act_init(void *hStaRec){
    hsmcasSchRec rec = (hsmcasSchRec)hStaRec;

    rec->casSch = (void *)&casSchA;
    //TODO

    rec->next = smcasSch_sta_sta1;
}

/*smcasSch_act_sta1
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcasSch_act_sta1(void *hStaRec){
    hsmcasSchRec rec = (hsmcasSchRec)hStaRec;
    //TODO

    rec->next = smcasSch_sta_default;
}

/*smcasSch_act_sta2
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcasSch_act_sta2(void *hStaRec){
    hsmcasSchRec rec = (hsmcasSchRec)hStaRec;
    //TODO

    rec->next = smcasSch_sta_default;
}

/*smcasSch_act_default
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcasSch_act_default(void *hStaRec){
    hsmcasSchRec rec = (hsmcasSchRec)hStaRec;
    //TODO

    rec->next = smcasSch_sta_default;
}


/***********************************************************
* 组件定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis casSch类指针
* 输出: hcasSch cthis/OOPC_NULL
***********************************************/
hcasSch casSch_init(hcasSch cthis, hstaAct smcasSch, hvfbOcasSch vfbOcasSch){
    cthis->smcasSch = smcasSch;
    cthis->vfbOcasSch = vfbOcasSch;
    //TODO

    return cthis;
}

/*组件运行函数
* 输入: t casSch类指针
* 输出: 无
***********************************************/
hcasSch casSch_run(hcasSch t){
    SMRE(t->smcasSch, t->smcasSchRec);
}

/*组件类构造函数
* 输入: cthis casSch类指针
* 输出: hcasSch cthis/OOPC_NULL
***********************************************/
CC(casSch){
    cthis->init = casSch_init;
    cthis->run = casSch_run;
    //TODO

    cthis->smcasSchRec.next = smcasSch_sta_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis casSch类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(casSch){
    return OOPC_TRUE;
}


/***********************************************************
* 组件异步调度功能函数
***********************************************************/
/*异步调度功能函数
***********************************************/
//void casSch_abi_example(void){
//  //TODO
//}


/***********************************************************
* 组件实例化
***********************************************************/
/*组件类实例
***********************************************/
casSch casSchA;


/**************************** Copyright(C) pxf ****************************/
