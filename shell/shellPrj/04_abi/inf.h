/*
 * inf.h
 *
 *  Created on: 2018��8��17��
 *      Author: pxf
 */

#ifndef INF_H_
#define INF_H_

// �߳���ӿ�
INF(iIsr)
{
    void (*isr)(void);
};

// ʱ������ӿ�
INF(iMeasure)
{
    void (*start)(uint32 *point);
    uint32 (*end)(uint32 point);
};

// GIO��������ӿ�
INF(iGi)
{
    uint16 (*get)(void);
};
INF(iGo)
{
    void (*set)(uint16 sw);
};



#endif /* INF_H_ */
