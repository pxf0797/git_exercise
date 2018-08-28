/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cpcLedEncode.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :组件cpcLedEncode 组件类定义
* @others       :
* @history      :180828 pxf 初次建立
***************************************************************************/

#include "cpcLedEncode.h"

/***********************************************************
* 组件初始化
***********************************************************/
/*组件初始化
* 输入: 无
* 输出: int16 0-成功,-1-失败
***********************************************/
int16 cpcLedEncodeInit(void){
    int16 rtv = 0;

    CN(cpcLedEncode, &cpcLedEncodeA, &smcpcLedEncode[0], &vfbOcpcLedEncodeA);
    if(OPRS(cpcLedEncodeA) != OOPC_NULL){
        rtv = vfbOcpcLedEncodeInit();
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
void cpcLedEncodeSch(void){
    cpcLedEncodeA.run(cpcLedEncodeA.self);
}


/***********************************************************
* 组件通用功能函数
***********************************************************/


/***********************************************************
* 组件状态机
***********************************************************/
/*组件状态机定义
***********************************************/
SMDF(smcpcLedEncode, SM_CPCLEDENCODE_STA_LIST);

/*smcpcLedEncode_act_init
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcpcLedEncode_act_init(void *hStaRec){
    hsmcpcLedEncodeRec rec = (hsmcpcLedEncodeRec)hStaRec;

    rec->cpcLedEncode = (void *)&cpcLedEncodeA;
    //TODO

    rec->next = smcpcLedEncode_sta_default;
}

/*smcpcLedEncode_act_sta1
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcpcLedEncode_act_sta1(void *hStaRec){
    hsmcpcLedEncodeRec rec = (hsmcpcLedEncodeRec)hStaRec;
    //((hcpcLedEncode)(rec->cpcLedEncode))->

    //TODO

    rec->next = smcpcLedEncode_sta_default;
}

/*smcpcLedEncode_act_sta2
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcpcLedEncode_act_sta2(void *hStaRec){
    hsmcpcLedEncodeRec rec = (hsmcpcLedEncodeRec)hStaRec;
    //((hcpcLedEncode)(rec->cpcLedEncode))->

    //TODO

    rec->next = smcpcLedEncode_sta_default;
}

/*smcpcLedEncode_act_default
* 输入: hStaRec 状态记录结构体指针
* 输出: 无
***********************************************/
void smcpcLedEncode_act_default(void *hStaRec){
    hsmcpcLedEncodeRec rec = (hsmcpcLedEncodeRec)hStaRec;
    //((hcpcLedEncode)(rec->cpcLedEncode))->

    //TODO

    rec->next = smcpcLedEncode_sta_default;
}


/***********************************************************
* 组件定义
***********************************************************/
/*组件类初始化函数
* 输入: cthis cpcLedEncode类指针
* 输出: hcpcLedEncode cthis/OOPC_NULL
***********************************************/
hcpcLedEncode cpcLedEncode_init(hcpcLedEncode cthis, hstaAct smcpcLedEncode, hvfbOcpcLedEncode vfbOcpcLedEncode){
    cthis->smcpcLedEncode = smcpcLedEncode;
    cthis->vfbOcpcLedEncode = vfbOcpcLedEncode;
    //TODO

    return cthis;
}

/*组件运行函数
* 输入: t cpcLedEncode类指针
* 输出: 无
***********************************************/
void cpcLedEncode_run(hcpcLedEncode t){
    SMRE(t->smcpcLedEncode, t->smcpcLedEncodeRec);
}

/*组件类构造函数
* 输入: cthis cpcLedEncode类指针
* 输出: hcpcLedEncode cthis/OOPC_NULL
***********************************************/
CC(cpcLedEncode){
    cthis->init = cpcLedEncode_init;
    cthis->run = cpcLedEncode_run;
    //TODO

    cthis->smcpcLedEncodeRec.next = smcpcLedEncode_sta_init;
    //TODO

    return cthis;
}
/*组件类析构函数
* 输入: cthis cpcLedEncode类指针
* 输出: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(cpcLedEncode){
    return OOPC_TRUE;
}


/***********************************************************
* 组件异步调度功能函数
***********************************************************/
/*异步调度功能函数
***********************************************/
//void cpcLedEncode_abi_example(void){
//  //TODO
//}


/***********************************************************
* 组件实例化
***********************************************************/
/*组件类实例
***********************************************/
cpcLedEncode cpcLedEncodeA;


/**************************** Copyright(C) pxf ****************************/
