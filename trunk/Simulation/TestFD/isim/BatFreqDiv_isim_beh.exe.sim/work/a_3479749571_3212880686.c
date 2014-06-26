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
static const char *ng0 = "E:/Source/Xilinx/Simulation/BatFD/TestBatFD/BatFreqDiv.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
unsigned char ieee_p_1242562249_sub_2720078402_1035706684(char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_3064532541_1035706684(char *, char *, char *, char *, int );
char *ieee_p_1242562249_sub_3410769178_1035706684(char *, char *, char *, char *, int );
char *ieee_p_1242562249_sub_3481121704_1035706684(char *, char *, char *, char *);
unsigned char ieee_p_1242562249_sub_4081755647_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_3479749571_3212880686_p_0(char *t0)
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

LAB0:    xsi_set_current_line(102, ng0);

LAB3:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 9501);
    t6 = ((IEEE_P_2592010699) + 4024);
    t7 = (t0 + 9156U);
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
    t10 = (t0 + 5624);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 24U);
    xsi_driver_first_trans_fast(t10);

LAB2:    t17 = (t0 + 5496);
    *((int *)t17) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3479749571_3212880686_p_1(char *t0)
{
    char t11[16];
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
    char *t12;
    char *t13;
    char *t14;
    int t15;
    unsigned char t16;
    char *t17;
    char *t18;
    unsigned int t19;
    unsigned int t20;
    int t21;

LAB0:    xsi_set_current_line(109, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5512);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(111, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(119, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(112, ng0);
    t3 = (t0 + 5688);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(113, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 5752);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(114, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 5816);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(115, ng0);
    t1 = (t0 + 5880);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(116, ng0);
    t1 = (t0 + 5944);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 1672U);
    t4 = *((char **)t1);
    t1 = (t0 + 9172U);
    t7 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t11, 0, 24);
    t6 = ieee_p_1242562249_sub_4081755647_1035706684(IEEE_P_1242562249, t4, t1, t7, t11);
    if (t6 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(126, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB17;

LAB19:
LAB18:
LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(121, ng0);
    t8 = (t0 + 5880);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(122, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t1 = (t0 + 9172U);
    t4 = (t0 + 2632U);
    t7 = *((char **)t4);
    t4 = (t0 + 9252U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB14;

LAB16:
LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(123, ng0);
    t8 = (t0 + 1672U);
    t9 = *((char **)t8);
    t8 = (t0 + 5816);
    t10 = (t8 + 56U);
    t12 = *((char **)t10);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t9, 24U);
    xsi_driver_first_trans_fast(t8);
    goto LAB15;

LAB17:    xsi_set_current_line(127, ng0);
    t1 = (t0 + 5880);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(128, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t1 = (t0 + 9252U);
    t4 = (t0 + 1992U);
    t7 = *((char **)t4);
    t4 = (t0 + 9204U);
    t2 = ieee_p_1242562249_sub_2720078402_1035706684(IEEE_P_1242562249, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB20;

LAB22:    xsi_set_current_line(142, ng0);
    t1 = (t0 + 5944);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(143, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 5816);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);

LAB21:    goto LAB18;

LAB20:    xsi_set_current_line(129, ng0);
    t8 = (t0 + 2952U);
    t9 = *((char **)t8);
    t15 = *((int *)t9);
    t5 = (t15 >= 4);
    if (t5 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(139, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t15 = *((int *)t3);
    t21 = (t15 + 1);
    t1 = (t0 + 5944);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t21;
    xsi_driver_first_trans_fast(t1);

LAB24:    goto LAB21;

LAB23:    xsi_set_current_line(130, ng0);
    t8 = (t0 + 3112U);
    t10 = *((char **)t8);
    t6 = *((unsigned char *)t10);
    t16 = (t6 == (unsigned char)3);
    if (t16 != 0)
        goto LAB26;

LAB28:    xsi_set_current_line(133, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t1 = (t0 + 9252U);
    t4 = ieee_p_1242562249_sub_3481121704_1035706684(IEEE_P_1242562249, t11, t3, t1);
    t7 = (t11 + 12U);
    t19 = *((unsigned int *)t7);
    t20 = (1U * t19);
    t2 = (24U != t20);
    if (t2 == 1)
        goto LAB29;

LAB30:    t8 = (t0 + 5752);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t4, 24U);
    xsi_driver_first_trans_fast(t8);

LAB27:    xsi_set_current_line(135, ng0);
    t1 = (t0 + 3112U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t2);
    t1 = (t0 + 5688);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t5;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(136, ng0);
    t1 = xsi_get_transient_memory(24U);
    memset(t1, 0, 24U);
    t3 = t1;
    memset(t3, (unsigned char)2, 24U);
    t4 = (t0 + 5816);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 24U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(137, ng0);
    t1 = (t0 + 5944);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB24;

LAB26:    xsi_set_current_line(131, ng0);
    t8 = (t0 + 2632U);
    t12 = *((char **)t8);
    t8 = (t0 + 5752);
    t13 = (t8 + 56U);
    t14 = *((char **)t13);
    t17 = (t14 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t12, 24U);
    xsi_driver_first_trans_fast(t8);
    goto LAB27;

LAB29:    xsi_size_not_matching(24U, t20, 0);
    goto LAB30;

}

static void work_a_3479749571_3212880686_p_2(char *t0)
{
    char t13[16];
    char t14[16];
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
    char *t15;

LAB0:    xsi_set_current_line(158, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5528);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(160, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(164, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(161, ng0);
    t3 = xsi_get_transient_memory(24U);
    memset(t3, 0, 24U);
    t7 = t3;
    memset(t7, (unsigned char)2, 24U);
    t8 = (t0 + 6008);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 24U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB6;

LAB8:    xsi_set_current_line(166, ng0);
    t1 = (t0 + 2312U);
    t4 = *((char **)t1);
    t1 = (t0 + 9236U);
    t7 = ieee_p_1242562249_sub_3064532541_1035706684(IEEE_P_1242562249, t14, t4, t1, 18);
    t8 = ieee_p_1242562249_sub_3410769178_1035706684(IEEE_P_1242562249, t13, t7, t14, 24);
    t9 = (t0 + 6008);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t15 = *((char **)t12);
    memcpy(t15, t8, 24U);
    xsi_driver_first_trans_fast_port(t9);
    goto LAB9;

}

static void work_a_3479749571_3212880686_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(95, ng0);

LAB3:    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 6072);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 24U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 5544);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3479749571_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3479749571_3212880686_p_0,(void *)work_a_3479749571_3212880686_p_1,(void *)work_a_3479749571_3212880686_p_2,(void *)work_a_3479749571_3212880686_p_3};
	xsi_register_didat("work_a_3479749571_3212880686", "isim/BatFreqDiv_isim_beh.exe.sim/work/a_3479749571_3212880686.didat");
	xsi_register_executes(pe);
}
