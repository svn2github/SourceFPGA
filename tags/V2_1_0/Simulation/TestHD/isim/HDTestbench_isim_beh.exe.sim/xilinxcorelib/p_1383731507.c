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
extern char *XILINXCORELIB_P_1837083571;
extern char *STD_STANDARD;
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3499444699;

char *ieee_p_3499444699_sub_2213602152_3536714472(char *, char *, int , int );
int xilinxcorelib_p_1837083571_sub_2363168970_775299228(char *, char *, char *);
int xilinxcorelib_p_1837083571_sub_2363173326_775299228(char *, char *, char *);
unsigned char xilinxcorelib_p_1837083571_sub_719035815_775299228(char *, char *, char *);


int xilinxcorelib_p_1383731507_sub_3554256854_2061450527(char *t1, char *t2, char *t3)
{
    char t5[24];
    int t0;
    char *t6;
    unsigned char t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    int t11;
    unsigned char t12;
    char *t13;

LAB0:    t6 = (t5 + 4U);
    t7 = (t2 != 0);
    if (t7 == 1)
        goto LAB3;

LAB2:    t8 = (t5 + 12U);
    *((char **)t8) = t3;
    t10 = xilinxcorelib_p_1837083571_sub_719035815_775299228(XILINXCORELIB_P_1837083571, t2, t3);
    if (t10 == 1)
        goto LAB7;

LAB8:    t11 = xilinxcorelib_p_1837083571_sub_2363168970_775299228(XILINXCORELIB_P_1837083571, t2, t3);
    t12 = (t11 > 0);
    t9 = t12;

LAB9:    if (t9 != 0)
        goto LAB4;

LAB6:    t11 = xilinxcorelib_p_1837083571_sub_2363173326_775299228(XILINXCORELIB_P_1837083571, t2, t3);
    t7 = (t11 > 0);
    if (t7 != 0)
        goto LAB11;

LAB12:    if ((unsigned char)0 == 0)
        goto LAB14;

LAB15:
LAB5:    t0 = 18;

LAB1:    return t0;
LAB3:    *((char **)t6) = t2;
    goto LAB2;

LAB4:    t0 = 18;
    goto LAB1;

LAB7:    t9 = (unsigned char)1;
    goto LAB9;

LAB10:    goto LAB5;

LAB11:    t0 = 25;
    goto LAB1;

LAB13:    goto LAB5;

LAB14:    t13 = (t1 + 5080);
    xsi_report(t13, 47U, (unsigned char)2);
    goto LAB15;

LAB16:;
}

int xilinxcorelib_p_1383731507_sub_3941146782_2061450527(char *t1, int t2, int t3, char *t4, char *t5, int t6, int t7, int t8, int t9)
{
    char t11[48];
    int t0;
    char *t12;
    char *t13;
    char *t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned char t21;
    unsigned char t22;
    unsigned char t23;
    char *t24;
    int t26;
    unsigned char t27;
    unsigned char t28;
    unsigned char t29;

LAB0:    t12 = (t11 + 4U);
    *((int *)t12) = t2;
    t13 = (t11 + 8U);
    *((int *)t13) = t3;
    t14 = (t11 + 12U);
    t15 = (t4 != 0);
    if (t15 == 1)
        goto LAB3;

LAB2:    t16 = (t11 + 20U);
    *((char **)t16) = t5;
    t17 = (t11 + 28U);
    *((int *)t17) = t6;
    t18 = (t11 + 32U);
    *((int *)t18) = t7;
    t19 = (t11 + 36U);
    *((int *)t19) = t8;
    t20 = (t11 + 40U);
    *((int *)t20) = t9;
    t22 = (t7 == 0);
    if (t22 == 1)
        goto LAB6;

LAB7:    t23 = (t7 == 1);
    t21 = t23;

LAB8:    if (t21 == 0)
        goto LAB4;

LAB5:    t21 = (t8 == 0);
    if (t21 == 1)
        goto LAB11;

LAB12:    t22 = (t8 == 1);
    t15 = t22;

LAB13:    if (t15 == 0)
        goto LAB9;

LAB10:    t21 = (t8 == 0);
    if (t21 == 1)
        goto LAB16;

LAB17:    t26 = xilinxcorelib_p_1837083571_sub_2363173326_775299228(XILINXCORELIB_P_1837083571, t4, t5);
    t22 = (t26 > 0);
    t15 = t22;

LAB18:    if (t15 == 0)
        goto LAB14;

LAB15:    t21 = (t9 == 0);
    if (t21 == 1)
        goto LAB21;

LAB22:    t22 = (t9 == 1);
    t15 = t22;

LAB23:    if (t15 == 0)
        goto LAB19;

LAB20:    t26 = (-(1));
    t22 = (t6 >= t26);
    if (t22 == 1)
        goto LAB29;

LAB30:    t21 = (unsigned char)0;

LAB31:    if (t21 == 1)
        goto LAB26;

LAB27:    t28 = (t6 >= 16);
    if (t28 == 1)
        goto LAB32;

LAB33:    t27 = (unsigned char)0;

LAB34:    t15 = t27;

LAB28:    if (t15 == 0)
        goto LAB24;

LAB25:    t15 = (t2 > 0);
    if (t15 != 0)
        goto LAB35;

LAB37:
LAB36:    t0 = 0;

LAB1:    return t0;
LAB3:    *((char **)t14) = t4;
    goto LAB2;

LAB4:    t24 = (t1 + 5127);
    xsi_report(t24, 50U, (unsigned char)2);
    goto LAB5;

LAB6:    t21 = (unsigned char)1;
    goto LAB8;

LAB9:    t24 = (t1 + 5177);
    xsi_report(t24, 50U, (unsigned char)2);
    goto LAB10;

LAB11:    t15 = (unsigned char)1;
    goto LAB13;

LAB14:    t24 = (t1 + 5227);
    xsi_report(t24, 61U, (unsigned char)2);
    goto LAB15;

LAB16:    t15 = (unsigned char)1;
    goto LAB18;

LAB19:    t24 = (t1 + 5288);
    xsi_report(t24, 50U, (unsigned char)2);
    goto LAB20;

LAB21:    t15 = (unsigned char)1;
    goto LAB23;

LAB24:    t24 = (t1 + 5338);
    xsi_report(t24, 49U, (unsigned char)2);
    goto LAB25;

LAB26:    t15 = (unsigned char)1;
    goto LAB28;

LAB29:    t23 = (t6 <= 4);
    t21 = t23;
    goto LAB31;

LAB32:    t29 = (t6 <= 31);
    t27 = t29;
    goto LAB34;

LAB35:    if ((unsigned char)0 == 0)
        goto LAB38;

LAB39:    t26 = xilinxcorelib_p_1837083571_sub_2363173326_775299228(XILINXCORELIB_P_1837083571, t4, t5);
    t15 = (t26 > 0);
    if (t15 == 0)
        goto LAB40;

LAB41:    goto LAB36;

LAB38:    t24 = (t1 + 5387);
    xsi_report(t24, 48U, (unsigned char)1);
    goto LAB39;

LAB40:    t24 = (t1 + 5435);
    xsi_report(t24, 47U, (unsigned char)1);
    goto LAB41;

LAB42:;
}

char *xilinxcorelib_p_1383731507_sub_1091906742_2061450527(char *t1, int t2, char *t3, char *t4)
{
    char t5[368];
    char t6[24];
    char t10[24];
    char t16[8];
    char t21[16];
    char t28[8];
    char t48[16];
    char *t0;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t22;
    char *t23;
    int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    unsigned char t34;
    char *t35;
    char *t36;
    char *t37;
    int t38;
    int t39;
    int t40;
    char *t41;
    int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned char t46;
    unsigned char t47;
    int t49;
    int t50;
    int t51;
    int t52;
    int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;

LAB0:    t7 = (t5 + 4U);
    t8 = (t1 + 3312);
    t9 = (t7 + 88U);
    *((char **)t9) = t8;
    t11 = (t7 + 56U);
    *((char **)t11) = t10;
    xsi_type_set_default_value(t8, t10, 0);
    t12 = (t7 + 80U);
    *((unsigned int *)t12) = 24U;
    t13 = (t5 + 124U);
    t14 = ((STD_STANDARD) + 384);
    t15 = (t13 + 88U);
    *((char **)t15) = t14;
    t17 = (t13 + 56U);
    *((char **)t17) = t16;
    xsi_type_set_default_value(t14, t16, 0);
    t18 = (t13 + 80U);
    *((unsigned int *)t18) = 4U;
    t19 = xsi_get_transient_memory(5U);
    memset(t19, 0, 5U);
    t20 = t19;
    memset(t20, (unsigned char)2, 5U);
    t22 = (t21 + 0U);
    t23 = (t22 + 0U);
    *((int *)t23) = 5;
    t23 = (t22 + 4U);
    *((int *)t23) = 1;
    t23 = (t22 + 8U);
    *((int *)t23) = -1;
    t24 = (1 - 5);
    t25 = (t24 * -1);
    t25 = (t25 + 1);
    t23 = (t22 + 12U);
    *((unsigned int *)t23) = t25;
    t23 = (t5 + 244U);
    t26 = ((IEEE_P_2592010699) + 4024);
    t27 = (t23 + 88U);
    *((char **)t27) = t26;
    t29 = (t23 + 56U);
    *((char **)t29) = t28;
    memcpy(t28, t19, 5U);
    t30 = (t23 + 64U);
    *((char **)t30) = t21;
    t31 = (t23 + 80U);
    *((unsigned int *)t31) = 5U;
    t32 = (t6 + 4U);
    *((int *)t32) = t2;
    t33 = (t6 + 8U);
    t34 = (t3 != 0);
    if (t34 == 1)
        goto LAB3;

LAB2:    t35 = (t6 + 16U);
    *((char **)t35) = t4;
    t36 = (t1 + 1168U);
    t37 = *((char **)t36);
    t38 = *((int *)t37);
    t39 = 0;
    t40 = t38;

LAB4:    if (t39 <= t40)
        goto LAB5;

LAB7:    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t25 = (0 + 0U);
    t8 = (t9 + t25);
    *((int *)t8) = 0;
    t8 = (t1 + 1168U);
    t9 = *((char **)t8);
    t24 = *((int *)t9);
    t38 = xsi_vhdl_pow(2, t24);
    t46 = (t2 >= t38);
    if (t46 == 1)
        goto LAB12;

LAB13:    t34 = (unsigned char)0;

LAB14:    if (t34 != 0)
        goto LAB9;

LAB11:    t8 = (t13 + 56U);
    t9 = *((char **)t8);
    t8 = (t9 + 0);
    *((int *)t8) = t2;
    t8 = (t13 + 56U);
    t9 = *((char **)t8);
    t24 = *((int *)t9);
    t34 = (t24 != 0);
    if (t34 != 0)
        goto LAB23;

LAB25:
LAB24:    t8 = (t13 + 56U);
    t9 = *((char **)t8);
    t24 = *((int *)t9);
    t34 = (t24 != 0);
    if (t34 != 0)
        goto LAB26;

LAB28:
LAB27:    t8 = (t13 + 56U);
    t9 = *((char **)t8);
    t24 = *((int *)t9);
    t34 = (t24 != 0);
    if (t34 != 0)
        goto LAB29;

LAB31:
LAB30:    t8 = (t13 + 56U);
    t9 = *((char **)t8);
    t24 = *((int *)t9);
    t34 = (t24 > 0);
    if (t34 != 0)
        goto LAB32;

LAB34:
LAB33:    t8 = (t13 + 56U);
    t9 = *((char **)t8);
    t24 = *((int *)t9);
    t34 = (t24 > 0);
    if (t34 != 0)
        goto LAB35;

LAB37:
LAB36:
LAB10:    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t0 = xsi_get_transient_memory(24U);
    memcpy(t0, t9, 24U);

LAB1:    return t0;
LAB3:    *((char **)t33) = t3;
    goto LAB2;

LAB5:    t36 = (t7 + 56U);
    t41 = *((char **)t36);
    t42 = (t39 - 0);
    t25 = (t42 * 1);
    xsi_vhdl_check_range_of_index(0, 4, 1, t39);
    t43 = (4U * t25);
    t44 = (0 + 4U);
    t45 = (t44 + t43);
    t36 = (t41 + t45);
    *((int *)t36) = 0;

LAB6:    if (t39 == t40)
        goto LAB7;

LAB8:    t24 = (t39 + 1);
    t39 = t24;
    goto LAB4;

LAB9:    t8 = (t1 + 1168U);
    t12 = *((char **)t8);
    t49 = *((int *)t12);
    t50 = (t49 + 1);
    t8 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t48, t2, t50);
    t14 = (t23 + 56U);
    t15 = *((char **)t14);
    t14 = (t21 + 0U);
    t51 = *((int *)t14);
    t17 = (t1 + 1168U);
    t18 = *((char **)t17);
    t52 = *((int *)t18);
    t53 = (t52 + 1);
    t25 = (t51 - t53);
    t43 = (t25 * 1U);
    t44 = (0 + t43);
    t17 = (t15 + t44);
    t19 = (t48 + 12U);
    t45 = *((unsigned int *)t19);
    t45 = (t45 * 1U);
    memcpy(t17, t8, t45);
    t8 = (t1 + 1168U);
    t9 = *((char **)t8);
    t24 = *((int *)t9);
    t38 = 1;
    t39 = t24;

LAB15:    if (t38 <= t39)
        goto LAB16;

LAB18:    goto LAB10;

LAB12:    t8 = (t1 + 1168U);
    t11 = *((char **)t8);
    t39 = *((int *)t11);
    t40 = (t39 + 1);
    t42 = xsi_vhdl_pow(2, t40);
    t47 = (t2 < t42);
    t34 = t47;
    goto LAB14;

LAB16:    t8 = (t23 + 56U);
    t11 = *((char **)t8);
    t8 = (t21 + 0U);
    t40 = *((int *)t8);
    t12 = (t21 + 8U);
    t42 = *((int *)t12);
    t49 = (t38 - t40);
    t25 = (t49 * t42);
    t14 = (t21 + 4U);
    t50 = *((int *)t14);
    xsi_vhdl_check_range_of_index(t40, t50, t42, t38);
    t43 = (1U * t25);
    t44 = (0 + t43);
    t15 = (t11 + t44);
    t34 = *((unsigned char *)t15);
    t46 = (t34 == (unsigned char)3);
    if (t46 != 0)
        goto LAB19;

LAB21:
LAB20:
LAB17:    if (t38 == t39)
        goto LAB18;

LAB22:    t24 = (t38 + 1);
    t38 = t24;
    goto LAB15;

LAB19:    t17 = (t7 + 56U);
    t18 = *((char **)t17);
    t51 = (t38 - 0);
    t45 = (t51 * 1);
    xsi_vhdl_check_range_of_index(0, 4, 1, t38);
    t54 = (4U * t45);
    t55 = (0 + 4U);
    t56 = (t55 + t54);
    t17 = (t18 + t56);
    *((int *)t17) = 1;
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t25 = (0 + 0U);
    t8 = (t9 + t25);
    t24 = *((int *)t8);
    t40 = (t24 + 1);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t43 = (0 + 0U);
    t11 = (t12 + t43);
    *((int *)t11) = t40;
    goto LAB20;

LAB23:    t8 = (t13 + 56U);
    t11 = *((char **)t8);
    t38 = *((int *)t11);
    t39 = (t38 - 1);
    t8 = (t13 + 56U);
    t12 = *((char **)t8);
    t8 = (t12 + 0);
    *((int *)t8) = t39;
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t8 = (t1 + 1648U);
    t11 = *((char **)t8);
    t24 = *((int *)t11);
    t38 = (t24 - 0);
    t25 = (t38 * 1);
    t43 = (4U * t25);
    t44 = (0 + 4U);
    t45 = (t44 + t43);
    t8 = (t9 + t45);
    t39 = *((int *)t8);
    t40 = (t39 + 1);
    t12 = (t7 + 56U);
    t14 = *((char **)t12);
    t12 = (t1 + 1648U);
    t15 = *((char **)t12);
    t42 = *((int *)t15);
    t49 = (t42 - 0);
    t54 = (t49 * 1);
    t55 = (4U * t54);
    t56 = (0 + 4U);
    t57 = (t56 + t55);
    t12 = (t14 + t57);
    *((int *)t12) = t40;
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t25 = (0 + 0U);
    t8 = (t9 + t25);
    t24 = *((int *)t8);
    t38 = (t24 + 1);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t43 = (0 + 0U);
    t11 = (t12 + t43);
    *((int *)t11) = t38;
    goto LAB24;

LAB26:    t8 = (t13 + 56U);
    t11 = *((char **)t8);
    t38 = *((int *)t11);
    t39 = (t38 - 1);
    t8 = (t13 + 56U);
    t12 = *((char **)t8);
    t8 = (t12 + 0);
    *((int *)t8) = t39;
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t8 = (t1 + 1528U);
    t11 = *((char **)t8);
    t24 = *((int *)t11);
    t38 = (t24 - 0);
    t25 = (t38 * 1);
    t43 = (4U * t25);
    t44 = (0 + 4U);
    t45 = (t44 + t43);
    t8 = (t9 + t45);
    t39 = *((int *)t8);
    t40 = (t39 + 1);
    t12 = (t7 + 56U);
    t14 = *((char **)t12);
    t12 = (t1 + 1528U);
    t15 = *((char **)t12);
    t42 = *((int *)t15);
    t49 = (t42 - 0);
    t54 = (t49 * 1);
    t55 = (4U * t54);
    t56 = (0 + 4U);
    t57 = (t56 + t55);
    t12 = (t14 + t57);
    *((int *)t12) = t40;
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t25 = (0 + 0U);
    t8 = (t9 + t25);
    t24 = *((int *)t8);
    t38 = (t24 + 1);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t43 = (0 + 0U);
    t11 = (t12 + t43);
    *((int *)t11) = t38;
    goto LAB27;

LAB29:    t8 = (t13 + 56U);
    t11 = *((char **)t8);
    t38 = *((int *)t11);
    t39 = (t38 - 1);
    t8 = (t13 + 56U);
    t12 = *((char **)t8);
    t8 = (t12 + 0);
    *((int *)t8) = t39;
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t8 = (t1 + 1408U);
    t11 = *((char **)t8);
    t24 = *((int *)t11);
    t38 = (t24 - 0);
    t25 = (t38 * 1);
    t43 = (4U * t25);
    t44 = (0 + 4U);
    t45 = (t44 + t43);
    t8 = (t9 + t45);
    t39 = *((int *)t8);
    t40 = (t39 + 1);
    t12 = (t7 + 56U);
    t14 = *((char **)t12);
    t12 = (t1 + 1408U);
    t15 = *((char **)t12);
    t42 = *((int *)t15);
    t49 = (t42 - 0);
    t54 = (t49 * 1);
    t55 = (4U * t54);
    t56 = (0 + 4U);
    t57 = (t56 + t55);
    t12 = (t14 + t57);
    *((int *)t12) = t40;
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t25 = (0 + 0U);
    t8 = (t9 + t25);
    t24 = *((int *)t8);
    t38 = (t24 + 1);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t43 = (0 + 0U);
    t11 = (t12 + t43);
    *((int *)t11) = t38;
    goto LAB30;

LAB32:    t8 = (t13 + 56U);
    t11 = *((char **)t8);
    t38 = *((int *)t11);
    t39 = (t38 - 1);
    t8 = (t13 + 56U);
    t12 = *((char **)t8);
    t8 = (t12 + 0);
    *((int *)t8) = t39;
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t8 = (t1 + 1288U);
    t11 = *((char **)t8);
    t24 = *((int *)t11);
    t38 = (t24 - 0);
    t25 = (t38 * 1);
    t43 = (4U * t25);
    t44 = (0 + 4U);
    t45 = (t44 + t43);
    t8 = (t9 + t45);
    t39 = *((int *)t8);
    t40 = (t39 + 1);
    t12 = (t7 + 56U);
    t14 = *((char **)t12);
    t12 = (t1 + 1288U);
    t15 = *((char **)t12);
    t42 = *((int *)t15);
    t49 = (t42 - 0);
    t54 = (t49 * 1);
    t55 = (4U * t54);
    t56 = (0 + 4U);
    t57 = (t56 + t55);
    t12 = (t14 + t57);
    *((int *)t12) = t40;
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t25 = (0 + 0U);
    t8 = (t9 + t25);
    t24 = *((int *)t8);
    t38 = (t24 + 1);
    t11 = (t7 + 56U);
    t12 = *((char **)t11);
    t43 = (0 + 0U);
    t11 = (t12 + t43);
    *((int *)t11) = t38;
    goto LAB33;

LAB35:    if ((unsigned char)0 == 0)
        goto LAB38;

LAB39:    goto LAB36;

LAB38:    t8 = (t1 + 5482);
    xsi_report(t8, 44U, (unsigned char)2);
    goto LAB39;

LAB40:;
}


extern void xilinxcorelib_p_1383731507_init()
{
	static char *se[] = {(void *)xilinxcorelib_p_1383731507_sub_3554256854_2061450527,(void *)xilinxcorelib_p_1383731507_sub_3941146782_2061450527,(void *)xilinxcorelib_p_1383731507_sub_1091906742_2061450527};
	xsi_register_didat("xilinxcorelib_p_1383731507", "isim/HDTestbench_isim_beh.exe.sim/xilinxcorelib/p_1383731507.didat");
	xsi_register_subprogram_executes(se);
}
