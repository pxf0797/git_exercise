/*
 * vfbMcpcFmea.c
 *
 *  Created on: 2018��8��22��
 *      Author: pxf
 */

#include "vfbMcpcFmea.h"

// --------------------------------------------------------------
// ���������ʼ��
// --------------------------------------------------------------
// ���������ʼ��------------------------
int16 vfbMcpcFmeaInit(void)
{
    int16 rtv = 0;

    CN(vfbMcpcFmea, &vfbMcpcFmeaA, &vfbOcpcFmeaA, &vfbIcasSchA);
    if (OPRS(vfbMcpcFmeaA) != OOPC_NULL)
    {
        rtv = 0;
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
hvfbMcpcFmea vfbMcpcFmea_init(hvfbMcpcFmea cthis, hvfbOcpcFmea vfbOcpcFmea, hvfbIcasSch vfbIcasSch)
{
    cthis->vfbOcpcFmea = vfbOcpcFmea;
    cthis->vfbIcasSch = vfbIcasSch;

    return cthis;
}

CC(vfbMcpcFmea)
{
    cthis->init = vfbMcpcFmea_init;

    return cthis;
}
CD(vfbMcpcFmea)
{
    return OOPC_TRUE;
}

// --------------------------------------------------------------
// �����ӿڶ���
// --------------------------------------------------------------




// --------------------------------------------------------------
// ���������ʵ��
// --------------------------------------------------------------
vfbMcpcFmea vfbMcpcFmeaA;
