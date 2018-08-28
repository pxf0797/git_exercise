/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :csLedServErrCode.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 21:05:29
* @brief        :���csLedServ �ڲ�����ɲ��ִ����붨��ͷ�ļ�
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef CSLEDSERVERRCODE_H_
#define CSLEDSERVERRCODE_H_

/*errClassify
************************************************************
* #define EC_EC_cie      0 // communicationInputErr   ͨ���������
* #define EC_EC_coe      1 // communicationOutputErr  ͨ���������
* #define EC_EC_se       2 // schedularErr            ������ȴ���
* #define EC_EC_fe       3 // functionErr             ���ܴ���
***********************************************************/

/*errRanking
************************************************************
* #define EC_ER_ignore   0 // ignore   �ɺ���
* #define EC_ER_warning  1 // warning  ����
* #define EC_ER_serious  2 // serious  ���ش���
* #define EC_ER_fatal    3 // fatal    ��������
***********************************************************/

/*errDefine
************************************************************************************************************************
*                                | csLedServPartId |   errCode  |  errClassify  |  errRanking     |
***********************************************************************************************************************/
#define csLedServ_part1_pi         0                                                              // �������1
#define csLedServ_part1_err1                           0        // EC_EC_cie       EC_ER_warning  // �������1����1
/**********************************************************************************************************************/
#define csLedServ_part2_pi         1                                                              // �������1
#define csLedServ_part2_err1                           0        // EC_EC_cie       EC_ER_warning  // �������1����1
/**********************************************************************************************************************/

#endif

/**************************** Copyright(C) pxf ****************************/
