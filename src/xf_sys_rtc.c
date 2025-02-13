/**
 * @file xf_sys_rtc.c
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2025-02-13
 *
 * @copyright Copyright (c) 2025, CorAL. All rights reserved.
 *
 */

/* ==================== [Includes] ========================================== */

#include "xf_sys_rtc.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

#if XF_SYS_RTC_WEAK_IS_ENABLE

__weak xf_err_t xf_sys_rtc_init(void)
{

}

__weak xf_err_t xf_sys_rtc_deinit(void)
{

}

__weak uint64_t xf_sys_get_rtc_count(void)
{

}

__weak xf_err_t xf_sys_set_rtc_count(uint64_t count)
{

}

#endif

/* ==================== [Static Functions] ================================== */
