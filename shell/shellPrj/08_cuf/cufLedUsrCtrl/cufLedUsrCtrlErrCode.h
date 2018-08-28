/**************************************************************************
* @copyright    :Copyright(C), 2018, pxf, person.
* @file         :cufLedUsrCtrlErrCode.h
* @author       :pxf
* @version      :v1.0
* @date         :2018/08/28 20:58:53
* @brief        :���cufLedUsrCtrl �ڲ�����ɲ��ִ����붨��ͷ�ļ�
* @others       :
* @history      :180828 pxf ���ν���
***************************************************************************/

#ifndef CUFLEDUSRCTRLERRCODE_H_
#define CUFLEDUSRCTRLERRCODE_H_

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
*                                | cufLedUsrCtrlPartId |   errCode  |  errClassify  |  errRanking     |
***********************************************************************************************************************/
#define cufLedUsrCtrl_part1_pi     0                                                                  // �������1
#define cufLedUsrCtrl_part1_err1                           0        // EC_EC_cie       EC_ER_warning  // �������1����1
/**********************************************************************************************************************/
#define cufLedUsrCtrl_part2_pi     1                                                                  // �������1
#define cufLedUsrCtrl_part2_err1                           0        // EC_EC_cie       EC_ER_warning  // �������1����1
/**********************************************************************************************************************/

#endif

/**************************** Copyright(C) pxf ****************************/
