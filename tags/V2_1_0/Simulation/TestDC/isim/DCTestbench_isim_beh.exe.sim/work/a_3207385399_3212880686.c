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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestDC/BatDecimator.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_3207385399_3212880686_p_0(char *t0)
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
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    static char *nl0[] = {&&LAB9, &&LAB10, &&LAB11, &&LAB12};

LAB0:    xsi_set_current_line(126, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6368);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(128, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(134, ng0);
    t1 = (t0 + 6544);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(135, ng0);
    t1 = (t0 + 6480);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(136, ng0);
    t1 = (t0 + 4232U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(129, ng0);
    t3 = (t0 + 6480);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(130, ng0);
    t1 = (t0 + 6544);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(131, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 6608);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB6:    goto LAB3;

LAB8:    goto LAB6;

LAB9:    xsi_set_current_line(138, ng0);
    t4 = (t0 + 1512U);
    t7 = *((char **)t4);
    t6 = *((unsigned char *)t7);
    t11 = (t6 == (unsigned char)3);
    if (t11 == 1)
        goto LAB16;

LAB17:    t5 = (unsigned char)0;

LAB18:    if (t5 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(141, ng0);
    t1 = (t0 + 6672);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB14:    goto LAB8;

LAB10:    xsi_set_current_line(144, ng0);
    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB25;

LAB27:    xsi_set_current_line(149, ng0);
    t1 = (t0 + 6672);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);

LAB26:    goto LAB8;

LAB11:    xsi_set_current_line(152, ng0);
    t1 = (t0 + 6672);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB8;

LAB12:    xsi_set_current_line(154, ng0);
    t1 = (t0 + 3272U);
    t3 = *((char **)t1);
    t5 = *((unsigned char *)t3);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB31;

LAB32:    t2 = (unsigned char)0;

LAB33:    if (t2 != 0)
        goto LAB28;

LAB30:    xsi_set_current_line(159, ng0);
    t1 = (t0 + 6672);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);

LAB29:    goto LAB8;

LAB13:    xsi_set_current_line(139, ng0);
    t15 = (t0 + 6672);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)1;
    xsi_driver_first_trans_fast(t15);
    goto LAB14;

LAB16:    t4 = (t0 + 3592U);
    t8 = *((char **)t4);
    t4 = (t0 + 11432);
    t12 = 1;
    if (1U == 1U)
        goto LAB19;

LAB20:    t12 = 0;

LAB21:    t5 = t12;
    goto LAB18;

LAB19:    t13 = 0;

LAB22:    if (t13 < 1U)
        goto LAB23;
    else
        goto LAB21;

LAB23:    t10 = (t8 + t13);
    t14 = (t4 + t13);
    if (*((unsigned char *)t10) != *((unsigned char *)t14))
        goto LAB20;

LAB24:    t13 = (t13 + 1);
    goto LAB22;

LAB25:    xsi_set_current_line(145, ng0);
    t1 = (t0 + 1832U);
    t4 = *((char **)t1);
    t1 = (t0 + 6608);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(146, ng0);
    t1 = (t0 + 6544);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(147, ng0);
    t1 = (t0 + 6672);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB26;

LAB28:    xsi_set_current_line(155, ng0);
    t10 = (t0 + 1992U);
    t14 = *((char **)t10);
    t10 = (t0 + 6608);
    t15 = (t10 + 56U);
    t16 = *((char **)t15);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t14, 24U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(156, ng0);
    t1 = (t0 + 6544);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(157, ng0);
    t1 = (t0 + 6672);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB29;

LAB31:    t1 = (t0 + 3592U);
    t4 = *((char **)t1);
    t1 = (t0 + 11433);
    t11 = 1;
    if (1U == 1U)
        goto LAB34;

LAB35:    t11 = 0;

LAB36:    t2 = t11;
    goto LAB33;

LAB34:    t13 = 0;

LAB37:    if (t13 < 1U)
        goto LAB38;
    else
        goto LAB36;

LAB38:    t8 = (t4 + t13);
    t9 = (t1 + t13);
    if (*((unsigned char *)t8) != *((unsigned char *)t9))
        goto LAB35;

LAB39:    t13 = (t13 + 1);
    goto LAB37;

}

static void work_a_3207385399_3212880686_p_1(char *t0)
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
    char *t12;
    unsigned char t13;
    unsigned char t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    static char *nl0[] = {&&LAB12, &&LAB13, &&LAB14, &&LAB15};

LAB0:    xsi_set_current_line(171, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6384);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(173, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(180, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(205, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (t0 + 6928);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(206, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t1 = (t0 + 6736);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(207, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t1 = (t0 + 6800);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast_port(t1);

LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(174, ng0);
    t3 = xsi_get_transient_memory(24U);
    memset(t3, 0, 24U);
    t7 = t3;
    memset(t7, (unsigned char)2, 24U);
    t8 = (t0 + 6736);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 24U);
    xsi_driver_first_trans_fast_port(t8);
    xsi_set_current_line(175, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 6800);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(176, ng0);
    t1 = (t0 + 6864);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(177, ng0);
    t1 = (t0 + 6928);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(181, ng0);
    t1 = (t0 + 6928);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(182, ng0);
    t1 = (t0 + 4072U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(184, ng0);
    t4 = (t0 + 3112U);
    t7 = *((char **)t4);
    t6 = *((unsigned char *)t7);
    t13 = (t6 == (unsigned char)3);
    if (t13 == 1)
        goto LAB19;

LAB20:    t5 = (unsigned char)0;

LAB21:    if (t5 != 0)
        goto LAB16;

LAB18:    xsi_set_current_line(187, ng0);
    t1 = (t0 + 6864);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB17:    goto LAB11;

LAB13:    xsi_set_current_line(190, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 6992);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(191, ng0);
    t1 = (t0 + 6864);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB11;

LAB14:    xsi_set_current_line(193, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB28;

LAB30:    xsi_set_current_line(196, ng0);
    t1 = (t0 + 6864);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB29:    goto LAB11;

LAB15:    xsi_set_current_line(199, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t1 = (t0 + 6800);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(200, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t1 = (t0 + 6736);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(201, ng0);
    t1 = (t0 + 6928);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(202, ng0);
    t1 = (t0 + 6864);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB11;

LAB16:    xsi_set_current_line(185, ng0);
    t12 = (t0 + 6864);
    t16 = (t12 + 56U);
    t17 = *((char **)t16);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    *((unsigned char *)t19) = (unsigned char)1;
    xsi_driver_first_trans_fast(t12);
    goto LAB17;

LAB19:    t4 = (t0 + 3752U);
    t8 = *((char **)t4);
    t4 = (t0 + 11434);
    t14 = 1;
    if (1U == 1U)
        goto LAB22;

LAB23:    t14 = 0;

LAB24:    t5 = t14;
    goto LAB21;

LAB22:    t15 = 0;

LAB25:    if (t15 < 1U)
        goto LAB26;
    else
        goto LAB24;

LAB26:    t10 = (t8 + t15);
    t11 = (t4 + t15);
    if (*((unsigned char *)t10) != *((unsigned char *)t11))
        goto LAB23;

LAB27:    t15 = (t15 + 1);
    goto LAB25;

LAB28:    xsi_set_current_line(194, ng0);
    t1 = (t0 + 6864);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB29;

}

static void work_a_3207385399_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(117, ng0);

LAB3:    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 7056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 24U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 6400);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3207385399_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3207385399_3212880686_p_0,(void *)work_a_3207385399_3212880686_p_1,(void *)work_a_3207385399_3212880686_p_2};
	xsi_register_didat("work_a_3207385399_3212880686", "isim/DCTestbench_isim_beh.exe.sim/work/a_3207385399_3212880686.didat");
	xsi_register_executes(pe);
}
