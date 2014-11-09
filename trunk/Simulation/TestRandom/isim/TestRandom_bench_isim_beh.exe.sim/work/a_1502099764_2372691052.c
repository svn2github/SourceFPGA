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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestRandom/TestRandom_tb.vhd";
extern char *IEEE_P_1242562249;
extern char *STD_STANDARD;
extern char *STD_TEXTIO;

int ieee_p_1242562249_sub_2271993008_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_3273497107_1035706684(char *, char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_3410769178_1035706684(char *, char *, char *, char *, int );


static void work_a_1502099764_2372691052_p_0(char *t0)
{
    char t13[16];
    char t14[16];
    char t21[16];
    char t35[16];
    char t43[40];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    unsigned char t10;
    int t11;
    unsigned char t12;
    char *t15;
    int t16;
    int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t22;
    char *t23;
    int t24;
    unsigned int t25;
    char *t26;
    int t27;
    char *t28;
    char *t29;
    char *t30;
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    char *t36;
    char *t37;
    int t38;
    unsigned int t39;
    int t40;
    char *t41;
    char *t42;
    int64 t44;
    int64 t45;

LAB0:    t1 = (t0 + 4616U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2808U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (!(t4));
    if (t5 != 0)
        goto LAB4;

LAB6:
LAB5:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 != 0)
        goto LAB7;

LAB9:
LAB8:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 5312);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 1968U);
    t3 = *((char **)t2);
    t44 = *((int64 *)t3);
    t45 = (t44 / 2);
    t2 = (t0 + 4424);
    xsi_process_wait(t2, t45);

LAB30:    *((char **)t1) = &&LAB31;

LAB1:    return;
LAB4:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 3496U);
    t6 = (t0 + 3888U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t7 = (t0 + 8948U);
    std_textio_file_open1(t2, t8, t7, (unsigned char)1);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 2808U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((unsigned char *)t2) = (unsigned char)1;
    goto LAB5;

LAB7:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 3048U);
    t6 = *((char **)t2);
    t9 = *((int *)t6);
    t10 = (t9 == 0);
    if (t10 != 0)
        goto LAB10;

LAB12:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 5248);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);

LAB11:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 3048U);
    t3 = *((char **)t2);
    t9 = *((int *)t3);
    t2 = (t0 + 2328U);
    t6 = *((char **)t2);
    t11 = *((int *)t6);
    t4 = (t9 < t11);
    if (t4 != 0)
        goto LAB16;

LAB18:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 3048U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((int *)t2) = 0;

LAB17:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 3168U);
    t3 = *((char **)t2);
    t9 = *((int *)t3);
    t4 = (t9 == 0);
    if (t4 != 0)
        goto LAB19;

LAB21:
LAB20:    goto LAB8;

LAB10:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 2688U);
    t7 = *((char **)t2);
    t11 = *((int *)t7);
    t12 = (t11 == 1);
    if (t12 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(95, ng0);
    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t2 = (t0 + 8964U);
    t9 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t3, t2);
    t6 = (t0 + 2928U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    *((int *)t6) = t9;

LAB14:    xsi_set_current_line(97, ng0);
    t2 = xsi_get_transient_memory(40U);
    memset(t2, 0, 40U);
    t3 = t2;
    memset(t3, (unsigned char)32, 40U);
    t6 = (t0 + 4032U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    memcpy(t7, t2, 40U);
    xsi_set_current_line(98, ng0);
    t2 = ((STD_STANDARD) + 384);
    t3 = (t0 + 2928U);
    t6 = *((char **)t3);
    t9 = *((int *)t6);
    t3 = xsi_int_to_mem(t9);
    t7 = xsi_string_variable_get_image(t13, t2, t3);
    t8 = (t0 + 4032U);
    t15 = (t8 + 56U);
    t22 = *((char **)t15);
    t15 = (t22 + 0);
    t23 = (t13 + 12U);
    t18 = *((unsigned int *)t23);
    memcpy(t15, t7, t18);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 4424);
    t3 = (t0 + 3672U);
    t6 = (t0 + 4032U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t43, t8, 40U);
    t7 = (t0 + 8996U);
    std_textio_write7(STD_TEXTIO, t2, t3, t43, t7, (unsigned char)0, 0);
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 4424);
    t3 = (t0 + 3496U);
    t6 = (t0 + 3672U);
    std_textio_writeline(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 5248);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(102, ng0);
    t2 = (t0 + 3168U);
    t3 = *((char **)t2);
    t9 = *((int *)t3);
    t11 = (t9 - 1);
    t2 = (t0 + 3168U);
    t6 = *((char **)t2);
    t2 = (t6 + 0);
    *((int *)t2) = t11;
    goto LAB11;

LAB13:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 1512U);
    t8 = *((char **)t2);
    t2 = (t0 + 2568U);
    t15 = *((char **)t2);
    t16 = *((int *)t15);
    t17 = (t16 - 2);
    t18 = (8 - t17);
    t19 = (t18 * 1U);
    t20 = (0 + t19);
    t2 = (t8 + t20);
    t22 = (t21 + 0U);
    t23 = (t22 + 0U);
    *((int *)t23) = 7;
    t23 = (t22 + 4U);
    *((int *)t23) = 0;
    t23 = (t22 + 8U);
    *((int *)t23) = -1;
    t24 = (0 - 7);
    t25 = (t24 * -1);
    t25 = (t25 + 1);
    t23 = (t22 + 12U);
    *((unsigned int *)t23) = t25;
    t23 = (t0 + 2568U);
    t26 = *((char **)t23);
    t27 = *((int *)t26);
    t23 = ieee_p_1242562249_sub_3410769178_1035706684(IEEE_P_1242562249, t14, t2, t21, t27);
    t28 = (t0 + 1672U);
    t29 = *((char **)t28);
    t28 = (t0 + 2568U);
    t30 = *((char **)t28);
    t31 = *((int *)t30);
    t32 = (t31 - 2);
    t25 = (8 - t32);
    t33 = (t25 * 1U);
    t34 = (0 + t33);
    t28 = (t29 + t34);
    t36 = (t35 + 0U);
    t37 = (t36 + 0U);
    *((int *)t37) = 7;
    t37 = (t36 + 4U);
    *((int *)t37) = 0;
    t37 = (t36 + 8U);
    *((int *)t37) = -1;
    t38 = (0 - 7);
    t39 = (t38 * -1);
    t39 = (t39 + 1);
    t37 = (t36 + 12U);
    *((unsigned int *)t37) = t39;
    t37 = ieee_p_1242562249_sub_3273497107_1035706684(IEEE_P_1242562249, t13, t23, t14, t28, t35);
    t40 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t37, t13);
    t41 = (t0 + 2928U);
    t42 = *((char **)t41);
    t41 = (t42 + 0);
    *((int *)t41) = t40;
    goto LAB14;

LAB16:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 3048U);
    t7 = *((char **)t2);
    t16 = *((int *)t7);
    t17 = (t16 + 1);
    t2 = (t0 + 3048U);
    t8 = *((char **)t2);
    t2 = (t8 + 0);
    *((int *)t2) = t17;
    goto LAB17;

LAB19:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 3496U);
    std_textio_file_close(t2);
    xsi_set_current_line(115, ng0);
    if ((unsigned char)0 == 0)
        goto LAB22;

LAB23:    xsi_set_current_line(116, ng0);

LAB26:    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB22:    t2 = (t0 + 9224);
    xsi_report(t2, 17U, (unsigned char)3);
    goto LAB23;

LAB24:    goto LAB20;

LAB25:    goto LAB24;

LAB27:    goto LAB25;

LAB28:    xsi_set_current_line(122, ng0);
    t2 = (t0 + 5312);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(123, ng0);
    t2 = (t0 + 1968U);
    t3 = *((char **)t2);
    t44 = *((int64 *)t3);
    t45 = (t44 / 2);
    t2 = (t0 + 4424);
    xsi_process_wait(t2, t45);

LAB34:    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB29:    goto LAB28;

LAB31:    goto LAB29;

LAB32:    goto LAB2;

LAB33:    goto LAB32;

LAB35:    goto LAB33;

}

static void work_a_1502099764_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;

LAB0:    t1 = (t0 + 4864U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 5376);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(130, ng0);
    t7 = (100 * 1000LL);
    t2 = (t0 + 4672);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 5376);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(132, ng0);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}


extern void work_a_1502099764_2372691052_init()
{
	static char *pe[] = {(void *)work_a_1502099764_2372691052_p_0,(void *)work_a_1502099764_2372691052_p_1};
	xsi_register_didat("work_a_1502099764_2372691052", "isim/TestRandom_bench_isim_beh.exe.sim/work/a_1502099764_2372691052.didat");
	xsi_register_executes(pe);
}
