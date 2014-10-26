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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestFreqD/BatFreqDiv.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
unsigned char ieee_p_1242562249_sub_2720078402_1035706684(char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_3481121704_1035706684(char *, char *, char *, char *);
unsigned char ieee_p_1242562249_sub_4081755647_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1308162848_3212880686_p_0(char *t0)
{
    char t5[16];
    char t8[16];
    char *t1;
    char *t2;
    char *t4;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    xsi_set_current_line(191, ng0);

LAB3:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 20028);
    t6 = ((IEEE_P_2592010699) + 4024);
    t7 = (t0 + 19076U);
    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 7;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t11 = (7 - 0);
    t12 = (t11 * 1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    t4 = xsi_base_array_concat(t4, t5, t6, (char)97, t2, t7, (char)97, t1, t8, (char)101);
    t10 = (t0 + 10840);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 24U);
    xsi_driver_first_trans_fast(t10);

LAB2:    t17 = (t0 + 10648);
    *((int *)t17) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1308162848_3212880686_p_1(char *t0)
{
    char t11[16];
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
    char *t12;
    char *t13;
    char *t14;
    int t15;
    unsigned char t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    int t21;

LAB0:    xsi_set_current_line(198, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10664);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(200, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(208, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(201, ng0);
    t3 = (t0 + 10904);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(202, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 10968);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(203, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11032);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(204, ng0);
    t1 = (t0 + 11096);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(205, ng0);
    t1 = (t0 + 11160);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(209, ng0);
    t1 = (t0 + 1672U);
    t4 = *((char **)t1);
    t1 = (t0 + 19092U);
    t7 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t11, 0, 24);
    t6 = ieee_p_1242562249_sub_4081755647_1035706684(IEEE_P_1242562249, t4, t1, t7, t11);
    if (t6 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(215, ng0);
    t1 = (t0 + 5352U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB17;

LAB19:
LAB18:
LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(210, ng0);
    t8 = (t0 + 11096);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(211, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t1 = (t0 + 19092U);
    t4 = (t0 + 5032U);
    t7 = *((char **)t4);
    t4 = (t0 + 19348U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB14;

LAB16:
LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(212, ng0);
    t8 = (t0 + 1672U);
    t9 = *((char **)t8);
    t8 = (t0 + 11032);
    t10 = (t8 + 56U);
    t12 = *((char **)t10);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t9, 24U);
    xsi_driver_first_trans_fast(t8);
    goto LAB15;

LAB17:    xsi_set_current_line(216, ng0);
    t1 = (t0 + 11096);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(217, ng0);
    t1 = (t0 + 5032U);
    t3 = *((char **)t1);
    t1 = (t0 + 19348U);
    t4 = (t0 + 2632U);
    t7 = *((char **)t4);
    t4 = (t0 + 19188U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB20;

LAB22:    xsi_set_current_line(231, ng0);
    t1 = (t0 + 11160);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(232, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11032);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB21:    goto LAB18;

LAB20:    xsi_set_current_line(218, ng0);
    t8 = (t0 + 5672U);
    t9 = *((char **)t8);
    t15 = *((int *)t9);
    t5 = (t15 >= 4);
    if (t5 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(228, ng0);
    t1 = (t0 + 5672U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t21 = (t15 + 1);
    t1 = (t0 + 11160);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t21;
    xsi_driver_first_trans_fast(t1);

LAB24:    goto LAB21;

LAB23:    xsi_set_current_line(219, ng0);
    t8 = (t0 + 5992U);
    t10 = *((char **)t8);
    t6 = *((unsigned char *)t10);
    t16 = (t6 == (unsigned char)3);
    if (t16 != 0)
        goto LAB26;

LAB28:    xsi_set_current_line(222, ng0);
    t1 = (t0 + 5032U);
    t3 = *((char **)t1);
    t1 = (t0 + 19348U);
    t4 = ieee_p_1242562249_sub_3481121704_1035706684(IEEE_P_1242562249, t11, t3, t1);
    t7 = (t11 + 12U);
    t19 = *((unsigned int *)t7);
    t20 = (1U * t19);
    t2 = (24U != t20);
    if (t2 == 1)
        goto LAB29;

LAB30:    t8 = (t0 + 10968);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t4, 24U);
    xsi_driver_first_trans_fast(t8);

LAB27:    xsi_set_current_line(224, ng0);
    t1 = (t0 + 5992U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t2);
    t1 = (t0 + 10904);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t5;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(225, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11032);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(226, ng0);
    t1 = (t0 + 11160);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB24;

LAB26:    xsi_set_current_line(220, ng0);
    t8 = (t0 + 5032U);
    t12 = *((char **)t8);
    t8 = (t0 + 10968);
    t13 = (t8 + 56U);
    t14 = *((char **)t13);
    t17 = (t14 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t12, 24U);
    xsi_driver_first_trans_fast(t8);
    goto LAB27;

LAB29:    xsi_size_not_matching(24U, t20, 0);
    goto LAB30;

}

static void work_a_1308162848_3212880686_p_2(char *t0)
{
    char t11[16];
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
    char *t12;
    char *t13;
    char *t14;
    int t15;
    unsigned char t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    int t21;

LAB0:    xsi_set_current_line(246, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10680);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(248, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(256, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(249, ng0);
    t3 = (t0 + 11224);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(250, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11288);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(251, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11352);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(252, ng0);
    t1 = (t0 + 11416);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(253, ng0);
    t1 = (t0 + 11480);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(257, ng0);
    t1 = (t0 + 1832U);
    t4 = *((char **)t1);
    t1 = (t0 + 19108U);
    t7 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t11, 0, 24);
    t6 = ieee_p_1242562249_sub_4081755647_1035706684(IEEE_P_1242562249, t4, t1, t7, t11);
    if (t6 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(263, ng0);
    t1 = (t0 + 5512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB17;

LAB19:
LAB18:
LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(258, ng0);
    t8 = (t0 + 11416);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(259, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t1 = (t0 + 19108U);
    t4 = (t0 + 5192U);
    t7 = *((char **)t4);
    t4 = (t0 + 19364U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB14;

LAB16:
LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(260, ng0);
    t8 = (t0 + 1832U);
    t9 = *((char **)t8);
    t8 = (t0 + 11352);
    t10 = (t8 + 56U);
    t12 = *((char **)t10);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t9, 24U);
    xsi_driver_first_trans_fast(t8);
    goto LAB15;

LAB17:    xsi_set_current_line(264, ng0);
    t1 = (t0 + 11416);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(265, ng0);
    t1 = (t0 + 5192U);
    t3 = *((char **)t1);
    t1 = (t0 + 19364U);
    t4 = (t0 + 2632U);
    t7 = *((char **)t4);
    t4 = (t0 + 19188U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB20;

LAB22:    xsi_set_current_line(279, ng0);
    t1 = (t0 + 11480);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(280, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11352);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB21:    goto LAB18;

LAB20:    xsi_set_current_line(266, ng0);
    t8 = (t0 + 5832U);
    t9 = *((char **)t8);
    t15 = *((int *)t9);
    t5 = (t15 >= 4);
    if (t5 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(276, ng0);
    t1 = (t0 + 5832U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t21 = (t15 + 1);
    t1 = (t0 + 11480);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t21;
    xsi_driver_first_trans_fast(t1);

LAB24:    goto LAB21;

LAB23:    xsi_set_current_line(267, ng0);
    t8 = (t0 + 6152U);
    t10 = *((char **)t8);
    t6 = *((unsigned char *)t10);
    t16 = (t6 == (unsigned char)3);
    if (t16 != 0)
        goto LAB26;

LAB28:    xsi_set_current_line(270, ng0);
    t1 = (t0 + 5192U);
    t3 = *((char **)t1);
    t1 = (t0 + 19364U);
    t4 = ieee_p_1242562249_sub_3481121704_1035706684(IEEE_P_1242562249, t11, t3, t1);
    t7 = (t11 + 12U);
    t19 = *((unsigned int *)t7);
    t20 = (1U * t19);
    t2 = (24U != t20);
    if (t2 == 1)
        goto LAB29;

LAB30:    t8 = (t0 + 11288);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t4, 24U);
    xsi_driver_first_trans_fast(t8);

LAB27:    xsi_set_current_line(272, ng0);
    t1 = (t0 + 6152U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t2);
    t1 = (t0 + 11224);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t5;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(273, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11352);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(274, ng0);
    t1 = (t0 + 11480);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB24;

LAB26:    xsi_set_current_line(268, ng0);
    t8 = (t0 + 5192U);
    t12 = *((char **)t8);
    t8 = (t0 + 11288);
    t13 = (t8 + 56U);
    t14 = *((char **)t13);
    t17 = (t14 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t12, 24U);
    xsi_driver_first_trans_fast(t8);
    goto LAB27;

LAB29:    xsi_size_not_matching(24U, t20, 0);
    goto LAB30;

}

static void work_a_1308162848_3212880686_p_3(char *t0)
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
    unsigned char t12;
    unsigned char t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned char t18;
    unsigned char t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    static char *nl0[] = {&&LAB9, &&LAB10, &&LAB11};

LAB0:    xsi_set_current_line(295, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10696);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(297, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(304, ng0);
    t1 = (t0 + 11544);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(305, ng0);
    t1 = (t0 + 11608);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(306, ng0);
    t1 = (t0 + 6632U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(298, ng0);
    t3 = (t0 + 11544);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(299, ng0);
    t1 = (t0 + 11608);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(300, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11672);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(301, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11736);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB6:    goto LAB3;

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(308, ng0);
    t4 = (t0 + 1512U);
    t7 = *((char **)t4);
    t11 = *((unsigned char *)t7);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 1)
        goto LAB18;

LAB19:    t6 = (unsigned char)0;

LAB20:    if (t6 == 1)
        goto LAB15;

LAB16:    t5 = (unsigned char)0;

LAB17:    if (t5 != 0)
        goto LAB12;

LAB14:    xsi_set_current_line(311, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t6 = *((unsigned char *)t3);
    t11 = (t6 == (unsigned char)3);
    if (t11 == 1)
        goto LAB33;

LAB34:    t5 = (unsigned char)0;

LAB35:    if (t5 == 1)
        goto LAB30;

LAB31:    t2 = (unsigned char)0;

LAB32:    if (t2 != 0)
        goto LAB27;

LAB29:
LAB28:    xsi_set_current_line(314, ng0);
    t1 = (t0 + 11800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB13:    goto LAB8;

LAB10:    xsi_set_current_line(317, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 11672);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(318, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t1 = (t0 + 11736);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(319, ng0);
    t1 = (t0 + 11608);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(320, ng0);
    t1 = (t0 + 11800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB11:    xsi_set_current_line(322, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t5 = *((unsigned char *)t3);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB45;

LAB46:    t2 = (unsigned char)0;

LAB47:    if (t2 != 0)
        goto LAB42;

LAB44:    xsi_set_current_line(327, ng0);
    t1 = (t0 + 11800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB43:    goto LAB8;

LAB12:    xsi_set_current_line(309, ng0);
    t16 = (t0 + 11800);
    t20 = (t16 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)1;
    xsi_driver_first_trans_fast(t16);
    goto LAB13;

LAB15:    t16 = (t0 + 4072U);
    t17 = *((char **)t16);
    t18 = *((unsigned char *)t17);
    t19 = (t18 == (unsigned char)3);
    t5 = t19;
    goto LAB17;

LAB18:    t4 = (t0 + 4392U);
    t8 = *((char **)t4);
    t4 = (t0 + 20036);
    t13 = 1;
    if (1U == 1U)
        goto LAB21;

LAB22:    t13 = 0;

LAB23:    t6 = t13;
    goto LAB20;

LAB21:    t14 = 0;

LAB24:    if (t14 < 1U)
        goto LAB25;
    else
        goto LAB23;

LAB25:    t10 = (t8 + t14);
    t15 = (t4 + t14);
    if (*((unsigned char *)t10) != *((unsigned char *)t15))
        goto LAB22;

LAB26:    t14 = (t14 + 1);
    goto LAB24;

LAB27:    xsi_set_current_line(312, ng0);
    t10 = (t0 + 11608);
    t16 = (t10 + 56U);
    t17 = *((char **)t16);
    t20 = (t17 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = (unsigned char)3;
    xsi_driver_first_trans_fast(t10);
    goto LAB28;

LAB30:    t10 = (t0 + 4072U);
    t15 = *((char **)t10);
    t13 = *((unsigned char *)t15);
    t18 = (t13 == (unsigned char)3);
    t2 = t18;
    goto LAB32;

LAB33:    t1 = (t0 + 4392U);
    t4 = *((char **)t1);
    t1 = (t0 + 20037);
    t12 = 1;
    if (1U == 1U)
        goto LAB36;

LAB37:    t12 = 0;

LAB38:    t5 = t12;
    goto LAB35;

LAB36:    t14 = 0;

LAB39:    if (t14 < 1U)
        goto LAB40;
    else
        goto LAB38;

LAB40:    t8 = (t4 + t14);
    t9 = (t1 + t14);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB37;

LAB41:    t14 = (t14 + 1);
    goto LAB39;

LAB42:    xsi_set_current_line(323, ng0);
    t10 = (t0 + 3272U);
    t15 = *((char **)t10);
    t10 = (t0 + 11672);
    t16 = (t10 + 56U);
    t17 = *((char **)t16);
    t20 = (t17 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t15, 24U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(324, ng0);
    t1 = (t0 + 11608);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(325, ng0);
    t1 = (t0 + 11800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB43;

LAB45:    t1 = (t0 + 4392U);
    t4 = *((char **)t1);
    t1 = (t0 + 20038);
    t11 = 1;
    if (1U == 1U)
        goto LAB48;

LAB49:    t11 = 0;

LAB50:    t2 = t11;
    goto LAB47;

LAB48:    t14 = 0;

LAB51:    if (t14 < 1U)
        goto LAB52;
    else
        goto LAB50;

LAB52:    t8 = (t4 + t14);
    t9 = (t1 + t14);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB49;

LAB53:    t14 = (t14 + 1);
    goto LAB51;

}

static void work_a_1308162848_3212880686_p_4(char *t0)
{
    char t49[16];
    char t51[16];
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
    char *t11;
    char *t12;
    unsigned char t13;
    unsigned char t14;
    unsigned int t15;
    char *t16;
    int t17;
    int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned char t22;
    unsigned char t23;
    char *t24;
    char *t25;
    int t26;
    int t27;
    int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    unsigned char t32;
    unsigned char t33;
    char *t34;
    char *t35;
    int t36;
    int t37;
    unsigned int t38;
    int t39;
    unsigned int t40;
    unsigned int t41;
    char *t42;
    int t43;
    int t44;
    int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t50;
    char *t52;
    char *t53;
    int t54;
    unsigned int t55;
    unsigned char t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    static char *nl0[] = {&&LAB9, &&LAB10, &&LAB11, &&LAB12, &&LAB13, &&LAB14};

LAB0:    xsi_set_current_line(340, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 10712);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(342, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(349, ng0);
    t1 = (t0 + 12056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(350, ng0);
    t1 = (t0 + 6472U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(343, ng0);
    t3 = xsi_get_transient_memory(24U);
    memset(t3, 0, 24U);
    t7 = t3;
    memset(t7, (unsigned char)2, 24U);
    t8 = (t0 + 11864);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 24U);
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(344, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 11928);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(345, ng0);
    t1 = (t0 + 11992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(346, ng0);
    t1 = (t0 + 12056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(352, ng0);
    t4 = (t0 + 3912U);
    t7 = *((char **)t4);
    t6 = *((unsigned char *)t7);
    t13 = (t6 == (unsigned char)3);
    if (t13 == 1)
        goto LAB18;

LAB19:    t5 = (unsigned char)0;

LAB20:    if (t5 != 0)
        goto LAB15;

LAB17:    xsi_set_current_line(370, ng0);
    t1 = (t0 + 11992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB16:    goto LAB8;

LAB10:    xsi_set_current_line(373, ng0);
    t1 = (t0 + 11992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB11:    xsi_set_current_line(375, ng0);
    t1 = (t0 + 3592U);
    t3 = *((char **)t1);
    t1 = (t0 + 12184);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(376, ng0);
    t1 = (t0 + 11992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB12:    xsi_set_current_line(378, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB123;

LAB125:    xsi_set_current_line(395, ng0);
    t1 = (t0 + 11992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);

LAB124:    goto LAB8;

LAB13:    xsi_set_current_line(398, ng0);
    t1 = (t0 + 11992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)5;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB14:    xsi_set_current_line(400, ng0);
    t1 = (t0 + 3592U);
    t3 = *((char **)t1);
    t1 = (t0 + 11928);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(401, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t1 = (t0 + 11864);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(402, ng0);
    t1 = (t0 + 11992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB15:    xsi_set_current_line(354, ng0);
    t12 = (t0 + 3432U);
    t16 = *((char **)t12);
    if (48 > 0)
        goto LAB30;

LAB31:    if (-1 == -1)
        goto LAB35;

LAB36:    t17 = 0;

LAB32:    t18 = (t17 - 48);
    t19 = (t18 * -1);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t12 = (t16 + t21);
    t22 = *((unsigned char *)t12);
    t23 = (t22 == (unsigned char)2);
    if (t23 != 0)
        goto LAB27;

LAB29:    xsi_set_current_line(361, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    if (48 > 0)
        goto LAB83;

LAB84:    if (-1 == -1)
        goto LAB88;

LAB89:    t17 = 0;

LAB85:    t18 = (t17 - 1);
    t26 = (t18 - 48);
    t15 = (t26 * -1);
    t19 = (1U * t15);
    t20 = (0 + t19);
    t1 = (t3 + t20);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB80;

LAB82:    xsi_set_current_line(364, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    if (48 > 0)
        goto LAB109;

LAB110:    if (-1 == -1)
        goto LAB114;

LAB115:    t17 = 0;

LAB111:    t18 = (t17 - 48);
    t15 = (t18 * -1);
    t19 = (1U * t15);
    t20 = (0 + t19);
    t1 = (t3 + t20);
    t2 = *((unsigned char *)t1);
    t4 = (t0 + 3432U);
    t7 = *((char **)t4);
    if (48 > 0)
        goto LAB116;

LAB117:    if (-1 == -1)
        goto LAB121;

LAB122:    t26 = 0;

LAB118:    t27 = (t26 - 2);
    t21 = (48 - t27);
    t29 = (t21 * 1U);
    t30 = (0 + t29);
    t4 = (t7 + t30);
    t9 = ((IEEE_P_2592010699) + 4024);
    t10 = (t51 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 46;
    t11 = (t10 + 4U);
    *((int *)t11) = 0;
    t11 = (t10 + 8U);
    *((int *)t11) = -1;
    t28 = (0 - 46);
    t31 = (t28 * -1);
    t31 = (t31 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t31;
    t8 = xsi_base_array_concat(t8, t49, t9, (char)99, t2, (char)97, t4, t51, (char)101);
    t11 = (t0 + 12120);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t8, 48U);
    xsi_driver_first_trans_fast(t11);

LAB81:
LAB28:    xsi_set_current_line(367, ng0);
    t1 = (t0 + 12056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(368, ng0);
    t1 = (t0 + 11992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB16;

LAB18:    t4 = (t0 + 4552U);
    t8 = *((char **)t4);
    t4 = (t0 + 20039);
    t14 = 1;
    if (1U == 1U)
        goto LAB21;

LAB22:    t14 = 0;

LAB23:    t5 = t14;
    goto LAB20;

LAB21:    t15 = 0;

LAB24:    if (t15 < 1U)
        goto LAB25;
    else
        goto LAB23;

LAB25:    t10 = (t8 + t15);
    t11 = (t4 + t15);
    if (*((unsigned char *)t10) != *((unsigned char *)t11))
        goto LAB22;

LAB26:    t15 = (t15 + 1);
    goto LAB24;

LAB27:    xsi_set_current_line(355, ng0);
    t24 = (t0 + 3432U);
    t25 = *((char **)t24);
    if (48 > 0)
        goto LAB40;

LAB41:    if (-1 == -1)
        goto LAB45;

LAB46:    t26 = 0;

LAB42:    t27 = (t26 - 1);
    t28 = (t27 - 48);
    t29 = (t28 * -1);
    t30 = (1U * t29);
    t31 = (0 + t30);
    t24 = (t25 + t31);
    t32 = *((unsigned char *)t24);
    t33 = (t32 == (unsigned char)3);
    if (t33 != 0)
        goto LAB37;

LAB39:    xsi_set_current_line(358, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    if (48 > 0)
        goto LAB66;

LAB67:    if (-1 == -1)
        goto LAB71;

LAB72:    t17 = 0;

LAB68:    t18 = (t17 - 48);
    t15 = (t18 * -1);
    t19 = (1U * t15);
    t20 = (0 + t19);
    t1 = (t3 + t20);
    t2 = *((unsigned char *)t1);
    t4 = (t0 + 3432U);
    t7 = *((char **)t4);
    if (48 > 0)
        goto LAB73;

LAB74:    if (-1 == -1)
        goto LAB78;

LAB79:    t26 = 0;

LAB75:    t27 = (t26 - 2);
    t21 = (48 - t27);
    t29 = (t21 * 1U);
    t30 = (0 + t29);
    t4 = (t7 + t30);
    t9 = ((IEEE_P_2592010699) + 4024);
    t10 = (t51 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 46;
    t11 = (t10 + 4U);
    *((int *)t11) = 0;
    t11 = (t10 + 8U);
    *((int *)t11) = -1;
    t28 = (0 - 46);
    t31 = (t28 * -1);
    t31 = (t31 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t31;
    t8 = xsi_base_array_concat(t8, t49, t9, (char)99, t2, (char)97, t4, t51, (char)101);
    t11 = (t0 + 12120);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t8, 48U);
    xsi_driver_first_trans_fast(t11);

LAB38:    goto LAB28;

LAB30:    if (-1 == 1)
        goto LAB33;

LAB34:    t17 = 48;
    goto LAB32;

LAB33:    t17 = 0;
    goto LAB32;

LAB35:    t17 = 48;
    goto LAB32;

LAB37:    xsi_set_current_line(356, ng0);
    t34 = xsi_get_transient_memory(47U);
    memset(t34, 0, 47U);
    t35 = t34;
    if (47 > 0)
        goto LAB47;

LAB48:    if (-1 == -1)
        goto LAB52;

LAB53:    t36 = 0;

LAB49:    t37 = (t36 - 1);
    if (-1 == 1)
        goto LAB54;

LAB55:    t38 = 0;

LAB56:    t39 = (t38 - 0);
    t40 = (t39 * 1);
    t41 = (1U * t40);
    t42 = (t35 + t41);
    if (47 > 0)
        goto LAB57;

LAB58:    if (-1 == -1)
        goto LAB62;

LAB63:    t43 = 0;

LAB59:    t44 = (t43 - 1);
    t45 = (0 - t44);
    t46 = (t45 * -1);
    t46 = (t46 + 1);
    t47 = (1U * t46);
    memset(t42, (unsigned char)3, t47);
    t50 = ((IEEE_P_1242562249) + 3112);
    t52 = (t51 + 0U);
    t53 = (t52 + 0U);
    *((int *)t53) = 0;
    t53 = (t52 + 4U);
    *((int *)t53) = 46;
    t53 = (t52 + 8U);
    *((int *)t53) = 1;
    t54 = (46 - 0);
    t55 = (t54 * 1);
    t55 = (t55 + 1);
    t53 = (t52 + 12U);
    *((unsigned int *)t53) = t55;
    t48 = xsi_base_array_concat(t48, t49, t50, (char)99, (unsigned char)2, (char)97, t34, t51, (char)101);
    t55 = (1U + 47U);
    t56 = (48U != t55);
    if (t56 == 1)
        goto LAB64;

LAB65:    t53 = (t0 + 12120);
    t57 = (t53 + 56U);
    t58 = *((char **)t57);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    memcpy(t60, t48, 48U);
    xsi_driver_first_trans_fast(t53);
    goto LAB38;

LAB40:    if (-1 == 1)
        goto LAB43;

LAB44:    t26 = 48;
    goto LAB42;

LAB43:    t26 = 0;
    goto LAB42;

LAB45:    t26 = 48;
    goto LAB42;

LAB47:    if (-1 == 1)
        goto LAB50;

LAB51:    t36 = 47;
    goto LAB49;

LAB50:    t36 = 0;
    goto LAB49;

LAB52:    t36 = 47;
    goto LAB49;

LAB54:    t38 = t37;
    goto LAB56;

LAB57:    if (-1 == 1)
        goto LAB60;

LAB61:    t43 = 47;
    goto LAB59;

LAB60:    t43 = 0;
    goto LAB59;

LAB62:    t43 = 47;
    goto LAB59;

LAB64:    xsi_size_not_matching(48U, t55, 0);
    goto LAB65;

LAB66:    if (-1 == 1)
        goto LAB69;

LAB70:    t17 = 48;
    goto LAB68;

LAB69:    t17 = 0;
    goto LAB68;

LAB71:    t17 = 48;
    goto LAB68;

LAB73:    if (-1 == 1)
        goto LAB76;

LAB77:    t26 = 48;
    goto LAB75;

LAB76:    t26 = 0;
    goto LAB75;

LAB78:    t26 = 48;
    goto LAB75;

LAB80:    xsi_set_current_line(362, ng0);
    t4 = xsi_get_transient_memory(47U);
    memset(t4, 0, 47U);
    t7 = t4;
    if (47 > 0)
        goto LAB90;

LAB91:    if (-1 == -1)
        goto LAB95;

LAB96:    t27 = 0;

LAB92:    t28 = (t27 - 1);
    if (-1 == 1)
        goto LAB97;

LAB98:    t21 = 0;

LAB99:    t36 = (t21 - 0);
    t29 = (t36 * 1);
    t30 = (1U * t29);
    t8 = (t7 + t30);
    if (47 > 0)
        goto LAB100;

LAB101:    if (-1 == -1)
        goto LAB105;

LAB106:    t37 = 0;

LAB102:    t39 = (t37 - 1);
    t43 = (0 - t39);
    t31 = (t43 * -1);
    t31 = (t31 + 1);
    t38 = (1U * t31);
    memset(t8, (unsigned char)2, t38);
    t10 = ((IEEE_P_1242562249) + 3112);
    t11 = (t51 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 0;
    t12 = (t11 + 4U);
    *((int *)t12) = 46;
    t12 = (t11 + 8U);
    *((int *)t12) = 1;
    t44 = (46 - 0);
    t40 = (t44 * 1);
    t40 = (t40 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t40;
    t9 = xsi_base_array_concat(t9, t49, t10, (char)99, (unsigned char)3, (char)97, t4, t51, (char)101);
    t40 = (1U + 47U);
    t6 = (48U != t40);
    if (t6 == 1)
        goto LAB107;

LAB108:    t12 = (t0 + 12120);
    t16 = (t12 + 56U);
    t24 = *((char **)t16);
    t25 = (t24 + 56U);
    t34 = *((char **)t25);
    memcpy(t34, t9, 48U);
    xsi_driver_first_trans_fast(t12);
    goto LAB81;

LAB83:    if (-1 == 1)
        goto LAB86;

LAB87:    t17 = 48;
    goto LAB85;

LAB86:    t17 = 0;
    goto LAB85;

LAB88:    t17 = 48;
    goto LAB85;

LAB90:    if (-1 == 1)
        goto LAB93;

LAB94:    t27 = 47;
    goto LAB92;

LAB93:    t27 = 0;
    goto LAB92;

LAB95:    t27 = 47;
    goto LAB92;

LAB97:    t21 = t28;
    goto LAB99;

LAB100:    if (-1 == 1)
        goto LAB103;

LAB104:    t37 = 47;
    goto LAB102;

LAB103:    t37 = 0;
    goto LAB102;

LAB105:    t37 = 47;
    goto LAB102;

LAB107:    xsi_size_not_matching(48U, t40, 0);
    goto LAB108;

LAB109:    if (-1 == 1)
        goto LAB112;

LAB113:    t17 = 48;
    goto LAB111;

LAB112:    t17 = 0;
    goto LAB111;

LAB114:    t17 = 48;
    goto LAB111;

LAB116:    if (-1 == 1)
        goto LAB119;

LAB120:    t26 = 48;
    goto LAB118;

LAB119:    t26 = 0;
    goto LAB118;

LAB121:    t26 = 48;
    goto LAB118;

LAB123:    xsi_set_current_line(379, ng0);
    t1 = (t0 + 3432U);
    t4 = *((char **)t1);
    if (48 > 0)
        goto LAB129;

LAB130:    if (-1 == -1)
        goto LAB134;

LAB135:    t17 = 0;

LAB131:    t18 = (t17 - 48);
    t15 = (t18 * -1);
    t19 = (1U * t15);
    t20 = (0 + t19);
    t1 = (t4 + t20);
    t6 = *((unsigned char *)t1);
    t13 = (t6 == (unsigned char)2);
    if (t13 != 0)
        goto LAB126;

LAB128:    xsi_set_current_line(386, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    if (48 > 0)
        goto LAB182;

LAB183:    if (-1 == -1)
        goto LAB187;

LAB188:    t17 = 0;

LAB184:    t18 = (t17 - 1);
    t26 = (t18 - 48);
    t15 = (t26 * -1);
    t19 = (1U * t15);
    t20 = (0 + t19);
    t1 = (t3 + t20);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB179;

LAB181:    xsi_set_current_line(389, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    if (48 > 0)
        goto LAB208;

LAB209:    if (-1 == -1)
        goto LAB213;

LAB214:    t17 = 0;

LAB210:    t18 = (t17 - 48);
    t15 = (t18 * -1);
    t19 = (1U * t15);
    t20 = (0 + t19);
    t1 = (t3 + t20);
    t2 = *((unsigned char *)t1);
    t4 = (t0 + 3432U);
    t7 = *((char **)t4);
    if (48 > 0)
        goto LAB215;

LAB216:    if (-1 == -1)
        goto LAB220;

LAB221:    t26 = 0;

LAB217:    t27 = (t26 - 2);
    t21 = (48 - t27);
    t29 = (t21 * 1U);
    t30 = (0 + t29);
    t4 = (t7 + t30);
    t9 = ((IEEE_P_2592010699) + 4024);
    t10 = (t51 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 46;
    t11 = (t10 + 4U);
    *((int *)t11) = 0;
    t11 = (t10 + 8U);
    *((int *)t11) = -1;
    t28 = (0 - 46);
    t31 = (t28 * -1);
    t31 = (t31 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t31;
    t8 = xsi_base_array_concat(t8, t49, t9, (char)99, t2, (char)97, t4, t51, (char)101);
    t11 = (t0 + 12120);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t8, 48U);
    xsi_driver_first_trans_fast(t11);

LAB180:
LAB127:    xsi_set_current_line(392, ng0);
    t1 = (t0 + 12056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(393, ng0);
    t1 = (t0 + 11992);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    goto LAB124;

LAB126:    xsi_set_current_line(380, ng0);
    t7 = (t0 + 3432U);
    t8 = *((char **)t7);
    if (48 > 0)
        goto LAB139;

LAB140:    if (-1 == -1)
        goto LAB144;

LAB145:    t26 = 0;

LAB141:    t27 = (t26 - 1);
    t28 = (t27 - 48);
    t21 = (t28 * -1);
    t29 = (1U * t21);
    t30 = (0 + t29);
    t7 = (t8 + t30);
    t14 = *((unsigned char *)t7);
    t22 = (t14 == (unsigned char)3);
    if (t22 != 0)
        goto LAB136;

LAB138:    xsi_set_current_line(383, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    if (48 > 0)
        goto LAB165;

LAB166:    if (-1 == -1)
        goto LAB170;

LAB171:    t17 = 0;

LAB167:    t18 = (t17 - 48);
    t15 = (t18 * -1);
    t19 = (1U * t15);
    t20 = (0 + t19);
    t1 = (t3 + t20);
    t2 = *((unsigned char *)t1);
    t4 = (t0 + 3432U);
    t7 = *((char **)t4);
    if (48 > 0)
        goto LAB172;

LAB173:    if (-1 == -1)
        goto LAB177;

LAB178:    t26 = 0;

LAB174:    t27 = (t26 - 2);
    t21 = (48 - t27);
    t29 = (t21 * 1U);
    t30 = (0 + t29);
    t4 = (t7 + t30);
    t9 = ((IEEE_P_2592010699) + 4024);
    t10 = (t51 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 46;
    t11 = (t10 + 4U);
    *((int *)t11) = 0;
    t11 = (t10 + 8U);
    *((int *)t11) = -1;
    t28 = (0 - 46);
    t31 = (t28 * -1);
    t31 = (t31 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t31;
    t8 = xsi_base_array_concat(t8, t49, t9, (char)99, t2, (char)97, t4, t51, (char)101);
    t11 = (t0 + 12120);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t8, 48U);
    xsi_driver_first_trans_fast(t11);

LAB137:    goto LAB127;

LAB129:    if (-1 == 1)
        goto LAB132;

LAB133:    t17 = 48;
    goto LAB131;

LAB132:    t17 = 0;
    goto LAB131;

LAB134:    t17 = 48;
    goto LAB131;

LAB136:    xsi_set_current_line(381, ng0);
    t9 = xsi_get_transient_memory(47U);
    memset(t9, 0, 47U);
    t10 = t9;
    if (47 > 0)
        goto LAB146;

LAB147:    if (-1 == -1)
        goto LAB151;

LAB152:    t36 = 0;

LAB148:    t37 = (t36 - 1);
    if (-1 == 1)
        goto LAB153;

LAB154:    t31 = 0;

LAB155:    t39 = (t31 - 0);
    t38 = (t39 * 1);
    t40 = (1U * t38);
    t11 = (t10 + t40);
    if (47 > 0)
        goto LAB156;

LAB157:    if (-1 == -1)
        goto LAB161;

LAB162:    t43 = 0;

LAB158:    t44 = (t43 - 1);
    t45 = (0 - t44);
    t41 = (t45 * -1);
    t41 = (t41 + 1);
    t46 = (1U * t41);
    memset(t11, (unsigned char)3, t46);
    t16 = ((IEEE_P_1242562249) + 3112);
    t24 = (t51 + 0U);
    t25 = (t24 + 0U);
    *((int *)t25) = 0;
    t25 = (t24 + 4U);
    *((int *)t25) = 46;
    t25 = (t24 + 8U);
    *((int *)t25) = 1;
    t54 = (46 - 0);
    t47 = (t54 * 1);
    t47 = (t47 + 1);
    t25 = (t24 + 12U);
    *((unsigned int *)t25) = t47;
    t12 = xsi_base_array_concat(t12, t49, t16, (char)99, (unsigned char)2, (char)97, t9, t51, (char)101);
    t47 = (1U + 47U);
    t23 = (48U != t47);
    if (t23 == 1)
        goto LAB163;

LAB164:    t25 = (t0 + 12120);
    t34 = (t25 + 56U);
    t35 = *((char **)t34);
    t42 = (t35 + 56U);
    t48 = *((char **)t42);
    memcpy(t48, t12, 48U);
    xsi_driver_first_trans_fast(t25);
    goto LAB137;

LAB139:    if (-1 == 1)
        goto LAB142;

LAB143:    t26 = 48;
    goto LAB141;

LAB142:    t26 = 0;
    goto LAB141;

LAB144:    t26 = 48;
    goto LAB141;

LAB146:    if (-1 == 1)
        goto LAB149;

LAB150:    t36 = 47;
    goto LAB148;

LAB149:    t36 = 0;
    goto LAB148;

LAB151:    t36 = 47;
    goto LAB148;

LAB153:    t31 = t37;
    goto LAB155;

LAB156:    if (-1 == 1)
        goto LAB159;

LAB160:    t43 = 47;
    goto LAB158;

LAB159:    t43 = 0;
    goto LAB158;

LAB161:    t43 = 47;
    goto LAB158;

LAB163:    xsi_size_not_matching(48U, t47, 0);
    goto LAB164;

LAB165:    if (-1 == 1)
        goto LAB168;

LAB169:    t17 = 48;
    goto LAB167;

LAB168:    t17 = 0;
    goto LAB167;

LAB170:    t17 = 48;
    goto LAB167;

LAB172:    if (-1 == 1)
        goto LAB175;

LAB176:    t26 = 48;
    goto LAB174;

LAB175:    t26 = 0;
    goto LAB174;

LAB177:    t26 = 48;
    goto LAB174;

LAB179:    xsi_set_current_line(387, ng0);
    t4 = xsi_get_transient_memory(47U);
    memset(t4, 0, 47U);
    t7 = t4;
    if (47 > 0)
        goto LAB189;

LAB190:    if (-1 == -1)
        goto LAB194;

LAB195:    t27 = 0;

LAB191:    t28 = (t27 - 1);
    if (-1 == 1)
        goto LAB196;

LAB197:    t21 = 0;

LAB198:    t36 = (t21 - 0);
    t29 = (t36 * 1);
    t30 = (1U * t29);
    t8 = (t7 + t30);
    if (47 > 0)
        goto LAB199;

LAB200:    if (-1 == -1)
        goto LAB204;

LAB205:    t37 = 0;

LAB201:    t39 = (t37 - 1);
    t43 = (0 - t39);
    t31 = (t43 * -1);
    t31 = (t31 + 1);
    t38 = (1U * t31);
    memset(t8, (unsigned char)2, t38);
    t10 = ((IEEE_P_1242562249) + 3112);
    t11 = (t51 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 0;
    t12 = (t11 + 4U);
    *((int *)t12) = 46;
    t12 = (t11 + 8U);
    *((int *)t12) = 1;
    t44 = (46 - 0);
    t40 = (t44 * 1);
    t40 = (t40 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t40;
    t9 = xsi_base_array_concat(t9, t49, t10, (char)99, (unsigned char)3, (char)97, t4, t51, (char)101);
    t40 = (1U + 47U);
    t6 = (48U != t40);
    if (t6 == 1)
        goto LAB206;

LAB207:    t12 = (t0 + 12120);
    t16 = (t12 + 56U);
    t24 = *((char **)t16);
    t25 = (t24 + 56U);
    t34 = *((char **)t25);
    memcpy(t34, t9, 48U);
    xsi_driver_first_trans_fast(t12);
    goto LAB180;

LAB182:    if (-1 == 1)
        goto LAB185;

LAB186:    t17 = 48;
    goto LAB184;

LAB185:    t17 = 0;
    goto LAB184;

LAB187:    t17 = 48;
    goto LAB184;

LAB189:    if (-1 == 1)
        goto LAB192;

LAB193:    t27 = 47;
    goto LAB191;

LAB192:    t27 = 0;
    goto LAB191;

LAB194:    t27 = 47;
    goto LAB191;

LAB196:    t21 = t28;
    goto LAB198;

LAB199:    if (-1 == 1)
        goto LAB202;

LAB203:    t37 = 47;
    goto LAB201;

LAB202:    t37 = 0;
    goto LAB201;

LAB204:    t37 = 47;
    goto LAB201;

LAB206:    xsi_size_not_matching(48U, t40, 0);
    goto LAB207;

LAB208:    if (-1 == 1)
        goto LAB211;

LAB212:    t17 = 48;
    goto LAB210;

LAB211:    t17 = 0;
    goto LAB210;

LAB213:    t17 = 48;
    goto LAB210;

LAB215:    if (-1 == 1)
        goto LAB218;

LAB219:    t26 = 48;
    goto LAB217;

LAB218:    t26 = 0;
    goto LAB217;

LAB220:    t26 = 48;
    goto LAB217;

}

static void work_a_1308162848_3212880686_p_5(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(166, ng0);

LAB3:    t1 = (t0 + 3112U);
    t2 = *((char **)t1);
    t1 = (t0 + 12248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 24U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 10728);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1308162848_3212880686_p_6(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(182, ng0);

LAB3:    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = (48U - 24U);
    t4 = (31 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 12312);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 25U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 10744);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1308162848_3212880686_p_7(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(183, ng0);

LAB3:    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = (48U - 24U);
    t4 = (31 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 12376);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 25U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 10760);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_1308162848_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1308162848_3212880686_p_0,(void *)work_a_1308162848_3212880686_p_1,(void *)work_a_1308162848_3212880686_p_2,(void *)work_a_1308162848_3212880686_p_3,(void *)work_a_1308162848_3212880686_p_4,(void *)work_a_1308162848_3212880686_p_5,(void *)work_a_1308162848_3212880686_p_6,(void *)work_a_1308162848_3212880686_p_7};
	xsi_register_didat("work_a_1308162848_3212880686", "isim/TestFreqD_bench_isim_beh.exe.sim/work/a_1308162848_3212880686.didat");
	xsi_register_executes(pe);
}
