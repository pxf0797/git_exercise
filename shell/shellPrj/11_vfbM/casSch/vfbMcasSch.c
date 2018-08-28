/*
 * vfbMcasSch.c
 *
 *  Created on: 2018��8��18��
 *      Author: pxf
 */

#include "vfbMcasSch.h"
#include "..\..\09_cpc\cpcFmea\cpcFmea.h"


// --------------------------------------------------------------
// ���������ʼ��
// --------------------------------------------------------------
int16 vfbMcasSchInit(void)
{
    int16 rtv = 0;

    CN(vfbMcasSch, &vfbMcasSchA, &vfbOcasSchA);
    if (OPRS(vfbMcasSchA) != OOPC_NULL)
    {
        rtv = vfbIcpcFmeaInit();
        if (rtv == 0)
        {
            vfbOcpcFmeaA.schParam.id = cpcFmea_id_priority_cfg;
            vfbOcpcFmeaA.schParam.prdTick = (CPCFMEA_PRD_TICK_CFG / CASSCH_TIMER_PRD_CFG);
            vfbOcpcFmeaA.schParam.startTick = (CPCFMEA_START_TICK_CFG / CASSCH_TIMER_PRD_CFG);
            vfbIcasSchA.addTask(vfbIcasSchA.self,
                    vfbOcpcFmeaA.schParam.id, vfbOcpcFmeaA.schParam.schTask,
                    vfbOcpcFmeaA.schParam.prdTick, vfbOcpcFmeaA.schParam.startTick);
        }

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
hvfbMcasSch hvfbMcasSch_init(hvfbMcasSch cthis, hvfbOcasSch vfbOcasSch)
{
    cthis->vfbOcasSch = vfbOcasSch;
    return cthis;
}

void hvfbMcasSch_tickOut(hvfbMcasSch t)
{}
void hvfbMcasSch_err(hvfbMcasSch t, herrCode code)
{}

CC(vfbMcasSch)
{
    cthis->init = hvfbMcasSch_init;
    cthis->tickOut = hvfbMcasSch_tickOut;
    cthis->err = hvfbMcasSch_err;

    return cthis;
}
CD(vfbMcasSch)
{
    return OOPC_TRUE;
}

// --------------------------------------------------------------
// �����ӿڶ���
// --------------------------------------------------------------
void vfbMcasSch_vfbOcasSch_tickOut(hvfbOcasSch t)
{}
void vfbMcasSch_vfbOcasSch_err(hvfbOcasSch t, herrCode code)
{}

// --------------------------------------------------------------
// ���������ʵ��
// --------------------------------------------------------------
vfbMcasSch vfbMcasSchA;
