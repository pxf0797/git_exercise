/*
 * vfbMcpnInit.c
 *
 *  Created on: 2018��8��18��
 *      Author: pxf
 */

#include "vfbMcpnInit.h"
#include "..\..\04_abi\abi.h"
#include "..\..\06_cas\casSch\casSch.h"

// --------------------------------------------------------------
// ���������ʼ��
// --------------------------------------------------------------
int16 vfbMcpnInit(void)
{
    int16 rtv = 0;

    rtv |= vfbIabiInit();
    rtv |= vfbIcasSchInit();

    return rtv;
}

