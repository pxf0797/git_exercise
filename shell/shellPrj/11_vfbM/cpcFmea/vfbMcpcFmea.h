/*
 * vfbMcpcFmea.h
 *
 *  Created on: 2018��8��22��
 *      Author: pxf
 */

#ifndef VFBMCPCFMEA_H_
#define VFBMCPCFMEA_H_

#include "..\..\09_cpc\cpcFmea\cpcFmea.h"

// --------------------------------------------------------------
// ���������ʼ��
// --------------------------------------------------------------
// ���������ʼ��------------------------
int16 vfbMcpcFmeaInit(void);



// --------------------------------------------------------------
// ��������ඨ��
// --------------------------------------------------------------
// �������������------------------------
CL(vfbMcpcFmea)
{
    hvfbMcpcFmea self;
    hvfbMcpcFmea (*init)(hvfbMcpcFmea cthis, hvfbOcpcFmea vfbOcpcFmea, hvfbIcasSch vfbIcasSch);

    INJ(vfbOcpcFmea, vfbOcpcFmea);
    INJ(vfbIcasSch, vfbIcasSch);
};

// �����ӿ�����------------------------
// �ӿڽṹ��������+�����+����ຯ��


// ���������ʵ��------------------------
extern vfbMcpcFmea vfbMcpcFmeaA;

#endif /* VFBMCPCFMEA_H_ */
