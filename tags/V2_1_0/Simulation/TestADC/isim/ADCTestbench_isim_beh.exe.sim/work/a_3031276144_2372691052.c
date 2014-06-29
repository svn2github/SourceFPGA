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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestADC/TestADC_tb.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );
unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
char *ieee_p_2592010699_sub_1735675855_503743352(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_3031276144_2372691052_p_0(char *t0)
{
    char t10[16];
    char t11[16];
    char t12[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    unsigned char t8;
    char *t9;
    int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    unsigned char t22;
    unsigned char t23;
    int t24;
    int t25;
    int t26;
    unsigned int t27;
    unsigned char t28;
    int64 t29;
    int64 t30;

LAB0:    t1 = (t0 + 6512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(130, ng0);
    t2 = (t0 + 7672);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 5288U);
    t3 = *((char **)t2);
    t7 = *((int *)t3);
    t8 = (t7 == 0);
    if (t8 != 0)
        goto LAB4;

LAB6:    xsi_set_current_line(141, ng0);
    t2 = (t0 + 7736);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 5288U);
    t3 = *((char **)t2);
    t7 = *((int *)t3);
    t22 = (t7 > 0);
    if (t22 == 1)
        goto LAB12;

LAB13:    t8 = (unsigned char)0;

LAB14:    if (t8 != 0)
        goto LAB9;

LAB11:    xsi_set_current_line(147, ng0);
    t2 = (t0 + 7800);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 7864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);

LAB10:
LAB5:    xsi_set_current_line(151, ng0);
    t2 = (t0 + 5288U);
    t3 = *((char **)t2);
    t7 = *((int *)t3);
    t13 = (t7 + 1);
    t2 = (t0 + 5288U);
    t4 = *((char **)t2);
    t2 = (t4 + 0);
    *((int *)t2) = t13;
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 5288U);
    t3 = *((char **)t2);
    t7 = *((int *)t3);
    t2 = (t0 + 5168U);
    t4 = *((char **)t2);
    t13 = *((int *)t4);
    t8 = (t7 == t13);
    if (t8 != 0)
        goto LAB15;

LAB17:
LAB16:    xsi_set_current_line(156, ng0);
    t2 = (t0 + 4808U);
    t3 = *((char **)t2);
    t29 = *((int64 *)t3);
    t30 = (t29 / 2);
    t2 = (t0 + 6320);
    xsi_process_wait(t2, t30);

LAB20:    *((char **)t1) = &&LAB21;

LAB1:    return;
LAB4:    xsi_set_current_line(134, ng0);
    t2 = (t0 + 7736);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 7800);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)4;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 7864);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)4;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(137, ng0);
    t2 = (t0 + 5408U);
    t3 = *((char **)t2);
    t7 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t11, t7, 32);
    t4 = (t0 + 13336);
    t6 = (t12 + 0U);
    t9 = (t6 + 0U);
    *((int *)t9) = 0;
    t9 = (t6 + 4U);
    *((int *)t9) = 31;
    t9 = (t6 + 8U);
    *((int *)t9) = 1;
    t13 = (31 - 0);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t9 = (t6 + 12U);
    *((unsigned int *)t9) = t14;
    t9 = ieee_p_2592010699_sub_1735675855_503743352(IEEE_P_2592010699, t10, t2, t11, t4, t12);
    t15 = (t10 + 12U);
    t14 = *((unsigned int *)t15);
    t16 = (1U * t14);
    t8 = (32U != t16);
    if (t8 == 1)
        goto LAB7;

LAB8:    t17 = (t0 + 7928);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t9, 32U);
    xsi_driver_first_trans_fast(t17);
    xsi_set_current_line(138, ng0);
    t2 = (t0 + 5408U);
    t3 = *((char **)t2);
    t7 = *((int *)t3);
    t13 = (t7 + 1);
    t2 = (t0 + 5408U);
    t4 = *((char **)t2);
    t2 = (t4 + 0);
    *((int *)t2) = t13;
    goto LAB5;

LAB7:    xsi_size_not_matching(32U, t16, 0);
    goto LAB8;

LAB9:    xsi_set_current_line(144, ng0);
    t2 = (t0 + 4232U);
    t5 = *((char **)t2);
    t2 = (t0 + 5288U);
    t6 = *((char **)t2);
    t24 = *((int *)t6);
    t25 = (32 - t24);
    t26 = (t25 - 31);
    t14 = (t26 * -1);
    xsi_vhdl_check_range_of_index(31, 0, -1, t25);
    t16 = (1U * t14);
    t27 = (0 + t16);
    t2 = (t5 + t27);
    t28 = *((unsigned char *)t2);
    t9 = (t0 + 7800);
    t15 = (t9 + 56U);
    t17 = *((char **)t15);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = t28;
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 4232U);
    t3 = *((char **)t2);
    t2 = (t0 + 5288U);
    t4 = *((char **)t2);
    t7 = *((int *)t4);
    t13 = (32 - t7);
    t24 = (t13 - 31);
    t14 = (t24 * -1);
    xsi_vhdl_check_range_of_index(31, 0, -1, t13);
    t16 = (1U * t14);
    t27 = (0 + t16);
    t2 = (t3 + t27);
    t8 = *((unsigned char *)t2);
    t22 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t8);
    t5 = (t0 + 7864);
    t6 = (t5 + 56U);
    t9 = *((char **)t6);
    t15 = (t9 + 56U);
    t17 = *((char **)t15);
    *((unsigned char *)t17) = t22;
    xsi_driver_first_trans_fast(t5);
    goto LAB10;

LAB12:    t2 = (t0 + 5288U);
    t4 = *((char **)t2);
    t13 = *((int *)t4);
    t23 = (t13 < 32);
    t8 = t23;
    goto LAB14;

LAB15:    xsi_set_current_line(153, ng0);
    t2 = (t0 + 5288U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    *((int *)t2) = 0;
    goto LAB16;

LAB18:    xsi_set_current_line(157, ng0);
    t2 = (t0 + 7672);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(158, ng0);
    t2 = (t0 + 4808U);
    t3 = *((char **)t2);
    t29 = *((int64 *)t3);
    t30 = (t29 / 2);
    t2 = (t0 + 6320);
    xsi_process_wait(t2, t30);

LAB24:    *((char **)t1) = &&LAB25;
    goto LAB1;

LAB19:    goto LAB18;

LAB21:    goto LAB19;

LAB22:    goto LAB2;

LAB23:    goto LAB22;

LAB25:    goto LAB23;

}

static void work_a_3031276144_2372691052_p_1(char *t0)
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
    unsigned char t11;
    int t12;
    int t13;
    static char *nl0[] = {&&LAB15, &&LAB16, &&LAB17};

LAB0:    xsi_set_current_line(165, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 7576);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(166, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(172, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:    xsi_set_current_line(180, ng0);
    t1 = (t0 + 4392U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(167, ng0);
    t3 = (t0 + 7992);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(168, ng0);
    t1 = (t0 + 5528U);
    t3 = *((char **)t1);
    t1 = (t3 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(169, ng0);
    t1 = (t0 + 8056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB8:    xsi_set_current_line(173, ng0);
    t1 = (t0 + 4072U);
    t4 = *((char **)t1);
    t6 = *((unsigned char *)t4);
    t11 = (t6 == (unsigned char)3);
    if (t11 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(176, ng0);
    t1 = (t0 + 7992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);

LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(174, ng0);
    t1 = (t0 + 7992);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB12;

LAB14:    goto LAB6;

LAB15:    xsi_set_current_line(182, ng0);
    t4 = (t0 + 5528U);
    t7 = *((char **)t4);
    t12 = *((int *)t7);
    t5 = (t12 == 400);
    if (t5 != 0)
        goto LAB18;

LAB20:    xsi_set_current_line(188, ng0);
    t1 = (t0 + 8056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(189, ng0);
    t1 = (t0 + 5528U);
    t3 = *((char **)t1);
    t12 = *((int *)t3);
    t13 = (t12 + 1);
    t1 = (t0 + 5528U);
    t4 = *((char **)t1);
    t1 = (t4 + 0);
    *((int *)t1) = t13;

LAB19:    goto LAB14;

LAB16:    xsi_set_current_line(192, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB21;

LAB23:    xsi_set_current_line(195, ng0);
    t1 = (t0 + 8056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB22:    goto LAB14;

LAB17:    xsi_set_current_line(198, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB24;

LAB26:    xsi_set_current_line(201, ng0);
    t1 = (t0 + 8056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB25:    goto LAB14;

LAB18:    xsi_set_current_line(183, ng0);
    t4 = (t0 + 5528U);
    t8 = *((char **)t4);
    t4 = (t8 + 0);
    *((int *)t4) = 0;
    xsi_set_current_line(184, ng0);
    t1 = (t0 + 13368);
    t4 = (t0 + 8120);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(185, ng0);
    t1 = (t0 + 7992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(186, ng0);
    t1 = (t0 + 8056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB19;

LAB21:    xsi_set_current_line(193, ng0);
    t1 = (t0 + 8056);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB22;

LAB24:    xsi_set_current_line(199, ng0);
    t1 = (t0 + 8056);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB25;

}

static void work_a_3031276144_2372691052_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 7008U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(211, ng0);
    t2 = (t0 + 8184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(212, ng0);
    t2 = (t0 + 4688U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 6816);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(213, ng0);
    t2 = (t0 + 8184);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(214, ng0);
    t2 = (t0 + 4688U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 6816);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_3031276144_2372691052_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    unsigned char t8;
    unsigned char t9;

LAB0:    t1 = (t0 + 7256U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(220, ng0);
    t2 = (t0 + 8248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(221, ng0);
    t2 = (t0 + 8312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(222, ng0);
    t7 = (500 * 1000LL);
    t2 = (t0 + 7064);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(223, ng0);
    t2 = (t0 + 8248);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(224, ng0);

LAB10:    t2 = (t0 + 7592);
    *((int *)t2) = 1;
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    t3 = (t0 + 7592);
    *((int *)t3) = 0;
    xsi_set_current_line(225, ng0);
    t2 = (t0 + 8312);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(226, ng0);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    t3 = (t0 + 2792U);
    t4 = *((char **)t3);
    t8 = *((unsigned char *)t4);
    t9 = (t8 == (unsigned char)2);
    if (t9 == 1)
        goto LAB8;
    else
        goto LAB10;

LAB11:    goto LAB9;

LAB12:    goto LAB2;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

}


extern void work_a_3031276144_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3031276144_2372691052_p_0,(void *)work_a_3031276144_2372691052_p_1,(void *)work_a_3031276144_2372691052_p_2,(void *)work_a_3031276144_2372691052_p_3};
	xsi_register_didat("work_a_3031276144_2372691052", "isim/ADCTestbench_isim_beh.exe.sim/work/a_3031276144_2372691052.didat");
	xsi_register_executes(pe);
}
