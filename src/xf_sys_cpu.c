/**
 * @file xf_sys_cpu.c
 * @author cangyu (sky.kirto@qq.com)
 * @brief cpu 相关操作
 * @version 0.1
 * @date 2025-02-04
 *
 * @copyright Copyright (c) 2025, CorAL. All rights reserved.
 *
 */

/* ==================== [Includes] ========================================== */

#include "xf_sys_cpu.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

#if XF_SYS_CPU_WEAK_IS_ENABLE

__weak xf_err_t xf_sys_set_cpu_freq(uint32_t freq_mhz)
{
    return XF_ERR_NOT_SUPPORTED;
}

__weak xf_err_t xf_sys_cpu_run(void)
{
    return XF_ERR_NOT_SUPPORTED;
}

__weak xf_err_t xf_sys_cpu_stop(void)
{
    return XF_ERR_NOT_SUPPORTED;
}

#endif

/* ==================== [Static Functions] ================================== */
