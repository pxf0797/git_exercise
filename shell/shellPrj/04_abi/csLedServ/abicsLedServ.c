/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :abicsLedServ.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:07
* @brief        :���csLedServ ����ӿ��ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "abicsLedServ.h"
#include "..\..\03_bsp\bsp.h"

/***********************************************************
* �������ӿڳ�ʼ��
***********************************************************/
/*�������ӿڳ�ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 abicsLedServInit(void){
    int16 rtv = 0;

    //CN(isr, &timer, csLedServ_abi_timer);
    //if(OPRS(timer) == OOPC_NULL){
    //    rtv -= 1;
    //}
    //CN(isr, &mainLoop, csLedServ_abi_mainLoop);
    //if(OPRS(mainLoop) == OOPC_NULL){
    //    rtv -= 1;
    //}
    //CN(measure, &time, bspMeasureStart, bspMeasureEnd);
    //if(OPRS(time) == OOPC_NULL){
    //    rtv -= 1;
    //}
    //CN(gi, &err, bspErr);
    //if(OPRS(err) == OOPC_NULL){
    //    rtv -= 1;
    //}
    //CN(go, &led, bspLed);
    //if(OPRS(led) == OOPC_NULL){
    //    rtv -= 1;
    //}

    return rtv;
}


/***********************************************************
* �������ӿ�ʵ��
***********************************************************/
/*�߳������ʵ��
***********************************************/
//isr timer;
//isr mainLoop;

/*ʱ����������ʵ��
***********************************************/
//measure time;

/*GIO���������ʵ��
***********************************************/
//gi err;

/*GIO��������ʵ��
***********************************************/
//go led;


/**************************** Copyright(C) pxf ****************************/
