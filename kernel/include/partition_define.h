
#ifndef __PARTITION_DEFINE_H__
#define __PARTITION_DEFINE_H__




#define KB  (1024)
#define MB  (1024 * KB)
#define GB  (1024 * MB)

#define PART_PRELOADER "PRELOADER" 
#define PART_DSP_BL "DSP_BL" 
#define PART_MBR "MBR" 
#define PART_EBR1 "EBR1" 
#define PART_PMT "PMT" 
#define PART_NVRAM "NVRAM" 
#define PART_SECCFG "SECCFG" 
#define PART_UBOOT "UBOOT" 
#define PART_BOOTIMG "BOOTIMG" 
#define PART_RECOVERY "RECOVERY" 
#define PART_SEC_RO "SEC_RO" 
#define PART_MISC "MISC" 
#define PART_LOGO "LOGO" 
#define PART_EXPDB "EXPDB" 
#define PART_PRO_INFO "PRO_INFO" 
#define PART_CUSTPACK "CUSTPACK" 
#define PART_MOBILE_INFO "MOBILE_INFO" 
#define PART_ANDROID "ANDROID" 
#define PART_CACHE "CACHE" 
#define PART_USRDATA "USRDATA" 
#define PART_OTP "OTP" 
#define PART_BMTPOOL "BMTPOOL" 
/*preloader re-name*/
#define PART_SECURE "SECURE" 
#define PART_SECSTATIC "SECSTATIC" 
#define PART_ANDSYSIMG "ANDSYSIMG" 
#define PART_USER "USER" 
/*Uboot re-name*/
#define PART_DSP_DL "DSP_DL" 
#define PART_APANIC "APANIC" 

#define PART_FLAG_NONE              0 
#define PART_FLAG_LEFT             0x1 
#define PART_FLAG_END              0x2 
#define PART_MAGIC              0x58881688 

#define PART_SIZE_PRELOADER			(256*KB)
#define PART_SIZE_DSP_BL			(16128*KB)
#define PART_SIZE_MBR			(16*KB)
#define PART_SIZE_EBR1			(16*KB)
#define PART_SIZE_PMT			(4096*KB)
#define PART_SIZE_NVRAM			(5120*KB)
#define PART_SIZE_SECCFG			(128*KB)
#define PART_OFFSET_SECCFG			(0x1908000)
#define PART_SIZE_UBOOT			(384*KB)
#define PART_SIZE_BOOTIMG			(6144*KB)
#define PART_SIZE_RECOVERY			(6144*KB)
#define PART_SIZE_SEC_RO			(6144*KB)
#define PART_OFFSET_SEC_RO			(0x2588000)
#define PART_SIZE_MISC			(384*KB)
#define PART_SIZE_LOGO			(3072*KB)
#define PART_SIZE_EXPDB			(2048*KB)
#define PART_SIZE_PRO_INFO			(3072*KB)
#define PART_SIZE_CUSTPACK			(422912*KB)
#define PART_SIZE_MOBILE_INFO			(8192*KB)
#define PART_SIZE_ANDROID			(422912*KB)
#define PART_SIZE_CACHE			(320512*KB)
#define PART_SIZE_USRDATA			(2485248*KB)
#define PART_SIZE_OTP			(44032*KB)
#define PART_SIZE_BMTPOOL			(0xa8)


#define PART_NUM			22



#define PART_MAX_COUNT			 40

#define MBR_START_ADDRESS_BYTE			(16384*KB)

#define WRITE_SIZE_Byte		512
typedef enum  {
	EMMC = 1,
	NAND = 2,
} dev_type;

typedef enum {
	USER = 0,
	BOOT_1,
	BOOT_2,
	RPMB,
	GP_1,
	GP_2,
	GP_3,
	GP_4,
} Region;


struct excel_info{
	char * name;
	unsigned long long size;
	unsigned long long start_address;
	dev_type type ;
	unsigned int partition_idx;
	Region region;
};
#ifdef  MTK_EMMC_SUPPORT
/*MBR or EBR struct*/
#define SLOT_PER_MBR 4
#define MBR_COUNT 8

struct MBR_EBR_struct{
	char part_name[8];
	int part_index[SLOT_PER_MBR];
};

extern struct MBR_EBR_struct MBR_EBR_px[MBR_COUNT];
#endif
extern struct excel_info *PartInfo;


#endif
