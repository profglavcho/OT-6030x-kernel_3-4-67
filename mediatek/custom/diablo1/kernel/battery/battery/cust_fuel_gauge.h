#include <mach/mt_typedefs.h>

#define FGAUGE_VOLTAGE_FACTOR           2.44 // mV
#define FGAUGE_CURRENT_FACTOR           6.25 // uV/Rsns
#define FGAUGE_CURRENT_OFFSET_FACTOR    1.56 // uV/Rsns
#define FGAUGE_CAR_FACTOR               6.25 // uV/Rsns
#define FGAUGE_RSNS_FACTOR              0.02 // Ohm

//#define COMPASATE_OCV                   80 // mV for evb
#define COMPASATE_OCV                   40 // mV for phone

#define BATTERY_VOLTAGE_MINIMUM         3400
#define BATTERY_VOLTAGE_MAXIMUM         4350

#define BATTERY_CAPACITY_MAXIMUM        1859

#define TEMPERATURE_T0                  110
#define TEMPERATURE_T1                  0
#define TEMPERATURE_T2                  25
#define TEMPERATURE_T3                  50
#define TEMPERATURE_T                   255 // This should be fixed, never change the value

//#define BATT_CAPACITY                   1280
#define BATT_CAPACITY                   1846

#define ENABLE_SW_COULOMB_COUNTER       0 // 1 is enable, 0 is disable
//#define ENABLE_SW_COULOMB_COUNTER       1 // 1 is enable, 0 is disable

//#define FG_CURRENT_OFFSET_DISCHARGING 	31
#define FG_CURRENT_OFFSET_DISCHARGING 	0

#define FG_RESISTANCE 	20

#define FG_METER_RESISTANCE 	0
//#define FG_METER_RESISTANCE 	540 // current meter

//#define MAX_BOOTING_TIME_FGCURRENT	5*6 // 5 seconds, 6 points = 1s
#define MAX_BOOTING_TIME_FGCURRENT	1*10 // 10s

#if defined(CONFIG_POWER_EXT)
//#define OCV_BOARD_COMPESATE	32 //mV 
#define OCV_BOARD_COMPESATE	72 //mV 
#define R_FG_BOARD_BASE		1000
#define R_FG_BOARD_SLOPE	1000 //slope
#else
//#define OCV_BOARD_COMPESATE	0 //mV 
//#define OCV_BOARD_COMPESATE	48 //mV 
//#define OCV_BOARD_COMPESATE	25 //mV 
#define OCV_BOARD_COMPESATE	0 //mV 
#define R_FG_BOARD_BASE		1000
#define R_FG_BOARD_SLOPE	1000 //slope
//#define R_FG_BOARD_SLOPE	1057 //slope
//#define R_FG_BOARD_SLOPE	1075 //slope
#endif

#define Q_MAX_POS_50	1859
#define Q_MAX_POS_25	1846
#define Q_MAX_POS_0		1905
#define Q_MAX_NEG_10	1708

#define Q_MAX_POS_50_H_CURRENT	1846
#define Q_MAX_POS_25_H_CURRENT	1816
#define Q_MAX_POS_0_H_CURRENT	1676
#define Q_MAX_NEG_10_H_CURRENT	1325

#define R_FG_VALUE 				20 // mOhm, base is 20
#define CURRENT_DETECT_R_FG	100  //10mA

#define OSR_SELECT_7			0

#define CAR_TUNE_VALUE			86 //1.00

/////////////////////////////////////////////////////////////////////
// <DOD, Battery_Voltage> Table
/////////////////////////////////////////////////////////////////////
typedef struct _BATTERY_PROFILE_STRUC
{
    kal_int32 percentage;
    kal_int32 voltage;
} BATTERY_PROFILE_STRUC, *BATTERY_PROFILE_STRUC_P;

typedef enum
{
    T1_0C,
    T2_25C,
    T3_50C
} PROFILE_TEMPERATURE;

// T0 -10C
BATTERY_PROFILE_STRUC battery_profile_t0[] =
{
	{0  , 4302},
	{2  , 4271},
	{4  , 4247},
	{5  , 4228},
	{7  , 4209},
	{9  , 4190},
	{10 , 4173},
	{12 , 4155},
	{14 , 4139},
	{16 , 4121},
	{17 , 4105},
	{19 , 4091},
	{21 , 4077},
	{23 , 4061},
	{24 , 4041},
	{26 , 4023},
	{28 , 4005},
	{30 , 3991},
	{31 , 3977},
	{33 , 3965},
	{35 , 3954},
	{37 , 3941},
	{38 , 3926},
	{40 , 3910},
	{42 , 3894},
	{44 , 3879},
	{45 , 3866},
	{47 , 3855},  
	{49 , 3846}, 
	{51 , 3838},
	{52 , 3831},
	{54 , 3824},  
	{56 , 3817},
	{58 , 3811},
	{59 , 3806},
	{61 , 3800},
	{63 , 3796},
	{65 , 3792},
	{66 , 3788},
	{68 , 3786},
	{70 , 3783},
	{72 , 3781},
	{73 , 3778},
	{75 , 3776},
	{77 , 3772},
	{79 , 3767},
	{80 , 3760},
	{82 , 3751},
        {84 , 3741},
        {86 , 3728},
        {87 , 3714},
        {89 , 3703},
        {91 , 3698},
        {93 , 3694},
        {94 , 3691},
        {95 , 3689},
        {96 , 3688},
        {97 , 3686},
        {97 , 3682},
        {98 , 3679},
        {98 , 3675},
        {98 , 3671},
        {98 , 3666},
        {99 , 3659},
        {99 , 3654},
        {99 , 3648},
        {99 , 3643},
        {99 , 3638},
        {99 , 3634},
        {100, 3630}, 
        {100, 3627},
        {100, 3623},
        {100, 3620},
        {100, 3617}, 
        {100, 3400}
};       
         
// T1 0C 
BATTERY_PROFILE_STRUC battery_profile_t1[] =
{        
	{0  , 4177},
	{2  , 4152},
	{3  , 4125},
	{5  , 4101},
	{6  , 4087},
	{8  , 4065},
	{9  , 4041},
	{11 , 4019},
	{13 , 4002},
	{14 , 3987},
	{16 , 3975},
	{17 , 3965},
	{19 , 3959},
	{20 , 3950},
	{22 , 3939},
	{24 , 3928},
	{25 , 3918},
	{27 , 3908},
	{28 , 3900},
	{30 , 3890},
	{31 , 3881},
	{33 , 3871},
	{34 , 3862},
	{36 , 3852},
	{38 , 3842},
	{39 , 3833},
	{41 , 3823},
	{42 , 3814},  
	{44 , 3808}, 
	{45 , 3802},
	{47 , 3797},
	{49 , 3794},  
	{50 , 3792},
	{52 , 3790},
	{53 , 3789},
	{55 , 3788},
	{56 , 3788},
	{58 , 3786},
	{60 , 3785},
	{61 , 3784},
	{63 , 3782},
	{64 , 3778},
	{66 , 3773},
	{67 , 3767},
	{69 , 3755},
	{70 , 3741},
	{72 , 3725},
	{74 , 3708},
        {75 , 3691},
        {77 , 3675},
        {78 , 3659},
        {80 , 3645},
        {81 , 3632},
        {83 , 3620},
        {85 , 3608},
        {86 , 3597},
        {88 , 3584},
        {89 , 3572},
        {91 , 3559},
        {92 , 3547},
        {94 , 3533},
        {96 , 3518},
        {97 , 3507},
        {97 , 3503},
        {98 , 3500},
        {98 , 3498},
        {99 , 3496},
        {99 , 3495},
        {99 , 3494},
        {99 , 3493}, 
        {99 , 3492},
        {100, 3492},
        {100, 3492},
        {100, 3490}, 
        {100, 3400}
  

}; 
// T2 25C
BATTERY_PROFILE_STRUC battery_profile_t2[] =
{
	{0  , 4335},
	{2  , 4313},
	{3  , 4294},
	{5  , 4274},
	{6  , 4256},
	{8  , 4238},
	{10 , 4220},
	{11 , 4202},
	{13 , 4184},
	{15 , 4167},
	{16 , 4151},
	{18 , 4133},
	{19 , 4116},
	{21 , 4100},
	{23 , 4085},
	{24 , 4071},
	{26 , 4056},
	{27 , 4039},
	{29 , 4022},
	{31 , 4006},
	{32 , 3992},
	{34 , 3980},
	{36 , 3968},
	{37 , 3957},
	{39 , 3946},
	{40 , 3934},
	{42 , 3920},
	{44 , 3903},  
	{45 , 3885}, 
	{47 , 3870},
	{48 , 3857},
	{50 , 3848},  
	{52 , 3839},
	{53 , 3831},
	{55 , 3825},
	{57 , 3818},
	{58 , 3812},
	{60 , 3806},
	{61 , 3801},
	{63 , 3796},
	{65 , 3791},
	{66 , 3787},
	{68 , 3783},
	{70 , 3779},
	{71 , 3776},
	{73 , 3773},
	{74 , 3769},
	{76 , 3764},
        {78 , 3756},
        {79 , 3748},
        {81 , 3742},
        {82 , 3733},
        {84 , 3719},
        {86 , 3705},
        {87 , 3690},
        {89 , 3686},
        {91 , 3685},
        {92 , 3683},
        {94 , 3679},
        {95 , 3666},
        {97 , 3608},
        {99 , 3520},
        {100, 3370},
        {100, 3328},
        {100, 3311},
        {100, 3301},
        {100, 3296},
        {100, 3292},
        {100, 3290},
        {100, 3288}, 
        {100, 3286},
        {100, 3283},
        {100, 3281},
        {100, 3279}, 
        {100, 3279}
  

}; 

// T3 50C
BATTERY_PROFILE_STRUC battery_profile_t3[] =
{
	{0  , 4340},
	{2  , 4318},
	{3  , 4299},
	{5  , 4281},
	{6  , 4261},
	{8  , 4244},
	{10 , 4226},
	{11 , 4208},
	{13 , 4190},
	{14 , 4173},
	{16 , 4156},
	{18 , 4139},
	{19 , 4122},
	{21 , 4106},
	{22 , 4089},
	{24 , 4074},
	{26 , 4059},
	{27 , 4043},
	{29 , 4027},
	{31 , 4012},
	{32 , 3998},
	{34 , 3986},
	{35 , 3973},
	{37 , 3961},
	{39 , 3948},
	{40 , 3937},
	{42 , 3925},
	{43 , 3912},  
	{45 , 3895}, 
	{47 , 3877},
	{48 , 3862},
	{50 , 3852},  
	{51 , 3843},
	{53 , 3834},
	{55 , 3827},
	{56 , 3820},
	{58 , 3813},
	{59 , 3807},
	{61 , 3802},
	{63 , 3796},
	{64 , 3791},
	{66 , 3787},
	{67 , 3783},
	{69 , 3778},
	{71 , 3773},
	{72 , 3764},
	{74 , 3755},
	{75 , 3750},
        {77 , 3744},
        {79 , 3738},
        {80 , 3730},
        {82 , 3724},
        {83 , 3714},
        {85 , 3701},
        {87 , 3684},
        {88 , 3675},
        {90 , 3673},
        {92 , 3671},
        {93 , 3668},
        {95 , 3662},
        {96 , 3627},
        {98 , 3560},
        {100, 3453},
        {100, 3281},
        {100, 3258},
        {100, 3249},
        {100, 3245},
        {100, 3243},
        {100, 3242},
        {100, 3240}, 
        {100, 3238},
        {100, 3235},
        {100, 3232},
        {100, 3230}, 
        {100, 3230}
  

};              

// battery profile for actual temperature. The size should be the same as T1, T2 and T3
BATTERY_PROFILE_STRUC battery_profile_temperature[] =
{
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
};    

/////////////////////////////////////////////////////////////////////
// <Rbat, Battery_Voltage> Table
/////////////////////////////////////////////////////////////////////
typedef struct _R_PROFILE_STRUC
{
    kal_int32 resistance; // Ohm
    kal_int32 voltage;
} R_PROFILE_STRUC, *R_PROFILE_STRUC_P;

// T0 -10C
R_PROFILE_STRUC r_profile_t0[] =
{
	{518 , 4302},
	{518 , 4271},
	{538 , 4247},
	{550 , 4228},
	{560 , 4209},
	{563 , 4190},
	{573 , 4173},
	{580 , 4155},
	{588 , 4139},
	{593 , 4121},
	{600 , 4105},
	{610 , 4091},
	{615 , 4077},
	{628 , 4061},
	{633 , 4041},
	{640 , 4023},
	{645 , 4005},
	{650 , 3991},
	{660 , 3977},
	{670 , 3965},
	{680 , 3954},
	{685 , 3941},
	{685 , 3926},
	{680 , 3910},
	{678 , 3894},
	{678 , 3879},
	{675 , 3866},
	{683 , 3855},  
	{693 , 3846}, 
	{700 , 3838},
	{710 , 3831},
	{720 , 3824},  
	{730 , 3817},
	{740 , 3811},
	{753 , 3806},
	{758 , 3800},
	{768 , 3796},
	{778 , 3792},
	{788 , 3788},
	{808 , 3786},
	{825 , 3783},
	{850 , 3781},
	{870 , 3778},
	{898 , 3776},
	{918 , 3772},
	{938 , 3767},
	{955 , 3760},
	{975 , 3751},
        {995 , 3741},
        {1018, 3728},
        {1043, 3714},
        {1065, 3703},
        {1100, 3698},
        {1148, 3694},
        {1213, 3691},
        {1223, 3689},
        {1220, 3688},
        {1218, 3686},
        {1208, 3682},
        {1203, 3679},
        {1190, 3675},
        {1180, 3671},
        {1168, 3666},
        {1153, 3659},
        {1138, 3654},
        {1125, 3648},
        {1115, 3643},
        {1095, 3638},
        {1088, 3634},
        {1078, 3630}, 
        {1075, 3627},
        {1068, 3623},
        {1055, 3620},
        {1055, 3617}, 
        {505 , 3400}

};

// T1 0C
R_PROFILE_STRUC r_profile_t1[] =
{
	{235 , 4177},
	{235 , 4152},
	{258 , 4125},
	{263 , 4101},
	{275 , 4087},
	{273 , 4065},
	{273 , 4041},
	{270 , 4019},
	{273 , 4002},
	{273 , 3987},
	{273 , 3975},
	{278 , 3965},
	{285 , 3959},
	{288 , 3950},
	{290 , 3939},
	{293 , 3928},
	{298 , 3918},
	{298 , 3908},
	{305 , 3900},
	{305 , 3890},
	{308 , 3881},
	{308 , 3871},
	{308 , 3862},
	{308 , 3852},
	{300 , 3842},
	{300 , 3833},
	{293 , 3823},
	{285 , 3814},
	{288 , 3808},
	{285 , 3802},
	{283 , 3797},
	{283 , 3794},
	{285 , 3792},
	{288 , 3790},
	{290 , 3789},
	{295 , 3788},
	{303 , 3788},
	{305 , 3786},
	{313 , 3785},
	{320 , 3784},
	{328 , 3782},
	{335 , 3778},
	{343 , 3773},
	{355 , 3767},
	{360 , 3755},
	{365 , 3741},
	{368 , 3725},
	{373 , 3708},
        {375 , 3691},
        {380 , 3675},
        {383 , 3659},
        {393 , 3645},
        {400 , 3632},
        {410 , 3620},
        {423 , 3608},
        {438 , 3597},
        {450 , 3584},
        {475 , 3572},
        {505 , 3559},
        {543 , 3547},
        {600 , 3533},
        {688 , 3518},
        {768 , 3507},
        {760 , 3503},
        {753 , 3500},
        {745 , 3498},
        {745 , 3496},
        {740 , 3495},
        {738 , 3494},
        {735 , 3493},
        {730 , 3492},
        {735 , 3492},
        {735 , 3492},
        {728 , 3490},
        {503 , 3400}          
  

}; 

// T2 25C
R_PROFILE_STRUC r_profile_t2[] =
{
	{155 , 4335},
	{155 , 4313},
	{160 , 4294},
	{158 , 4274},
	{163 , 4256},
	{165 , 4238},
	{165 , 4220},
	{168 , 4202},
	{168 , 4184},
	{170 , 4167},
	{178 , 4151},
	{175 , 4133},
	{178 , 4116},
	{183 , 4100},
	{185 , 4085},
	{188 , 4071},
	{190 , 4056},
	{195 , 4039},
	{198 , 4022},
	{200 , 4006},
	{205 , 3992},
	{210 , 3980},
	{210 , 3968},
	{215 , 3957},
	{218 , 3946},
	{220 , 3934},
	{215 , 3920},
	{205 , 3903},
	{188 , 3885},
	{180 , 3870},
	{173 , 3857},
	{173 , 3848},
	{173 , 3839},
	{173 , 3831},
	{178 , 3825},
	{180 , 3818},
	{183 , 3812},
	{185 , 3806},
	{190 , 3801},
	{193 , 3796},
	{195 , 3791},
	{198 , 3787},
	{200 , 3783},
	{203 , 3779},
	{205 , 3776},
	{208 , 3773},
	{210 , 3769},
	{215 , 3764},
        {213 , 3756},
        {213 , 3748},
        {223 , 3742},
        {225 , 3733},
        {228 , 3719},
        {233 , 3705},
        {228 , 3690},
        {233 , 3686},
        {250 , 3685},
        {268 , 3683},
        {285 , 3679},
        {303 , 3666},
        {305 , 3608},
        {343 , 3520},
        {388 , 3370},
        {325 , 3328},
        {283 , 3311},
        {255 , 3301},
        {245 , 3296},
        {238 , 3292},
        {230 , 3290},
        {233 , 3288},
        {228 , 3286},
        {225 , 3283},
        {228 , 3281},
        {228 , 3279},
        {225 , 3279} 


};

// T3 50C
R_PROFILE_STRUC r_profile_t3[] =
{
	{105 , 4340},
	{105 , 4318},
	{105 , 4299},
	{108 , 4281},
	{103 , 4261},
	{110 , 4244},
	{110 , 4226},
	{110 , 4208},
	{113 , 4190},
	{115 , 4173},
	{118 , 4156},
	{120 , 4139},
	{120 , 4122},
	{123 , 4106},
	{123 , 4089},
	{128 , 4074},
	{128 , 4059},
	{128 , 4043},
	{128 , 4027},
	{133 , 4012},
	{135 , 3998},
	{140 , 3986},
	{140 , 3973},
	{143 , 3961},
	{145 , 3948},
	{150 , 3937},
	{153 , 3925},
	{153 , 3912},
	{140 , 3895},
	{125 , 3877},
	{115 , 3862},
	{115 , 3852},
	{113 , 3843},
	{110 , 3834},
	{115 , 3827},
	{118 , 3820},
	{118 , 3813},
	{123 , 3807},
	{125 , 3802},
	{128 , 3796},
	{130 , 3791},
	{135 , 3787},
	{138 , 3783},
	{138 , 3778},
	{135 , 3773},
	{125 , 3764},
	{120 , 3755},
	{123 , 3750},
        {125 , 3744},
        {123 , 3738},
        {123 , 3730},
        {128 , 3724},
        {128 , 3714},
        {128 , 3701},
        {125 , 3684},
        {118 , 3675},
        {125 , 3673},
        {133 , 3671},
        {135 , 3668},
        {145 , 3662},
        {143 , 3627},
        {163 , 3560},
        {175 , 3453},
        {205 , 3281},
        {148 , 3258},
        {128 , 3249},
        {118 , 3245},
        {110 , 3243},
        {110 , 3242},
        {113 , 3240},
        {113 , 3238},
        {110 , 3235},
        {108 , 3232},
        {110 , 3230},
        {118 , 3230} 


};

// r-table profile for actual temperature. The size should be the same as T1, T2 and T3
R_PROFILE_STRUC r_profile_temperature[] =
{
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},   
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0}
    
};    


int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUC_P fgauge_get_profile(kal_uint32 temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUC_P fgauge_get_profile_r_table(kal_uint32 temperature);
