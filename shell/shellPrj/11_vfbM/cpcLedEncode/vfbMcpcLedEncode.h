/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcpcLedEncode.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :���cpcLedEncode ������������������
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef VFBMCPCLEDENCODE_H_
#define VFBMCPCLEDENCODE_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\09_cpc\cpcLedEncode\cpcLedEncode.h"
#include "..\vfbMCfg.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbMcpcLedEncodeInit(void);


/***********************************************************
* ��������ඨ��
***********************************************************/
/*�������������
***********************************************/
CL(vfbMcpcLedEncode){
    hvfbMcpcLedEncode self;
    hvfbMcpcLedEncode (*init)(hvfbMcpcLedEncode cthis, hvfbOcpcLedEncode vfbOcpcLedEncode, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcpcLedEncode t);
    //TODO

    // ע�������
    INJ(vfbOcpcLedEncode, vfbOcpcLedEncode);
    INJ(vfbIcasSch, vfbIcasSch);
};

/*��������ӿ�����
* ������ʽ: �����+ʵ����+ʵ���๦��
***********************************************/
//void vfbMcpcLedEncode_vfbOcpcLedEncode_example(hvfbOcpcLedEncode t);

/*���������ʵ��
***********************************************/
extern vfbMcpcLedEncode vfbMcpcLedEncodeA;


#endif

/**************************** Copyright(C) pxf ****************************/
