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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestFreqDDDS/BatDither.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
char *ieee_p_1242562249_sub_3273497107_1035706684(char *, char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_3410769178_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0638805043_3212880686_p_0(char *t0)
{
    char t10[16];
    char t11[16];
    char t19[16];
    char t33[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t12;
    char *t13;
    int t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t20;
    char *t21;
    int t22;
    unsigned int t23;
    char *t24;
    int t25;
    char *t26;
    char *t27;
    char *t28;
    int t29;
    int t30;
    unsigned int t31;
    unsigned int t32;
    char *t34;
    char *t35;
    int t36;
    unsigned int t37;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    unsigned char t43;
    unsigned char t44;
    int t45;
    int t46;
    unsigned int t47;
    int t48;
    unsigned int t49;
    unsigned int t50;
    int t51;
    int t52;
    int t53;
    unsigned int t54;
    unsigned int t55;
    int t56;
    unsigned int t57;
    int t58;
    unsigned char t59;
    char *t60;
    char *t61;
    char *t62;

LAB0:    xsi_set_current_line(69, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4352);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(70, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(72, ng0);
    t3 = (t0 + 1512U);
    t7 = *((char **)t3);
    t8 = *((unsigned char *)t7);
    t9 = (t8 == (unsigned char)3);
    if (t9 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t1 = (t0 + 3048U);
    t4 = *((char **)t1);
    t1 = (t4 + 0);
    memcpy(t1, t3, 18U);

LAB9:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    if (40 > 0)
        goto LAB11;

LAB12:    if (-1 == -1)
        goto LAB16;

LAB17:    t14 = 0;

LAB13:    t15 = (t14 - 40);
    t16 = (t15 * -1);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t2 = *((unsigned char *)t1);
    t4 = (t0 + 1992U);
    t7 = *((char **)t4);
    t12 = ((IEEE_P_1242562249) + 3112);
    t13 = (t0 + 7116U);
    t4 = xsi_base_array_concat(t4, t11, t12, (char)99, t2, (char)97, t7, t13, (char)101);
    if (41 > 0)
        goto LAB18;

LAB19:    if (-1 == -1)
        goto LAB23;

LAB24:    t22 = 0;

LAB20:    t25 = (t22 - 41U);
    t20 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t19, 0, t25);
    t24 = ((IEEE_P_1242562249) + 3112);
    t21 = xsi_base_array_concat(t21, t33, t24, (char)97, t4, t11, (char)97, t20, t19, (char)101);
    t26 = (t0 + 3048U);
    t27 = *((char **)t26);
    t26 = (t0 + 7164U);
    t28 = ieee_p_1242562249_sub_3273497107_1035706684(IEEE_P_1242562249, t10, t21, t33, t27, t26);
    t34 = (t0 + 2928U);
    t35 = *((char **)t34);
    t34 = (t35 + 0);
    t38 = (t10 + 12U);
    t23 = *((unsigned int *)t38);
    t31 = (1U * t23);
    memcpy(t34, t28, t31);
    xsi_set_current_line(80, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    if (40 > 0)
        goto LAB28;

LAB29:    if (-1 == -1)
        goto LAB33;

LAB34:    t14 = 0;

LAB30:    t15 = (t14 - 40);
    t16 = (t15 * -1);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB25;

LAB27:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 2928U);
    t3 = *((char **)t1);
    if (41 > 0)
        goto LAB87;

LAB88:    if (-1 == -1)
        goto LAB92;

LAB93:    t14 = 0;

LAB89:    t15 = (t14 - 41);
    t16 = (t15 * -1);
    t17 = (1U * t16);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB84;

LAB85:    t2 = (unsigned char)0;

LAB86:    if (t2 != 0)
        goto LAB81;

LAB83:    xsi_set_current_line(90, ng0);
    t1 = (t0 + 2928U);
    t3 = *((char **)t1);
    if (41 > 0)
        goto LAB120;

LAB121:    if (-1 == -1)
        goto LAB125;

LAB126:    t14 = 0;

LAB122:    t15 = (t14 - 1);
    t16 = (41 - t15);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t4 = (t0 + 4432);
    t7 = (t4 + 56U);
    t12 = *((char **)t7);
    t13 = (t12 + 56U);
    t20 = *((char **)t13);
    memcpy(t20, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);

LAB82:
LAB26:    xsi_set_current_line(93, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB127;

LAB129:
LAB128:    goto LAB6;

LAB8:    xsi_set_current_line(73, ng0);
    t3 = (t0 + 1672U);
    t12 = *((char **)t3);
    t3 = (t0 + 2688U);
    t13 = *((char **)t3);
    t14 = *((int *)t13);
    t15 = (t14 - 2);
    t16 = (17 - t15);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t3 = (t12 + t18);
    t20 = (t19 + 0U);
    t21 = (t20 + 0U);
    *((int *)t21) = 16;
    t21 = (t20 + 4U);
    *((int *)t21) = 0;
    t21 = (t20 + 8U);
    *((int *)t21) = -1;
    t22 = (0 - 16);
    t23 = (t22 * -1);
    t23 = (t23 + 1);
    t21 = (t20 + 12U);
    *((unsigned int *)t21) = t23;
    t21 = (t0 + 2688U);
    t24 = *((char **)t21);
    t25 = *((int *)t24);
    t21 = ieee_p_1242562249_sub_3410769178_1035706684(IEEE_P_1242562249, t11, t3, t19, t25);
    t26 = (t0 + 1832U);
    t27 = *((char **)t26);
    t26 = (t0 + 2688U);
    t28 = *((char **)t26);
    t29 = *((int *)t28);
    t30 = (t29 - 2);
    t23 = (17 - t30);
    t31 = (t23 * 1U);
    t32 = (0 + t31);
    t26 = (t27 + t32);
    t34 = (t33 + 0U);
    t35 = (t34 + 0U);
    *((int *)t35) = 16;
    t35 = (t34 + 4U);
    *((int *)t35) = 0;
    t35 = (t34 + 8U);
    *((int *)t35) = -1;
    t36 = (0 - 16);
    t37 = (t36 * -1);
    t37 = (t37 + 1);
    t35 = (t34 + 12U);
    *((unsigned int *)t35) = t37;
    t35 = ieee_p_1242562249_sub_3273497107_1035706684(IEEE_P_1242562249, t10, t21, t11, t26, t33);
    t38 = (t0 + 3048U);
    t39 = *((char **)t38);
    t38 = (t39 + 0);
    t40 = (t10 + 12U);
    t37 = *((unsigned int *)t40);
    t41 = (1U * t37);
    memcpy(t38, t35, t41);
    goto LAB9;

LAB11:    if (-1 == 1)
        goto LAB14;

LAB15:    t14 = 40;
    goto LAB13;

LAB14:    t14 = 0;
    goto LAB13;

LAB16:    t14 = 40;
    goto LAB13;

LAB18:    if (-1 == 1)
        goto LAB21;

LAB22:    t22 = 41;
    goto LAB20;

LAB21:    t22 = 0;
    goto LAB20;

LAB23:    t22 = 41;
    goto LAB20;

LAB25:    xsi_set_current_line(81, ng0);
    t4 = (t0 + 2928U);
    t7 = *((char **)t4);
    if (41 > 0)
        goto LAB41;

LAB42:    if (-1 == -1)
        goto LAB46;

LAB47:    t22 = 0;

LAB43:    t25 = (t22 - 41);
    t23 = (t25 * -1);
    t31 = (1U * t23);
    t32 = (0 + t31);
    t4 = (t7 + t32);
    t8 = *((unsigned char *)t4);
    t9 = (t8 == (unsigned char)3);
    if (t9 == 1)
        goto LAB38;

LAB39:    t6 = (unsigned char)0;

LAB40:    if (t6 != 0)
        goto LAB35;

LAB37:    xsi_set_current_line(84, ng0);
    t1 = (t0 + 2928U);
    t3 = *((char **)t1);
    if (41 > 0)
        goto LAB74;

LAB75:    if (-1 == -1)
        goto LAB79;

LAB80:    t14 = 0;

LAB76:    t15 = (t14 - 1);
    t16 = (41 - t15);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t3 + t18);
    t4 = (t0 + 4432);
    t7 = (t4 + 56U);
    t12 = *((char **)t7);
    t13 = (t12 + 56U);
    t20 = *((char **)t13);
    memcpy(t20, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);

LAB36:    goto LAB26;

LAB28:    if (-1 == 1)
        goto LAB31;

LAB32:    t14 = 40;
    goto LAB30;

LAB31:    t14 = 0;
    goto LAB30;

LAB33:    t14 = 40;
    goto LAB30;

LAB35:    xsi_set_current_line(82, ng0);
    t20 = (t0 + 7372);
    t24 = xsi_get_transient_memory(23U);
    memset(t24, 0, 23U);
    t26 = t24;
    if (23 > 0)
        goto LAB55;

LAB56:    if (-1 == -1)
        goto LAB60;

LAB61:    t45 = 0;

LAB57:    t46 = (t45 - 1);
    if (-1 == 1)
        goto LAB62;

LAB63:    t47 = 0;

LAB64:    t48 = (t47 - 0);
    t49 = (t48 * 1);
    t50 = (1U * t49);
    t27 = (t26 + t50);
    if (23 > 0)
        goto LAB65;

LAB66:    if (-1 == -1)
        goto LAB70;

LAB71:    t51 = 0;

LAB67:    t52 = (t51 - 1);
    t53 = (0 - t52);
    t54 = (t53 * -1);
    t54 = (t54 + 1);
    t55 = (1U * t54);
    memset(t27, (unsigned char)2, t55);
    t34 = ((IEEE_P_2592010699) + 4024);
    t35 = (t11 + 0U);
    t38 = (t35 + 0U);
    *((int *)t38) = 0;
    t38 = (t35 + 4U);
    *((int *)t38) = 0;
    t38 = (t35 + 8U);
    *((int *)t38) = 1;
    t56 = (0 - 0);
    t57 = (t56 * 1);
    t57 = (t57 + 1);
    t38 = (t35 + 12U);
    *((unsigned int *)t38) = t57;
    t38 = (t19 + 0U);
    t39 = (t38 + 0U);
    *((int *)t39) = 0;
    t39 = (t38 + 4U);
    *((int *)t39) = 22;
    t39 = (t38 + 8U);
    *((int *)t39) = 1;
    t58 = (22 - 0);
    t57 = (t58 * 1);
    t57 = (t57 + 1);
    t39 = (t38 + 12U);
    *((unsigned int *)t39) = t57;
    t28 = xsi_base_array_concat(t28, t10, t34, (char)97, t20, t11, (char)97, t24, t19, (char)101);
    t57 = (1U + 23U);
    t59 = (24U != t57);
    if (t59 == 1)
        goto LAB72;

LAB73:    t39 = (t0 + 4432);
    t40 = (t39 + 56U);
    t60 = *((char **)t40);
    t61 = (t60 + 56U);
    t62 = *((char **)t61);
    memcpy(t62, t28, 24U);
    xsi_driver_first_trans_fast_port(t39);
    goto LAB36;

LAB38:    t12 = (t0 + 2928U);
    t13 = *((char **)t12);
    if (41 > 0)
        goto LAB48;

LAB49:    if (-1 == -1)
        goto LAB53;

LAB54:    t29 = 0;

LAB50:    t30 = (t29 - 1);
    t36 = (t30 - 41);
    t37 = (t36 * -1);
    t41 = (1U * t37);
    t42 = (0 + t41);
    t12 = (t13 + t42);
    t43 = *((unsigned char *)t12);
    t44 = (t43 == (unsigned char)2);
    t6 = t44;
    goto LAB40;

LAB41:    if (-1 == 1)
        goto LAB44;

LAB45:    t22 = 41;
    goto LAB43;

LAB44:    t22 = 0;
    goto LAB43;

LAB46:    t22 = 41;
    goto LAB43;

LAB48:    if (-1 == 1)
        goto LAB51;

LAB52:    t29 = 41;
    goto LAB50;

LAB51:    t29 = 0;
    goto LAB50;

LAB53:    t29 = 41;
    goto LAB50;

LAB55:    if (-1 == 1)
        goto LAB58;

LAB59:    t45 = 23;
    goto LAB57;

LAB58:    t45 = 0;
    goto LAB57;

LAB60:    t45 = 23;
    goto LAB57;

LAB62:    t47 = t46;
    goto LAB64;

LAB65:    if (-1 == 1)
        goto LAB68;

LAB69:    t51 = 23;
    goto LAB67;

LAB68:    t51 = 0;
    goto LAB67;

LAB70:    t51 = 23;
    goto LAB67;

LAB72:    xsi_size_not_matching(24U, t57, 0);
    goto LAB73;

LAB74:    if (-1 == 1)
        goto LAB77;

LAB78:    t14 = 41;
    goto LAB76;

LAB77:    t14 = 0;
    goto LAB76;

LAB79:    t14 = 41;
    goto LAB76;

LAB81:    xsi_set_current_line(88, ng0);
    t12 = (t0 + 7373);
    t20 = xsi_get_transient_memory(23U);
    memset(t20, 0, 23U);
    t21 = t20;
    if (23 > 0)
        goto LAB101;

LAB102:    if (-1 == -1)
        goto LAB106;

LAB107:    t30 = 0;

LAB103:    t36 = (t30 - 1);
    if (-1 == 1)
        goto LAB108;

LAB109:    t37 = 0;

LAB110:    t45 = (t37 - 0);
    t41 = (t45 * 1);
    t42 = (1U * t41);
    t24 = (t21 + t42);
    if (23 > 0)
        goto LAB111;

LAB112:    if (-1 == -1)
        goto LAB116;

LAB117:    t46 = 0;

LAB113:    t48 = (t46 - 1);
    t51 = (0 - t48);
    t47 = (t51 * -1);
    t47 = (t47 + 1);
    t49 = (1U * t47);
    memset(t24, (unsigned char)3, t49);
    t27 = ((IEEE_P_2592010699) + 4024);
    t28 = (t11 + 0U);
    t34 = (t28 + 0U);
    *((int *)t34) = 0;
    t34 = (t28 + 4U);
    *((int *)t34) = 0;
    t34 = (t28 + 8U);
    *((int *)t34) = 1;
    t52 = (0 - 0);
    t50 = (t52 * 1);
    t50 = (t50 + 1);
    t34 = (t28 + 12U);
    *((unsigned int *)t34) = t50;
    t34 = (t19 + 0U);
    t35 = (t34 + 0U);
    *((int *)t35) = 0;
    t35 = (t34 + 4U);
    *((int *)t35) = 22;
    t35 = (t34 + 8U);
    *((int *)t35) = 1;
    t53 = (22 - 0);
    t50 = (t53 * 1);
    t50 = (t50 + 1);
    t35 = (t34 + 12U);
    *((unsigned int *)t35) = t50;
    t26 = xsi_base_array_concat(t26, t10, t27, (char)97, t12, t11, (char)97, t20, t19, (char)101);
    t50 = (1U + 23U);
    t43 = (24U != t50);
    if (t43 == 1)
        goto LAB118;

LAB119:    t35 = (t0 + 4432);
    t38 = (t35 + 56U);
    t39 = *((char **)t38);
    t40 = (t39 + 56U);
    t60 = *((char **)t40);
    memcpy(t60, t26, 24U);
    xsi_driver_first_trans_fast_port(t35);
    goto LAB82;

LAB84:    t4 = (t0 + 2928U);
    t7 = *((char **)t4);
    if (41 > 0)
        goto LAB94;

LAB95:    if (-1 == -1)
        goto LAB99;

LAB100:    t22 = 0;

LAB96:    t25 = (t22 - 1);
    t29 = (t25 - 41);
    t23 = (t29 * -1);
    t31 = (1U * t23);
    t32 = (0 + t31);
    t4 = (t7 + t32);
    t8 = *((unsigned char *)t4);
    t9 = (t8 == (unsigned char)3);
    t2 = t9;
    goto LAB86;

LAB87:    if (-1 == 1)
        goto LAB90;

LAB91:    t14 = 41;
    goto LAB89;

LAB90:    t14 = 0;
    goto LAB89;

LAB92:    t14 = 41;
    goto LAB89;

LAB94:    if (-1 == 1)
        goto LAB97;

LAB98:    t22 = 41;
    goto LAB96;

LAB97:    t22 = 0;
    goto LAB96;

LAB99:    t22 = 41;
    goto LAB96;

LAB101:    if (-1 == 1)
        goto LAB104;

LAB105:    t30 = 23;
    goto LAB103;

LAB104:    t30 = 0;
    goto LAB103;

LAB106:    t30 = 23;
    goto LAB103;

LAB108:    t37 = t36;
    goto LAB110;

LAB111:    if (-1 == 1)
        goto LAB114;

LAB115:    t46 = 23;
    goto LAB113;

LAB114:    t46 = 0;
    goto LAB113;

LAB116:    t46 = 23;
    goto LAB113;

LAB118:    xsi_size_not_matching(24U, t50, 0);
    goto LAB119;

LAB120:    if (-1 == 1)
        goto LAB123;

LAB124:    t14 = 41;
    goto LAB122;

LAB123:    t14 = 0;
    goto LAB122;

LAB125:    t14 = 41;
    goto LAB122;

LAB127:    xsi_set_current_line(94, ng0);
    t1 = (t0 + 1992U);
    t4 = *((char **)t1);
    if (40 > 0)
        goto LAB130;

LAB131:    if (-1 == -1)
        goto LAB135;

LAB136:    t14 = 0;

LAB132:    t16 = (40 - t14);
    t17 = (t16 * 1U);
    t18 = (0 + t17);
    t1 = (t4 + t18);
    t7 = (t0 + 4432);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    t20 = (t13 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t1, 24U);
    xsi_driver_first_trans_fast_port(t7);
    goto LAB128;

LAB130:    if (-1 == 1)
        goto LAB133;

LAB134:    t14 = 40;
    goto LAB132;

LAB133:    t14 = 0;
    goto LAB132;

LAB135:    t14 = 40;
    goto LAB132;

}


extern void work_a_0638805043_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0638805043_3212880686_p_0};
	xsi_register_didat("work_a_0638805043_3212880686", "isim/TestFreqDDDS_bench_isim_beh.exe.sim/work/a_0638805043_3212880686.didat");
	xsi_register_executes(pe);
}
