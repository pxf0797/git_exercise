/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : myClass.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/01/12 23:10:48
* Description  : myClass������ܺ�������Դ�ļ�
* Others       : 
* History      : 190112 pxf ���ν���
***************************************************************************/

/*ͷ�ļ�����*/
#include "./myClass.h"

/***********************************************************
* myClass�ඨ��
***********************************************************/
/*���� : myClass_firsFunc(hmyClass t)
* ���� : t - myClass��ָ��
* ��� : ��
* ���� : myClass�๦�ܺ���
***********************************************/
void myClass_firsFunc(hmyClass t){
    //TODO
}

/*���� : myClass_secondFunc(hmyClass t)
* ���� : t - myClass��ָ��
* ��� : ��
* ���� : myClass�๦�ܺ���
***********************************************/
void myClass_secondFunc(hmyClass t){
    //TODO
}

/*���� : hmyClass myClass_init(hmyClass cthis)
* ���� : cthis - myClass��ָ��
* ��� : hmyClass - cthis/OOPC_NULL
* ���� : myClass���ʼ������
***********************************************/
hmyClass myClass_init(hmyClass cthis){
    // ���ܺ�������
    //cthis->firsFunc = myClass_firsFunc;
    //TODO

    // ��������
    //TODO

    return cthis;
}

/*���� : hmyClass myClass_ctor(hmyClass cthis)
* ���� : cthis - myClass��ָ��
* ��� : hmyClass - cthis/OOPC_NULL
* ���� : myClass�๹�캯��
***********************************************/
CC(myClass){
    cthis->init = myClass_init;
    cthis->firsFunc = myClass_firsFunc;
    cthis->secondFunc = myClass_secondFunc;
    //TODO

    // ��������
    //TODO
    return cthis;
}

/*���� : hmyClass myClass_dtor(hmyClass cthis)
* ���� : cthis - myClass��ָ��
* ��� : OOPC_RETURN_DATATYPE - OOPC_TRUE/OOPC_FALSE
* ���� : myClass����������
***********************************************/
CD(myClass){
    return OOPC_TRUE;
}

/**************************** Copyright(C) pxf ****************************/
