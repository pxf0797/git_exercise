/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcufLedUsrCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :���cufLedUsrCtrl �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "cufLedUsrCtrl.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbIcufLedUsrCtrlInit(void){
    int16 rtv = 0;

    CN(vfbIcufLedUsrCtrl, &vfbIcufLedUsrCtrlA, &cufLedUsrCtrlA);
    if(OPRS(vfbIcufLedUsrCtrlA) != OOPC_NULL){
        rtv = cufLedUsrCtrlInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ������붨��
***********************************************************/
/*������ʼ������
* ����: cthis vfbIcufLedUsrCtrl��ָ��
* ���: hvfbIcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
hvfbIcufLedUsrCtrl vfbIcufLedUsrCtrl_init(hvfbIcufLedUsrCtrl cthis, hcufLedUsrCtrl cufLedUsrCtrl){
    cthis->cufLedUsrCtrl = cufLedUsrCtrl;
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbIcufLedUsrCtrl��ָ��
* ���: hvfbIcufLedUsrCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbIcufLedUsrCtrl){
    cthis->init = vfbIcufLedUsrCtrl_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbIcufLedUsrCtrl��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcufLedUsrCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbIcufLedUsrCtrl vfbIcufLedUsrCtrlA;


/**************************** Copyright(C) pxf ****************************/
