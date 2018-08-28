/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cpcLedEncode.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:20
* @brief        :���cpcLedEncode �����ࡢ����ࡢ�����������������ͷ�ļ�
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef CPCLEDENCODE_H_
#define CPCLEDENCODE_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "cpcLedEncodeCfg.h"
#include "cpcLedEncodeErrCode.h"

/***********************************************************
* �����ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbIcpcLedEncodeInit(void);

/*�����ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 cpcLedEncodeInit(void);

/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbOcpcLedEncodeInit(void);

/*���������ʼ���ⲿ����
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
extern int16 vfbMcpcLedEncodeInit(void);


/***********************************************************
* �������
***********************************************************/
/*������е���
* ����: ��
* ���: ��
***********************************************/
void cpcLedEncodeSch(void);


/***********************************************************
* ���������ͨ����������
***********************************************************/


/***********************************************************
* ��������ͨ����������
***********************************************************/


/***********************************************************
* �������ඨ��
***********************************************************/
/*������������
***********************************************/
CL(vfbOcpcLedEncode){
    hvfbOcpcLedEncode self;
    hvfbOcpcLedEncode (*init)(hvfbOcpcLedEncode cthis);

    // ������Ȳ���
    schParam schParam;

    // ʾ���������๦�ܺ���
    //void (*example)(hvfbOcpcLedEncode t);
    //TODO
};

/*���������ⲿ�ӿ�����
* ������ʽ: �����+ʵ����+ʵ���๦��
***********************************************/
//extern void vfbMcpcLedEncode_vfbOcpcLedEncode_example(hvfbOcpcLedEncode t);
//TODO

/*��������ʵ��
***********************************************/
extern vfbOcpcLedEncode vfbOcpcLedEncodeA;


/***********************************************************
* ����ඨ��
***********************************************************/
/*���״̬��״̬
* ������״̬init/default��״̬list����ʾ��Ĭ�ϸ���
* ״̬list�����ʵ��Ӧ�ý�����д��list�޸ĺ���Ӧ״̬�����ö�Ӧ�޸�
***********************************************/
#define SM_CPCLEDENCODE_STA_LIST(_) \
    _(smcpcLedEncode, sta1)\
    _(smcpcLedEncode, sta2)

/*���״̬������
***********************************************/
SMDC(smcpcLedEncode, SM_CPCLEDENCODE_STA_LIST)
{
    sta next;
    //TODO

    // ע�������
    void *cpcLedEncode;
};


/*���������
***********************************************/
CL(cpcLedEncode){
    hcpcLedEncode self;
    hcpcLedEncode (*init)(hcpcLedEncode cthis, hstaAct smcpcLedEncode, hvfbOcpcLedEncode vfbOcpcLedEncode);

    // �������״̬��
    smcpcLedEncodeRec smcpcLedEncodeRec;
    hstaAct smcpcLedEncode;

    // ������й��ܺ���
    void (*run)(hcpcLedEncode t);
    //void (*example)(hcpcLedEncode t);
    //TODO

    // ע����������
    INJ(vfbOcpcLedEncode, vfbOcpcLedEncode);
};

/*�첽���ȹ��ܺ���
* ������ʽ: �����+ʵ����+ʵ���๦��
* ֻ��cas����������д˺���
***********************************************/
//void cpcLedEncode_abi_example(void);
//TODO

/*�����ʵ��
***********************************************/
extern cpcLedEncode cpcLedEncodeA;


/***********************************************************
* ��������ඨ��
***********************************************************/
/*�������������
***********************************************/
CL(vfbIcpcLedEncode){
    hvfbIcpcLedEncode self;
    hvfbIcpcLedEncode (*init)(hvfbIcpcLedEncode cthis, hcpcLedEncode cpcLedEncode);

    //void (*example)(hvfbIcpcLedEncode t);
    //TODO

    // ע�������
    INJ(cpcLedEncode, cpcLedEncode);
};

/*���������ʵ��
***********************************************/
extern vfbIcpcLedEncode vfbIcpcLedEncodeA;


#endif

/**************************** Copyright(C) pxf ****************************/
