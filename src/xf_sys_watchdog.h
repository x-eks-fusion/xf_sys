/**
 * @file xf_sys_watchdog.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_SYS_WATCHDOG_H__
#define __XF_SYS_WATCHDOG_H__

/* ==================== [Includes] ========================================== */

#include "xf_sys_config_internal.h"
#include "xf_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/**
 * @brief 开启看门狗
 *
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_watchdog_enable(void);

/**
 * @brief 关闭看门狗
 *
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_watchdog_disable(void);

/**
 * @brief 喂狗，防止看门狗超时叫
 *
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_watchdog_kick(void);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_SYS_WATCHDOG_H__
