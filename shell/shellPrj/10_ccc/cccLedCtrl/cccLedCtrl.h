/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cccLedCtrl.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :���cccLedCtrl �����ࡢ����ࡢ�����������������ͷ�ļ�
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef CCCLEDCTRL_H_
#define CCCLEDCTRL_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "cccLedCtrlCfg.h"
#include "cccLedCtrlErrCode.h"

/***********************************************************
* �����ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbIcccLedCtrlInit(void);

/*�����ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 cccLedCtrlInit(void);

/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbOcccLedCtrlInit(void);

/*���������ʼ���ⲿ����
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
extern int16 vfbMcccLedCtrlInit(void);


/***********************************************************
* �������
***********************************************************/
/*������е���
* ����: ��
* ���: ��
***********************************************/
void cccLedCtrlSch(void);


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
CL(vfbOcccLedCtrl){
    hvfbOcccLedCtrl self;
    hvfbOcccLedCtrl (*init)(hvfbOcccLedCtrl cthis);

    // ������Ȳ���
    schParam schParam;

    // ʾ���������๦�ܺ���
    //void (*example)(hvfbOcccLedCtrl t);
    //TODO
};

/*���������ⲿ�ӿ�����
* ������ʽ: �����+ʵ����+ʵ���๦��
***********************************************/
//extern void vfbMcccLedCtrl_vfbOcccLedCtrl_example(hvfbOcccLedCtrl t);
//TODO

/*��������ʵ��
***********************************************/
extern vfbOcccLedCtrl vfbOcccLedCtrlA;


/***********************************************************
* ����ඨ��
***********************************************************/
/*���״̬��״̬
* ������״̬init/default��״̬list����ʾ��Ĭ�ϸ���
* ״̬list�����ʵ��Ӧ�ý�����д��list�޸ĺ���Ӧ״̬�����ö�Ӧ�޸�
***********************************************/
#define SM_CCCLEDCTRL_STA_LIST(_) \
    _(smcccLedCtrl, sta1)\
    _(smcccLedCtrl, sta2)

/*���״̬������
***********************************************/
SMDC(smcccLedCtrl, SM_CCCLEDCTRL_STA_LIST)
{
    sta next;
    //TODO

    // ע�������
    void *cccLedCtrl;
};


/*���������
***********************************************/
CL(cccLedCtrl){
    hcccLedCtrl self;
    hcccLedCtrl (*init)(hcccLedCtrl cthis, hstaAct smcccLedCtrl, hvfbOcccLedCtrl vfbOcccLedCtrl);

    // �������״̬��
    smcccLedCtrlRec smcccLedCtrlRec;
    hstaAct smcccLedCtrl;

    // ������й��ܺ���
    void (*run)(hcccLedCtrl t);
    //void (*example)(hcccLedCtrl t);
    //TODO

    // ע����������
    INJ(vfbOcccLedCtrl, vfbOcccLedCtrl);
};

/*�첽���ȹ��ܺ���
* ������ʽ: �����+ʵ����+ʵ���๦��
* ֻ��cas����������д˺���
***********************************************/
//void cccLedCtrl_abi_example(void);
//TODO

/*�����ʵ��
***********************************************/
extern cccLedCtrl cccLedCtrlA;


/***********************************************************
* ��������ඨ��
***********************************************************/
/*�������������
***********************************************/
CL(vfbIcccLedCtrl){
    hvfbIcccLedCtrl self;
    hvfbIcccLedCtrl (*init)(hvfbIcccLedCtrl cthis, hcccLedCtrl cccLedCtrl);

    //void (*example)(hvfbIcccLedCtrl t);
    //TODO

    // ע�������
    INJ(cccLedCtrl, cccLedCtrl);
};

/*���������ʵ��
***********************************************/
extern vfbIcccLedCtrl vfbIcccLedCtrlA;


#endif

/**************************** Copyright(C) pxf ****************************/
