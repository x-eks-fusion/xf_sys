/**
 * @file xf_sys_watchdog.c
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

/* ==================== [Includes] ========================================== */

#include "xf_sys_watchdog.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

#if XF_SYS_WATCHDOG_DEFAULT_IS_ENABLE

__weak xf_err_t xf_sys_watchdog_enable(void)
{
    return XF_ERR_NOT_SUPPORTED;
}

__weak xf_err_t xf_sys_watchdog_disable(void)
{
    return XF_ERR_NOT_SUPPORTED;
}

__weak xf_err_t xf_sys_watchdog_kick(void)
{
    return XF_ERR_NOT_SUPPORTED;
}

#endif

/* ==================== [Static Functions] ================================== */
