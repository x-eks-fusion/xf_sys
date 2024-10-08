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
 * @param freq: 基准频率
 * @return 错误码
 */
xf_err_t xf_sys_time_init(uint32_t freq, xf_tick_t (*get_tick)(void));

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
 * @brief 延时到一个绝对的时间戳
 *
 * @param tick 延时到的时间戳
 * @return xf_err_t 错误码
 */
xf_err_t xf_delay_until(xf_tick_t tick);

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
 *  @note 如果得到结果恒为 1 ，说明不支持
 *
 * @return xf_us_t 时间戳（微秒）
 */
xf_us_t xf_sys_time_get_us(void);

/**
 * @brief 获取系统时间的时间戳，单位 tick (单位为初始化时设置的 freq 的倒数)
 *
 * @return xf_tick_t 时间戳
 */
xf_tick_t xf_sys_time_get_tick(void);

/**
 * @brief 时间转换： tick 转 ms
 *
 * @return xf_ms_t 时间戳（毫秒）
 */
xf_ms_t xf_sys_time_tick_to_ms(xf_tick_t n_tick);

/**
 * @brief 时间转换： ms 转 tick
 *
 * @return xf_tick_t 时间戳
 */
xf_tick_t xf_sys_time_ms_to_tick(xf_ms_t n_ms);

/**
 * @brief 时间转换： tick 转 us
 *
 * @return xf_us_t 时间戳（微秒）
 */
xf_us_t xf_sys_time_tick_to_us(xf_tick_t n_tick);

/**
 * @brief 时间转换： us 转 tick
 *
 * @return xf_tick_t 时间戳
 */
xf_tick_t xf_sys_time_us_to_tick(xf_us_t n_us);


/* ==================== [Macros] ============================================ */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif // __XF_SYS_TIME_H__
