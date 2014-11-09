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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestDec/BatRandom.vhd";
extern char *IEEE_P_2592010699;
extern char *WORK_P_0539175533;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
unsigned char work_p_0539175533_sub_2037905280_2408126421(char *, char *, char *);


static void work_a_3458358099_3212880686_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    char *t6;
    char *t7;
    int t8;
    int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;

LAB0:    xsi_set_current_line(77, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3472);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(78, ng0);
    t3 = (t0 + 2048U);
    t4 = *((char **)t3);
    t3 = (t0 + 5896U);
    t5 = work_p_0539175533_sub_2037905280_2408126421(WORK_P_0539175533, t4, t3);
    t6 = (t0 + 2168U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    *((unsigned char *)t6) = t5;
    xsi_set_current_line(79, ng0);
    t1 = (t0 + 2048U);
    t3 = *((char **)t1);
    t1 = (t0 + 1928U);
    t4 = *((char **)t1);
    t8 = *((int *)t4);
    t9 = (t8 - 2);
    t10 = (63 - t9);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t3 + t12);
    t6 = xsi_get_transient_memory(63U);
    memcpy(t6, t1, 63U);
    t7 = (t0 + 2048U);
    t13 = *((char **)t7);
    t7 = (t0 + 1928U);
    t14 = *((char **)t7);
    t15 = *((int *)t14);
    t16 = (t15 - 1);
    t17 = (63 - t16);
    t18 = (t17 * 1U);
    t19 = (0 + t18);
    t7 = (t13 + t19);
    memcpy(t7, t6, 63U);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 2168U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (t0 + 2048U);
    t4 = *((char **)t1);
    t8 = (0 - 63);
    t10 = (t8 * -1);
    t11 = (1U * t10);
    t12 = (0 + t11);
    t1 = (t4 + t12);
    *((unsigned char *)t1) = t2;
    xsi_set_current_line(81, ng0);
    t1 = (t0 + 2048U);
    t3 = *((char **)t1);
    t8 = (32 - 1);
    t10 = (63 - t8);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t3 + t12);
    t4 = (t0 + 3552);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t13 = (t7 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t1, 32U);
    xsi_driver_first_trans_fast_port(t4);
    xsi_set_current_line(82, ng0);
    t1 = (t0 + 2048U);
    t3 = *((char **)t1);
    t1 = (t0 + 1928U);
    t4 = *((char **)t1);
    t8 = *((int *)t4);
    t9 = (t8 - 1);
    t10 = (63 - t9);
    t11 = (t10 * 1U);
    t12 = (0 + t11);
    t1 = (t3 + t12);
    t6 = (t0 + 3616);
    t7 = (t6 + 56U);
    t13 = *((char **)t7);
    t14 = (t13 + 56U);
    t20 = *((char **)t14);
    memcpy(t20, t1, 32U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(83, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t1 = (t0 + 3680);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t13 = *((char **)t7);
    memcpy(t13, t3, 32U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB3;

}


extern void work_a_3458358099_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3458358099_3212880686_p_0};
	xsi_register_didat("work_a_3458358099_3212880686", "isim/TestFIR_bench_isim_beh.exe.sim/work/a_3458358099_3212880686.didat");
	xsi_register_executes(pe);
}
