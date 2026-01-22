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
	"kernel_addr_r=" __stringify(CONFIG_SYS_LOAD_ADDR) "\0" \
	"fdt_addr_r=0x43000000\0"

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
