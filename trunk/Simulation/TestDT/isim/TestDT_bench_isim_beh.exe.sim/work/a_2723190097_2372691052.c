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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestDT/TestDT_tb.vhd";
extern char *STD_TEXTIO;
extern char *IEEE_P_1242562249;
extern char *STD_STANDARD;

int ieee_p_1242562249_sub_2271993008_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );


static void work_a_2723190097_2372691052_p_0(char *t0)
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

LAB0:    t1 = (t0 + 5936U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(132, ng0);
    t2 = (t0 + 3448U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (!(t4));
    if (t5 != 0)
        goto LAB4;

LAB6:
LAB5:    xsi_set_current_line(138, ng0);
    t2 = (t0 + 1032U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 != 0)
        goto LAB7;

LAB9:
LAB8:    xsi_set_current_line(186, ng0);
    t2 = (t0 + 7224);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(187, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t23 = *((int64 *)t3);
    t24 = (t23 / 2);
    t2 = (t0 + 5744);
    xsi_process_wait(t2, t24);

LAB42:    *((char **)t1) = &&LAB43;

LAB1:    return;
LAB4:    xsi_set_current_line(133, ng0);
    t2 = (t0 + 4600U);
    t6 = (t0 + 5208U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t7 = (t0 + 12000U);
    std_textio_file_open1(t2, t8, t7, (unsigned char)1);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 4496U);
    t3 = (t0 + 5064U);
    t6 = (t3 + 56U);
    t7 = *((char **)t6);
    t6 = (t0 + 11984U);
    std_textio_file_open1(t2, t7, t6, (unsigned char)0);
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 3448U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((unsigned char *)t2) = (unsigned char)1;
    goto LAB5;

LAB7:    xsi_set_current_line(141, ng0);
    t2 = (t0 + 7096);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(144, ng0);
    t2 = (t0 + 3688U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t4 = (t10 == 0);
    if (t4 != 0)
        goto LAB10;

LAB12:
LAB11:    xsi_set_current_line(160, ng0);
    t2 = (t0 + 3928U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = (t0 + 3328U);
    t6 = *((char **)t2);
    t18 = *((int *)t6);
    t4 = (t10 == t18);
    if (t4 != 0)
        goto LAB23;

LAB25:    t2 = (t0 + 3928U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = (t0 + 3328U);
    t6 = *((char **)t2);
    t18 = *((int *)t6);
    t4 = (t10 < t18);
    if (t4 != 0)
        goto LAB35;

LAB36:
LAB24:    xsi_set_current_line(178, ng0);
    t2 = (t0 + 3688U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = (t0 + 2968U);
    t6 = *((char **)t2);
    t18 = *((int *)t6);
    t4 = (t10 < t18);
    if (t4 != 0)
        goto LAB37;

LAB39:    xsi_set_current_line(181, ng0);
    t2 = (t0 + 3688U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((int *)t2) = 0;

LAB38:    goto LAB8;

LAB10:    xsi_set_current_line(145, ng0);
    t2 = (t0 + 4496U);
    t5 = std_textio_endfile(t2);
    if (t5 != 0)
        goto LAB13;

LAB15:    xsi_set_current_line(150, ng0);
    t2 = (t0 + 5744);
    t3 = (t0 + 4496U);
    t6 = (t0 + 4776U);
    std_textio_readline(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 5744);
    t3 = (t0 + 4776U);
    t6 = (t0 + 4048U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    std_textio_read12(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 4048U);
    t3 = *((char **)t2);
    t11 = *((double *)t3);
    t4 = (t11 >= 0);
    if (t4 == 1)
        goto LAB16;

LAB17:    t13 = (t11 - 0.50000000000000000);
    t10 = ((int)(t13));

LAB18:    t2 = (t0 + 4168U);
    t6 = *((char **)t2);
    t2 = (t6 + 0);
    *((int *)t2) = t10;
    xsi_set_current_line(154, ng0);
    t2 = (t0 + 4168U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t14, t10, 24);
    t6 = (t14 + 12U);
    t15 = *((unsigned int *)t6);
    t15 = (t15 * 1U);
    t4 = (24U != t15);
    if (t4 == 1)
        goto LAB21;

LAB22:    t7 = (t0 + 7160);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t16 = (t9 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t2, 24U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(155, ng0);
    t2 = (t0 + 7096);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(156, ng0);
    t2 = (t0 + 3928U);
    t3 = *((char **)t2);
    t2 = (t3 + 0);
    *((int *)t2) = 0;

LAB14:    goto LAB11;

LAB13:    xsi_set_current_line(146, ng0);
    t6 = (t0 + 3568U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    *((unsigned char *)t6) = (unsigned char)1;
    xsi_set_current_line(147, ng0);
    t2 = (t0 + 4496U);
    std_textio_file_close(t2);
    goto LAB14;

LAB16:    t5 = (t11 >= 2147483647);
    if (t5 == 1)
        goto LAB19;

LAB20:    t12 = (t11 + 0.50000000000000000);
    t10 = ((int)(t12));
    goto LAB18;

LAB19:    t10 = 2147483647;
    goto LAB18;

LAB21:    xsi_size_not_matching(24U, t15, 0);
    goto LAB22;

LAB23:    xsi_set_current_line(162, ng0);
    t2 = xsi_get_transient_memory(40U);
    memset(t2, 0, 40U);
    t7 = t2;
    memset(t7, (unsigned char)32, 40U);
    t8 = (t0 + 5352U);
    t9 = (t8 + 56U);
    t16 = *((char **)t9);
    t9 = (t16 + 0);
    memcpy(t9, t2, 40U);
    xsi_set_current_line(163, ng0);
    t2 = ((STD_STANDARD) + 384);
    t3 = (t0 + 1992U);
    t6 = *((char **)t3);
    t3 = (t0 + 12064U);
    t10 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t6, t3);
    t7 = xsi_int_to_mem(t10);
    t8 = xsi_string_variable_get_image(t14, t2, t7);
    t9 = (t0 + 5352U);
    t16 = (t9 + 56U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    t19 = (t14 + 12U);
    t15 = *((unsigned int *)t19);
    memcpy(t16, t8, t15);
    xsi_set_current_line(164, ng0);
    t2 = (t0 + 5744);
    t3 = (t0 + 4848U);
    t6 = (t0 + 5352U);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    memcpy(t20, t8, 40U);
    t7 = (t0 + 12112U);
    std_textio_write7(STD_TEXTIO, t2, t3, t20, t7, (unsigned char)0, 0);
    xsi_set_current_line(165, ng0);
    t2 = (t0 + 5744);
    t3 = (t0 + 4600U);
    t6 = (t0 + 4848U);
    std_textio_writeline(STD_TEXTIO, t2, t3, t6);
    xsi_set_current_line(167, ng0);
    t2 = (t0 + 3568U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)1);
    if (t5 != 0)
        goto LAB26;

LAB28:
LAB27:    xsi_set_current_line(172, ng0);
    t2 = (t0 + 3928U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t18 = (t10 + 1);
    t2 = (t0 + 3928U);
    t6 = *((char **)t2);
    t2 = (t6 + 0);
    *((int *)t2) = t18;
    goto LAB24;

LAB26:    xsi_set_current_line(168, ng0);
    t2 = (t0 + 4600U);
    std_textio_file_close(t2);
    xsi_set_current_line(169, ng0);
    if ((unsigned char)0 == 0)
        goto LAB29;

LAB30:    xsi_set_current_line(170, ng0);

LAB33:    *((char **)t1) = &&LAB34;
    goto LAB1;

LAB29:    t2 = (t0 + 12556);
    xsi_report(t2, 17U, (unsigned char)3);
    goto LAB30;

LAB31:    goto LAB27;

LAB32:    goto LAB31;

LAB34:    goto LAB32;

LAB35:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 3928U);
    t7 = *((char **)t2);
    t21 = *((int *)t7);
    t22 = (t21 + 1);
    t2 = (t0 + 3928U);
    t8 = *((char **)t2);
    t2 = (t8 + 0);
    *((int *)t2) = t22;
    goto LAB24;

LAB37:    xsi_set_current_line(179, ng0);
    t2 = (t0 + 3688U);
    t7 = *((char **)t2);
    t21 = *((int *)t7);
    t22 = (t21 + 1);
    t2 = (t0 + 3688U);
    t8 = *((char **)t2);
    t2 = (t8 + 0);
    *((int *)t2) = t22;
    goto LAB38;

LAB40:    xsi_set_current_line(188, ng0);
    t2 = (t0 + 7224);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(189, ng0);
    t2 = (t0 + 2608U);
    t3 = *((char **)t2);
    t23 = *((int64 *)t3);
    t24 = (t23 / 2);
    t2 = (t0 + 5744);
    xsi_process_wait(t2, t24);

LAB46:    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB41:    goto LAB40;

LAB43:    goto LAB41;

LAB44:    goto LAB2;

LAB45:    goto LAB44;

LAB47:    goto LAB45;

}

static void work_a_2723190097_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;

LAB0:    t1 = (t0 + 6184U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(195, ng0);
    t2 = (t0 + 7288);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(196, ng0);
    t7 = (100 * 1000LL);
    t2 = (t0 + 5992);
    xsi_process_wait(t2, t7);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(197, ng0);
    t2 = (t0 + 7288);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(198, ng0);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_2723190097_2372691052_p_2(char *t0)
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

LAB0:    xsi_set_current_line(99, ng0);

LAB3:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = (24U - 16U);
    t4 = (31 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 7352);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 9U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 7000);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2723190097_2372691052_p_3(char *t0)
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

LAB0:    xsi_set_current_line(100, ng0);

LAB3:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t3 = (24U - 16U);
    t4 = (31 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 7416);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 9U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 7016);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_2723190097_2372691052_init()
{
	static char *pe[] = {(void *)work_a_2723190097_2372691052_p_0,(void *)work_a_2723190097_2372691052_p_1,(void *)work_a_2723190097_2372691052_p_2,(void *)work_a_2723190097_2372691052_p_3};
	xsi_register_didat("work_a_2723190097_2372691052", "isim/TestDT_bench_isim_beh.exe.sim/work/a_2723190097_2372691052.didat");
	xsi_register_executes(pe);
}
