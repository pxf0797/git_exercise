/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbIcpcLedEncode.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :���cpcLedEncode �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "cpcLedEncode.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbIcpcLedEncodeInit(void){
    int16 rtv = 0;

    CN(vfbIcpcLedEncode, &vfbIcpcLedEncodeA, &cpcLedEncodeA);
    if(OPRS(vfbIcpcLedEncodeA) != OOPC_NULL){
        rtv = cpcLedEncodeInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ������붨��
***********************************************************/
/*������ʼ������
* ����: cthis vfbIcpcLedEncode��ָ��
* ���: hvfbIcpcLedEncode cthis/OOPC_NULL
***********************************************/
hvfbIcpcLedEncode vfbIcpcLedEncode_init(hvfbIcpcLedEncode cthis, hcpcLedEncode cpcLedEncode){
    cthis->cpcLedEncode = cpcLedEncode;
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbIcpcLedEncode��ָ��
* ���: hvfbIcpcLedEncode cthis/OOPC_NULL
***********************************************/
CC(vfbIcpcLedEncode){
    cthis->init = vfbIcpcLedEncode_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbIcpcLedEncode��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbIcpcLedEncode){
    return OOPC_TRUE;
}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbIcpcLedEncode vfbIcpcLedEncodeA;


/**************************** Copyright(C) pxf ****************************/
