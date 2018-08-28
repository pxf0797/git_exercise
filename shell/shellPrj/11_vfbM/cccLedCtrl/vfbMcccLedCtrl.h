/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcccLedCtrl.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:57:56
* @brief        :���cccLedCtrl ������������������
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef VFBMCCCLEDCTRL_H_
#define VFBMCCCLEDCTRL_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\10_ccc\cccLedCtrl\cccLedCtrl.h"
#include "..\vfbMCfg.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbMcccLedCtrlInit(void);


/***********************************************************
* ��������ඨ��
***********************************************************/
/*�������������
***********************************************/
CL(vfbMcccLedCtrl){
    hvfbMcccLedCtrl self;
    hvfbMcccLedCtrl (*init)(hvfbMcccLedCtrl cthis, hvfbOcccLedCtrl vfbOcccLedCtrl, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcccLedCtrl t);
    //TODO

    // ע�������
    INJ(vfbOcccLedCtrl, vfbOcccLedCtrl);
    INJ(vfbIcasSch, vfbIcasSch);
};

/*��������ӿ�����
* ������ʽ: �����+ʵ����+ʵ���๦��
***********************************************/
//void vfbMcccLedCtrl_vfbOcccLedCtrl_example(hvfbOcccLedCtrl t);

/*���������ʵ��
***********************************************/
extern vfbMcccLedCtrl vfbMcccLedCtrlA;


#endif

/**************************** Copyright(C) pxf ****************************/
