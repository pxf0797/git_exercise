/*
 * gi.h
 *
 *  Created on: 2018��8��17��
 *      Author: pxf
 */

#ifndef GI_H_
#define GI_H_

CL(gi)
{
    hgi self;
    hgi (*init)(hgi cthis, uint16 (*get)(void));

    IMPL(iGi);
};

#endif /* GI_H_ */
