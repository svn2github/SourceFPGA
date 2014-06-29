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
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);


static void xilinxcorelib_a_2705073035_1516540902_p_0(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;

LAB0:
LAB3:    t1 = (t0 + 1776U);
    t2 = *((char **)t1);
    t1 = (t0 + 7324U);
    t3 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t2, t1);
    t4 = (t0 + 4544);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = t3;
    xsi_driver_first_trans_fast(t4);

LAB2:    t9 = (t0 + 4448);
    *((int *)t9) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2705073035_1516540902_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:
LAB3:    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 2096U);
    t3 = *((char **)t1);
    t4 = *((int *)t3);
    t5 = (t4 - 0);
    t6 = (t5 * 1);
    xsi_vhdl_check_range_of_index(0, 1023, 1, t4);
    t7 = (18U * t6);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t9 = (t0 + 4608);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 18U);
    xsi_driver_first_trans_fast_port(t9);

LAB2:    t14 = (t0 + 4464);
    *((int *)t14) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void xilinxcorelib_a_2705073035_1516540902_init()
{
	static char *pe[] = {(void *)xilinxcorelib_a_2705073035_1516540902_p_0,(void *)xilinxcorelib_a_2705073035_1516540902_p_1};
	xsi_register_didat("xilinxcorelib_a_2705073035_1516540902", "isim/HDTestbench_isim_beh.exe.sim/xilinxcorelib/a_2705073035_1516540902.didat");
	xsi_register_executes(pe);
}
