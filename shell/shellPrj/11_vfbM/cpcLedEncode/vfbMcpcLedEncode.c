/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcpcLedEncode.c
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :���cpcLedEncode �����ඨ��
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#include "vfbMcpcLedEncode.h"

/*�������id��ʱ���ã����ʵ��ʹ��ʱ������vbfMCfg.h������
***********************************************************/
#define cpcLedEncode_id_priority_cfg   0


/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbMcpcLedEncodeInit(void){
    int16 rtv = 0;

    CN(vfbMcpcLedEncode, &vfbMcpcLedEncodeA, &vfbOcpcLedEncodeA, &vfbIcasSchA);
    if(OPRS(vfbMcpcLedEncodeA) != OOPC_NULL){
        vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.id = cpcLedEncode_id_priority_cfg;
        vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.prdTick = (CPCLEDENCODE_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.startTick = (CPCLEDENCODE_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
        vfbMcpcLedEncodeA.vfbIcasSch->addTask(vfbMcpcLedEncodeA.vfbIcasSch,
            vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.id, vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.schTask,
            vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.prdTick, vfbMcpcLedEncodeA.vfbOcpcLedEncode->schParam.startTick);

        rtv = 0;
    }else{
        rtv = -1;
    }

    return rtv;
}


/***********************************************************
* ���������
***********************************************************/
/*����������ʼ������
* ����: cthis vfbMcpcLedEncode��ָ��
* ���: hvfbMcpcLedEncode cthis/OOPC_NULL
***********************************************/
hvfbMcpcLedEncode vfbMcpcLedEncode_init(hvfbMcpcLedEncode cthis, hvfbOcpcLedEncode vfbOcpcLedEncode, hvfbIcasSch vfbIcasSch){
    cthis->vfbOcpcLedEncode = vfbOcpcLedEncode;
    cthis->vfbIcasSch = vfbIcasSch;
    //TODO

    return cthis;
}

/*��������๹�캯��
* ����: cthis vfbMcpcLedEncode��ָ��
* ���: hvfbMcpcLedEncode cthis/OOPC_NULL
***********************************************/
CC(vfbMcpcLedEncode){
    cthis->init = vfbMcpcLedEncode_init;
    //TODO

    return cthis;
}
/*�����������������
* ����: cthis vfbMcpcLedEncode��ָ��
* ���: OOPC_RETURN_DATATYPE OOPC_TRUE/OOPC_FALSE
***********************************************/
CD(vfbMcpcLedEncode){
    return OOPC_TRUE;
}


/***********************************************************
* ��������ӿڶ���
***********************************************************/
/*�������๦�ܺ���
***********************************************/
//void vfbMcpcLedEncode_vfbOcpcLedEncode_example(hvfbOcpcLedEncode t){
//  //TODO
//}


/***********************************************************
* �������ʵ����
***********************************************************/
/*���������ʵ��
***********************************************/
vfbMcpcLedEncode vfbMcpcLedEncodeA;


/**************************** Copyright(C) pxf ****************************/
