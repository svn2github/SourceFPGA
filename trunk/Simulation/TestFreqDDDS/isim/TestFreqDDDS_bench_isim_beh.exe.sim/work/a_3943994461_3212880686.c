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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestFreqDDDS/BatFreqDivDDS.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );
char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
unsigned char ieee_p_1242562249_sub_2720078402_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_1242562249_sub_4081755647_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_3943994461_3212880686_p_0(char *t0)
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

LAB0:    xsi_set_current_line(339, ng0);

LAB3:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 38862);
    t6 = ((IEEE_P_2592010699) + 4024);
    t7 = (t0 + 36916U);
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
    t10 = (t0 + 19688);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 24U);
    xsi_driver_first_trans_fast(t10);

LAB2:    t17 = (t0 + 19384);
    *((int *)t17) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3943994461_3212880686_p_1(char *t0)
{
    char t15[16];
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
    int t13;
    int t14;
    char *t16;
    int t17;
    unsigned int t18;
    unsigned char t19;

LAB0:    xsi_set_current_line(346, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 19400);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(348, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(356, ng0);
    t1 = (t0 + 20072);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(357, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(349, ng0);
    t3 = xsi_get_transient_memory(24U);
    memset(t3, 0, 24U);
    t7 = t3;
    memset(t7, (unsigned char)2, 24U);
    t8 = (t0 + 19752);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 24U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(350, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 19816);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(351, ng0);
    t1 = (t0 + 19880);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(352, ng0);
    t1 = (t0 + 19944);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(353, ng0);
    t1 = (t0 + 20008);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(358, ng0);
    t1 = (t0 + 4392U);
    t4 = *((char **)t1);
    t13 = *((int *)t4);
    t14 = (t13 + 1);
    t1 = (t0 + 20008);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = t14;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(359, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t1 = (t0 + 36932U);
    t4 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t15, 0, 24);
    t2 = ieee_p_1242562249_sub_4081755647_1035706684(IEEE_P_1242562249, t3, t1, t4, t15);
    if (t2 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(365, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB17;

LAB19:
LAB18:
LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(360, ng0);
    t7 = (t0 + 19880);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(361, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t1 = (t0 + 36932U);
    t4 = (t0 + 2792U);
    t7 = *((char **)t4);
    t4 = (t0 + 37044U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB14;

LAB16:
LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(362, ng0);
    t8 = (t0 + 1672U);
    t9 = *((char **)t8);
    t8 = (t0 + 19816);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    memcpy(t16, t9, 24U);
    xsi_driver_first_trans_fast(t8);
    goto LAB15;

LAB17:    xsi_set_current_line(366, ng0);
    t1 = (t0 + 19880);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(367, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 37044U);
    t4 = (t0 + 2632U);
    t7 = *((char **)t4);
    t4 = (t0 + 37028U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB20;

LAB22:    xsi_set_current_line(384, ng0);
    t1 = (t0 + 19944);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(385, ng0);
    t1 = (t0 + 20008);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(386, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 19816);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB21:    goto LAB18;

LAB20:    xsi_set_current_line(368, ng0);
    t8 = (t0 + 4072U);
    t9 = *((char **)t8);
    t13 = *((int *)t9);
    t5 = (t13 >= 9);
    if (t5 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(381, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t13 = *((int *)t3);
    t14 = (t13 + 1);
    t1 = (t0 + 19944);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t14;
    xsi_driver_first_trans_fast(t1);

LAB24:    goto LAB21;

LAB23:    xsi_set_current_line(369, ng0);
    t8 = (t0 + 19944);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    *((int *)t16) = 0;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(370, ng0);
    t1 = (t0 + 4392U);
    t3 = *((char **)t1);
    t13 = *((int *)t3);
    t5 = (t13 <= 65535);
    if (t5 == 1)
        goto LAB29;

LAB30:    t2 = (unsigned char)0;

LAB31:    if (t2 != 0)
        goto LAB26;

LAB28:    xsi_set_current_line(375, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 19752);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB27:    xsi_set_current_line(377, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 19816);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(378, ng0);
    t1 = (t0 + 20072);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(379, ng0);
    t1 = (t0 + 20008);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB24;

LAB26:    xsi_set_current_line(371, ng0);
    t1 = (t0 + 4392U);
    t7 = *((char **)t1);
    t17 = *((int *)t7);
    t1 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t15, t17, 18);
    t8 = (t15 + 12U);
    t18 = *((unsigned int *)t8);
    t18 = (t18 * 1U);
    t19 = (18U != t18);
    if (t19 == 1)
        goto LAB32;

LAB33:    t9 = (t0 + 20136);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    memcpy(t16, t1, 18U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(372, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 19752);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    goto LAB27;

LAB29:    t1 = (t0 + 4392U);
    t4 = *((char **)t1);
    t14 = *((int *)t4);
    t6 = (t14 >= 20);
    t2 = t6;
    goto LAB31;

LAB32:    xsi_size_not_matching(18U, t18, 0);
    goto LAB33;

}

static void work_a_3943994461_3212880686_p_2(char *t0)
{
    char t15[16];
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
    int t13;
    int t14;
    char *t16;
    int t17;
    unsigned int t18;
    unsigned char t19;

LAB0:    xsi_set_current_line(400, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 19416);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(402, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(410, ng0);
    t1 = (t0 + 20520);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(411, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(403, ng0);
    t3 = xsi_get_transient_memory(24U);
    memset(t3, 0, 24U);
    t7 = t3;
    memset(t7, (unsigned char)2, 24U);
    t8 = (t0 + 20200);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 24U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(404, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 20264);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(405, ng0);
    t1 = (t0 + 20328);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(406, ng0);
    t1 = (t0 + 20392);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(407, ng0);
    t1 = (t0 + 20456);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(412, ng0);
    t1 = (t0 + 4552U);
    t4 = *((char **)t1);
    t13 = *((int *)t4);
    t14 = (t13 + 1);
    t1 = (t0 + 20456);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = t14;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(413, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t1 = (t0 + 36948U);
    t4 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t15, 0, 24);
    t2 = ieee_p_1242562249_sub_4081755647_1035706684(IEEE_P_1242562249, t3, t1, t4, t15);
    if (t2 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(419, ng0);
    t1 = (t0 + 3912U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB17;

LAB19:
LAB18:
LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(414, ng0);
    t7 = (t0 + 20328);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(415, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t1 = (t0 + 36948U);
    t4 = (t0 + 2952U);
    t7 = *((char **)t4);
    t4 = (t0 + 37060U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB14;

LAB16:
LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(416, ng0);
    t8 = (t0 + 1832U);
    t9 = *((char **)t8);
    t8 = (t0 + 20264);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    memcpy(t16, t9, 24U);
    xsi_driver_first_trans_fast(t8);
    goto LAB15;

LAB17:    xsi_set_current_line(420, ng0);
    t1 = (t0 + 20328);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(421, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t1 = (t0 + 37060U);
    t4 = (t0 + 2632U);
    t7 = *((char **)t4);
    t4 = (t0 + 37028U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB20;

LAB22:    xsi_set_current_line(438, ng0);
    t1 = (t0 + 20392);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(439, ng0);
    t1 = (t0 + 20456);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(440, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 20264);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB21:    goto LAB18;

LAB20:    xsi_set_current_line(422, ng0);
    t8 = (t0 + 4232U);
    t9 = *((char **)t8);
    t13 = *((int *)t9);
    t5 = (t13 >= 9);
    if (t5 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(435, ng0);
    t1 = (t0 + 4232U);
    t3 = *((char **)t1);
    t13 = *((int *)t3);
    t14 = (t13 + 1);
    t1 = (t0 + 20392);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t14;
    xsi_driver_first_trans_fast(t1);

LAB24:    goto LAB21;

LAB23:    xsi_set_current_line(423, ng0);
    t8 = (t0 + 20392);
    t10 = (t8 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    *((int *)t16) = 0;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(424, ng0);
    t1 = (t0 + 4552U);
    t3 = *((char **)t1);
    t13 = *((int *)t3);
    t5 = (t13 <= 65535);
    if (t5 == 1)
        goto LAB29;

LAB30:    t2 = (unsigned char)0;

LAB31:    if (t2 != 0)
        goto LAB26;

LAB28:    xsi_set_current_line(429, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 20200);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB27:    xsi_set_current_line(431, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 20264);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(432, ng0);
    t1 = (t0 + 20520);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(433, ng0);
    t1 = (t0 + 20456);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB24;

LAB26:    xsi_set_current_line(425, ng0);
    t1 = (t0 + 4552U);
    t7 = *((char **)t1);
    t17 = *((int *)t7);
    t1 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t15, t17, 18);
    t8 = (t15 + 12U);
    t18 = *((unsigned int *)t8);
    t18 = (t18 * 1U);
    t19 = (18U != t18);
    if (t19 == 1)
        goto LAB32;

LAB33:    t9 = (t0 + 20584);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    memcpy(t16, t1, 18U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(426, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t1 = (t0 + 20200);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    goto LAB27;

LAB29:    t1 = (t0 + 4552U);
    t4 = *((char **)t1);
    t14 = *((int *)t4);
    t6 = (t14 >= 20);
    t2 = t6;
    goto LAB31;

LAB32:    xsi_size_not_matching(18U, t18, 0);
    goto LAB33;

}

static void work_a_3943994461_3212880686_p_3(char *t0)
{
    char t13[16];
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
    int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    int t18;
    static char *nl0[] = {&&LAB15, &&LAB16, &&LAB17};

LAB0:    xsi_set_current_line(454, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 19432);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(456, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(464, ng0);
    t1 = (t0 + 5032U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:    xsi_set_current_line(467, ng0);
    t1 = (t0 + 5192U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB11;

LAB13:
LAB12:    xsi_set_current_line(470, ng0);
    t1 = (t0 + 12232U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(457, ng0);
    t3 = xsi_get_transient_memory(19U);
    memset(t3, 0, 19U);
    t7 = t3;
    memset(t7, (unsigned char)2, 19U);
    t8 = (t0 + 20648);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 19U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(458, ng0);
    t1 = xsi_get_transient_memory(18U);
    memset(t1, 0, 18U);
    t3 = t1;
    memset(t3, (unsigned char)3, 18U);
    t4 = (t0 + 20712);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 18U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(459, ng0);
    t1 = (t0 + 20776);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(460, ng0);
    t1 = (t0 + 20840);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(461, ng0);
    t1 = (t0 + 20904);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(462, ng0);
    t1 = (t0 + 20968);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB8:    xsi_set_current_line(465, ng0);
    t1 = (t0 + 20840);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB9;

LAB11:    xsi_set_current_line(468, ng0);
    t1 = (t0 + 20904);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB12;

LAB14:    goto LAB6;

LAB15:    xsi_set_current_line(472, ng0);
    t4 = (t0 + 20968);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(473, ng0);
    t1 = (t0 + 6312U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB18;

LAB20:    t1 = (t0 + 6472U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB21;

LAB22:
LAB19:    goto LAB14;

LAB16:    xsi_set_current_line(485, ng0);
    t1 = (t0 + 21032);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(486, ng0);
    t1 = (t0 + 6152U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(489, ng0);
    t1 = (t0 + 20968);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB24:    goto LAB14;

LAB17:    xsi_set_current_line(492, ng0);
    t1 = (t0 + 6632U);
    t3 = *((char **)t1);
    t14 = *((int *)t3);
    t2 = (t14 >= 21);
    if (t2 != 0)
        goto LAB26;

LAB28:    xsi_set_current_line(506, ng0);
    t1 = (t0 + 6632U);
    t3 = *((char **)t1);
    t14 = *((int *)t3);
    t18 = (t14 + 1);
    t1 = (t0 + 21032);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t18;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(507, ng0);
    t1 = (t0 + 20968);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB27:    goto LAB14;

LAB18:    xsi_set_current_line(474, ng0);
    t1 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t13, 65536, 19);
    t4 = (t0 + 20648);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 19U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(475, ng0);
    t1 = (t0 + 4712U);
    t3 = *((char **)t1);
    t1 = (t0 + 20712);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 18U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(476, ng0);
    t1 = (t0 + 20776);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(477, ng0);
    t1 = (t0 + 20968);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB19;

LAB21:    xsi_set_current_line(479, ng0);
    t1 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t13, 65536, 19);
    t4 = (t0 + 20648);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 19U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(480, ng0);
    t1 = (t0 + 4872U);
    t3 = *((char **)t1);
    t1 = (t0 + 20712);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 18U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(481, ng0);
    t1 = (t0 + 20776);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(482, ng0);
    t1 = (t0 + 20968);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB19;

LAB23:    xsi_set_current_line(487, ng0);
    t1 = (t0 + 20968);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB24;

LAB26:    xsi_set_current_line(493, ng0);
    t1 = (t0 + 6312U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB29;

LAB31:    t1 = (t0 + 6472U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB32;

LAB33:
LAB30:    xsi_set_current_line(504, ng0);
    t1 = (t0 + 20968);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB27;

LAB29:    xsi_set_current_line(494, ng0);
    t1 = (t0 + 5672U);
    t7 = *((char **)t1);
    t15 = (18 - 15);
    t16 = (t15 * 1U);
    t17 = (0 + t16);
    t1 = (t7 + t17);
    t8 = (t0 + 21096);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 16U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(495, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t1 = (t0 + 21160);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(496, ng0);
    t1 = (t0 + 20840);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(497, ng0);
    t1 = (t0 + 20776);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB30;

LAB32:    xsi_set_current_line(499, ng0);
    t1 = (t0 + 5672U);
    t4 = *((char **)t1);
    t15 = (18 - 15);
    t16 = (t15 * 1U);
    t17 = (0 + t16);
    t1 = (t4 + t17);
    t7 = (t0 + 21224);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 16U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(500, ng0);
    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t1 = (t0 + 21288);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(501, ng0);
    t1 = (t0 + 20904);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(502, ng0);
    t1 = (t0 + 20776);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB30;

}

static void work_a_3943994461_3212880686_p_4(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    int t5;
    char *t6;
    int t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(521, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 19448);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(522, ng0);
    t3 = (t0 + 11592U);
    t4 = *((char **)t3);
    t5 = *((int *)t4);
    t3 = (t0 + 14608U);
    t6 = *((char **)t3);
    t7 = *((int *)t6);
    t8 = (t5 == t7);
    if (t8 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(526, ng0);
    t1 = (t0 + 21416);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t9 = *((char **)t6);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(527, ng0);
    t1 = (t0 + 11592U);
    t3 = *((char **)t1);
    t5 = *((int *)t3);
    t7 = (t5 + 1);
    t1 = (t0 + 21352);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t9 = (t6 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = t7;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(523, ng0);
    t3 = (t0 + 21352);
    t9 = (t3 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((int *)t12) = 0;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(524, ng0);
    t1 = (t0 + 21416);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t9 = *((char **)t6);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

}

static void work_a_3943994461_3212880686_p_5(char *t0)
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
    char *t11;
    static char *nl0[] = {&&LAB12, &&LAB13};

LAB0:    xsi_set_current_line(539, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 19464);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(541, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(546, ng0);
    t1 = (t0 + 11752U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(542, ng0);
    t3 = (t0 + 21480);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(543, ng0);
    t1 = (t0 + 21544);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(547, ng0);
    t1 = (t0 + 11912U);
    t4 = *((char **)t1);
    t6 = *((unsigned char *)t4);
    t1 = (char *)((nl0) + t6);
    goto **((char **)t1);

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(549, ng0);
    t7 = (t0 + 21480);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(550, ng0);
    t1 = (t0 + 9352U);
    t3 = *((char **)t1);
    t1 = (t0 + 21608);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(551, ng0);
    t1 = (t0 + 21544);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB11;

LAB13:    xsi_set_current_line(553, ng0);
    t1 = (t0 + 9192U);
    t3 = *((char **)t1);
    t1 = (t0 + 21608);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 16U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(554, ng0);
    t1 = (t0 + 21544);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB11;

}

static void work_a_3943994461_3212880686_p_6(char *t0)
{
    char t43[16];
    char t44[16];
    char t47[16];
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
    unsigned char t15;
    unsigned char t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    int t24;
    int t25;
    unsigned int t26;
    unsigned int t27;
    int t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    int t32;
    int t33;
    unsigned int t34;
    int t35;
    unsigned int t36;
    unsigned int t37;
    int t38;
    int t39;
    int t40;
    unsigned int t41;
    unsigned int t42;
    int t45;
    unsigned int t46;
    int t48;
    char *t49;
    char *t50;
    char *t51;
    char *t52;
    static char *nl0[] = {&&LAB9, &&LAB10, &&LAB11, &&LAB12};

LAB0:    xsi_set_current_line(567, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 19480);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(569, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(574, ng0);
    t1 = (t0 + 12072U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(570, ng0);
    t3 = xsi_get_transient_memory(24U);
    memset(t3, 0, 24U);
    t7 = t3;
    memset(t7, (unsigned char)2, 24U);
    t8 = (t0 + 21672);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 24U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(571, ng0);
    t1 = (t0 + 21736);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(572, ng0);
    t1 = (t0 + 21800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(576, ng0);
    t4 = (t0 + 11752U);
    t7 = *((char **)t4);
    t6 = *((unsigned char *)t7);
    t13 = (t6 == (unsigned char)3);
    if (t13 == 1)
        goto LAB16;

LAB17:    t5 = (unsigned char)0;

LAB18:    if (t5 != 0)
        goto LAB13;

LAB15:
LAB14:    goto LAB8;

LAB10:    xsi_set_current_line(592, ng0);
    t1 = (t0 + 7432U);
    t3 = *((char **)t1);
    t24 = *((int *)t3);
    t2 = (t24 == 6);
    if (t2 != 0)
        goto LAB28;

LAB30:    xsi_set_current_line(602, ng0);
    t1 = (t0 + 7432U);
    t3 = *((char **)t1);
    t24 = *((int *)t3);
    t25 = (t24 + 1);
    t1 = (t0 + 21928);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t25;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(603, ng0);
    t1 = (t0 + 21800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB29:    goto LAB8;

LAB11:    xsi_set_current_line(606, ng0);
    t1 = (t0 + 22056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(607, ng0);
    t1 = (t0 + 21800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB12:    xsi_set_current_line(609, ng0);
    t1 = (t0 + 10952U);
    t3 = *((char **)t1);
    t1 = (t0 + 38872);
    t2 = 1;
    if (1U == 1U)
        goto LAB61;

LAB62:    t2 = 0;

LAB63:    if (t2 != 0)
        goto LAB58;

LAB60:    xsi_set_current_line(612, ng0);
    t1 = (t0 + 11432U);
    t3 = *((char **)t1);
    t1 = (t0 + 22120);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(613, ng0);
    t1 = (t0 + 9992U);
    t3 = *((char **)t1);
    t1 = (t0 + 22184);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(614, ng0);
    t1 = (t0 + 21736);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB59:    xsi_set_current_line(616, ng0);
    t1 = (t0 + 21800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB13:    xsi_set_current_line(577, ng0);
    t4 = (t0 + 10952U);
    t9 = *((char **)t4);
    t4 = (t0 + 38870);
    t16 = 1;
    if (1U == 1U)
        goto LAB22;

LAB23:    t16 = 0;

LAB24:    if (t16 != 0)
        goto LAB19;

LAB21:    xsi_set_current_line(585, ng0);
    t1 = (t0 + 3592U);
    t3 = *((char **)t1);
    t1 = (t0 + 21864);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(586, ng0);
    t1 = (t0 + 21736);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(587, ng0);
    t1 = (t0 + 21928);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(588, ng0);
    t1 = (t0 + 21800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB20:    goto LAB14;

LAB16:    t4 = (t0 + 11112U);
    t8 = *((char **)t4);
    t14 = *((unsigned char *)t8);
    t15 = (t14 == (unsigned char)3);
    t5 = t15;
    goto LAB18;

LAB19:    xsi_set_current_line(580, ng0);
    t18 = (t0 + 3432U);
    t19 = *((char **)t18);
    t18 = (t0 + 21864);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t19, 24U);
    xsi_driver_first_trans_fast(t18);
    xsi_set_current_line(581, ng0);
    t1 = (t0 + 21736);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(582, ng0);
    t1 = (t0 + 21928);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(583, ng0);
    t1 = (t0 + 21800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB20;

LAB22:    t17 = 0;

LAB25:    if (t17 < 1U)
        goto LAB26;
    else
        goto LAB24;

LAB26:    t11 = (t9 + t17);
    t12 = (t4 + t17);
    if (*((unsigned char *)t11) != *((unsigned char *)t12))
        goto LAB23;

LAB27:    t17 = (t17 + 1);
    goto LAB25;

LAB28:    xsi_set_current_line(594, ng0);
    t1 = (t0 + 7112U);
    t4 = *((char **)t1);
    t25 = (41 - 41);
    t17 = (t25 * -1);
    t26 = (1U * t17);
    t27 = (0 + t26);
    t1 = (t4 + t27);
    t6 = *((unsigned char *)t1);
    t13 = (t6 == (unsigned char)2);
    if (t13 == 1)
        goto LAB34;

LAB35:    t5 = (unsigned char)0;

LAB36:    if (t5 != 0)
        goto LAB31;

LAB33:    xsi_set_current_line(597, ng0);
    t1 = (t0 + 7112U);
    t3 = *((char **)t1);
    t24 = (41 - 41);
    t17 = (t24 * -1);
    t26 = (1U * t17);
    t27 = (0 + t26);
    t1 = (t3 + t27);
    t2 = *((unsigned char *)t1);
    t4 = (t0 + 7112U);
    t7 = *((char **)t4);
    t29 = (41 - 39);
    t30 = (t29 * 1U);
    t31 = (0 + t30);
    t4 = (t7 + t31);
    t9 = ((IEEE_P_2592010699) + 4024);
    t10 = (t44 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 39;
    t11 = (t10 + 4U);
    *((int *)t11) = 0;
    t11 = (t10 + 8U);
    *((int *)t11) = -1;
    t25 = (0 - 39);
    t34 = (t25 * -1);
    t34 = (t34 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t34;
    t8 = xsi_base_array_concat(t8, t43, t9, (char)99, t2, (char)97, t4, t44, (char)101);
    t34 = (1U + 40U);
    t5 = (41U != t34);
    if (t5 == 1)
        goto LAB56;

LAB57:    t11 = (t0 + 21992);
    t12 = (t11 + 56U);
    t18 = *((char **)t12);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t8, 41U);
    xsi_driver_first_trans_fast(t11);

LAB32:    xsi_set_current_line(599, ng0);
    t1 = (t0 + 22056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(600, ng0);
    t1 = (t0 + 21800);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB29;

LAB31:    xsi_set_current_line(595, ng0);
    t9 = (t0 + 38871);
    t11 = xsi_get_transient_memory(40U);
    memset(t11, 0, 40U);
    t12 = t11;
    if (40 > 0)
        goto LAB37;

LAB38:    if (-1 == -1)
        goto LAB42;

LAB43:    t32 = 0;

LAB39:    t33 = (t32 - 1);
    if (-1 == 1)
        goto LAB44;

LAB45:    t34 = 0;

LAB46:    t35 = (t34 - 0);
    t36 = (t35 * 1);
    t37 = (1U * t36);
    t18 = (t12 + t37);
    if (40 > 0)
        goto LAB47;

LAB48:    if (-1 == -1)
        goto LAB52;

LAB53:    t38 = 0;

LAB49:    t39 = (t38 - 1);
    t40 = (0 - t39);
    t41 = (t40 * -1);
    t41 = (t41 + 1);
    t42 = (1U * t41);
    memset(t18, (unsigned char)3, t42);
    t20 = ((IEEE_P_2592010699) + 4024);
    t21 = (t44 + 0U);
    t22 = (t21 + 0U);
    *((int *)t22) = 0;
    t22 = (t21 + 4U);
    *((int *)t22) = 0;
    t22 = (t21 + 8U);
    *((int *)t22) = 1;
    t45 = (0 - 0);
    t46 = (t45 * 1);
    t46 = (t46 + 1);
    t22 = (t21 + 12U);
    *((unsigned int *)t22) = t46;
    t22 = (t47 + 0U);
    t23 = (t22 + 0U);
    *((int *)t23) = 0;
    t23 = (t22 + 4U);
    *((int *)t23) = 39;
    t23 = (t22 + 8U);
    *((int *)t23) = 1;
    t48 = (39 - 0);
    t46 = (t48 * 1);
    t46 = (t46 + 1);
    t23 = (t22 + 12U);
    *((unsigned int *)t23) = t46;
    t19 = xsi_base_array_concat(t19, t43, t20, (char)97, t9, t44, (char)97, t11, t47, (char)101);
    t46 = (1U + 40U);
    t16 = (41U != t46);
    if (t16 == 1)
        goto LAB54;

LAB55:    t23 = (t0 + 21992);
    t49 = (t23 + 56U);
    t50 = *((char **)t49);
    t51 = (t50 + 56U);
    t52 = *((char **)t51);
    memcpy(t52, t19, 41U);
    xsi_driver_first_trans_fast(t23);
    goto LAB32;

LAB34:    t7 = (t0 + 7112U);
    t8 = *((char **)t7);
    t28 = (40 - 41);
    t29 = (t28 * -1);
    t30 = (1U * t29);
    t31 = (0 + t30);
    t7 = (t8 + t31);
    t14 = *((unsigned char *)t7);
    t15 = (t14 == (unsigned char)3);
    t5 = t15;
    goto LAB36;

LAB37:    if (-1 == 1)
        goto LAB40;

LAB41:    t32 = 40;
    goto LAB39;

LAB40:    t32 = 0;
    goto LAB39;

LAB42:    t32 = 40;
    goto LAB39;

LAB44:    t34 = t33;
    goto LAB46;

LAB47:    if (-1 == 1)
        goto LAB50;

LAB51:    t38 = 40;
    goto LAB49;

LAB50:    t38 = 0;
    goto LAB49;

LAB52:    t38 = 40;
    goto LAB49;

LAB54:    xsi_size_not_matching(41U, t46, 0);
    goto LAB55;

LAB56:    xsi_size_not_matching(41U, t34, 0);
    goto LAB57;

LAB58:    xsi_set_current_line(610, ng0);
    t9 = (t0 + 9992U);
    t10 = *((char **)t9);
    t9 = (t0 + 21672);
    t11 = (t9 + 56U);
    t12 = *((char **)t11);
    t18 = (t12 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t10, 24U);
    xsi_driver_first_trans_fast(t9);
    goto LAB59;

LAB61:    t17 = 0;

LAB64:    if (t17 < 1U)
        goto LAB65;
    else
        goto LAB63;

LAB65:    t7 = (t3 + t17);
    t8 = (t1 + t17);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB62;

LAB66:    t17 = (t17 + 1);
    goto LAB64;

}

static void work_a_3943994461_3212880686_p_7(char *t0)
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

LAB0:    xsi_set_current_line(628, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 19496);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(630, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(637, ng0);
    t1 = (t0 + 22248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(638, ng0);
    t1 = (t0 + 22312);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(639, ng0);
    t1 = (t0 + 12552U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(631, ng0);
    t3 = (t0 + 22248);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(632, ng0);
    t1 = (t0 + 22312);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(633, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 22376);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(634, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 22440);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB6:    goto LAB3;

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(641, ng0);
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

LAB14:    xsi_set_current_line(644, ng0);
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
LAB28:    xsi_set_current_line(647, ng0);
    t1 = (t0 + 22504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB13:    goto LAB8;

LAB10:    xsi_set_current_line(650, ng0);
    t1 = (t0 + 9512U);
    t3 = *((char **)t1);
    t1 = (t0 + 22376);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(651, ng0);
    t1 = (t0 + 9672U);
    t3 = *((char **)t1);
    t1 = (t0 + 22440);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(652, ng0);
    t1 = (t0 + 22312);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(653, ng0);
    t1 = (t0 + 22504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB11:    xsi_set_current_line(655, ng0);
    t1 = (t0 + 7912U);
    t3 = *((char **)t1);
    t5 = *((unsigned char *)t3);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB45;

LAB46:    t2 = (unsigned char)0;

LAB47:    if (t2 != 0)
        goto LAB42;

LAB44:    xsi_set_current_line(660, ng0);
    t1 = (t0 + 22504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB43:    goto LAB8;

LAB12:    xsi_set_current_line(642, ng0);
    t16 = (t0 + 22504);
    t20 = (t16 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = (unsigned char)1;
    xsi_driver_first_trans_fast(t16);
    goto LAB13;

LAB15:    t16 = (t0 + 7912U);
    t17 = *((char **)t16);
    t18 = *((unsigned char *)t17);
    t19 = (t18 == (unsigned char)3);
    t5 = t19;
    goto LAB17;

LAB18:    t4 = (t0 + 8232U);
    t8 = *((char **)t4);
    t4 = (t0 + 38873);
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

LAB27:    xsi_set_current_line(645, ng0);
    t10 = (t0 + 22312);
    t16 = (t10 + 56U);
    t17 = *((char **)t16);
    t20 = (t17 + 56U);
    t21 = *((char **)t20);
    *((unsigned char *)t21) = (unsigned char)3;
    xsi_driver_first_trans_fast(t10);
    goto LAB28;

LAB30:    t10 = (t0 + 7912U);
    t15 = *((char **)t10);
    t13 = *((unsigned char *)t15);
    t18 = (t13 == (unsigned char)3);
    t2 = t18;
    goto LAB32;

LAB33:    t1 = (t0 + 8232U);
    t4 = *((char **)t1);
    t1 = (t0 + 38874);
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

LAB42:    xsi_set_current_line(656, ng0);
    t10 = (t0 + 8712U);
    t15 = *((char **)t10);
    t10 = (t0 + 22376);
    t16 = (t10 + 56U);
    t17 = *((char **)t16);
    t20 = (t17 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t15, 24U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(657, ng0);
    t1 = (t0 + 22312);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(658, ng0);
    t1 = (t0 + 22504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB43;

LAB45:    t1 = (t0 + 8232U);
    t4 = *((char **)t1);
    t1 = (t0 + 38875);
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

static void work_a_3943994461_3212880686_p_8(char *t0)
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

LAB0:    xsi_set_current_line(672, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 19512);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(674, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(681, ng0);
    t1 = (t0 + 22760);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(682, ng0);
    t1 = (t0 + 12712U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(675, ng0);
    t3 = xsi_get_transient_memory(24U);
    memset(t3, 0, 24U);
    t7 = t3;
    memset(t7, (unsigned char)2, 24U);
    t8 = (t0 + 22568);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 24U);
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(676, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 22632);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(677, ng0);
    t1 = (t0 + 22696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(678, ng0);
    t1 = (t0 + 22760);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(684, ng0);
    t4 = (t0 + 8072U);
    t7 = *((char **)t4);
    t6 = *((unsigned char *)t7);
    t13 = (t6 == (unsigned char)3);
    if (t13 == 1)
        goto LAB18;

LAB19:    t5 = (unsigned char)0;

LAB20:    if (t5 != 0)
        goto LAB15;

LAB17:    xsi_set_current_line(702, ng0);
    t1 = (t0 + 22696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB16:    goto LAB8;

LAB10:    xsi_set_current_line(705, ng0);
    t1 = (t0 + 22696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB11:    xsi_set_current_line(707, ng0);
    t1 = (t0 + 10472U);
    t3 = *((char **)t1);
    t1 = (t0 + 22888);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(708, ng0);
    t1 = (t0 + 22696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB12:    xsi_set_current_line(710, ng0);
    t1 = (t0 + 8072U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB123;

LAB125:    xsi_set_current_line(727, ng0);
    t1 = (t0 + 22696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);

LAB124:    goto LAB8;

LAB13:    xsi_set_current_line(730, ng0);
    t1 = (t0 + 22696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)5;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB14:    xsi_set_current_line(732, ng0);
    t1 = (t0 + 10472U);
    t3 = *((char **)t1);
    t1 = (t0 + 22632);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(733, ng0);
    t1 = (t0 + 10632U);
    t3 = *((char **)t1);
    t1 = (t0 + 22568);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(734, ng0);
    t1 = (t0 + 22696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB15:    xsi_set_current_line(686, ng0);
    t12 = (t0 + 8872U);
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

LAB29:    xsi_set_current_line(693, ng0);
    t1 = (t0 + 8872U);
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

LAB82:    xsi_set_current_line(696, ng0);
    t1 = (t0 + 8872U);
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
    t4 = (t0 + 8872U);
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
    t11 = (t0 + 22824);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t8, 48U);
    xsi_driver_first_trans_fast(t11);

LAB81:
LAB28:    xsi_set_current_line(699, ng0);
    t1 = (t0 + 22760);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(700, ng0);
    t1 = (t0 + 22696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB16;

LAB18:    t4 = (t0 + 8392U);
    t8 = *((char **)t4);
    t4 = (t0 + 38876);
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

LAB27:    xsi_set_current_line(687, ng0);
    t24 = (t0 + 8872U);
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

LAB39:    xsi_set_current_line(690, ng0);
    t1 = (t0 + 8872U);
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
    t4 = (t0 + 8872U);
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
    t11 = (t0 + 22824);
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

LAB37:    xsi_set_current_line(688, ng0);
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

LAB65:    t53 = (t0 + 22824);
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

LAB80:    xsi_set_current_line(694, ng0);
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

LAB108:    t12 = (t0 + 22824);
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

LAB123:    xsi_set_current_line(711, ng0);
    t1 = (t0 + 8872U);
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

LAB128:    xsi_set_current_line(718, ng0);
    t1 = (t0 + 8872U);
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

LAB181:    xsi_set_current_line(721, ng0);
    t1 = (t0 + 8872U);
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
    t4 = (t0 + 8872U);
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
    t11 = (t0 + 22824);
    t12 = (t11 + 56U);
    t16 = *((char **)t12);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    memcpy(t25, t8, 48U);
    xsi_driver_first_trans_fast(t11);

LAB180:
LAB127:    xsi_set_current_line(724, ng0);
    t1 = (t0 + 22760);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(725, ng0);
    t1 = (t0 + 22696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    goto LAB124;

LAB126:    xsi_set_current_line(712, ng0);
    t7 = (t0 + 8872U);
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

LAB138:    xsi_set_current_line(715, ng0);
    t1 = (t0 + 8872U);
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
    t4 = (t0 + 8872U);
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
    t11 = (t0 + 22824);
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

LAB136:    xsi_set_current_line(713, ng0);
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

LAB164:    t25 = (t0 + 22824);
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

LAB179:    xsi_set_current_line(719, ng0);
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

LAB207:    t12 = (t0 + 22824);
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

static void work_a_3943994461_3212880686_p_9(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(272, ng0);

LAB3:    t1 = (t0 + 6952U);
    t2 = *((char **)t1);
    t1 = (t0 + 22952);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 24U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 19528);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3943994461_3212880686_p_10(char *t0)
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

LAB0:    xsi_set_current_line(289, ng0);

LAB3:    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = (41U - 24U);
    t4 = (31 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 23016);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 18U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 19544);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3943994461_3212880686_p_11(char *t0)
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

LAB0:    xsi_set_current_line(290, ng0);

LAB3:    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = (41U - 24U);
    t4 = (31 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 23080);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 18U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 19560);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3943994461_3212880686_p_12(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(291, ng0);

LAB3:    t1 = (t0 + 7272U);
    t2 = *((char **)t1);
    t1 = (t0 + 23144);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 41U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 19576);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3943994461_3212880686_p_13(char *t0)
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

LAB0:    xsi_set_current_line(306, ng0);

LAB3:    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = (48U - 24U);
    t4 = (31 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 23208);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 25U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 19592);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3943994461_3212880686_p_14(char *t0)
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

LAB0:    xsi_set_current_line(307, ng0);

LAB3:    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = (48U - 24U);
    t4 = (31 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 23272);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 25U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 19608);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3943994461_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3943994461_3212880686_p_0,(void *)work_a_3943994461_3212880686_p_1,(void *)work_a_3943994461_3212880686_p_2,(void *)work_a_3943994461_3212880686_p_3,(void *)work_a_3943994461_3212880686_p_4,(void *)work_a_3943994461_3212880686_p_5,(void *)work_a_3943994461_3212880686_p_6,(void *)work_a_3943994461_3212880686_p_7,(void *)work_a_3943994461_3212880686_p_8,(void *)work_a_3943994461_3212880686_p_9,(void *)work_a_3943994461_3212880686_p_10,(void *)work_a_3943994461_3212880686_p_11,(void *)work_a_3943994461_3212880686_p_12,(void *)work_a_3943994461_3212880686_p_13,(void *)work_a_3943994461_3212880686_p_14};
	xsi_register_didat("work_a_3943994461_3212880686", "isim/TestFreqDDDS_bench_isim_beh.exe.sim/work/a_3943994461_3212880686.didat");
	xsi_register_executes(pe);
}
