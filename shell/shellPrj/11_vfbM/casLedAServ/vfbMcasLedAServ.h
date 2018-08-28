/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :vfbMcasLedAServ.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:59:32
* @brief        :���casLedAServ ������������������
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef VFBMCASLEDASERV_H_
#define VFBMCASLEDASERV_H_

#include "..\..\01_std\std.h"
#include "..\..\06_cas\casSch\casSch.h"
#include "..\..\06_cas\casLedAServ\casLedAServ.h"
#include "..\vfbMCfg.h"

/***********************************************************
* ��������ʼ��
***********************************************************/
/*��������ʼ��
* ����: ��
* ���: int16 0-�ɹ�,-1-ʧ��
***********************************************/
int16 vfbMcasLedAServInit(void);


/***********************************************************
* ��������ඨ��
***********************************************************/
/*�������������
***********************************************/
CL(vfbMcasLedAServ){
    hvfbMcasLedAServ self;
    hvfbMcasLedAServ (*init)(hvfbMcasLedAServ cthis, hvfbOcasLedAServ vfbOcasLedAServ, hvfbIcasSch vfbIcasSch);

    //void (*example)(hvfbMcasLedAServ t);
    //TODO

    // ע�������
    INJ(vfbOcasLedAServ, vfbOcasLedAServ);
    INJ(vfbIcasSch, vfbIcasSch);
};

/*��������ӿ�����
* ������ʽ: �����+ʵ����+ʵ���๦��
***********************************************/
//void vfbMcasLedAServ_vfbOcasLedAServ_example(hvfbOcasLedAServ t);

/*���������ʵ��
***********************************************/
extern vfbMcasLedAServ vfbMcasLedAServA;


#endif

/**************************** Copyright(C) pxf ****************************/
