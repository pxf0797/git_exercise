/*
 * abi.h
 *
 *  Created on: 2018��8��17��
 *      Author: pxf
 */

#ifndef ABI_H_
#define ABI_H_

// �����ӿڽ��з���
#include "..\01_std\std.h"

#include "inf.h"

#include ".\abiInf\isr.h"
#include ".\abiInf\measure.h"

#include ".\abiInf\gi.h"
#include ".\abiInf\go.h"

// --------------------------------------------------------------
// �������ӿڰ���
// --------------------------------------------------------------
#include ".\casSch\abicasSch.h"
#include ".\csLedServ\abicsLedServ.h"

// --------------------------------------------------------------
// �����ʼ��
// --------------------------------------------------------------
// ��������ʼ��------------------------
int16 vfbIabiInit(void);

// �����ʼ��----------------------------
int16 abiInit(void);

// ��������ʼ��------------------------

#endif /* ABI_H_ */
