/**
 * @file xf_sys_time.c
 * @author cangyu (sky.kirto@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-10-08
 *
 * @copyright Copyright (c) 2024, CorAL. All rights reserved.
 *
 */

/* ==================== [Includes] ========================================== */

#include "xf_sys_time.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

#define XF_FREQ_OF_S    (1)             /*!< 1s 频率 */
#define XF_FREQ_OF_MS   (1000UL)        /*!< 1ms 频率 */
#define XF_FREQ_OF_US   (1000000UL)     /*!< 1us 频率 */

/* ==================== [Static Prototypes] ================================= */

/**
 * @brief 增加 __always_inline 属性使得内部调用以下函数时尽量内联
 */

/* ==================== [Static Variables] ================================== */

static xf_us_t (*s_get_us)(void) = NULL;

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

/***
 * @brief 根据传入基准频率初始化系统时间
 *
 * @param freq: 基准频率
 * @return 错误码
 */
xf_err_t xf_sys_time_init(xf_us_t (*get_us)(void))
{
    if (unlikely(get_us == NULL)) {
        return XF_ERR_INVALID_ARG;
    }
    s_get_us = get_us;

    return XF_OK;
}

/**
 * @brief 毫秒级延时
 *
 * @param ms 需要延时的毫秒数
 */
xf_err_t xf_delay_ms(xf_ms_t n_ms)
{
    if (unlikely(n_ms == 0)) {
        return XF_ERR_INVALID_ARG;
    }
    xf_us_t timeout_us = s_get_us();

    timeout_us += n_ms * 1000;
    while (timeout_us > s_get_us());

    return XF_OK;
}

/**
 * @brief 微秒级延时
 *
 * @param ms 需要延时的微秒数
 */
xf_err_t xf_delay_us(xf_us_t n_us)
{
    if (unlikely(n_us == 0)) {
        return XF_ERR_INVALID_ARG;
    }

    xf_us_t timeout_us = s_get_us();

    timeout_us += n_us;
    while (timeout_us > s_get_us());

    return XF_OK;
}

/**
 * @brief 延时到一个绝对的时间戳
 *
 * @param tick_us 延时到的时间戳
 * @return xf_err_t 错误码
 */
xf_err_t xf_delay_until(xf_us_t n_us)
{
    if (unlikely(n_us <= s_get_us())) {
        return XF_ERR_INVALID_ARG;
    }

    while (n_us > s_get_us());

    return XF_OK;
}

/**
 * @brief 获取系统时间的时间戳，单位秒（s）
 *
 * @return xf_s_t 时间戳（秒）
 */
xf_s_t xf_sys_time_get_s(void)
{
    return s_get_us() / 1000 / 1000;
}

/**
 * @brief 获取系统时间的时间戳，单位毫秒（ms）
 *
 * @return xf_ms_t 时间戳（毫秒）
 */
xf_ms_t xf_sys_time_get_ms(void)
{
    return s_get_us() / 1000;
}

/**
 * @brief 获取系统时间的时间戳，单位微秒（us）
 *
 * @return xf_us_t 时间戳（微秒）
 */
xf_us_t xf_sys_time_get_us(void)
{
    return s_get_us();
}

/* ==================== [Static Functions] ================================== */
