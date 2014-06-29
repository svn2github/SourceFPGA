/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestADC/BatADC.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1258338084_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
char *ieee_p_2592010699_sub_1735675855_503743352(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2358102284_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(146, ng0);

LAB3:    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 11296);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 11072);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2358102284_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:    xsi_set_current_line(147, ng0);

LAB3:    t1 = (t0 + 11360);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2358102284_3212880686_p_2(char *t0)
{
    char t12[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned char t11;
    char *t13;
    unsigned int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 8768U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(152, ng0);

LAB6:    t2 = (t0 + 11088);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t5 = (t0 + 11088);
    *((int *)t5) = 0;
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 4232U);
    t3 = *((char **)t2);
    t6 = (0 - 1);
    t7 = (t6 * -1);
    t8 = (1U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t4 = *((unsigned char *)t2);
    t5 = (t0 + 5352U);
    t10 = *((char **)t5);
    t11 = *((unsigned char *)t10);
    t13 = ((IEEE_P_2592010699) + 4024);
    t5 = xsi_base_array_concat(t5, t12, t13, (char)99, t4, (char)99, t11, (char)101);
    t14 = (1U + 1U);
    t15 = (2U != t14);
    if (t15 == 1)
        goto LAB8;

LAB9:    t16 = (t0 + 11424);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t5, 2U);
    xsi_driver_first_trans_fast(t16);
    goto LAB2;

LAB5:    t3 = (t0 + 1312U);
    t4 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t4 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    xsi_size_not_matching(2U, t14, 0);
    goto LAB9;

}

static void work_a_2358102284_3212880686_p_3(char *t0)
{
    char t12[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned char t11;
    char *t13;
    unsigned int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 9016U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(158, ng0);

LAB6:    t2 = (t0 + 11104);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t5 = (t0 + 11104);
    *((int *)t5) = 0;
    xsi_set_current_line(159, ng0);
    t2 = (t0 + 6472U);
    t3 = *((char **)t2);
    t6 = (0 - 1);
    t7 = (t6 * -1);
    t8 = (1U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t4 = *((unsigned char *)t2);
    t5 = (t0 + 6312U);
    t10 = *((char **)t5);
    t11 = *((unsigned char *)t10);
    t13 = ((IEEE_P_2592010699) + 4024);
    t5 = xsi_base_array_concat(t5, t12, t13, (char)99, t4, (char)99, t11, (char)101);
    t14 = (1U + 1U);
    t15 = (2U != t14);
    if (t15 == 1)
        goto LAB8;

LAB9:    t16 = (t0 + 11488);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t5, 2U);
    xsi_driver_first_trans_fast(t16);
    goto LAB2;

LAB5:    t3 = (t0 + 1312U);
    t4 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t4 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    xsi_size_not_matching(2U, t14, 0);
    goto LAB9;

}

static void work_a_2358102284_3212880686_p_4(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    static char *nl0[] = {&&LAB9, &&LAB10};

LAB0:    xsi_set_current_line(166, ng0);
    t1 = (t0 + 1312U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 11120);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(168, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(173, ng0);
    t1 = (t0 + 6792U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(169, ng0);
    t3 = (t0 + 11552);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(170, ng0);
    t1 = (t0 + 11616);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB6:    goto LAB3;

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(175, ng0);
    t4 = (t0 + 6472U);
    t7 = *((char **)t4);
    t11 = (1 - 1);
    t12 = (t11 * -1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t4 = (t7 + t14);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(179, ng0);
    t1 = (t0 + 11552);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB12:    goto LAB8;

LAB10:    xsi_set_current_line(182, ng0);
    t1 = (t0 + 6472U);
    t3 = *((char **)t1);
    t11 = (1 - 1);
    t12 = (t11 * -1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB14;

LAB16:    xsi_set_current_line(186, ng0);
    t1 = (t0 + 11552);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB15:    goto LAB8;

LAB11:    xsi_set_current_line(176, ng0);
    t8 = (t0 + 11616);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t15 = (t10 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(177, ng0);
    t1 = (t0 + 11552);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB12;

LAB14:    xsi_set_current_line(183, ng0);
    t4 = (t0 + 11616);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(184, ng0);
    t1 = (t0 + 11552);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB15;

}

static void work_a_2358102284_3212880686_p_5(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    static char *nl0[] = {&&LAB9, &&LAB10};

LAB0:    xsi_set_current_line(197, ng0);
    t1 = (t0 + 1312U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 11136);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(199, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(208, ng0);
    t1 = (t0 + 11936);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(209, ng0);
    t1 = (t0 + 6632U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(200, ng0);
    t3 = (t0 + 11680);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(201, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11744);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(202, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11808);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(203, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t3 = t1;
    memset(t3, (unsigned char)2, 8U);
    t4 = (t0 + 11872);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(204, ng0);
    t1 = (t0 + 11936);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(205, ng0);
    t1 = (t0 + 12000);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(211, ng0);
    t4 = (t0 + 4232U);
    t7 = *((char **)t4);
    t11 = (1 - 1);
    t12 = (t11 * -1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t4 = (t7 + t14);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(219, ng0);
    t1 = (t0 + 11680);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB12:    goto LAB8;

LAB10:    xsi_set_current_line(222, ng0);
    t1 = (t0 + 4232U);
    t3 = *((char **)t1);
    t11 = (1 - 1);
    t12 = (t11 * -1);
    t13 = (1U * t12);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB14;

LAB16:    xsi_set_current_line(226, ng0);
    t1 = (t0 + 11680);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB15:    goto LAB8;

LAB11:    xsi_set_current_line(212, ng0);
    t8 = (t0 + 5032U);
    t9 = *((char **)t8);
    t15 = (31 - 7);
    t16 = (t15 * 1U);
    t17 = (0 + t16);
    t8 = (t9 + t17);
    t10 = (t0 + 11872);
    t18 = (t10 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t8, 8U);
    xsi_driver_first_trans_fast_port(t10);
    xsi_set_current_line(213, ng0);
    t1 = (t0 + 5032U);
    t3 = *((char **)t1);
    t12 = (31 - 31);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t4 = (t0 + 11744);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(214, ng0);
    t1 = (t0 + 5192U);
    t3 = *((char **)t1);
    t12 = (31 - 31);
    t13 = (t12 * 1U);
    t14 = (0 + t13);
    t1 = (t3 + t14);
    t4 = (t0 + 11808);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(215, ng0);
    t1 = (t0 + 11936);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(216, ng0);
    t1 = (t0 + 12000);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(217, ng0);
    t1 = (t0 + 11680);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB12;

LAB14:    xsi_set_current_line(223, ng0);
    t4 = (t0 + 12000);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(224, ng0);
    t1 = (t0 + 11680);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB15;

}

static void work_a_2358102284_3212880686_p_6(char *t0)
{
    char t12[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned char t11;
    char *t13;
    unsigned int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 9760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(242, ng0);

LAB6:    t2 = (t0 + 11152);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t5 = (t0 + 11152);
    *((int *)t5) = 0;
    xsi_set_current_line(243, ng0);
    t2 = (t0 + 5672U);
    t3 = *((char **)t2);
    t6 = (0 - 1);
    t7 = (t6 * -1);
    t8 = (1U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t4 = *((unsigned char *)t2);
    t5 = (t0 + 1032U);
    t10 = *((char **)t5);
    t11 = *((unsigned char *)t10);
    t13 = ((IEEE_P_2592010699) + 4024);
    t5 = xsi_base_array_concat(t5, t12, t13, (char)99, t4, (char)99, t11, (char)101);
    t14 = (1U + 1U);
    t15 = (2U != t14);
    if (t15 == 1)
        goto LAB8;

LAB9:    t16 = (t0 + 12064);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t5, 2U);
    xsi_driver_first_trans_fast(t16);
    goto LAB2;

LAB5:    t3 = (t0 + 3552U);
    t4 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t4 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    xsi_size_not_matching(2U, t14, 0);
    goto LAB9;

}

static void work_a_2358102284_3212880686_p_7(char *t0)
{
    char t12[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned char t11;
    char *t13;
    unsigned int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 10008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(248, ng0);

LAB6:    t2 = (t0 + 11168);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t5 = (t0 + 11168);
    *((int *)t5) = 0;
    xsi_set_current_line(249, ng0);
    t2 = (t0 + 5832U);
    t3 = *((char **)t2);
    t6 = (0 - 1);
    t7 = (t6 * -1);
    t8 = (1U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t4 = *((unsigned char *)t2);
    t5 = (t0 + 4392U);
    t10 = *((char **)t5);
    t11 = *((unsigned char *)t10);
    t13 = ((IEEE_P_2592010699) + 4024);
    t5 = xsi_base_array_concat(t5, t12, t13, (char)99, t4, (char)99, t11, (char)101);
    t14 = (1U + 1U);
    t15 = (2U != t14);
    if (t15 == 1)
        goto LAB8;

LAB9:    t16 = (t0 + 12128);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t5, 2U);
    xsi_driver_first_trans_fast(t16);
    goto LAB2;

LAB5:    t3 = (t0 + 3552U);
    t4 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t4 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    xsi_size_not_matching(2U, t14, 0);
    goto LAB9;

}

static void work_a_2358102284_3212880686_p_8(char *t0)
{
    char t12[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    char *t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t10;
    unsigned char t11;
    char *t13;
    unsigned int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    t1 = (t0 + 10256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(254, ng0);

LAB6:    t2 = (t0 + 11184);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    t5 = (t0 + 11184);
    *((int *)t5) = 0;
    xsi_set_current_line(255, ng0);
    t2 = (t0 + 6152U);
    t3 = *((char **)t2);
    t6 = (0 - 1);
    t7 = (t6 * -1);
    t8 = (1U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t4 = *((unsigned char *)t2);
    t5 = (t0 + 2312U);
    t10 = *((char **)t5);
    t11 = *((unsigned char *)t10);
    t13 = ((IEEE_P_2592010699) + 4024);
    t5 = xsi_base_array_concat(t5, t12, t13, (char)99, t4, (char)99, t11, (char)101);
    t14 = (1U + 1U);
    t15 = (2U != t14);
    if (t15 == 1)
        goto LAB8;

LAB9:    t16 = (t0 + 12192);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t5, 2U);
    xsi_driver_first_trans_fast(t16);
    goto LAB2;

LAB5:    t3 = (t0 + 3552U);
    t4 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t3, 0U, 0U);
    if (t4 == 1)
        goto LAB4;
    else
        goto LAB6;

LAB7:    goto LAB5;

LAB8:    xsi_size_not_matching(2U, t14, 0);
    goto LAB9;

}

static void work_a_2358102284_3212880686_p_9(char *t0)
{
    char t16[16];
    char t17[16];
    char t20[16];
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    int t18;
    unsigned int t19;
    unsigned int t21;
    unsigned char t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    static char *nl0[] = {&&LAB9, &&LAB10};

LAB0:    xsi_set_current_line(263, ng0);
    t1 = (t0 + 5672U);
    t2 = *((char **)t1);
    t3 = (1 - 1);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(270, ng0);
    t1 = (t0 + 3552U);
    t7 = ieee_p_2592010699_sub_1258338084_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t7 != 0)
        goto LAB5;

LAB7:
LAB6:
LAB3:    t1 = (t0 + 11200);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(264, ng0);
    t9 = xsi_get_transient_memory(32U);
    memset(t9, 0, 32U);
    t10 = t9;
    memset(t10, (unsigned char)2, 32U);
    t11 = (t0 + 12256);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t9, 32U);
    xsi_driver_first_trans_fast(t11);
    xsi_set_current_line(265, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t9 = (t0 + 12320);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 32U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(266, ng0);
    t1 = (t0 + 12384);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((int *)t11) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(267, ng0);
    t1 = (t0 + 12448);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(268, ng0);
    t1 = (t0 + 12512);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(271, ng0);
    t2 = (t0 + 6952U);
    t9 = *((char **)t2);
    t8 = *((unsigned char *)t9);
    t2 = (char *)((nl0) + t8);
    goto **((char **)t2);

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(273, ng0);
    t10 = (t0 + 12448);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(274, ng0);
    t1 = (t0 + 3752U);
    t2 = *((char **)t1);
    t7 = *((unsigned char *)t2);
    t8 = (t7 == (unsigned char)2);
    if (t8 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(278, ng0);
    t1 = (t0 + 12512);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB12:    goto LAB8;

LAB10:    xsi_set_current_line(281, ng0);
    t1 = (t0 + 5512U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t7 = (t3 == 30);
    if (t7 != 0)
        goto LAB14;

LAB16:    xsi_set_current_line(287, ng0);
    t1 = (t0 + 5032U);
    t2 = *((char **)t1);
    t4 = (31 - 30);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t9 = (t0 + 4552U);
    t10 = *((char **)t9);
    t7 = *((unsigned char *)t10);
    t11 = ((IEEE_P_2592010699) + 4024);
    t12 = (t17 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 30;
    t13 = (t12 + 4U);
    *((int *)t13) = 0;
    t13 = (t12 + 8U);
    *((int *)t13) = -1;
    t3 = (0 - 30);
    t19 = (t3 * -1);
    t19 = (t19 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t19;
    t9 = xsi_base_array_concat(t9, t16, t11, (char)97, t1, t17, (char)99, t7, (char)101);
    t19 = (31U + 1U);
    t8 = (32U != t19);
    if (t8 == 1)
        goto LAB21;

LAB22:    t13 = (t0 + 12256);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t23 = (t15 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t9, 32U);
    xsi_driver_first_trans_fast(t13);
    xsi_set_current_line(288, ng0);
    t1 = (t0 + 5192U);
    t2 = *((char **)t1);
    t4 = (31 - 30);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t9 = (t0 + 4712U);
    t10 = *((char **)t9);
    t7 = *((unsigned char *)t10);
    t11 = ((IEEE_P_2592010699) + 4024);
    t12 = (t17 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 30;
    t13 = (t12 + 4U);
    *((int *)t13) = 0;
    t13 = (t12 + 8U);
    *((int *)t13) = -1;
    t3 = (0 - 30);
    t19 = (t3 * -1);
    t19 = (t19 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t19;
    t9 = xsi_base_array_concat(t9, t16, t11, (char)97, t1, t17, (char)99, t7, (char)101);
    t19 = (31U + 1U);
    t8 = (32U != t19);
    if (t8 == 1)
        goto LAB23;

LAB24:    t13 = (t0 + 12320);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t23 = (t15 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t9, 32U);
    xsi_driver_first_trans_fast(t13);
    xsi_set_current_line(289, ng0);
    t1 = (t0 + 5512U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t18 = (t3 + 1);
    t1 = (t0 + 12384);
    t9 = (t1 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((int *)t12) = t18;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(290, ng0);
    t1 = (t0 + 12512);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB15:    goto LAB8;

LAB11:    xsi_set_current_line(275, ng0);
    t1 = (t0 + 12384);
    t9 = (t1 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((int *)t12) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(276, ng0);
    t1 = (t0 + 12512);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB12;

LAB14:    xsi_set_current_line(282, ng0);
    t1 = (t0 + 5032U);
    t9 = *((char **)t1);
    t4 = (31 - 29);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t9 + t6);
    t10 = (t0 + 4552U);
    t11 = *((char **)t10);
    t8 = *((unsigned char *)t11);
    t12 = ((IEEE_P_2592010699) + 4024);
    t13 = (t17 + 0U);
    t14 = (t13 + 0U);
    *((int *)t14) = 29;
    t14 = (t13 + 4U);
    *((int *)t14) = 0;
    t14 = (t13 + 8U);
    *((int *)t14) = -1;
    t18 = (0 - 29);
    t19 = (t18 * -1);
    t19 = (t19 + 1);
    t14 = (t13 + 12U);
    *((unsigned int *)t14) = t19;
    t10 = xsi_base_array_concat(t10, t16, t12, (char)97, t1, t17, (char)99, t8, (char)101);
    t15 = ((IEEE_P_2592010699) + 4024);
    t14 = xsi_base_array_concat(t14, t20, t15, (char)97, t10, t16, (char)99, (unsigned char)2, (char)101);
    t19 = (30U + 1U);
    t21 = (t19 + 1U);
    t22 = (32U != t21);
    if (t22 == 1)
        goto LAB17;

LAB18:    t23 = (t0 + 12256);
    t24 = (t23 + 56U);
    t25 = *((char **)t24);
    t26 = (t25 + 56U);
    t27 = *((char **)t26);
    memcpy(t27, t14, 32U);
    xsi_driver_first_trans_fast(t23);
    xsi_set_current_line(283, ng0);
    t1 = (t0 + 5192U);
    t2 = *((char **)t1);
    t4 = (31 - 29);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t9 = (t0 + 4712U);
    t10 = *((char **)t9);
    t7 = *((unsigned char *)t10);
    t11 = ((IEEE_P_2592010699) + 4024);
    t12 = (t17 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 29;
    t13 = (t12 + 4U);
    *((int *)t13) = 0;
    t13 = (t12 + 8U);
    *((int *)t13) = -1;
    t3 = (0 - 29);
    t19 = (t3 * -1);
    t19 = (t19 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t19;
    t9 = xsi_base_array_concat(t9, t16, t11, (char)97, t1, t17, (char)99, t7, (char)101);
    t14 = ((IEEE_P_2592010699) + 4024);
    t13 = xsi_base_array_concat(t13, t20, t14, (char)97, t9, t16, (char)99, (unsigned char)2, (char)101);
    t19 = (30U + 1U);
    t21 = (t19 + 1U);
    t8 = (32U != t21);
    if (t8 == 1)
        goto LAB19;

LAB20:    t15 = (t0 + 12320);
    t23 = (t15 + 56U);
    t24 = *((char **)t23);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    memcpy(t26, t13, 32U);
    xsi_driver_first_trans_fast(t15);
    xsi_set_current_line(284, ng0);
    t1 = (t0 + 12448);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(285, ng0);
    t1 = (t0 + 12512);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB15;

LAB17:    xsi_size_not_matching(32U, t21, 0);
    goto LAB18;

LAB19:    xsi_size_not_matching(32U, t21, 0);
    goto LAB20;

LAB21:    xsi_size_not_matching(32U, t19, 0);
    goto LAB22;

LAB23:    xsi_size_not_matching(32U, t19, 0);
    goto LAB24;

}

static void work_a_2358102284_3212880686_p_10(char *t0)
{
    char t19[16];
    char t20[16];
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned char t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t21;
    char *t22;
    int t23;
    static char *nl0[] = {&&LAB9, &&LAB10, &&LAB11};

LAB0:    xsi_set_current_line(303, ng0);
    t1 = (t0 + 5672U);
    t2 = *((char **)t1);
    t3 = (1 - 1);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(313, ng0);
    t1 = (t0 + 3552U);
    t7 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t7 != 0)
        goto LAB5;

LAB7:
LAB6:
LAB3:    t1 = (t0 + 11216);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(304, ng0);
    t9 = (t0 + 12576);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)0;
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(305, ng0);
    t1 = (t0 + 12640);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(306, ng0);
    t1 = (t0 + 12704);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(307, ng0);
    t1 = (t0 + 12768);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(308, ng0);
    t1 = (t0 + 12832);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(309, ng0);
    t1 = (t0 + 12896);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(310, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t9 = (t0 + 12960);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 32U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(311, ng0);
    t1 = (t0 + 13024);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((int *)t11) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB5:    xsi_set_current_line(314, ng0);
    t2 = (t0 + 7112U);
    t9 = *((char **)t2);
    t8 = *((unsigned char *)t9);
    t2 = (char *)((nl0) + t8);
    goto **((char **)t2);

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(316, ng0);
    t10 = (t0 + 6152U);
    t11 = *((char **)t10);
    t3 = (1 - 1);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t10 = (t11 + t6);
    t14 = *((unsigned char *)t10);
    t15 = (t14 == (unsigned char)3);
    if (t15 != 0)
        goto LAB12;

LAB14:    xsi_set_current_line(331, ng0);
    t1 = (t0 + 12576);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB13:    goto LAB8;

LAB10:    xsi_set_current_line(334, ng0);
    t1 = (t0 + 12768);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(335, ng0);
    t1 = (t0 + 12896);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(336, ng0);
    t1 = (t0 + 13024);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((int *)t11) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(337, ng0);
    t1 = (t0 + 4872U);
    t2 = *((char **)t1);
    t3 = (31 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t7);
    t9 = (t0 + 12704);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t8;
    xsi_driver_first_trans_fast_port(t9);
    xsi_set_current_line(338, ng0);
    t1 = (t0 + 4872U);
    t2 = *((char **)t1);
    t3 = (31 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t7);
    t9 = (t0 + 12832);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t8;
    xsi_driver_first_trans_fast_port(t9);
    xsi_set_current_line(339, ng0);
    t1 = (t0 + 4872U);
    t2 = *((char **)t1);
    t4 = (31 - 30);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t9 = (t0 + 12960);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 31U);
    xsi_driver_first_trans_delta(t9, 0U, 31U, 0LL);
    xsi_set_current_line(340, ng0);
    t1 = (t0 + 12576);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB11:    xsi_set_current_line(342, ng0);
    t1 = (t0 + 5992U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t7 = (t3 <= 30);
    if (t7 != 0)
        goto LAB22;

LAB24:    xsi_set_current_line(349, ng0);
    t1 = (t0 + 12704);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(350, ng0);
    t1 = (t0 + 12832);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(351, ng0);
    t1 = (t0 + 12640);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(352, ng0);
    t1 = (t0 + 12576);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB23:    goto LAB8;

LAB12:    xsi_set_current_line(317, ng0);
    t12 = (t0 + 12640);
    t13 = (t12 + 56U);
    t16 = *((char **)t13);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    *((unsigned char *)t18) = (unsigned char)3;
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(318, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t3 = (31 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB15;

LAB17:    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t3 = (30 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = (t7 == (unsigned char)3);
    if (t8 != 0)
        goto LAB18;

LAB19:    xsi_set_current_line(325, ng0);
    t1 = (t0 + 12768);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(326, ng0);
    t1 = (t0 + 12896);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB16:    xsi_set_current_line(328, ng0);
    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 19468U);
    t9 = (t0 + 19817);
    t11 = (t20 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 0;
    t12 = (t11 + 4U);
    *((int *)t12) = 31;
    t12 = (t11 + 8U);
    *((int *)t12) = 1;
    t3 = (31 - 0);
    t4 = (t3 * 1);
    t4 = (t4 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t4;
    t12 = ieee_p_2592010699_sub_1735675855_503743352(IEEE_P_2592010699, t19, t2, t1, t9, t20);
    t13 = (t19 + 12U);
    t4 = *((unsigned int *)t13);
    t5 = (1U * t4);
    t7 = (32U != t5);
    if (t7 == 1)
        goto LAB20;

LAB21:    t16 = (t0 + 12960);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t21 = (t18 + 56U);
    t22 = *((char **)t21);
    memcpy(t22, t12, 32U);
    xsi_driver_first_trans_fast(t16);
    xsi_set_current_line(329, ng0);
    t1 = (t0 + 12576);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB13;

LAB15:    xsi_set_current_line(319, ng0);
    t9 = (t0 + 12768);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t9);
    xsi_set_current_line(320, ng0);
    t1 = (t0 + 12896);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB16;

LAB18:    xsi_set_current_line(322, ng0);
    t9 = (t0 + 12768);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t9);
    xsi_set_current_line(323, ng0);
    t1 = (t0 + 12896);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB16;

LAB20:    xsi_size_not_matching(32U, t5, 0);
    goto LAB21;

LAB22:    xsi_set_current_line(343, ng0);
    t1 = (t0 + 4872U);
    t9 = *((char **)t1);
    t23 = (31 - 31);
    t4 = (t23 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t9 + t6);
    t8 = *((unsigned char *)t1);
    t14 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t8);
    t10 = (t0 + 12704);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t16 = *((char **)t13);
    *((unsigned char *)t16) = t14;
    xsi_driver_first_trans_fast_port(t10);
    xsi_set_current_line(344, ng0);
    t1 = (t0 + 4872U);
    t2 = *((char **)t1);
    t3 = (31 - 31);
    t4 = (t3 * -1);
    t5 = (1U * t4);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = *((unsigned char *)t1);
    t8 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t7);
    t9 = (t0 + 12832);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t8;
    xsi_driver_first_trans_fast_port(t9);
    xsi_set_current_line(345, ng0);
    t1 = (t0 + 4872U);
    t2 = *((char **)t1);
    t4 = (31 - 30);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t9 = (t0 + 12960);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 31U);
    xsi_driver_first_trans_delta(t9, 0U, 31U, 0LL);
    xsi_set_current_line(346, ng0);
    t1 = (t0 + 5992U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t23 = (t3 + 1);
    t1 = (t0 + 13024);
    t9 = (t1 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((int *)t12) = t23;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(347, ng0);
    t1 = (t0 + 12576);
    t2 = (t1 + 56U);
    t9 = *((char **)t2);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB23;

}


extern void work_a_2358102284_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2358102284_3212880686_p_0,(void *)work_a_2358102284_3212880686_p_1,(void *)work_a_2358102284_3212880686_p_2,(void *)work_a_2358102284_3212880686_p_3,(void *)work_a_2358102284_3212880686_p_4,(void *)work_a_2358102284_3212880686_p_5,(void *)work_a_2358102284_3212880686_p_6,(void *)work_a_2358102284_3212880686_p_7,(void *)work_a_2358102284_3212880686_p_8,(void *)work_a_2358102284_3212880686_p_9,(void *)work_a_2358102284_3212880686_p_10};
	xsi_register_didat("work_a_2358102284_3212880686", "isim/ADCTestbench_isim_beh.exe.sim/work/a_2358102284_3212880686.didat");
	xsi_register_executes(pe);
}
