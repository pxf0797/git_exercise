/*
 * basic.c
 *
 *  Created on: 2018��8��17��
 *      Author: pxf
 */

#include "bsp.h"
#include "..\04_abi\abi.h"
#include "..\05_cpnInit\cpnInit.h"

// --------------------------------------------------------------
// bsp�ӿڳ�ʼ��
// --------------------------------------------------------------
int16 bspInit(void)
{
    return cpnInit();
}




void bspTimer_bsp(void)
{
    timer.iIsr.isr();
}
void bspMainLoop_bsp(void)
{
    mainLoop.iIsr.isr();
}


void bspMeasureStart(uint32 *point)
{}
uint32 bspMeasureEnd(uint32 point)
{
    return 0;
}

