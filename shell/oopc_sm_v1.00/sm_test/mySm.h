/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : mySm.h
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/01/12 23:11:27
* Description  : ״̬��mySm������״̬��ʹ��ʾ��ͷ�ļ�
* Others       : 
* History      : 190112 pxf ���ν���
***************************************************************************/

#ifndef MYSM_H_
#define MYSM_H_

/*ͷ�ļ�����*/
#include "../sm_v1.01/sm.h"

/*״̬��mySmʹ��ʾ����
* ��ǰ״̬������SMDF�ж����ʵ��mySm����Ҫ����ֻ��������������
* ״̬�����з�ʽ������ֱ�Ӹ�ʱ��������SMR��ʹ���Զ����¼״̬���������SMRE
***********************************************
* SMR��ʽ
***********************************************
void test(void){
    while(1){SMR(mySm);};
}
***********************************************
* SMRE��ʽ
***********************************************
void test2(void){
    static mySmRec mySmRunRec = {mySm_sta_init};
    while(1){SMRE(mySm, mySmRunRec);};
}
***********************************************/


/*״̬��mySm״̬���ж���
* ע������mySm_init,mySm_defaultδ�ڴ˶��壬Ĭ�ϻ����
***********************************************/
#define MYSM_LIST(_)        \
    _(mySm, firsState)      \
    _(mySm, secondState)


/*״̬��mySm����
* �Ѹ���״̬��¼next,����һ״̬last��������������������
***********************************************/
SMDC(mySm, MYSM_LIST){
    sta next; // ����״̬��¼
    sta last; // ��һ״̬��¼
    // TODO
};

#endif /*MYSM_H_*/

/**************************** Copyright(C) pxf ****************************/