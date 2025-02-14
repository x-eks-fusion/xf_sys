/**
 * @file xf_sys.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief xf_sys 系统级接口包含门狗控制、开关系统中断、获取时间戳及阻塞精确延迟等功能。
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

/**
 * @cond (XFAPI_USER || XFAPI_PORT || XFAPI_INTERNAL)
 * @defgroup group_xf_sys xf_sys
 * @brief xf_sys 系统级接口包含门狗控制、开关系统中断、获取时间戳及阻塞精确延迟等功能。
 * @endcond
 */

#ifndef __XF_SYS_H__
#define __XF_SYS_H__

/* ==================== [Includes] ========================================== */

#include "xf_sys_config_internal.h"
#include "xf_sys_time.h"
#include "xf_sys_watchdog.h"
#include "xf_sys_cpu.h"
#include "xf_sys_rtc.h"

/**
 * @cond (XFAPI_USER || XFAPI_PORT)
 * @addtogroup group_xf_sys
 * @endcond
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/**
 * @brief 软件系统重启
 *
 */
void xf_sys_reboot(void);

/**
 * @brief 打开系统中断
 *
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_interrupt_enable(void);

/**
 * @brief 关闭系统中断
 *
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_interrupt_disable(void);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

/**
 * End of addtogroup group_xf_sys
 * @}
 */

#endif // __XF_SYS_H__
