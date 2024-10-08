/**
 * @file xf_sys.c
 * @author cangyu (sky.kirto@qq.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-08
 * 
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 * 
 */

/* ==================== [Includes] ========================================== */

#include "xf_sys.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

#if XF_SYS_REBOOT_WEAK_IS_ENABLE

__weak xf_err_t xf_sys_reboot(void)
{
    return XF_ERR_NOT_SUPPORTED;
}

#endif

#if XF_SYS_INTERRUPT_WEAK_IS_ENABLE

__weak xf_err_t xf_sys_interrupt_enable(void)
{
    return XF_ERR_NOT_SUPPORTED;
}

__weak xf_err_t xf_sys_interrupt_disable(void)
{
    return XF_ERR_NOT_SUPPORTED;
}

#endif

/* ==================== [Static Functions] ================================== */
