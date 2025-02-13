/**
 * @file xf_sys_rtc.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief 
 * @version 0.1
 * @date 2025-02-13
 * 
 * @copyright Copyright (c) 2025, CorAL. All rights reserved.
 * 
 */

#ifndef __XF_SYS_RTC_H__
#define __XF_SYS_RTC_H__

/* ==================== [Includes] ========================================== */

#include "xf_sys_config_internal.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

xf_err_t xf_sys_rtc_init(void);

xf_err_t xf_sys_rtc_deinit(void);

uint64_t xf_sys_get_rtc_count(void);

xf_err_t xf_sys_set_rtc_count(uint64_t count);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_SYS_RTC_H__
