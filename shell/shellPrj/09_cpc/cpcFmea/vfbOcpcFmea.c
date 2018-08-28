/*
 * vfbOcpcFmea.c
 *
 *  Created on: 2018��8��22��
 *      Author: pxf
 */

#include "cpcFmea.h"

// --------------------------------------------------------------
// ��������ʼ��
// --------------------------------------------------------------
// ��������ʼ��------------------------
int16 vfbOcpcFmeaInit(void)
{
    int16 rtv = 0;

    CNNP(vfbOcpcFmea, &vfbOcpcFmeaA);
    if (OPRS(vfbOcpcFmeaA) != OOPC_NULL)
    {
        rtv = vfbMcpcFmeaInit();
    }
    else
    {
        rtv = -1;
    }

    return rtv;
}


// --------------------------------------------------------------
// ��������ඨ��
// --------------------------------------------------------------
hvfbOcpcFmea vfbOcpcFmea_init(hvfbOcpcFmea cthis)
{
    return cthis;
}

CC(vfbOcpcFmea)
{
    cthis->init = vfbOcpcFmea_init;

    cthis->schParam.id = 0;
    cthis->schParam.schTask = cpcFmeaSch;
    cthis->schParam.startTick = (CPCFMEA_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
    cthis->schParam.prdTick = (CPCFMEA_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);

    return cthis;
}
CD(vfbOcpcFmea)
{
    return OOPC_TRUE;
}

// --------------------------------------------------------------
// ���������ʵ����
// --------------------------------------------------------------
vfbOcpcFmea vfbOcpcFmeaA;
