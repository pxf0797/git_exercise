/*
 * vfbIcasSch.c
 *
 *  Created on: 2018��8��18��
 *      Author: pxf
 */

#include "casSch.h"


// --------------------------------------------------------------
// ��������ʼ��
// --------------------------------------------------------------
// ��������ʼ��------------------------
int16 vfbIcasSchInit(void)
{
    int16 rtv = 0;

    CN(vfbIcasSch, &vfbIcasSchA, &casSchA);
    if (OPRS(vfbIcasSchA) != OOPC_NULL)
    {
        rtv = casSchInit();
    }
    else
    {
        rtv = -1;
    }

    return rtv;
}


// --------------------------------------------------------------
// ���������ඨ��
// --------------------------------------------------------------
hvfbIcasSch vfbIcasSch_init(hvfbIcasSch cthis, hcasSch casSch)
{
    cthis->casSch = casSch;

    return cthis;
}
void vfbIcasSch_addTask(hvfbIcasSch t, int16 id, void(*schTask)(void), uint16 prdTick, uint16 startTick)
{
    t->casSch->addTask(t->casSch, id, schTask, prdTick, startTick);
}
void vfbIcasSch_delTask(hvfbIcasSch t, int16 id, void(*schTask)(void))
{
    t->casSch->delTask(t->casSch, id, schTask);
}

CC(vfbIcasSch)
{
    cthis->init = vfbIcasSch_init;
    cthis->addTask = vfbIcasSch_addTask;
    cthis->delTask = vfbIcasSch_delTask;

    return cthis;
}

CD(vfbIcasSch)
{
    return OOPC_TRUE;
}

// --------------------------------------------------------------
// ����������ʵ����
// --------------------------------------------------------------
vfbIcasSch vfbIcasSchA;
