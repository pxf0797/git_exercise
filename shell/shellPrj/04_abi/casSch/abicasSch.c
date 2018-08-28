/*
 * abicasSch.c
 *
 *  Created on: 2018��8��22��
 *      Author: pxf
 */

#include "abicasSch.h"
#include "..\..\03_bsp\bsp.h"
#include "..\..\06_cas\casSch\casSch.h"

// --------------------------------------------------------------
// �������ӿڳ�ʼ��
// --------------------------------------------------------------
int16 abicasSchInit(void)
{
    int16 rtv = 0;

    CN(isr, &timer, casSch_abi_timer);
    if (OPRS(timer) == OOPC_NULL)
    {
        rtv++;
    }
    CN(isr, &mainLoop, casSch_abi_mainLoop);
    if (OPRS(mainLoop) == OOPC_NULL)
    {
        rtv++;
    }

    CN(measure, &time, bspMeasureStart, bspMeasureEnd);
    if (OPRS(time) == OOPC_NULL)
    {
        rtv++;
    }

    return rtv;
}

// --------------------------------------------------------------
// �������ӿ�
// --------------------------------------------------------------
// �߳������ӿ�------------------------
isr timer;
isr mainLoop;

// ʱ����������ӿ�--------------------
measure time;

