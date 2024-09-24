/**
 * @file xf_sys_config_internal.h
 * @author dotc (dotchan@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-07-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef __XF_SYS_CONFIG_INTERNAL_H__
#define __XF_SYS_CONFIG_INTERNAL_H__

/* ==================== [Includes] ========================================== */

#include "xf_sys_config.h"
#include "xf_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

#ifndef XF_TICK_TYPE
#define XF_TICK_TYPE uint64_t
#endif

typedef XF_TICK_TYPE xf_tick_t;

#ifndef XF_S_TYPE
#define XF_S_TYPE uint64_t
#endif

typedef XF_S_TYPE xf_s_t;

#ifndef XF_MS_TYPE
#define XF_MS_TYPE uint64_t
#endif

typedef XF_MS_TYPE xf_ms_t;

#ifndef XF_US_TYPE
#define XF_US_TYPE uint64_t
#endif

typedef XF_US_TYPE xf_us_t;

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

/**
 * @brief 系统软件重启（需对接）
 * 
 */
#ifndef xf_sys_reset
#define xf_sys_reset()      (void)0
#endif

/**
 * @brief 打开系统中断（需对接）
 * 
 */
#ifndef xf_sys_interrupts_enable
#define xf_sys_interrupts_enable()      (void)0
#endif

/**
 * @brief 关闭系统中断（需对接）
 * 
 */
#ifndef xf_sys_interrupts_disable
#define xf_sys_interrupts_disable()     (void)0
#endif

#ifdef __cplusplus
}
#endif


#endif //__XF_SYS_CONFIG_INTERNAL_H__
