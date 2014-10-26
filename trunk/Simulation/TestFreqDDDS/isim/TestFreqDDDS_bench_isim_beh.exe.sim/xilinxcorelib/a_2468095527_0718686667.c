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
extern char *XILINXCORELIB_P_2602938013;
extern char *STD_STANDARD;
extern char *IEEE_P_1242562249;
extern char *XILINXCORELIB_P_3381355550;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
int ieee_p_1242562249_sub_2271993008_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_3410769178_1035706684(char *, char *, char *, char *, int );
int xilinxcorelib_p_3381355550_sub_3326504488_1067159583(char *, char *, char *);


char *xilinxcorelib_a_2468095527_0718686667_sub_666516397_567902854(char *t1, char *t2, int t3)
{
    char t4[128];
    char t5[24];
    char t6[16];
    char t11[16];
    char t16[32];
    char *t0;
    char *t7;
    char *t8;
    int t9;
    unsigned int t10;
    char *t12;
    int t13;
    char *t14;
    char *t15;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    unsigned char t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    int t28;
    int t29;
    int t30;
    int t31;
    char *t32;
    int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;

LAB0:    t7 = (t6 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 12;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t9 = (12 - 0);
    t10 = (t9 * 1);
    t10 = (t10 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t10;
    t8 = (t11 + 0U);
    t12 = (t8 + 0U);
    *((int *)t12) = 0;
    t12 = (t8 + 4U);
    *((int *)t12) = 7;
    t12 = (t8 + 8U);
    *((int *)t12) = 1;
    t13 = (7 - 0);
    t10 = (t13 * 1);
    t10 = (t10 + 1);
    t12 = (t8 + 12U);
    *((unsigned int *)t12) = t10;
    t12 = (t4 + 4U);
    t14 = (t1 + 26264);
    t15 = (t12 + 88U);
    *((char **)t15) = t14;
    t17 = (t12 + 56U);
    *((char **)t17) = t16;
    xsi_type_set_default_value(t14, t16, 0);
    t18 = (t12 + 64U);
    t19 = (t14 + 80U);
    t20 = *((char **)t19);
    *((char **)t18) = t20;
    t21 = (t12 + 80U);
    *((unsigned int *)t21) = 32U;
    t22 = (t5 + 4U);
    t23 = (t2 != 0);
    if (t23 == 1)
        goto LAB3;

LAB2:    t24 = (t5 + 12U);
    *((char **)t24) = t6;
    t25 = (t5 + 20U);
    *((int *)t25) = t3;
    t26 = (t1 + 16040U);
    t27 = *((char **)t26);
    t28 = *((int *)t27);
    t29 = (t28 - 1);
    t30 = 0;
    t31 = t29;

LAB4:    if (t30 <= t31)
        goto LAB5;

LAB7:    t7 = ((XILINXCORELIB_P_2602938013) + 7528U);
    t8 = *((char **)t7);
    t9 = *((int *)t8);
    t13 = (t9 - 0);
    t10 = (t13 * 1);
    t34 = (4U * t10);
    t35 = (0 + t34);
    t7 = (t2 + t35);
    t28 = *((int *)t7);
    if (t28 == 0)
        goto LAB10;

LAB14:    if (t28 == 1)
        goto LAB11;

LAB15:    if (t28 == 2)
        goto LAB12;

LAB16:
LAB13:    t7 = xsi_get_transient_memory(12U);
    memset(t7, 0, 12U);
    t8 = t7;
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (0 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);

LAB9:    t23 = (t3 == 1);
    if (t23 != 0)
        goto LAB18;

LAB20:    t7 = ((XILINXCORELIB_P_2602938013) + 7648U);
    t8 = *((char **)t7);
    t9 = *((int *)t8);
    t13 = (t9 - 0);
    t10 = (t13 * 1);
    t34 = (4U * t10);
    t35 = (0 + t34);
    t7 = (t2 + t35);
    t28 = *((int *)t7);
    if (t28 == 0)
        goto LAB35;

LAB42:    if (t28 == 1)
        goto LAB36;

LAB43:    if (t28 == 2)
        goto LAB37;

LAB44:    if (t28 == 3)
        goto LAB38;

LAB45:    if (t28 == 4)
        goto LAB39;

LAB46:    if (t28 == 5)
        goto LAB40;

LAB47:
LAB41:    if ((unsigned char)0 == 0)
        goto LAB49;

LAB50:
LAB34:
LAB19:    t7 = (t12 + 56U);
    t8 = *((char **)t7);
    t23 = (32U != 32U);
    if (t23 == 1)
        goto LAB51;

LAB52:    t0 = xsi_get_transient_memory(32U);
    memcpy(t0, t8, 32U);

LAB1:    return t0;
LAB3:    *((char **)t22) = t2;
    goto LAB2;

LAB5:    t26 = (t12 + 56U);
    t32 = *((char **)t26);
    t33 = (t30 - 0);
    t10 = (t33 * 1);
    xsi_vhdl_check_range_of_index(0, 7, 1, t30);
    t34 = (4U * t10);
    t35 = (0 + t34);
    t26 = (t32 + t35);
    *((int *)t26) = 0;

LAB6:    if (t30 == t31)
        goto LAB7;

LAB8:    t9 = (t30 + 1);
    t30 = t9;
    goto LAB4;

LAB10:    t14 = xsi_get_transient_memory(12U);
    memset(t14, 0, 12U);
    t15 = t14;
    *((int *)t15) = 0;
    t15 = (t15 + 4U);
    *((int *)t15) = 0;
    t15 = (t15 + 4U);
    *((int *)t15) = 0;
    t17 = (t12 + 56U);
    t18 = *((char **)t17);
    t36 = (0 - 0);
    t37 = (t36 * 4U);
    t38 = (0 + t37);
    t17 = (t18 + t38);
    memcpy(t17, t14, 32U);
    goto LAB9;

LAB11:    t7 = xsi_get_transient_memory(12U);
    memset(t7, 0, 12U);
    t8 = t7;
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (0 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB9;

LAB12:    t7 = xsi_get_transient_memory(12U);
    memset(t7, 0, 12U);
    t8 = t7;
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (0 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB9;

LAB17:;
LAB18:    t7 = ((XILINXCORELIB_P_2602938013) + 7648U);
    t8 = *((char **)t7);
    t9 = *((int *)t8);
    t13 = (t9 - 0);
    t10 = (t13 * 1);
    t34 = (4U * t10);
    t35 = (0 + t34);
    t7 = (t2 + t35);
    t28 = *((int *)t7);
    if (t28 == 0)
        goto LAB22;

LAB27:    if (t28 == 1)
        goto LAB23;

LAB28:    if (t28 == 2)
        goto LAB24;

LAB29:    if (t28 == 3)
        goto LAB25;

LAB30:
LAB26:    if ((unsigned char)0 == 0)
        goto LAB32;

LAB33:
LAB21:    goto LAB19;

LAB22:    t14 = xsi_get_transient_memory(12U);
    memset(t14, 0, 12U);
    t15 = t14;
    *((int *)t15) = 0;
    t15 = (t15 + 4U);
    *((int *)t15) = 0;
    t15 = (t15 + 4U);
    *((int *)t15) = 0;
    t17 = (t12 + 56U);
    t18 = *((char **)t17);
    t36 = (3 - 0);
    t37 = (t36 * 4U);
    t38 = (0 + t37);
    t17 = (t18 + t38);
    memcpy(t17, t14, 32U);
    goto LAB21;

LAB23:    t7 = xsi_get_transient_memory(12U);
    memset(t7, 0, 12U);
    t8 = t7;
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (3 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB21;

LAB24:    t7 = xsi_get_transient_memory(12U);
    memset(t7, 0, 12U);
    t8 = t7;
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (3 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB21;

LAB25:    t7 = xsi_get_transient_memory(12U);
    memset(t7, 0, 12U);
    t8 = t7;
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (3 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB21;

LAB31:;
LAB32:    t7 = (t1 + 43175);
    xsi_report(t7, 30U, (unsigned char)2);
    goto LAB33;

LAB35:    t14 = xsi_get_transient_memory(20U);
    memset(t14, 0, 20U);
    t15 = t14;
    *((int *)t15) = 0;
    t15 = (t15 + 4U);
    *((int *)t15) = 0;
    t15 = (t15 + 4U);
    *((int *)t15) = 0;
    t15 = (t15 + 4U);
    *((int *)t15) = 0;
    t15 = (t15 + 4U);
    *((int *)t15) = 0;
    t17 = (t12 + 56U);
    t18 = *((char **)t17);
    t36 = (3 - 0);
    t37 = (t36 * 4U);
    t38 = (0 + t37);
    t17 = (t18 + t38);
    memcpy(t17, t14, 32U);
    goto LAB34;

LAB36:    t7 = xsi_get_transient_memory(20U);
    memset(t7, 0, 20U);
    t8 = t7;
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (3 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB34;

LAB37:    t7 = xsi_get_transient_memory(20U);
    memset(t7, 0, 20U);
    t8 = t7;
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (3 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB34;

LAB38:    t7 = xsi_get_transient_memory(20U);
    memset(t7, 0, 20U);
    t8 = t7;
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (3 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB34;

LAB39:    t7 = xsi_get_transient_memory(20U);
    memset(t7, 0, 20U);
    t8 = t7;
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 0;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (3 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB34;

LAB40:    t7 = xsi_get_transient_memory(20U);
    memset(t7, 0, 20U);
    t8 = t7;
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t8 = (t8 + 4U);
    *((int *)t8) = 1;
    t14 = (t12 + 56U);
    t15 = *((char **)t14);
    t10 = (3 - 0);
    t34 = (t10 * 4U);
    t35 = (0 + t34);
    t14 = (t15 + t35);
    memcpy(t14, t7, 32U);
    goto LAB34;

LAB48:;
LAB49:    t7 = (t1 + 43205);
    xsi_report(t7, 30U, (unsigned char)2);
    goto LAB50;

LAB51:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB52;

LAB53:;
}

double xilinxcorelib_a_2468095527_0718686667_sub_3428844293_567902854(char *t1, char *t2, char *t3, int t4)
{
    char t5[128];
    char t6[24];
    char t10[8];
    char t30[16];
    double t0;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    char *t13;
    unsigned char t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t18;
    unsigned char t19;
    char *t20;
    int t21;
    unsigned int t22;
    char *t23;
    int t24;
    char *t25;
    int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t31;
    char *t32;
    int t33;
    unsigned int t34;
    int t35;
    char *t36;
    double t37;
    int t38;
    int t39;
    double t40;
    double t41;
    double t42;

LAB0:    t7 = (t5 + 4U);
    t8 = ((STD_STANDARD) + 472);
    t9 = (t7 + 88U);
    *((char **)t9) = t8;
    t11 = (t7 + 56U);
    *((char **)t11) = t10;
    *((double *)t10) = 0.00000000000000000;
    t12 = (t7 + 80U);
    *((unsigned int *)t12) = 8U;
    t13 = (t6 + 4U);
    t14 = (t2 != 0);
    if (t14 == 1)
        goto LAB3;

LAB2:    t15 = (t6 + 12U);
    *((char **)t15) = t3;
    t16 = (t6 + 20U);
    *((int *)t16) = t4;
    t17 = (t3 + 12U);
    t18 = *((unsigned int *)t17);
    t19 = (t18 > 30);
    if (t19 != 0)
        goto LAB4;

LAB6:    t21 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t2, t3);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t8 = (t9 + 0);
    *((double *)t8) = ((double)(t21));

LAB5:    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t37 = *((double *)t9);
    t21 = (-(t4));
    t40 = xsi_vhdl_pow_double(2.0000000000000000, t21);
    t41 = (t37 * t40);
    t0 = t41;

LAB1:    return t0;
LAB3:    *((char **)t13) = t2;
    goto LAB2;

LAB4:    t20 = (t3 + 0U);
    t21 = *((int *)t20);
    t22 = (t21 - 29);
    t23 = (t3 + 4U);
    t24 = *((int *)t23);
    t25 = (t3 + 8U);
    t26 = *((int *)t25);
    xsi_vhdl_check_range_of_slice(t21, t24, t26, 29, 0, -1);
    t27 = (t22 * 1U);
    t28 = (0 + t27);
    t29 = (t2 + t28);
    t31 = (t30 + 0U);
    t32 = (t31 + 0U);
    *((int *)t32) = 29;
    t32 = (t31 + 4U);
    *((int *)t32) = 0;
    t32 = (t31 + 8U);
    *((int *)t32) = -1;
    t33 = (0 - 29);
    t34 = (t33 * -1);
    t34 = (t34 + 1);
    t32 = (t31 + 12U);
    *((unsigned int *)t32) = t34;
    t35 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t29, t30);
    t32 = (t7 + 56U);
    t36 = *((char **)t32);
    t32 = (t36 + 0);
    *((double *)t32) = ((double)(t35));
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t37 = *((double *)t9);
    t8 = (t3 + 0U);
    t21 = *((int *)t8);
    t11 = (t3 + 0U);
    t24 = *((int *)t11);
    t18 = (t21 - t24);
    t12 = (t3 + 4U);
    t26 = *((int *)t12);
    t17 = (t3 + 8U);
    t33 = *((int *)t17);
    xsi_vhdl_check_range_of_slice(t21, t26, t33, t24, 30, -1);
    t22 = (t18 * 1U);
    t27 = (0 + t22);
    t20 = (t2 + t27);
    t23 = (t3 + 0U);
    t35 = *((int *)t23);
    t25 = (t30 + 0U);
    t29 = (t25 + 0U);
    *((int *)t29) = t35;
    t29 = (t25 + 4U);
    *((int *)t29) = 30;
    t29 = (t25 + 8U);
    *((int *)t29) = -1;
    t38 = (30 - t35);
    t28 = (t38 * -1);
    t28 = (t28 + 1);
    t29 = (t25 + 12U);
    *((unsigned int *)t29) = t28;
    t39 = ieee_p_1242562249_sub_2271993008_1035706684(IEEE_P_1242562249, t20, t30);
    t40 = xsi_vhdl_pow_double(2.0000000000000000, 30);
    t41 = ((((double)(t39))) * t40);
    t42 = (t37 + t41);
    t29 = (t7 + 56U);
    t31 = *((char **)t29);
    t29 = (t31 + 0);
    *((double *)t29) = t42;
    goto LAB5;

LAB7:;
}

static void xilinxcorelib_a_2468095527_0718686667_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:
LAB3:    t1 = (t0 + 24488);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 0U, 1, 0LL);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_1(char *t0)
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
LAB3:    t1 = (t0 + 2624U);
    t2 = *((char **)t1);
    t1 = (t0 + 17360U);
    t3 = *((char **)t1);
    t4 = *((int *)t3);
    t5 = (t4 - 1);
    t6 = (15 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t9 = (t0 + 24552);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 5U);
    xsi_driver_first_trans_delta(t9, 1U, 5U, 0LL);

LAB2:    t14 = (t0 + 24248);
    *((int *)t14) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:
LAB3:    t1 = xsi_get_transient_memory(42U);
    memset(t1, 0, 42U);
    t2 = t1;
    memset(t2, (unsigned char)2, 42U);
    t3 = (t0 + 24616);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t1, 42U);
    xsi_driver_first_trans_delta(t3, 6U, 42U, 0LL);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:
LAB3:    t1 = (t0 + 2304U);
    t2 = *((char **)t1);
    t1 = (t0 + 24680);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 18U);
    xsi_driver_first_trans_delta(t1, 0U, 18U, 0LL);

LAB2:    t7 = (t0 + 24264);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:
LAB3:    t1 = (t0 + 24744);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 18U, 1, 0LL);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_5(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:
LAB3:    t1 = xsi_get_transient_memory(29U);
    memset(t1, 0, 29U);
    t2 = t1;
    memset(t2, (unsigned char)2, 29U);
    t3 = (t0 + 24808);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t1, 29U);
    xsi_driver_first_trans_delta(t3, 19U, 29U, 0LL);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_6(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:
LAB3:    t1 = (t0 + 2464U);
    t2 = *((char **)t1);
    t1 = (t0 + 24872);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 18U);
    xsi_driver_first_trans_delta(t1, 0U, 18U, 0LL);

LAB2:    t7 = (t0 + 24280);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_7(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:
LAB3:    t1 = (t0 + 24936);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 18U, 1, 0LL);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_8(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:
LAB3:    t1 = xsi_get_transient_memory(29U);
    memset(t1, 0, 29U);
    t2 = t1;
    memset(t2, (unsigned char)2, 29U);
    t3 = (t0 + 25000);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t1, 29U);
    xsi_driver_first_trans_delta(t3, 19U, 29U, 0LL);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_9(char *t0)
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
LAB3:    t1 = (t0 + 7584U);
    t2 = *((char **)t1);
    t1 = (t0 + 15680U);
    t3 = *((char **)t1);
    t4 = *((int *)t3);
    t5 = (t4 - 1);
    t6 = (47 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t9 = (t0 + 25064);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 18U);
    xsi_driver_first_trans_fast(t9);

LAB2:    t14 = (t0 + 24296);
    *((int *)t14) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_10(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:
LAB3:    t2 = (t0 + 7904U);
    t3 = *((char **)t2);
    t2 = (t0 + 40808U);
    t4 = (t0 + 43235);
    t6 = (t0 + 40200U);
    t7 = xilinxcorelib_p_3381355550_sub_3326504488_1067159583(XILINXCORELIB_P_3381355550, t4, t6);
    t8 = ieee_p_1242562249_sub_3410769178_1035706684(IEEE_P_1242562249, t1, t3, t2, t7);
    t9 = (t0 + 25128);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t8, 18U);
    xsi_driver_first_trans_fast(t9);

LAB2:    t14 = (t0 + 24312);
    *((int *)t14) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_11(char *t0)
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
LAB3:    t1 = (t0 + 6624U);
    t2 = *((char **)t1);
    t1 = (t0 + 15680U);
    t3 = *((char **)t1);
    t4 = *((int *)t3);
    t5 = (t4 - 1);
    t6 = (47 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t9 = (t0 + 25192);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 36U);
    xsi_driver_first_trans_delta(t9, 6U, 36U, 0LL);

LAB2:    t14 = (t0 + 24328);
    *((int *)t14) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_12(char *t0)
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
LAB3:    t1 = (t0 + 6784U);
    t2 = *((char **)t1);
    t1 = (t0 + 15680U);
    t3 = *((char **)t1);
    t4 = *((int *)t3);
    t5 = (t4 - 1);
    t6 = (47 - t5);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t2 + t8);
    t9 = (t0 + 25256);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t1, 36U);
    xsi_driver_first_trans_delta(t9, 6U, 36U, 0LL);

LAB2:    t14 = (t0 + 24344);
    *((int *)t14) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_13(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    int t7;
    int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned char t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;

LAB0:
LAB3:    t1 = xsi_get_transient_memory(6U);
    memset(t1, 0, 6U);
    t2 = t1;
    t3 = (t0 + 6624U);
    t4 = *((char **)t3);
    t3 = (t0 + 15680U);
    t5 = *((char **)t3);
    t6 = *((int *)t5);
    t7 = (t6 - 1);
    t8 = (t7 - 47);
    t9 = (t8 * -1);
    t10 = (1U * t9);
    t11 = (0 + t10);
    t3 = (t4 + t11);
    t12 = *((unsigned char *)t3);
    memset(t2, t12, 6U);
    t13 = (t0 + 25320);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t1, 6U);
    xsi_driver_first_trans_delta(t13, 0U, 6U, 0LL);

LAB2:    t18 = (t0 + 24360);
    *((int *)t18) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_14(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    int t7;
    int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned char t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;

LAB0:
LAB3:    t1 = xsi_get_transient_memory(6U);
    memset(t1, 0, 6U);
    t2 = t1;
    t3 = (t0 + 6784U);
    t4 = *((char **)t3);
    t3 = (t0 + 15680U);
    t5 = *((char **)t3);
    t6 = *((int *)t5);
    t7 = (t6 - 1);
    t8 = (t7 - 47);
    t9 = (t8 * -1);
    t10 = (1U * t9);
    t11 = (0 + t10);
    t3 = (t4 + t11);
    t12 = *((unsigned char *)t3);
    memset(t2, t12, 6U);
    t13 = (t0 + 25384);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t1, 6U);
    xsi_driver_first_trans_delta(t13, 0U, 6U, 0LL);

LAB2:    t18 = (t0 + 24376);
    *((int *)t18) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_15(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:
LAB3:    t1 = (t0 + 25448);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 42U, 1, 0LL);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_16(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:
LAB3:    t1 = (t0 + 25512);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_delta(t1, 42U, 1, 0LL);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_17(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:
LAB3:    t1 = (t0 + 25576);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_18(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;

LAB0:
LAB3:    t1 = (t0 + 25640);
    t2 = (t1 + 56U);
    t3 = *((char **)t2);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    *((unsigned char *)t5) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_19(char *t0)
{
    char t1[16];
    char t10[16];
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t11;
    char *t12;
    int t13;
    unsigned int t14;
    char *t16;
    int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;

LAB0:
LAB3:    t2 = (t0 + 4544U);
    t3 = *((char **)t2);
    t2 = (t0 + 15680U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 1);
    t7 = (47 - t6);
    t8 = (t7 * 1U);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t11 = (t10 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 47;
    t12 = (t11 + 4U);
    *((int *)t12) = 30;
    t12 = (t11 + 8U);
    *((int *)t12) = -1;
    t13 = (30 - 47);
    t14 = (t13 * -1);
    t14 = (t14 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t14;
    t12 = (t0 + 43243);
    t16 = (t0 + 40200U);
    t17 = xilinxcorelib_p_3381355550_sub_3326504488_1067159583(XILINXCORELIB_P_3381355550, t12, t16);
    t18 = ieee_p_1242562249_sub_3410769178_1035706684(IEEE_P_1242562249, t1, t2, t10, t17);
    t19 = (t0 + 25704);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t18, 18U);
    xsi_driver_first_trans_fast(t19);

LAB2:    t24 = (t0 + 24392);
    *((int *)t24) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void xilinxcorelib_a_2468095527_0718686667_p_20(char *t0)
{
    char t1[16];
    char t10[16];
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    char *t11;
    char *t12;
    int t13;
    unsigned int t14;
    char *t16;
    int t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;

LAB0:
LAB3:    t2 = (t0 + 4384U);
    t3 = *((char **)t2);
    t2 = (t0 + 15680U);
    t4 = *((char **)t2);
    t5 = *((int *)t4);
    t6 = (t5 - 1);
    t7 = (47 - t6);
    t8 = (t7 * 1U);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t11 = (t10 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 47;
    t12 = (t11 + 4U);
    *((int *)t12) = 30;
    t12 = (t11 + 8U);
    *((int *)t12) = -1;
    t13 = (30 - 47);
    t14 = (t13 * -1);
    t14 = (t14 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t14;
    t12 = (t0 + 43251);
    t16 = (t0 + 40200U);
    t17 = xilinxcorelib_p_3381355550_sub_3326504488_1067159583(XILINXCORELIB_P_3381355550, t12, t16);
    t18 = ieee_p_1242562249_sub_3410769178_1035706684(IEEE_P_1242562249, t1, t2, t10, t17);
    t19 = (t0 + 25768);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t18, 18U);
    xsi_driver_first_trans_fast(t19);

LAB2:    t24 = (t0 + 24408);
    *((int *)t24) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void xilinxcorelib_a_2468095527_0718686667_init()
{
	static char *pe[] = {(void *)xilinxcorelib_a_2468095527_0718686667_p_0,(void *)xilinxcorelib_a_2468095527_0718686667_p_1,(void *)xilinxcorelib_a_2468095527_0718686667_p_2,(void *)xilinxcorelib_a_2468095527_0718686667_p_3,(void *)xilinxcorelib_a_2468095527_0718686667_p_4,(void *)xilinxcorelib_a_2468095527_0718686667_p_5,(void *)xilinxcorelib_a_2468095527_0718686667_p_6,(void *)xilinxcorelib_a_2468095527_0718686667_p_7,(void *)xilinxcorelib_a_2468095527_0718686667_p_8,(void *)xilinxcorelib_a_2468095527_0718686667_p_9,(void *)xilinxcorelib_a_2468095527_0718686667_p_10,(void *)xilinxcorelib_a_2468095527_0718686667_p_11,(void *)xilinxcorelib_a_2468095527_0718686667_p_12,(void *)xilinxcorelib_a_2468095527_0718686667_p_13,(void *)xilinxcorelib_a_2468095527_0718686667_p_14,(void *)xilinxcorelib_a_2468095527_0718686667_p_15,(void *)xilinxcorelib_a_2468095527_0718686667_p_16,(void *)xilinxcorelib_a_2468095527_0718686667_p_17,(void *)xilinxcorelib_a_2468095527_0718686667_p_18,(void *)xilinxcorelib_a_2468095527_0718686667_p_19,(void *)xilinxcorelib_a_2468095527_0718686667_p_20};
	static char *se[] = {(void *)xilinxcorelib_a_2468095527_0718686667_sub_666516397_567902854,(void *)xilinxcorelib_a_2468095527_0718686667_sub_3428844293_567902854};
	xsi_register_didat("xilinxcorelib_a_2468095527_0718686667", "isim/TestFreqDDDS_bench_isim_beh.exe.sim/xilinxcorelib/a_2468095527_0718686667.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
