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

#if (!defined(XF_SYS_WATCHDOG_WEAK_ENABLE)) || (XF_SYS_WATCHDOG_WEAK_ENABLE)
#   define XF_SYS_WATCHDOG_WEAK_IS_ENABLE     (1)
#else
#   define XF_SYS_WATCHDOG_WEAK_IS_ENABLE     (0)
#endif

#if (!defined(XF_SYS_REBOOT_WEAK_ENABLE)) || (XF_SYS_REBOOT_WEAK_ENABLE)
#   define XF_SYS_REBOOT_WEAK_IS_ENABLE     (1)
#else
#   define XF_SYS_REBOOT_WEAK_IS_ENABLE     (0)
#endif

#if (!defined(XF_SYS_INTERRUPT_WEAK_ENABLE)) || (XF_SYS_INTERRUPT_WEAK_ENABLE)
#   define XF_SYS_INTERRUPT_WEAK_IS_ENABLE     (1)
#else
#   define XF_SYS_INTERRUPT_WEAK_IS_ENABLE     (0)
#endif

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
}
#endif


#endif //__XF_SYS_CONFIG_INTERNAL_H__
