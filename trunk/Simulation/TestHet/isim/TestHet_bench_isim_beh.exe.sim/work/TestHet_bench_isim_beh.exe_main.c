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
char *STD_TEXTIO;
char *XILINXCORELIB_P_1837083571;
char *XILINXCORELIB_P_1705937335;
char *IEEE_P_3620187407;
char *IEEE_P_3564397177;
char *XILINXCORELIB_P_0292540400;
char *XILINXCORELIB_P_0347517956;
char *XILINXCORELIB_P_2180628434;
char *IEEE_P_3972351953;
char *XILINXCORELIB_P_3381355550;
char *XILINXCORELIB_P_1849098369;
char *XILINXCORELIB_P_2602938013;
char *XILINXCORELIB_P_3160202542;
char *XILINXCORELIB_P_3155556343;
char *WORK_P_0539175533;
char *XILINXCORELIB_P_3743709326;
char *XILINXCORELIB_P_1383731507;
char *XILINXCORELIB_P_1010636052;
char *XILINXCORELIB_P_3395472069;
char *XILINXCORELIB_P_3845737924;
char *XILINXCORELIB_P_1301089577;
char *XILINXCORELIB_P_1577873452;


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
    ieee_p_0774719531_init();
    ieee_p_3972351953_init();
    xilinxcorelib_p_1837083571_init();
    xilinxcorelib_p_3381355550_init();
    xilinxcorelib_p_1849098369_init();
    xilinxcorelib_p_2602938013_init();
    xilinxcorelib_p_3160202542_init();
    xilinxcorelib_p_3155556343_init();
    xilinxcorelib_p_3743709326_init();
    xilinxcorelib_a_1895741882_3212880686_init();
    xilinxcorelib_a_2506099404_3212880686_init();
    xilinxcorelib_a_3087771575_3212880686_init();
    xilinxcorelib_a_2911026324_3212880686_init();
    xilinxcorelib_a_0638675678_3212880686_init();
    xilinxcorelib_a_4192223809_3212880686_init();
    xilinxcorelib_a_2799795649_3212880686_init();
    xilinxcorelib_a_2031113566_3212880686_init();
    xilinxcorelib_a_2051526847_3212880686_init();
    xilinxcorelib_a_2780231712_3212880686_init();
    xilinxcorelib_p_1383731507_init();
    xilinxcorelib_p_1010636052_init();
    xilinxcorelib_p_3395472069_init();
    xilinxcorelib_p_3845737924_init();
    xilinxcorelib_p_1301089577_init();
    xilinxcorelib_p_1577873452_init();
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
    xilinxcorelib_a_2705073035_1516540902_init();
    xilinxcorelib_a_1460241465_0718686667_init();
    xilinxcorelib_a_2320793195_3212880686_init();
    xilinxcorelib_a_1436899060_3212880686_init();
    xilinxcorelib_a_1396899019_3212880686_init();
    work_a_1133811506_0268565419_init();
    ieee_p_3564397177_init();
    xilinxcorelib_p_0292540400_init();
    xilinxcorelib_p_0347517956_init();
    xilinxcorelib_p_2180628434_init();
    xilinxcorelib_a_3946510123_3212880686_init();
    xilinxcorelib_a_3197987408_3212880686_init();
    work_a_3779199659_4081616539_init();
    xilinxcorelib_p_1705937335_init();
    xilinxcorelib_a_3846100417_3212880686_init();
    work_a_0103048724_1811031129_init();
    work_a_3718022953_3212880686_init();
    work_a_2032032410_3212880686_init();
    work_a_3500389135_3212880686_init();
    work_a_3458358099_3212880686_init();
    work_a_0793226021_2372691052_init();


    xsi_register_tops("work_a_0793226021_2372691052");

    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_0774719531 = xsi_get_engine_memory("ieee_p_0774719531");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    XILINXCORELIB_P_1837083571 = xsi_get_engine_memory("xilinxcorelib_p_1837083571");
    XILINXCORELIB_P_1705937335 = xsi_get_engine_memory("xilinxcorelib_p_1705937335");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    IEEE_P_3564397177 = xsi_get_engine_memory("ieee_p_3564397177");
    XILINXCORELIB_P_0292540400 = xsi_get_engine_memory("xilinxcorelib_p_0292540400");
    XILINXCORELIB_P_0347517956 = xsi_get_engine_memory("xilinxcorelib_p_0347517956");
    XILINXCORELIB_P_2180628434 = xsi_get_engine_memory("xilinxcorelib_p_2180628434");
    IEEE_P_3972351953 = xsi_get_engine_memory("ieee_p_3972351953");
    XILINXCORELIB_P_3381355550 = xsi_get_engine_memory("xilinxcorelib_p_3381355550");
    XILINXCORELIB_P_1849098369 = xsi_get_engine_memory("xilinxcorelib_p_1849098369");
    XILINXCORELIB_P_2602938013 = xsi_get_engine_memory("xilinxcorelib_p_2602938013");
    XILINXCORELIB_P_3160202542 = xsi_get_engine_memory("xilinxcorelib_p_3160202542");
    XILINXCORELIB_P_3155556343 = xsi_get_engine_memory("xilinxcorelib_p_3155556343");
    WORK_P_0539175533 = xsi_get_engine_memory("work_p_0539175533");
    XILINXCORELIB_P_3743709326 = xsi_get_engine_memory("xilinxcorelib_p_3743709326");
    XILINXCORELIB_P_1383731507 = xsi_get_engine_memory("xilinxcorelib_p_1383731507");
    XILINXCORELIB_P_1010636052 = xsi_get_engine_memory("xilinxcorelib_p_1010636052");
    XILINXCORELIB_P_3395472069 = xsi_get_engine_memory("xilinxcorelib_p_3395472069");
    XILINXCORELIB_P_3845737924 = xsi_get_engine_memory("xilinxcorelib_p_3845737924");
    XILINXCORELIB_P_1301089577 = xsi_get_engine_memory("xilinxcorelib_p_1301089577");
    XILINXCORELIB_P_1577873452 = xsi_get_engine_memory("xilinxcorelib_p_1577873452");

    return xsi_run_simulation(argc, argv);

}
