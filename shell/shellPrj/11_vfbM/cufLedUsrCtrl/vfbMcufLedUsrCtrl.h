/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcufLedUsrCtrl.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :���cufLedUsrCtrl ������������������
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef VFBMCUFLEDUSRCTRL_H_
#define VFBMCUFLEDUSRCTRL_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\08_cuf\cufLedUsrCtrl\cufLedUsrCtrl.h"
#include "..\vfbMCfg.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbMcufLedUsrCtrlInit(void);


/***********************************************************
* ��������ඨ��
***********************************************************/
/*�������������
***********************************************/
CL(vfbMcufLedUsrCtrl){
    hvfbMcufLedUsrCtrl self;
    hvfbMcufLedUsrCtrl (*init)(hvfbMcufLedUsrCtrl cthis, hvfbOcufLedUsrCtrl vfbOcufLedUsrCtrl, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcufLedUsrCtrl t);
    //TODO

    // ע�������
    INJ(vfbOcufLedUsrCtrl, vfbOcufLedUsrCtrl);
    INJ(vfbIcasSch, vfbIcasSch);
};

/*��������ӿ�����
* ������ʽ: �����+ʵ����+ʵ���๦��
***********************************************/
//void vfbMcufLedUsrCtrl_vfbOcufLedUsrCtrl_example(hvfbOcufLedUsrCtrl t);

/*���������ʵ��
***********************************************/
extern vfbMcufLedUsrCtrl vfbMcufLedUsrCtrlA;


#endif

/**************************** Copyright(C) pxf ****************************/
