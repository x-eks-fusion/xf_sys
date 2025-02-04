/**
 * @file xf_sys_cpu.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief cpu 相关操作
 * @version 0.1
 * @date 2025-02-04
 * 
 * @copyright Copyright (c) 2025, CorAL. All rights reserved.
 * 
 */

#ifndef __XF_SYS_CPU_H__
#define __XF_SYS_CPU_H__

/* ==================== [Includes] ========================================== */

#include "xf_sys_config_internal.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/**
 * @brief 设置cpu频率
 * 
 * @param freq_mhz 设置CPU的频率为freq_mhz
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败 
 */
xf_err_t xf_sys_set_cpu_freq(uint32_t freq_mhz);

/**
 * @brief CPU运行
 * 
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_cpu_run(void);

/**
 * @brief 暂停CPU
 * 
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_cpu_stop(void);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_SYS_CPU_H__
