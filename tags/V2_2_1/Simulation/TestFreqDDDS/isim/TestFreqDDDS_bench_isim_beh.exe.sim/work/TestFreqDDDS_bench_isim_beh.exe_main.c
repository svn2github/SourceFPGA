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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *IEEE_P_2592010699;
char *STD_STANDARD;
char *IEEE_P_3499444699;
char *IEEE_P_0774719531;
char *IEEE_P_1242562249;
char *IEEE_P_3972351953;
char *STD_TEXTIO;
char *XILINXCORELIB_P_1837083571;
char *XILINXCORELIB_P_3381355550;
char *XILINXCORELIB_P_1849098369;
char *XILINXCORELIB_P_2602938013;
char *XILINXCORELIB_P_3160202542;
char *XILINXCORELIB_P_3155556343;
char *UNISIM_P_0947159679;
char *UNISIM_P_3222816464;
char *IEEE_P_2717149903;
char *IEEE_P_1367372525;
char *IEEE_P_3564397177;
char *XILINXCORELIB_P_0292540400;
char *XILINXCORELIB_P_0347517956;
char *XILINXCORELIB_P_2180628434;
char *XILINXCORELIB_P_1705937335;
char *IEEE_P_3620187407;
char *WORK_P_0539175533;
char *XILINXCORELIB_P_3743709326;
char *XILINXCORELIB_P_1383731507;
char *XILINXCORELIB_P_1010636052;
char *XILINXCORELIB_P_3395472069;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    ieee_p_1242562249_init();
    std_textio_init();
    ieee_p_3499444699_init();
    ieee_p_3620187407_init();
    work_p_0539175533_init();
    unisim_p_0947159679_init();
    ieee_p_2717149903_init();
    ieee_p_1367372525_init();
    unisim_p_3222816464_init();
    ieee_p_0774719531_init();
    ieee_p_3972351953_init();
    xilinxcorelib_p_1837083571_init();
    xilinxcorelib_p_3381355550_init();
    xilinxcorelib_p_1849098369_init();
    xilinxcorelib_p_2602938013_init();
    xilinxcorelib_p_3160202542_init();
    xilinxcorelib_p_3155556343_init();
    xilinxcorelib_p_3743709326_init();
    xilinxcorelib_a_3851316527_3212880686_init();
    xilinxcorelib_a_0001105497_3212880686_init();
    xilinxcorelib_a_0638675678_3212880686_init();
    xilinxcorelib_a_4192223809_3212880686_init();
    xilinxcorelib_a_3320227045_3212880686_init();
    xilinxcorelib_a_0437750906_3212880686_init();
    xilinxcorelib_a_0618420642_3212880686_init();
    xilinxcorelib_a_3242388180_3212880686_init();
    xilinxcorelib_a_0304284417_3212880686_init();
    xilinxcorelib_a_3453103006_3212880686_init();
    xilinxcorelib_p_1383731507_init();
    xilinxcorelib_p_1010636052_init();
    xilinxcorelib_p_3395472069_init();
    xilinxcorelib_a_1091826098_3212880686_init();
    xilinxcorelib_a_1922322233_3212880686_init();
    xilinxcorelib_a_2980875575_3212880686_init();
    xilinxcorelib_a_0571348387_3212880686_init();
    xilinxcorelib_a_4019957327_3212880686_init();
    xilinxcorelib_a_2317361259_3212880686_init();
    xilinxcorelib_a_0516140769_0718686667_init();
    xilinxcorelib_a_3725427157_3212880686_init();
    xilinxcorelib_a_0033335626_3212880686_init();
    xilinxcorelib_a_3985260382_3212880686_init();
    xilinxcorelib_a_0846927809_3212880686_init();
    xilinxcorelib_a_2468095527_0718686667_init();
    xilinxcorelib_a_3652736641_3212880686_init();
    xilinxcorelib_a_0105479710_3212880686_init();
    xilinxcorelib_a_3829108786_3212880686_init();
    xilinxcorelib_a_0027599684_3212880686_init();
    xilinxcorelib_a_3888667633_3212880686_init();
    work_a_3245716193_0930315672_init();
    xilinxcorelib_p_1705937335_init();
    xilinxcorelib_a_1393401644_3212880686_init();
    work_a_3706124908_0442380582_init();
    work_a_0638805043_3212880686_init();
    work_a_0018626043_3212880686_init();
    ieee_p_3564397177_init();
    xilinxcorelib_p_0292540400_init();
    xilinxcorelib_p_0347517956_init();
    xilinxcorelib_p_2180628434_init();
    xilinxcorelib_a_1707539323_3212880686_init();
    xilinxcorelib_a_2594074899_3212880686_init();
    work_a_3250648064_3984700968_init();
    unisim_a_2562466605_1496654361_init();
    unisim_a_1717296735_4086321779_init();
    unisim_a_3055263662_1392679692_init();
    unisim_a_3519694068_2693788048_init();
    unisim_a_1769350033_2693788048_init();
    unisim_a_0789928158_3731405331_init();
    unisim_a_0900199298_3731405331_init();
    unisim_a_2279040086_3731405331_init();
    unisim_a_0774281858_3731405331_init();
    unisim_a_3600803327_3731405331_init();
    unisim_a_3504150236_3731405331_init();
    unisim_a_1917843982_3731405331_init();
    unisim_a_4104775526_3752513572_init();
    unisim_a_3822252837_3752513572_init();
    unisim_a_1446710196_3752513572_init();
    unisim_a_4130368794_3634591992_init();
    unisim_a_1582295314_3634591992_init();
    unisim_a_0295785205_3676810390_init();
    unisim_a_0505210609_3676810390_init();
    unisim_a_3734420696_3676810390_init();
    unisim_a_3509258460_3676810390_init();
    unisim_a_3702704980_1602505438_init();
    unisim_a_1646226234_1266530935_init();
    unisim_a_3484885994_2523279426_init();
    unisim_a_2456189163_0111667855_init();
    work_a_2115795998_0632001823_init();
    work_a_3943994461_3212880686_init();
    work_a_3458358099_3212880686_init();
    work_a_0941118023_2372691052_init();


    xsi_register_tops("work_a_0941118023_2372691052");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_0774719531 = xsi_get_engine_memory("ieee_p_0774719531");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    IEEE_P_3972351953 = xsi_get_engine_memory("ieee_p_3972351953");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    XILINXCORELIB_P_1837083571 = xsi_get_engine_memory("xilinxcorelib_p_1837083571");
    XILINXCORELIB_P_3381355550 = xsi_get_engine_memory("xilinxcorelib_p_3381355550");
    XILINXCORELIB_P_1849098369 = xsi_get_engine_memory("xilinxcorelib_p_1849098369");
    XILINXCORELIB_P_2602938013 = xsi_get_engine_memory("xilinxcorelib_p_2602938013");
    XILINXCORELIB_P_3160202542 = xsi_get_engine_memory("xilinxcorelib_p_3160202542");
    XILINXCORELIB_P_3155556343 = xsi_get_engine_memory("xilinxcorelib_p_3155556343");
    UNISIM_P_0947159679 = xsi_get_engine_memory("unisim_p_0947159679");
    UNISIM_P_3222816464 = xsi_get_engine_memory("unisim_p_3222816464");
    IEEE_P_2717149903 = xsi_get_engine_memory("ieee_p_2717149903");
    IEEE_P_1367372525 = xsi_get_engine_memory("ieee_p_1367372525");
    IEEE_P_3564397177 = xsi_get_engine_memory("ieee_p_3564397177");
    XILINXCORELIB_P_0292540400 = xsi_get_engine_memory("xilinxcorelib_p_0292540400");
    XILINXCORELIB_P_0347517956 = xsi_get_engine_memory("xilinxcorelib_p_0347517956");
    XILINXCORELIB_P_2180628434 = xsi_get_engine_memory("xilinxcorelib_p_2180628434");
    XILINXCORELIB_P_1705937335 = xsi_get_engine_memory("xilinxcorelib_p_1705937335");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    WORK_P_0539175533 = xsi_get_engine_memory("work_p_0539175533");
    XILINXCORELIB_P_3743709326 = xsi_get_engine_memory("xilinxcorelib_p_3743709326");
    XILINXCORELIB_P_1383731507 = xsi_get_engine_memory("xilinxcorelib_p_1383731507");
    XILINXCORELIB_P_1010636052 = xsi_get_engine_memory("xilinxcorelib_p_1010636052");
    XILINXCORELIB_P_3395472069 = xsi_get_engine_memory("xilinxcorelib_p_3395472069");

    return xsi_run_simulation(argc, argv);

}
