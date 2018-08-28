/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :casLedAServ.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :���casLedAServ �����ࡢ����ࡢ�����������������ͷ�ļ�
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef CASLEDASERV_H_
#define CASLEDASERV_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "casLedAServCfg.h"
#include "casLedAServErrCode.h"

/***********************************************************
* �����ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbIcasLedAServInit(void);

/*�����ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 casLedAServInit(void);

/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbOcasLedAServInit(void);

/*���������ʼ���ⲿ����
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
extern int16 vfbMcasLedAServInit(void);


/***********************************************************
* �������
***********************************************************/
/*������е���
* ����: ��
* ���: ��
***********************************************/
void casLedAServSch(void);


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
CL(vfbOcasLedAServ){
    hvfbOcasLedAServ self;
    hvfbOcasLedAServ (*init)(hvfbOcasLedAServ cthis);

    // ������Ȳ���
    schParam schParam;

    // ʾ���������๦�ܺ���
    //void (*example)(hvfbOcasLedAServ t);
    //TODO
};

/*���������ⲿ�ӿ�����
* ������ʽ: �����+ʵ����+ʵ���๦��
***********************************************/
//extern void vfbMcasLedAServ_vfbOcasLedAServ_example(hvfbOcasLedAServ t);
//TODO

/*��������ʵ��
***********************************************/
extern vfbOcasLedAServ vfbOcasLedAServA;


/***********************************************************
* ����ඨ��
***********************************************************/
/*���״̬��״̬
* ������״̬init/default��״̬list����ʾ��Ĭ�ϸ���
* ״̬list�����ʵ��Ӧ�ý�����д��list�޸ĺ���Ӧ״̬�����ö�Ӧ�޸�
***********************************************/
#define SM_CASLEDASERV_STA_LIST(_) \
    _(smcasLedAServ, sta1)\
    _(smcasLedAServ, sta2)

/*���״̬������
***********************************************/
SMDC(smcasLedAServ, SM_CASLEDASERV_STA_LIST)
{
    sta next;
    //TODO

    // ע�������
    void *casLedAServ;
};


/*���������
***********************************************/
CL(casLedAServ){
    hcasLedAServ self;
    hcasLedAServ (*init)(hcasLedAServ cthis, hstaAct smcasLedAServ, hvfbOcasLedAServ vfbOcasLedAServ);

    // �������״̬��
    smcasLedAServRec smcasLedAServRec;
    hstaAct smcasLedAServ;

    // ������й��ܺ���
    void (*run)(hcasLedAServ t);
    //void (*example)(hcasLedAServ t);
    //TODO

    // ע����������
    INJ(vfbOcasLedAServ, vfbOcasLedAServ);
};

/*�첽���ȹ��ܺ���
* ������ʽ: �����+ʵ����+ʵ���๦��
* ֻ��cas����������д˺���
***********************************************/
//void casLedAServ_abi_example(void);
//TODO

/*�����ʵ��
***********************************************/
extern casLedAServ casLedAServA;


/***********************************************************
* ��������ඨ��
***********************************************************/
/*�������������
***********************************************/
CL(vfbIcasLedAServ){
    hvfbIcasLedAServ self;
    hvfbIcasLedAServ (*init)(hvfbIcasLedAServ cthis, hcasLedAServ casLedAServ);

    //void (*example)(hvfbIcasLedAServ t);
    //TODO

    // ע�������
    INJ(casLedAServ, casLedAServ);
};

/*���������ʵ��
***********************************************/
extern vfbIcasLedAServ vfbIcasLedAServA;


#endif

/**************************** Copyright(C) pxf ****************************/
