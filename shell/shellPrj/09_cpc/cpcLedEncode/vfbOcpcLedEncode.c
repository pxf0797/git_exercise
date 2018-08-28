/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbOcpcLedEncode.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :���cpcLedEncode ����ඨ��
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
int16 vfbOcpcLedEncodeInit(void){
    int16 rtv = 0;

    CNNP(vfbOcpcLedEncode, &vfbOcpcLedEncodeA);
    if(OPRS(vfbOcpcLedEncodeA) != OOPC_NULL){
        rtv = vfbMcpcLedEncodeInit();
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ����������
***********************************************************/
/*������ʼ������
* ����: cthis vfbOcpcLedEncode��ָ��
* ���: hvfbOcpcLedEncode cthis/OOPC_NULL
***********************************************/
hvfbOcpcLedEncode vfbOcpcLedEncode_init(hvfbOcpcLedEncode cthis){
    cthis->schParam.id = 0;
    cthis->schParam.schTask = cpcLedEncodeSch;
    cthis->schParam.startTick = (CPCLEDENCODE_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CPCLEDENCODE_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    //TODO

    return cthis;
}

/*����๹�캯��
* ����: cthis vfbOcpcLedEncode��ָ��
* ���: hvfbOcpcLedEncode cthis/OOPC_NULL
***********************************************/
CC(vfbOcpcLedEncode){
    cthis->init = vfbOcpcLedEncode_init;
    //TODO

    return cthis;
}
/*�������������
* ����: cthis vfbOcpcLedEncode��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbOcpcLedEncode){
    return OOPC_TRUE;
}


/***********************************************************
* ������ʵ����
***********************************************************/
/*��������ʵ��
***********************************************/
vfbOcpcLedEncode vfbOcpcLedEncodeA;


/**************************** Copyright(C) pxf ****************************/
