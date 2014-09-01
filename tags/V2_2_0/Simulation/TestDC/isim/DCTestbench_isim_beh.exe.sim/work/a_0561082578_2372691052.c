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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestDC/TestDC_tb.vhd";
extern char *IEEE_P_3972351953;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
double ieee_p_3972351953_sub_1485185913_2984157535(char *, double );


static void work_a_0561082578_2372691052_p_0(char *t0)
{
    char t19[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    int t7;
    unsigned char t8;
    char *t9;
    double t10;
    double t11;
    char *t12;
    double t13;
    double t14;
    char *t15;
    double t16;
    double t17;
    char *t18;
    int t20;
    int t21;
    int t22;
    int64 t23;
    int64 t24;

LAB0:    t1 = (t0 + 4952U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 != 0)
        goto LAB4;

LAB6:
LAB5:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 5776);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    *((unsigned char *)t12) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 3128U);
    t3 = *((char **)t2);
    t23 = *((int64 *)t3);
    t24 = (t23 / 2);
    t2 = (t0 + 4760);
    xsi_process_wait(t2, t24);

LAB25:    *((char **)t1) = &&LAB26;

LAB1:    return;
LAB4:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 3608U);
    t6 = *((char **)t2);
    t7 = *((int *)t6);
    t8 = (t7 == 0);
    if (t8 != 0)
        goto LAB7;

LAB9:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 5712);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    *((unsigned char *)t12) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);

LAB8:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 3608U);
    t3 = *((char **)t2);
    t7 = *((int *)t3);
    t2 = (t0 + 3008U);
    t6 = *((char **)t2);
    t20 = *((int *)t6);
    t4 = (t7 < t20);
    if (t4 != 0)
        goto LAB20;

LAB22:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 3608U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((int *)t2) = 0;

LAB21:    goto LAB5;

LAB7:    xsi_set_current_line(93, ng0);
    t2 = ((IEEE_P_3972351953) + 1408U);
    t9 = *((char **)t2);
    t10 = *((double *)t9);
    t11 = (2.0000000000000000 * t10);
    t2 = (t0 + 3728U);
    t12 = *((char **)t2);
    t13 = *((double *)t12);
    t14 = (t11 * t13);
    t2 = (t0 + 2888U);
    t15 = *((char **)t2);
    t16 = *((double *)t15);
    t17 = (t14 * t16);
    t2 = (t0 + 3848U);
    t18 = *((char **)t2);
    t2 = (t18 + 0);
    *((double *)t2) = t17;
    xsi_set_current_line(94, ng0);
    t2 = (t0 + 3728U);
    t3 = *((char **)t2);
    t10 = *((double *)t3);
    t2 = (t0 + 3488U);
    t6 = *((char **)t2);
    t11 = *((double *)t6);
    t13 = (t10 + t11);
    t2 = (t0 + 3728U);
    t9 = *((char **)t2);
    t2 = (t9 + 0);
    *((double *)t2) = t13;
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 3248U);
    t3 = *((char **)t2);
    t7 = *((int *)t3);
    t2 = (t0 + 3848U);
    t6 = *((char **)t2);
    t10 = *((double *)t6);
    t11 = ieee_p_3972351953_sub_1485185913_2984157535(IEEE_P_3972351953, t10);
    t13 = (t11 + 1.0000000000000000);
    t14 = ((((double)(t7))) * t13);
    t2 = (t0 + 3968U);
    t9 = *((char **)t2);
    t2 = (t9 + 0);
    *((double *)t2) = t14;
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 3968U);
    t3 = *((char **)t2);
    t10 = *((double *)t3);
    t4 = (t10 >= 0);
    if (t4 == 1)
        goto LAB10;

LAB11:    t13 = (t10 - 0.50000000000000000);
    t7 = ((int)(t13));

LAB12:    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t19, t7, 24);
    t6 = (t0 + 5584);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    t15 = (t12 + 56U);
    t18 = *((char **)t15);
    memcpy(t18, t2, 24U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 3968U);
    t3 = *((char **)t2);
    t10 = *((double *)t3);
    t4 = (t10 >= 0);
    if (t4 == 1)
        goto LAB15;

LAB16:    t13 = (t10 - 0.50000000000000000);
    t7 = ((int)(t13));

LAB17:    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t19, t7, 24);
    t6 = (t0 + 5648);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    t15 = (t12 + 56U);
    t18 = *((char **)t15);
    memcpy(t18, t2, 24U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(98, ng0);
    t2 = (t0 + 5712);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    *((unsigned char *)t12) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    goto LAB8;

LAB10:    t5 = (t10 >= 2147483647);
    if (t5 == 1)
        goto LAB13;

LAB14:    t11 = (t10 + 0.50000000000000000);
    t7 = ((int)(t11));
    goto LAB12;

LAB13:    t7 = 2147483647;
    goto LAB12;

LAB15:    t5 = (t10 >= 2147483647);
    if (t5 == 1)
        goto LAB18;

LAB19:    t11 = (t10 + 0.50000000000000000);
    t7 = ((int)(t11));
    goto LAB17;

LAB18:    t7 = 2147483647;
    goto LAB17;

LAB20:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 3608U);
    t9 = *((char **)t2);
    t21 = *((int *)t9);
    t22 = (t21 + 1);
    t2 = (t0 + 3608U);
    t12 = *((char **)t2);
    t2 = (t12 + 0);
    *((int *)t2) = t22;
    goto LAB21;

LAB23:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 5776);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    *((unsigned char *)t12) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 3128U);
    t3 = *((char **)t2);
    t23 = *((int64 *)t3);
    t24 = (t23 / 2);
    t2 = (t0 + 4760);
    xsi_process_wait(t2, t24);

LAB29:    *((char **)t1) = &&LAB30;
    goto LAB1;

LAB24:    goto LAB23;

LAB26:    goto LAB24;

LAB27:    goto LAB2;

LAB28:    goto LAB27;

LAB30:    goto LAB28;

}

static void work_a_0561082578_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;

LAB0:    t1 = (t0 + 5200U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(119, ng0);
    t2 = (t0 + 5840);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(120, ng0);
    t7 = (500 * 1000LL);
    t2 = (t0 + 5008);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 5840);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(122, ng0);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}


extern void work_a_0561082578_2372691052_init()
{
	static char *pe[] = {(void *)work_a_0561082578_2372691052_p_0,(void *)work_a_0561082578_2372691052_p_1};
	xsi_register_didat("work_a_0561082578_2372691052", "isim/DCTestbench_isim_beh.exe.sim/work/a_0561082578_2372691052.didat");
	xsi_register_executes(pe);
}
