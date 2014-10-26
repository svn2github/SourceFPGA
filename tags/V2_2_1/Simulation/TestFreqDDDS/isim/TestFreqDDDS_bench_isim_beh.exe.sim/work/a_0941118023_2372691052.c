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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestFreqDDDS/TestFreqDDDS_tb.vhd";
extern char *STD_TEXTIO;
extern char *IEEE_P_1242562249;
extern char *STD_STANDARD;

int ieee_p_1242562249_sub_2271993008_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );


static void work_a_0941118023_2372691052_p_0(char *t0)
{
    char t14[16];
    char t20[40];
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    int t10;
    double t11;
    double t12;
    double t13;
    unsigned int t15;
    char *t16;
    char *t17;
    int t18;
    char *t19;
    int t21;
    int t22;
    int64 t23;
    int64 t24;

LAB0:    t1 = (t0 + 6576U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(130, ng0);
    t2 = (t0 + 4328U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (!(t4));
    if (t5 != 0)
        goto LAB4;

LAB6:
LAB5:    xsi_set_current_line(136, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 != 0)
        goto LAB7;

LAB9:
LAB8:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 7928);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(175, ng0);
    t2 = (t0 + 3728U);
    t3 = *((char **)t2);
    t23 = *((int64 *)t3);
    t24 = (t23 / 2);
    t2 = (t0 + 6384);
    xsi_process_wait(t2, t24);

LAB39:    *((char **)t1) = &&LAB40;

LAB1:    return;
LAB4:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 5240U);
    t6 = (t0 + 5848U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t7 = (t0 + 13504U);
    std_textio_file_open1(t2, t8, t7, (unsigned char)1);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 5136U);
    t3 = (t0 + 5704U);
    t6 = (t3 + 56U);
    t7 = *((char **)t6);
    t6 = (t0 + 13488U);
    std_textio_file_open1(t2, t7, t6, (unsigned char)0);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 4328U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((unsigned char *)t2) = (unsigned char)1;
    goto LAB5;

LAB7:    xsi_set_current_line(139, ng0);
    t2 = (t0 + 7736);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(140, ng0);
    t2 = (t0 + 4448U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t4 = (t10 == 0);
    if (t4 != 0)
        goto LAB10;

LAB12:
LAB11:    xsi_set_current_line(167, ng0);
    t2 = (t0 + 4448U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = (t0 + 4088U);
    t6 = *((char **)t2);
    t18 = *((int *)t6);
    t4 = (t10 < t18);
    if (t4 != 0)
        goto LAB34;

LAB36:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 4448U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((int *)t2) = 0;

LAB35:    goto LAB8;

LAB10:    xsi_set_current_line(141, ng0);
    t2 = (t0 + 5136U);
    t5 = std_textio_endfile(t2);
    if (t5 != 0)
        goto LAB13;

LAB15:
LAB14:    xsi_set_current_line(148, ng0);
    t2 = (t0 + 6384);
    t3 = (t0 + 5136U);
    t6 = (t0 + 5416U);
    std_textio_readline(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 6384);
    t3 = (t0 + 5416U);
    t6 = (t0 + 4688U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    std_textio_read12(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 4688U);
    t3 = *((char **)t2);
    t11 = *((double *)t3);
    t4 = (t11 >= 0);
    if (t4 == 1)
        goto LAB22;

LAB23:    t13 = (t11 - 0.50000000000000000);
    t10 = ((int)(t13));

LAB24:    t2 = (t0 + 4808U);
    t6 = *((char **)t2);
    t2 = (t6 + 0);
    *((int *)t2) = t10;
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 4808U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t14, t10, 24);
    t6 = (t14 + 12U);
    t15 = *((unsigned int *)t6);
    t15 = (t15 * 1U);
    t4 = (24U != t15);
    if (t4 == 1)
        goto LAB27;

LAB28:    t7 = (t0 + 7800);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t16 = (t9 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t2, 24U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 4808U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t14, t10, 24);
    t6 = (t14 + 12U);
    t15 = *((unsigned int *)t6);
    t15 = (t15 * 1U);
    t4 = (24U != t15);
    if (t4 == 1)
        goto LAB29;

LAB30:    t7 = (t0 + 7864);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t16 = (t9 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t2, 24U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(154, ng0);
    t2 = (t0 + 7736);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(156, ng0);
    t2 = (t0 + 4568U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t18 = (t10 + 1);
    t2 = (t0 + 4568U);
    t6 = *((char **)t2);
    t2 = (t6 + 0);
    *((int *)t2) = t18;
    xsi_set_current_line(157, ng0);
    t2 = (t0 + 4568U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t4 = (t10 == 5);
    if (t4 != 0)
        goto LAB31;

LAB33:
LAB32:    goto LAB11;

LAB13:    xsi_set_current_line(142, ng0);
    t6 = (t0 + 5136U);
    std_textio_file_close(t6);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 5240U);
    std_textio_file_close(t2);
    xsi_set_current_line(144, ng0);
    if ((unsigned char)0 == 0)
        goto LAB16;

LAB17:    xsi_set_current_line(145, ng0);

LAB20:    *((char **)t1) = &&LAB21;
    goto LAB1;

LAB16:    t2 = (t0 + 14196);
    xsi_report(t2, 17U, (unsigned char)3);
    goto LAB17;

LAB18:    goto LAB14;

LAB19:    goto LAB18;

LAB21:    goto LAB19;

LAB22:    t5 = (t11 >= 2147483647);
    if (t5 == 1)
        goto LAB25;

LAB26:    t12 = (t11 + 0.50000000000000000);
    t10 = ((int)(t12));
    goto LAB24;

LAB25:    t10 = 2147483647;
    goto LAB24;

LAB27:    xsi_size_not_matching(24U, t15, 0);
    goto LAB28;

LAB29:    xsi_size_not_matching(24U, t15, 0);
    goto LAB30;

LAB31:    xsi_set_current_line(158, ng0);
    t2 = (t0 + 4568U);
    t6 = *((char **)t2);
    t2 = (t6 + 0);
    *((int *)t2) = 0;
    xsi_set_current_line(160, ng0);
    t2 = xsi_get_transient_memory(40U);
    memset(t2, 0, 40U);
    t3 = t2;
    memset(t3, (unsigned char)32, 40U);
    t6 = (t0 + 5992U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    memcpy(t7, t2, 40U);
    xsi_set_current_line(161, ng0);
    t2 = ((STD_STANDARD) + 384);
    t3 = (t0 + 2632U);
    t6 = *((char **)t3);
    t3 = (t0 + 13600U);
    t10 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t6, t3);
    t7 = xsi_int_to_mem(t10);
    t8 = xsi_string_variable_get_image(t14, t2, t7);
    t9 = (t0 + 5992U);
    t16 = (t9 + 56U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    t19 = (t14 + 12U);
    t15 = *((unsigned int *)t19);
    memcpy(t16, t8, t15);
    xsi_set_current_line(162, ng0);
    t2 = (t0 + 6384);
    t3 = (t0 + 5488U);
    t6 = (t0 + 5992U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t20, t8, 40U);
    t7 = (t0 + 13664U);
    std_textio_write7(STD_TEXTIO, t2, t3, t20, t7, (unsigned char)0, 0);
    xsi_set_current_line(163, ng0);
    t2 = (t0 + 6384);
    t3 = (t0 + 5240U);
    t6 = (t0 + 5488U);
    std_textio_writeline(STD_TEXTIO, t2, t3, t6);
    goto LAB32;

LAB34:    xsi_set_current_line(168, ng0);
    t2 = (t0 + 4448U);
    t7 = *((char **)t2);
    t21 = *((int *)t7);
    t22 = (t21 + 1);
    t2 = (t0 + 4448U);
    t8 = *((char **)t2);
    t2 = (t8 + 0);
    *((int *)t2) = t22;
    goto LAB35;

LAB37:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 7928);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(177, ng0);
    t2 = (t0 + 3728U);
    t3 = *((char **)t2);
    t23 = *((int64 *)t3);
    t24 = (t23 / 2);
    t2 = (t0 + 6384);
    xsi_process_wait(t2, t24);

LAB43:    *((char **)t1) = &&LAB44;
    goto LAB1;

LAB38:    goto LAB37;

LAB40:    goto LAB38;

LAB41:    goto LAB2;

LAB42:    goto LAB41;

LAB44:    goto LAB42;

}

static void work_a_0941118023_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;

LAB0:    t1 = (t0 + 6824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(184, ng0);
    t2 = (t0 + 7992);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(185, ng0);
    t7 = (100 * 1000LL);
    t2 = (t0 + 6632);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(186, ng0);
    t2 = (t0 + 7992);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(187, ng0);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_0941118023_2372691052_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(97, ng0);

LAB3:    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 8056);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 24U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 7640);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0941118023_2372691052_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(98, ng0);

LAB3:    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t1 = (t0 + 8120);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 24U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 7656);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0941118023_2372691052_init()
{
	static char *pe[] = {(void *)work_a_0941118023_2372691052_p_0,(void *)work_a_0941118023_2372691052_p_1,(void *)work_a_0941118023_2372691052_p_2,(void *)work_a_0941118023_2372691052_p_3};
	xsi_register_didat("work_a_0941118023_2372691052", "isim/TestFreqDDDS_bench_isim_beh.exe.sim/work/a_0941118023_2372691052.didat");
	xsi_register_executes(pe);
}
