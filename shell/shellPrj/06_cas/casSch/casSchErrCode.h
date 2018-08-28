/*
 * casSchErrCode.h
 *
 *  Created on: 2018��8��18��
 *      Author: pxf
 */

#ifndef CASSCHERRCODE_H_
#define CASSCHERRCODE_H_

// errClassify
// 0  communicationInputErr  ͨ���������
// 1  communicationOutputErr ͨ���������
// 2  schedularErr           ������ȴ���
// 3  functionErr            ���ܴ���
//#define EC_EC_cie            0 // communicationInputErr
//#define EC_EC_coe            1 // communicationOutputErr
//#define EC_EC_se             2 // schedularErr
//#define EC_EC_fe             3 // functionErr

// errRanking
// 0  ignore    �ɺ���
// 1  warning   ����
// 2  serious   ���ش���
// 3  fatal     ��������
//#define EC_ER_ignore         0 // ignore
//#define EC_ER_warning        1 // warning
//#define EC_ER_serious        2 // serious
//#define EC_ER_fatal          3 // fatal

//                                        cpnPartId      errCode       errClassify        errRanking
// casSch_addTask
#define casSch_addTask_pi                 0                                                                 // �������
#define casSch_addTask_id_outOfRange                     0          // EC_EC_se           EC_ER_warning     // id������Χ
#define casSch_addTask_task_exist                        1          // EC_EC_se           EC_ER_warning     // �����Ѵ���

// casSch_delTask
#define casSch_delTask_pi                 1                                                                 // ɾ������
#define casSch_delTask_id_outOfRange                     0          // EC_EC_se           EC_ER_warning     // ɾ������ʧ��
#define casSch_delTask_task_null                         1          // EC_EC_se           EC_ER_warning     // ���񲻴���
#define casSch_delTask_task_false                        2          // EC_EC_se           EC_ER_warning     // ��Ŀ������

// casSch_taskExecute
#define casSch_taskExecute_pi             2                                                                 // �������
#define casSch_taskExecute_task_delay                    0          // EC_EC_se           EC_ER_warning     // ����ִ���ӳ�
#define casSch_taskExecute_task_miss                     1          // EC_EC_se           EC_ER_serious     // ����ִ�ж�ʧ

// casSch_taskExecute
#define casSch_schSm_pi                   3                                                                 // ����״̬��
#define casSch_schSm_sta_default                         0          // EC_EC_se           EC_ER_serious     // ״̬���쳣����Ĭ��״̬

#endif /* CASSCHERRCODE_H_ */
