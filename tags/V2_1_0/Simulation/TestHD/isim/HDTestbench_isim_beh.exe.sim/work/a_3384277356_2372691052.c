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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestHD/TestHD_tb.vhd";
extern char *IEEE_P_3972351953;
extern char *IEEE_P_1242562249;
extern char *STD_TEXTIO;

char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );
char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
double ieee_p_3972351953_sub_188333038_2984157535(char *, double );
void ieee_p_3972351953_sub_3007962107_2984157535(char *, char *, char *, char *, char *);


static void work_a_3384277356_2372691052_p_0(char *t0)
{
    char t8[16];
    char t21[16];
    char t22[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    char *t7;
    char *t9;
    char *t10;
    int t11;
    unsigned int t12;
    char *t13;
    double t14;
    double t15;
    double t16;
    double t17;
    double t18;
    unsigned char t19;
    unsigned char t20;
    char *t23;
    int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    int t29;
    int t30;
    int64 t31;
    int64 t32;

LAB0:    t1 = (t0 + 5568U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 3568U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (!(t4));
    if (t5 != 0)
        goto LAB4;

LAB6:
LAB5:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 5376);
    t3 = (t0 + 3928U);
    t6 = *((char **)t3);
    t3 = (t6 + 0);
    t7 = (t0 + 4048U);
    t9 = *((char **)t7);
    t7 = (t9 + 0);
    t10 = (t0 + 4168U);
    t13 = *((char **)t10);
    t10 = (t13 + 0);
    ieee_p_3972351953_sub_3007962107_2984157535(IEEE_P_3972351953, t2, t3, t7, t10);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 4168U);
    t3 = *((char **)t2);
    t14 = *((double *)t3);
    t15 = (t14 * 2147483648.0000000);
    t16 = ieee_p_3972351953_sub_188333038_2984157535(IEEE_P_3972351953, t15);
    t4 = (t16 >= 0);
    if (t4 == 1)
        goto LAB7;

LAB8:    t18 = (t16 - 0.50000000000000000);
    t11 = ((int)(t18));

LAB9:    t2 = (t0 + 4288U);
    t6 = *((char **)t2);
    t2 = (t6 + 0);
    *((int *)t2) = t11;
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 4288U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t8, t11, 32);
    t6 = (t0 + 6200);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t2, 32U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 != 0)
        goto LAB12;

LAB14:
LAB13:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 6456);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 3088U);
    t3 = *((char **)t2);
    t31 = *((int64 *)t3);
    t32 = (t31 / 2);
    t2 = (t0 + 5376);
    xsi_process_wait(t2, t32);

LAB26:    *((char **)t1) = &&LAB27;

LAB1:    return;
LAB4:    xsi_set_current_line(101, ng0);
    t2 = (t0 + 4736U);
    t6 = (t0 + 10928);
    t9 = (t8 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 1;
    t10 = (t9 + 4U);
    *((int *)t10) = 23;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t11 = (23 - 1);
    t12 = (t11 * 1);
    t12 = (t12 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t12;
    std_textio_file_open1(t2, t6, t8, (unsigned char)0);
    xsi_set_current_line(102, ng0);
    t2 = (t0 + 3568U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((unsigned char *)t2) = (unsigned char)1;
    goto LAB5;

LAB7:    t5 = (t16 >= 2147483647);
    if (t5 == 1)
        goto LAB10;

LAB11:    t17 = (t16 + 0.50000000000000000);
    t11 = ((int)(t17));
    goto LAB9;

LAB10:    t11 = 2147483647;
    goto LAB9;

LAB12:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 3808U);
    t6 = *((char **)t2);
    t11 = *((int *)t6);
    t19 = (t11 == 0);
    if (t19 != 0)
        goto LAB15;

LAB17:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 6392);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);

LAB16:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 3808U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t2 = (t0 + 3448U);
    t6 = *((char **)t2);
    t24 = *((int *)t6);
    t4 = (t11 < t24);
    if (t4 != 0)
        goto LAB21;

LAB23:    xsi_set_current_line(127, ng0);
    t2 = (t0 + 3808U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((int *)t2) = 0;

LAB22:    goto LAB13;

LAB15:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 4736U);
    t20 = std_textio_endfile(t2);
    if (t20 != 0)
        goto LAB18;

LAB20:
LAB19:    xsi_set_current_line(115, ng0);
    t2 = (t0 + 5376);
    t3 = (t0 + 4736U);
    t6 = (t0 + 4912U);
    std_textio_readline(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 5376);
    t3 = (t0 + 4912U);
    t6 = (t0 + 3688U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    std_textio_read10(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 3688U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t8, t11, 16);
    t6 = (t0 + 10974);
    t10 = ((IEEE_P_1242562249) + 3112);
    t13 = (t22 + 0U);
    t23 = (t13 + 0U);
    *((int *)t23) = 0;
    t23 = (t13 + 4U);
    *((int *)t23) = 7;
    t23 = (t13 + 8U);
    *((int *)t23) = 1;
    t24 = (7 - 0);
    t12 = (t24 * 1);
    t12 = (t12 + 1);
    t23 = (t13 + 12U);
    *((unsigned int *)t23) = t12;
    t9 = xsi_base_array_concat(t9, t21, t10, (char)97, t2, t8, (char)97, t6, t22, (char)101);
    t23 = (t0 + 6264);
    t25 = (t23 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t9, 24U);
    xsi_driver_first_trans_fast(t23);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 3688U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t8, t11, 16);
    t6 = (t0 + 10982);
    t10 = ((IEEE_P_1242562249) + 3112);
    t13 = (t22 + 0U);
    t23 = (t13 + 0U);
    *((int *)t23) = 0;
    t23 = (t13 + 4U);
    *((int *)t23) = 7;
    t23 = (t13 + 8U);
    *((int *)t23) = 1;
    t24 = (7 - 0);
    t12 = (t24 * 1);
    t12 = (t12 + 1);
    t23 = (t13 + 12U);
    *((unsigned int *)t23) = t12;
    t9 = xsi_base_array_concat(t9, t21, t10, (char)97, t2, t8, (char)97, t6, t22, (char)101);
    t23 = (t0 + 6328);
    t25 = (t23 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t9, 24U);
    xsi_driver_first_trans_fast(t23);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 6392);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    goto LAB16;

LAB18:    xsi_set_current_line(112, ng0);
    t7 = (t0 + 4736U);
    std_textio_file_close(t7);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 4736U);
    t3 = (t0 + 10951);
    t7 = (t8 + 0U);
    t9 = (t7 + 0U);
    *((int *)t9) = 1;
    t9 = (t7 + 4U);
    *((int *)t9) = 23;
    t9 = (t7 + 8U);
    *((int *)t9) = 1;
    t11 = (23 - 1);
    t12 = (t11 * 1);
    t12 = (t12 + 1);
    t9 = (t7 + 12U);
    *((unsigned int *)t9) = t12;
    std_textio_file_open1(t2, t3, t8, (unsigned char)0);
    goto LAB19;

LAB21:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 3808U);
    t7 = *((char **)t2);
    t29 = *((int *)t7);
    t30 = (t29 + 1);
    t2 = (t0 + 3808U);
    t9 = *((char **)t2);
    t2 = (t9 + 0);
    *((int *)t2) = t30;
    goto LAB22;

LAB24:    xsi_set_current_line(133, ng0);
    t2 = (t0 + 6456);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 3088U);
    t3 = *((char **)t2);
    t31 = *((int64 *)t3);
    t32 = (t31 / 2);
    t2 = (t0 + 5376);
    xsi_process_wait(t2, t32);

LAB30:    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB25:    goto LAB24;

LAB27:    goto LAB25;

LAB28:    goto LAB2;

LAB29:    goto LAB28;

LAB31:    goto LAB29;

}

static void work_a_3384277356_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;

LAB0:    t1 = (t0 + 5816U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(189, ng0);
    t2 = (t0 + 6520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(190, ng0);
    t7 = (500 * 1000LL);
    t2 = (t0 + 5624);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(191, ng0);
    t2 = (t0 + 6520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(192, ng0);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}


extern void work_a_3384277356_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3384277356_2372691052_p_0,(void *)work_a_3384277356_2372691052_p_1};
	xsi_register_didat("work_a_3384277356_2372691052", "isim/HDTestbench_isim_beh.exe.sim/work/a_3384277356_2372691052.didat");
	xsi_register_executes(pe);
}
