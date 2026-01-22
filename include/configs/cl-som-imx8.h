/*
 * Copyright 2017 NXP
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CL_SOM_IMX8_H
#define __CL_SOM_IMX8_H

#include <linux/sizes.h>
#include <asm/arch/imx-regs.h>
#include "imx_env.h"

#ifdef CONFIG_SPL_BUILD
/*#define CONFIG_ENABLE_DDR_TRAINING_DEBUG*/

/* SPL Stack and BSS */
#define CONFIG_SPL_STACK		0x187FF0
#define CONFIG_SPL_BSS_START_ADDR	0x00180000
#define CONFIG_SPL_BSS_MAX_SIZE		0x2000		/* 8 KB */

/* SPL Malloc */
#define CONFIG_SYS_SPL_MALLOC_START	0x42200000
#define CONFIG_SYS_SPL_MALLOC_SIZE	0x80000		/* 512 KB */
#define CONFIG_MALLOC_F_ADDR		0x182000	/* malloc f used before GD_FLG_FULL_MALLOC_INIT set */

#define CONFIG_SPL_ABORT_ON_RAW_IMAGE

/* Disable device model for SPL to reduce size */
#undef CONFIG_DM_MMC
#undef CONFIG_DM_PMIC
#undef CONFIG_DM_PMIC_PFUZE100

/* PMIC */
#define CONFIG_SYS_I2C
#define CONFIG_POWER_I2C
#define CONFIG_POWER_PFUZE100
#define CFG_POWER_PFUZE100_I2C_ADDR	0x08
#endif /* CONFIG_SPL_BUILD */

/* Environment */
#define CFG_EXTRA_ENV_SETTINGS		\
	"script=boot.scr\0" \
	"image=Image\0" \
	"console=ttymxc2,115200 earlycon=ec_imx6q,0x30880000,115200, quiet\0" \
	"fdt_addr=0x43000000\0"			\
	"fdt_high=0xffffffffffffffff\0"		\
	"fdt_file="CONFIG_DEFAULT_DTB"\0" \
	"initrd_addr=0x43800000\0"		\
	"initrd_high=0xffffffffffffffff\0" \
	"mmcautodetect=yes\0" \
	"autoload=off\0" \
	"part=1\0" \
	"bootscript=echo Running LUCI bootscript from ${iface} ...; source\0"	\
	"iface_boot=if run loadbootscript; then run bootscript; else if run loadimage; then run loadfdt;" \
	" booti ${loadaddr} - ${fdt_addr}; fi; fi;\0"	\
	"iface_args=setenv bootargs console=${console} root=${rootdev} rootwait rw \0"	\
	"loadbootscript=load ${iface} ${dev}:${part} ${loadaddr} ${script}\0"	\
	"loadfdt=load ${iface} ${dev}:${part} ${fdt_addr} ${fdt_file}\0"	\
	"loadimage=load ${iface} ${dev}:${part} ${loadaddr} ${image}\0"	\
	"mmc_boot=setenv iface mmc; run ${iface}_pre; run ${iface}_init; run iface_args; run iface_boot\0"	\
	"mmc_init=mmc rescan\0"	\
	"mmc_pre=setenv iface mmc; setenv dev ${mmcdev}; setenv rootdev /dev/mmcblk${mmcdev}p2\0"	\
	"kernel_addr_r=" __stringify(CONFIG_SYS_LOAD_ADDR) "\0" \
	"fdt_addr_r=0x43000000\0"

#define CONFIG_BOOTCOMMAND \
	"setenv mmcdev 1; run mmc_boot; setenv mmcdev 0; run mmc_boot;"

/* Memory Layout */
#define CFG_SYS_INIT_RAM_ADDR		0x40000000
#define CFG_SYS_INIT_RAM_SIZE		0x80000

#define PHYS_SDRAM			0x40000000
#define PHYS_SDRAM_SIZE			0x40000000	/* 1 GB, recalculated at runtime */
#define CFG_SYS_SDRAM_BASE		PHYS_SDRAM

/* UART */
#define CFG_MXC_UART_BASE		UART3_BASE_ADDR

/* eMMC/SD */
#define CFG_SYS_FSL_USDHC_NUM		2
#define CFG_SYS_FSL_ESDHC_ADDR		0

/* I2C */
#define CONFIG_SYS_I2C_SPEED		100000

#if defined(CONFIG_ANDROID_SUPPORT)
#include "cl-som-imx8_android.h"
#endif

#endif
