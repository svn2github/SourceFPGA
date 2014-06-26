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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestFD/TestFD_tb.vhd";
extern char *STD_TEXTIO;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );


static void work_a_2613170794_2372691052_p_0(char *t0)
{
    char t8[16];
    char t15[16];
    char t16[16];
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
    unsigned char t13;
    unsigned char t14;
    char *t17;
    char *t18;
    int t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    int t24;
    int t25;
    int64 t26;
    int64 t27;

LAB0:    t1 = (t0 + 4488U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 3088U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (!(t4));
    if (t5 != 0)
        goto LAB4;

LAB6:
LAB5:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 != 0)
        goto LAB7;

LAB9:
LAB8:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 5312);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t26 = *((int64 *)t3);
    t27 = (t26 / 2);
    t2 = (t0 + 4296);
    xsi_process_wait(t2, t27);

LAB21:    *((char **)t1) = &&LAB22;

LAB1:    return;
LAB4:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3656U);
    t6 = (t0 + 8972);
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
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 3088U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((unsigned char *)t2) = (unsigned char)1;
    goto LAB5;

LAB7:    xsi_set_current_line(88, ng0);
    t2 = (t0 + 3328U);
    t6 = *((char **)t2);
    t11 = *((int *)t6);
    t13 = (t11 == 0);
    if (t13 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 5248);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);

LAB11:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 3328U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t2 = (t0 + 2968U);
    t6 = *((char **)t2);
    t19 = *((int *)t6);
    t4 = (t11 < t19);
    if (t4 != 0)
        goto LAB16;

LAB18:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 3328U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((int *)t2) = 0;

LAB17:    goto LAB8;

LAB10:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 3656U);
    t14 = std_textio_endfile(t2);
    if (t14 != 0)
        goto LAB13;

LAB15:
LAB14:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 4296);
    t3 = (t0 + 3656U);
    t6 = (t0 + 3832U);
    std_textio_readline(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(94, ng0);
    t2 = (t0 + 4296);
    t3 = (t0 + 3832U);
    t6 = (t0 + 3208U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    std_textio_read10(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 3208U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t8, t11, 16);
    t6 = (t0 + 9018);
    t10 = ((IEEE_P_1242562249) + 3112);
    t17 = (t16 + 0U);
    t18 = (t17 + 0U);
    *((int *)t18) = 0;
    t18 = (t17 + 4U);
    *((int *)t18) = 7;
    t18 = (t17 + 8U);
    *((int *)t18) = 1;
    t19 = (7 - 0);
    t12 = (t19 * 1);
    t12 = (t12 + 1);
    t18 = (t17 + 12U);
    *((unsigned int *)t18) = t12;
    t9 = xsi_base_array_concat(t9, t15, t10, (char)97, t2, t8, (char)97, t6, t16, (char)101);
    t18 = (t0 + 5120);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t9, 24U);
    xsi_driver_first_trans_fast(t18);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 3208U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t8, t11, 16);
    t6 = (t0 + 9026);
    t10 = ((IEEE_P_1242562249) + 3112);
    t17 = (t16 + 0U);
    t18 = (t17 + 0U);
    *((int *)t18) = 0;
    t18 = (t17 + 4U);
    *((int *)t18) = 7;
    t18 = (t17 + 8U);
    *((int *)t18) = 1;
    t19 = (7 - 0);
    t12 = (t19 * 1);
    t12 = (t12 + 1);
    t18 = (t17 + 12U);
    *((unsigned int *)t18) = t12;
    t9 = xsi_base_array_concat(t9, t15, t10, (char)97, t2, t8, (char)97, t6, t16, (char)101);
    t18 = (t0 + 5184);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t9, 24U);
    xsi_driver_first_trans_fast(t18);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 5248);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    goto LAB11;

LAB13:    xsi_set_current_line(90, ng0);
    t7 = (t0 + 3656U);
    std_textio_file_close(t7);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 3656U);
    t3 = (t0 + 8995);
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
    goto LAB14;

LAB16:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 3328U);
    t7 = *((char **)t2);
    t24 = *((int *)t7);
    t25 = (t24 + 1);
    t2 = (t0 + 3328U);
    t9 = *((char **)t2);
    t2 = (t9 + 0);
    *((int *)t2) = t25;
    goto LAB17;

LAB19:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 5312);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t9 = *((char **)t7);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t26 = *((int64 *)t3);
    t27 = (t26 / 2);
    t2 = (t0 + 4296);
    xsi_process_wait(t2, t27);

LAB25:    *((char **)t1) = &&LAB26;
    goto LAB1;

LAB20:    goto LAB19;

LAB22:    goto LAB20;

LAB23:    goto LAB2;

LAB24:    goto LAB23;

LAB26:    goto LAB24;

}

static void work_a_2613170794_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;

LAB0:    t1 = (t0 + 4736U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 5376);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(119, ng0);
    t7 = (500 * 1000LL);
    t2 = (t0 + 4544);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 5376);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(121, ng0);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}


extern void work_a_2613170794_2372691052_init()
{
	static char *pe[] = {(void *)work_a_2613170794_2372691052_p_0,(void *)work_a_2613170794_2372691052_p_1};
	xsi_register_didat("work_a_2613170794_2372691052", "isim/FDTestbench_isim_beh.exe.sim/work/a_2613170794_2372691052.didat");
	xsi_register_executes(pe);
}
