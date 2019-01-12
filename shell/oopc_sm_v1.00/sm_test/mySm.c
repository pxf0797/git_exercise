/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : mySm.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/01/12 23:11:27
* Description  : ״̬��mySm���弰��״̬��������Դ�ļ�
* Others       : 
* History      : 190112 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./mySm.h"

/*״̬��mySm����
* ����״̬����ش���״̬
***********************************************/
SMDF(mySm, MYSM_LIST);

/*���� : mySm_act_init()
* ���� : mySmRec - ״̬��¼����ָ��
* ��� : ��
* ���� : ��ʼ״̬��������
***********************************************/
void mySm_act_init(void *mySmRec){
    hmySmRec hRec = (hmySmRec)mySmRec;

    // TODO

    hRec->next = mySm_sta_default;
    hRec->last = mySm_sta_init;
}

/*���� : mySm_act_default()
* ���� : mySmRec - ״̬��¼����ָ��
* ��� : ��
* ���� : Ĭ��״̬��������
***********************************************/
void mySm_act_default(void *mySmRec){
    hmySmRec hRec = (hmySmRec)mySmRec;

    // TODO

    hRec->next = mySm_sta_default;
    hRec->last = mySm_sta_default;
}

/*���� : mySm_act_firsState()
* ���� : mySmRec - ״̬��¼����ָ��
* ��� : ��
* ���� : ״̬firsState��������
***********************************************/
void mySm_act_firsState(void *mySmRec){
    hmySmRec hRec = (hmySmRec)mySmRec;

    // TODO

    hRec->next = mySm_sta_default;
    hRec->last = mySm_sta_firsState;
}

/*���� : mySm_act_secondState()
* ���� : mySmRec - ״̬��¼����ָ��
* ��� : ��
* ���� : ״̬secondState��������
***********************************************/
void mySm_act_secondState(void *mySmRec){
    hmySmRec hRec = (hmySmRec)mySmRec;

    // TODO

    hRec->next = mySm_sta_default;
    hRec->last = mySm_sta_secondState;
}

/**************************** Copyright(C) pxf ****************************/
