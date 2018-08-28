/*
 * go.c
 *
 *  Created on: 2018��8��17��
 *      Author: pxf
 */

#include "..\abi.h"

hgo go_init(hgo cthis, void (*set)(uint16 sw))
{
    cthis->iGo.set = set;

    return cthis;
}

CC(go)
{
    cthis->init = go_init;
    return cthis;
}

CD(go)
{
    return OOPC_TRUE;
}
