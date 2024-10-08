/**
 * @file xf_sys_time.h
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

#ifndef __XF_SYS_TIME_H__
#define __XF_SYS_TIME_H__

/* ==================== [Includes] ========================================== */

#include "xf_sys_config_internal.h"
#include "xf_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

/* ==================== [Global Prototypes] ================================= */

/***
 * @brief 对接us级时间戳
 *
 * @param get_us: us级时间戳获取函数
 * @return 错误码
 */
xf_err_t xf_sys_time_init(xf_us_t (*get_us)(void));

/**
 * @brief 毫秒级延时
 *
 * @param ms 需要延时的毫秒数
 * @return 错误码
 */
xf_err_t xf_delay_ms(xf_ms_t n_ms);

/**
 * @brief 微秒级延时
 *
 * @param ms 需要延时的微秒数
 * @return 错误码
 */
xf_err_t xf_delay_us(xf_us_t n_us);

/**
 * @brief 延时到一个绝对的 us 级时间戳
 *
 * @param n_us 延时到的 us 级时间戳
 * @return xf_err_t 错误码
 */
xf_err_t xf_delay_until(xf_us_t n_us);

/**
 * @brief 获取系统时间的时间戳，单位秒（s）
 *
 * @return uint32_t 时间戳（秒）
 */
xf_s_t xf_sys_time_get_s(void);

/**
 * @brief 获取系统时间的时间戳，单位毫秒（ms）
 *
 * @return xf_ms_t 时间戳（毫秒）
 */
xf_ms_t xf_sys_time_get_ms(void);

/**
 * @brief 获取系统时间的时间戳，单位微秒（us）
 *
 *
 * @return xf_us_t 时间戳（微秒）
 */
xf_us_t xf_sys_time_get_us(void);

/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_SYS_TIME_H__
