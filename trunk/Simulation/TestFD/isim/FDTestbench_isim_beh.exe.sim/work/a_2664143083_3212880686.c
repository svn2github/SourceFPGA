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
static const char *ng0 = "E:/Source/BatDroidV2/SourceFPGA/Simulation/TestFD/BatDither.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
char *ieee_p_1242562249_sub_3273497107_1035706684(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2664143083_3212880686_p_0(char *t0)
{
    char t7[16];
    char t17[16];
    char t20[16];
    char t25[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t8;
    int t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned char t14;
    char *t15;
    char *t16;
    char *t18;
    char *t19;
    int t21;
    int t22;
    char *t23;
    char *t24;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned char t36;
    int t37;
    int t38;
    int t39;
    unsigned int t40;
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

LAB0:    xsi_set_current_line(43, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3912);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(44, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(46, ng0);
    t3 = (t0 + 1672U);
    t8 = *((char **)t3);
    if (24 > 0)
        goto LAB8;

LAB9:    if (-1 == -1)
        goto LAB13;

LAB14:    t9 = 0;

LAB10:    t10 = (t9 - 24);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t3 = (t8 + t13);
    t14 = *((unsigned char *)t3);
    t15 = (t0 + 1672U);
    t16 = *((char **)t15);
    t18 = ((IEEE_P_1242562249) + 3112);
    t19 = (t0 + 6284U);
    t15 = xsi_base_array_concat(t15, t17, t18, (char)99, t14, (char)97, t16, t19, (char)101);
    if (25 > 0)
        goto LAB15;

LAB16:    if (-1 == -1)
        goto LAB20;

LAB21:    t21 = 0;

LAB17:    t22 = (t21 - 25U);
    t23 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t20, 0, t22);
    t26 = ((IEEE_P_1242562249) + 3112);
    t24 = xsi_base_array_concat(t24, t25, t26, (char)97, t15, t17, (char)97, t23, t20, (char)101);
    t27 = (t0 + 1512U);
    t28 = *((char **)t27);
    t27 = (t0 + 6268U);
    t29 = ieee_p_1242562249_sub_3273497107_1035706684(IEEE_P_1242562249, t7, t24, t25, t28, t27);
    t30 = (t0 + 2608U);
    t31 = *((char **)t30);
    t30 = (t31 + 0);
    t32 = (t7 + 12U);
    t33 = *((unsigned int *)t32);
    t34 = (1U * t33);
    memcpy(t30, t29, t34);
    xsi_set_current_line(48, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    if (24 > 0)
        goto LAB25;

LAB26:    if (-1 == -1)
        goto LAB30;

LAB31:    t9 = 0;

LAB27:    t10 = (t9 - 24);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t3 + t13);
    t2 = *((unsigned char *)t1);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB22;

LAB24:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 2608U);
    t3 = *((char **)t1);
    if (25 > 0)
        goto LAB84;

LAB85:    if (-1 == -1)
        goto LAB89;

LAB90:    t9 = 0;

LAB86:    t10 = (t9 - 25);
    t11 = (t10 * -1);
    t12 = (1U * t11);
    t13 = (0 + t12);
    t1 = (t3 + t13);
    t5 = *((unsigned char *)t1);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB81;

LAB82:    t2 = (unsigned char)0;

LAB83:    if (t2 != 0)
        goto LAB78;

LAB80:    xsi_set_current_line(58, ng0);
    t1 = (t0 + 2608U);
    t3 = *((char **)t1);
    if (25 > 0)
        goto LAB117;

LAB118:    if (-1 == -1)
        goto LAB122;

LAB123:    t9 = 0;

LAB119:    t10 = (t9 - 1);
    t11 = (25 - t10);
    t12 = (t11 * 1U);
    t13 = (0 + t12);
    t1 = (t3 + t13);
    t4 = (t0 + 3992);
    t8 = (t4 + 56U);
    t15 = *((char **)t8);
    t16 = (t15 + 56U);
    t18 = *((char **)t16);
    memcpy(t18, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);

LAB79:
LAB23:    xsi_set_current_line(61, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB124;

LAB126:
LAB125:    goto LAB6;

LAB8:    if (-1 == 1)
        goto LAB11;

LAB12:    t9 = 24;
    goto LAB10;

LAB11:    t9 = 0;
    goto LAB10;

LAB13:    t9 = 24;
    goto LAB10;

LAB15:    if (-1 == 1)
        goto LAB18;

LAB19:    t21 = 25;
    goto LAB17;

LAB18:    t21 = 0;
    goto LAB17;

LAB20:    t21 = 25;
    goto LAB17;

LAB22:    xsi_set_current_line(49, ng0);
    t4 = (t0 + 2608U);
    t8 = *((char **)t4);
    if (25 > 0)
        goto LAB38;

LAB39:    if (-1 == -1)
        goto LAB43;

LAB44:    t21 = 0;

LAB40:    t22 = (t21 - 25);
    t33 = (t22 * -1);
    t34 = (1U * t33);
    t35 = (0 + t34);
    t4 = (t8 + t35);
    t14 = *((unsigned char *)t4);
    t36 = (t14 == (unsigned char)3);
    if (t36 == 1)
        goto LAB35;

LAB36:    t6 = (unsigned char)0;

LAB37:    if (t6 != 0)
        goto LAB32;

LAB34:    xsi_set_current_line(52, ng0);
    t1 = (t0 + 2608U);
    t3 = *((char **)t1);
    if (25 > 0)
        goto LAB71;

LAB72:    if (-1 == -1)
        goto LAB76;

LAB77:    t9 = 0;

LAB73:    t10 = (t9 - 1);
    t11 = (25 - t10);
    t12 = (t11 * 1U);
    t13 = (0 + t12);
    t1 = (t3 + t13);
    t4 = (t0 + 3992);
    t8 = (t4 + 56U);
    t15 = *((char **)t8);
    t16 = (t15 + 56U);
    t18 = *((char **)t16);
    memcpy(t18, t1, 24U);
    xsi_driver_first_trans_fast_port(t4);

LAB33:    goto LAB23;

LAB25:    if (-1 == 1)
        goto LAB28;

LAB29:    t9 = 24;
    goto LAB27;

LAB28:    t9 = 0;
    goto LAB27;

LAB30:    t9 = 24;
    goto LAB27;

LAB32:    xsi_set_current_line(50, ng0);
    t18 = (t0 + 6414);
    t23 = xsi_get_transient_memory(23U);
    memset(t23, 0, 23U);
    t24 = t23;
    if (23 > 0)
        goto LAB52;

LAB53:    if (-1 == -1)
        goto LAB57;

LAB58:    t45 = 0;

LAB54:    t46 = (t45 - 1);
    if (-1 == 1)
        goto LAB59;

LAB60:    t47 = 0;

LAB61:    t48 = (t47 - 0);
    t49 = (t48 * 1);
    t50 = (1U * t49);
    t26 = (t24 + t50);
    if (23 > 0)
        goto LAB62;

LAB63:    if (-1 == -1)
        goto LAB67;

LAB68:    t51 = 0;

LAB64:    t52 = (t51 - 1);
    t53 = (0 - t52);
    t54 = (t53 * -1);
    t54 = (t54 + 1);
    t55 = (1U * t54);
    memset(t26, (unsigned char)2, t55);
    t28 = ((IEEE_P_2592010699) + 4024);
    t29 = (t17 + 0U);
    t30 = (t29 + 0U);
    *((int *)t30) = 0;
    t30 = (t29 + 4U);
    *((int *)t30) = 0;
    t30 = (t29 + 8U);
    *((int *)t30) = 1;
    t56 = (0 - 0);
    t57 = (t56 * 1);
    t57 = (t57 + 1);
    t30 = (t29 + 12U);
    *((unsigned int *)t30) = t57;
    t30 = (t20 + 0U);
    t31 = (t30 + 0U);
    *((int *)t31) = 0;
    t31 = (t30 + 4U);
    *((int *)t31) = 22;
    t31 = (t30 + 8U);
    *((int *)t31) = 1;
    t58 = (22 - 0);
    t57 = (t58 * 1);
    t57 = (t57 + 1);
    t31 = (t30 + 12U);
    *((unsigned int *)t31) = t57;
    t27 = xsi_base_array_concat(t27, t7, t28, (char)97, t18, t17, (char)97, t23, t20, (char)101);
    t57 = (1U + 23U);
    t59 = (24U != t57);
    if (t59 == 1)
        goto LAB69;

LAB70:    t31 = (t0 + 3992);
    t32 = (t31 + 56U);
    t60 = *((char **)t32);
    t61 = (t60 + 56U);
    t62 = *((char **)t61);
    memcpy(t62, t27, 24U);
    xsi_driver_first_trans_fast_port(t31);
    goto LAB33;

LAB35:    t15 = (t0 + 2608U);
    t16 = *((char **)t15);
    if (25 > 0)
        goto LAB45;

LAB46:    if (-1 == -1)
        goto LAB50;

LAB51:    t37 = 0;

LAB47:    t38 = (t37 - 1);
    t39 = (t38 - 25);
    t40 = (t39 * -1);
    t41 = (1U * t40);
    t42 = (0 + t41);
    t15 = (t16 + t42);
    t43 = *((unsigned char *)t15);
    t44 = (t43 == (unsigned char)2);
    t6 = t44;
    goto LAB37;

LAB38:    if (-1 == 1)
        goto LAB41;

LAB42:    t21 = 25;
    goto LAB40;

LAB41:    t21 = 0;
    goto LAB40;

LAB43:    t21 = 25;
    goto LAB40;

LAB45:    if (-1 == 1)
        goto LAB48;

LAB49:    t37 = 25;
    goto LAB47;

LAB48:    t37 = 0;
    goto LAB47;

LAB50:    t37 = 25;
    goto LAB47;

LAB52:    if (-1 == 1)
        goto LAB55;

LAB56:    t45 = 23;
    goto LAB54;

LAB55:    t45 = 0;
    goto LAB54;

LAB57:    t45 = 23;
    goto LAB54;

LAB59:    t47 = t46;
    goto LAB61;

LAB62:    if (-1 == 1)
        goto LAB65;

LAB66:    t51 = 23;
    goto LAB64;

LAB65:    t51 = 0;
    goto LAB64;

LAB67:    t51 = 23;
    goto LAB64;

LAB69:    xsi_size_not_matching(24U, t57, 0);
    goto LAB70;

LAB71:    if (-1 == 1)
        goto LAB74;

LAB75:    t9 = 25;
    goto LAB73;

LAB74:    t9 = 0;
    goto LAB73;

LAB76:    t9 = 25;
    goto LAB73;

LAB78:    xsi_set_current_line(56, ng0);
    t15 = (t0 + 6415);
    t18 = xsi_get_transient_memory(23U);
    memset(t18, 0, 23U);
    t19 = t18;
    if (23 > 0)
        goto LAB98;

LAB99:    if (-1 == -1)
        goto LAB103;

LAB104:    t38 = 0;

LAB100:    t39 = (t38 - 1);
    if (-1 == 1)
        goto LAB105;

LAB106:    t40 = 0;

LAB107:    t45 = (t40 - 0);
    t41 = (t45 * 1);
    t42 = (1U * t41);
    t23 = (t19 + t42);
    if (23 > 0)
        goto LAB108;

LAB109:    if (-1 == -1)
        goto LAB113;

LAB114:    t46 = 0;

LAB110:    t48 = (t46 - 1);
    t51 = (0 - t48);
    t47 = (t51 * -1);
    t47 = (t47 + 1);
    t49 = (1U * t47);
    memset(t23, (unsigned char)3, t49);
    t26 = ((IEEE_P_2592010699) + 4024);
    t27 = (t17 + 0U);
    t28 = (t27 + 0U);
    *((int *)t28) = 0;
    t28 = (t27 + 4U);
    *((int *)t28) = 0;
    t28 = (t27 + 8U);
    *((int *)t28) = 1;
    t52 = (0 - 0);
    t50 = (t52 * 1);
    t50 = (t50 + 1);
    t28 = (t27 + 12U);
    *((unsigned int *)t28) = t50;
    t28 = (t20 + 0U);
    t29 = (t28 + 0U);
    *((int *)t29) = 0;
    t29 = (t28 + 4U);
    *((int *)t29) = 22;
    t29 = (t28 + 8U);
    *((int *)t29) = 1;
    t53 = (22 - 0);
    t50 = (t53 * 1);
    t50 = (t50 + 1);
    t29 = (t28 + 12U);
    *((unsigned int *)t29) = t50;
    t24 = xsi_base_array_concat(t24, t7, t26, (char)97, t15, t17, (char)97, t18, t20, (char)101);
    t50 = (1U + 23U);
    t43 = (24U != t50);
    if (t43 == 1)
        goto LAB115;

LAB116:    t29 = (t0 + 3992);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    t32 = (t31 + 56U);
    t60 = *((char **)t32);
    memcpy(t60, t24, 24U);
    xsi_driver_first_trans_fast_port(t29);
    goto LAB79;

LAB81:    t4 = (t0 + 2608U);
    t8 = *((char **)t4);
    if (25 > 0)
        goto LAB91;

LAB92:    if (-1 == -1)
        goto LAB96;

LAB97:    t21 = 0;

LAB93:    t22 = (t21 - 1);
    t37 = (t22 - 25);
    t33 = (t37 * -1);
    t34 = (1U * t33);
    t35 = (0 + t34);
    t4 = (t8 + t35);
    t14 = *((unsigned char *)t4);
    t36 = (t14 == (unsigned char)3);
    t2 = t36;
    goto LAB83;

LAB84:    if (-1 == 1)
        goto LAB87;

LAB88:    t9 = 25;
    goto LAB86;

LAB87:    t9 = 0;
    goto LAB86;

LAB89:    t9 = 25;
    goto LAB86;

LAB91:    if (-1 == 1)
        goto LAB94;

LAB95:    t21 = 25;
    goto LAB93;

LAB94:    t21 = 0;
    goto LAB93;

LAB96:    t21 = 25;
    goto LAB93;

LAB98:    if (-1 == 1)
        goto LAB101;

LAB102:    t38 = 23;
    goto LAB100;

LAB101:    t38 = 0;
    goto LAB100;

LAB103:    t38 = 23;
    goto LAB100;

LAB105:    t40 = t39;
    goto LAB107;

LAB108:    if (-1 == 1)
        goto LAB111;

LAB112:    t46 = 23;
    goto LAB110;

LAB111:    t46 = 0;
    goto LAB110;

LAB113:    t46 = 23;
    goto LAB110;

LAB115:    xsi_size_not_matching(24U, t50, 0);
    goto LAB116;

LAB117:    if (-1 == 1)
        goto LAB120;

LAB121:    t9 = 25;
    goto LAB119;

LAB120:    t9 = 0;
    goto LAB119;

LAB122:    t9 = 25;
    goto LAB119;

LAB124:    xsi_set_current_line(62, ng0);
    t1 = (t0 + 1672U);
    t4 = *((char **)t1);
    if (24 > 0)
        goto LAB127;

LAB128:    if (-1 == -1)
        goto LAB132;

LAB133:    t9 = 0;

LAB129:    t11 = (24 - t9);
    t12 = (t11 * 1U);
    t13 = (0 + t12);
    t1 = (t4 + t13);
    t8 = (t0 + 3992);
    t15 = (t8 + 56U);
    t16 = *((char **)t15);
    t18 = (t16 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t1, 24U);
    xsi_driver_first_trans_fast_port(t8);
    goto LAB125;

LAB127:    if (-1 == 1)
        goto LAB130;

LAB131:    t9 = 24;
    goto LAB129;

LAB130:    t9 = 0;
    goto LAB129;

LAB132:    t9 = 24;
    goto LAB129;

}


extern void work_a_2664143083_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2664143083_3212880686_p_0};
	xsi_register_didat("work_a_2664143083_3212880686", "isim/FDTestbench_isim_beh.exe.sim/work/a_2664143083_3212880686.didat");
	xsi_register_executes(pe);
}
