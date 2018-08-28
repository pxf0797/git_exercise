/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcccLedCtrl.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :���cccLedCtrl �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "cccLedCtrl.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbIcccLedCtrlInit(void){
    int16 rtv = 0;

    CN(vfbIcccLedCtrl, &vfbIcccLedCtrlA, &cccLedCtrlA);
    if(OPRS(vfbIcccLedCtrlA) != OOPC_NULL){
        rtv = cccLedCtrlInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ������붨��
***********************************************************/
/*������ʼ������
* ����: cthis vfbIcccLedCtrl��ָ��
* ���: hvfbIcccLedCtrl cthis/OOPC_NULL
***********************************************/
hvfbIcccLedCtrl vfbIcccLedCtrl_init(hvfbIcccLedCtrl cthis, hcccLedCtrl cccLedCtrl){
    cthis->cccLedCtrl = cccLedCtrl;
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbIcccLedCtrl��ָ��
* ���: hvfbIcccLedCtrl cthis/OOPC_NULL
***********************************************/
CC(vfbIcccLedCtrl){
    cthis->init = vfbIcccLedCtrl_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbIcccLedCtrl��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcccLedCtrl){
    return OOPC_TRUE;
}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbIcccLedCtrl vfbIcccLedCtrlA;


/**************************** Copyright(C) pxf ****************************/
