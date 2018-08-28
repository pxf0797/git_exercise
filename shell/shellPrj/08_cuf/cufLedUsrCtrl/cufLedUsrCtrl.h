/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cufLedUsrCtrl.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :���cufLedUsrCtrl �����ࡢ����ࡢ�����������������ͷ�ļ�
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef CUFLEDUSRCTRL_H_
#define CUFLEDUSRCTRL_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "cufLedUsrCtrlCfg.h"
#include "cufLedUsrCtrlErrCode.h"

/***********************************************************
* �����ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbIcufLedUsrCtrlInit(void);

/*�����ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 cufLedUsrCtrlInit(void);

/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbOcufLedUsrCtrlInit(void);

/*���������ʼ���ⲿ����
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
extern int16 vfbMcufLedUsrCtrlInit(void);


/***********************************************************
* �������
***********************************************************/
/*������е���
* ����: ��
* ���: ��
***********************************************/
void cufLedUsrCtrlSch(void);


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
CL(vfbOcufLedUsrCtrl){
    hvfbOcufLedUsrCtrl self;
    hvfbOcufLedUsrCtrl (*init)(hvfbOcufLedUsrCtrl cthis);

    // ������Ȳ���
    schParam schParam;

    // ʾ���������๦�ܺ���
    //void (*example)(hvfbOcufLedUsrCtrl t);
    //TODO
};

/*���������ⲿ�ӿ�����
* ������ʽ: �����+ʵ����+ʵ���๦��
***********************************************/
//extern void vfbMcufLedUsrCtrl_vfbOcufLedUsrCtrl_example(hvfbOcufLedUsrCtrl t);
//TODO

/*��������ʵ��
***********************************************/
extern vfbOcufLedUsrCtrl vfbOcufLedUsrCtrlA;


/***********************************************************
* ����ඨ��
***********************************************************/
/*���״̬��״̬
* ������״̬init/default��״̬list����ʾ��Ĭ�ϸ���
* ״̬list�����ʵ��Ӧ�ý�����д��list�޸ĺ���Ӧ״̬�����ö�Ӧ�޸�
***********************************************/
#define SM_CUFLEDUSRCTRL_STA_LIST(_) \
    _(smcufLedUsrCtrl, sta1)\
    _(smcufLedUsrCtrl, sta2)

/*���״̬������
***********************************************/
SMDC(smcufLedUsrCtrl, SM_CUFLEDUSRCTRL_STA_LIST)
{
    sta next;
    //TODO

    // ע�������
    void *cufLedUsrCtrl;
};


/*���������
***********************************************/
CL(cufLedUsrCtrl){
    hcufLedUsrCtrl self;
    hcufLedUsrCtrl (*init)(hcufLedUsrCtrl cthis, hstaAct smcufLedUsrCtrl, hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl);

    // �������״̬��
    smcufLedUsrCtrlRec smcufLedUsrCtrlRec;
    hstaAct smcufLedUsrCtrl;

    // ������й��ܺ���
    void (*run)(hcufLedUsrCtrl t);
    //void (*example)(hcufLedUsrCtrl t);
    //TODO

    // ע����������
    INJ(vfbOcufLedUsrCtrl, vfbOcufLedUsrCtrl);
};

/*�첽���ȹ��ܺ���
* ������ʽ: �����+ʵ����+ʵ���๦��
* ֻ��cas����������д˺���
***********************************************/
//void cufLedUsrCtrl_abi_example(void);
//TODO

/*�����ʵ��
***********************************************/
extern cufLedUsrCtrl cufLedUsrCtrlA;


/***********************************************************
* ��������ඨ��
***********************************************************/
/*�������������
***********************************************/
CL(vfbIcufLedUsrCtrl){
    hvfbIcufLedUsrCtrl self;
    hvfbIcufLedUsrCtrl (*init)(hvfbIcufLedUsrCtrl cthis, hcufLedUsrCtrl cufLedUsrCtrl);

    //void (*example)(hvfbIcufLedUsrCtrl t);
    //TODO

    // ע�������
    INJ(cufLedUsrCtrl, cufLedUsrCtrl);
};

/*���������ʵ��
***********************************************/
extern vfbIcufLedUsrCtrl vfbIcufLedUsrCtrlA;


#endif

/**************************** Copyright(C) pxf ****************************/
