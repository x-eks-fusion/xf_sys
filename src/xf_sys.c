/**
 * @file xf_sys.c
 * @author dotc (dotchan@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-07-10
 *
 * @copyright Copyright (c) 2024
 *
 */

/* ==================== [Includes] ========================================== */

#include "xf_utils.h"
#include "xf_sys.h"

/* ==================== [Defines] =========================================== */

/* ==================== [Typedefs] ========================================== */

#define XF_FREQ_OF_S    (1)             /*!< 1s 频率 */
#define XF_FREQ_OF_MS   (1000UL)        /*!< 1ms 频率 */
#define XF_FREQ_OF_US   (1000000UL)     /*!< 1us 频率 */

/* ==================== [Static Prototypes] ================================= */

/**
 * @brief 增加 __always_inline 属性使得内部调用以下函数时尽量内联
 */
__always_inline inline xf_ms_t xf_sys_tick_to_ms(xf_tick_t n_tick);
__always_inline inline xf_tick_t xf_sys_ms_to_tick(xf_ms_t n_ms);
__always_inline inline xf_us_t xf_sys_tick_to_us(xf_tick_t n_tick);
__always_inline inline xf_tick_t xf_sys_us_to_tick(xf_us_t n_us);

/* ==================== [Static Variables] ================================== */

static const char *TAG = "xf_sys";

static xf_ms_t s_tick_of_ms = 0;
static xf_us_t s_tick_of_us = 0;
static xf_tick_t (*s_get_tick)(void) = NULL;

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

/***
 * @brief 根据传入基准频率初始化系统时间
 *
 * @param freq: 基准频率
 * @return 错误码
 */
xf_err_t xf_sys_init(uint32_t freq, xf_tick_t (*get_tick)(void))
{
    if (unlikely(freq < XF_FREQ_OF_MS)) {
        XF_LOGE(TAG, "freq(%u) < XF_FREQ_OF_US", freq);
        return XF_ERR_INVALID_ARG;
    }
    s_get_tick = get_tick;
    s_tick_of_ms =  freq / XF_FREQ_OF_MS;
    s_tick_of_us =  freq / XF_FREQ_OF_US;

    return XF_OK;
}

/**
 * @brief 毫秒级延时
 *
 * @param ms 需要延时的毫秒数
 */
xf_err_t xf_delay_ms(xf_ms_t n_ms)
{
    xf_tick_t tick_timeout = s_get_tick();
    if (unlikely(n_ms == 0)) {
        return XF_ERR_INVALID_ARG;
    }

    tick_timeout += xf_sys_ms_to_tick(n_ms);
    while (tick_timeout > s_get_tick());
    return XF_OK;
}

/**
 * @brief 微秒级延时
 *
 * @param ms 需要延时的微秒数
 */
xf_err_t xf_delay_us(xf_us_t n_us)
{
    xf_tick_t tick_timeout = s_get_tick();
    if (unlikely(n_us == 0)) {
        return XF_ERR_INVALID_ARG;
    }

    if (unlikely(s_tick_of_us == 0)) {
        return XF_ERR_NOT_SUPPORTED;
    }

    tick_timeout += xf_sys_us_to_tick(n_us);
    while (tick_timeout > s_get_tick());
    return XF_OK;
}

/**
 * @brief 延时到一个绝对的时间戳
 * 
 * @param tick 延时到的时间戳
 * @return xf_err_t 错误码 
 */
xf_err_t xf_delay_until(xf_tick_t tick)
{
    if (unlikely(tick <= s_get_tick()))
    {
        return XF_ERR_INVALID_ARG;
    }
    
    while (tick > s_get_tick());
    return XF_OK;
}

/**
 * @brief 获取系统时间的时间戳，单位秒（s）
 *
 * @return xf_s_t 时间戳（秒）
 */
xf_s_t xf_sys_get_s(void)
{
    xf_tick_t tick = s_get_tick();
    return (xf_sys_tick_to_ms(tick) / 1000);
}

/**
 * @brief 获取系统时间的时间戳，单位毫秒（ms）
 *
 * @return xf_ms_t 时间戳（毫秒）
 */
xf_ms_t xf_sys_get_ms(void)
{
    xf_tick_t tick = s_get_tick();
    return xf_sys_tick_to_ms(tick);
}

/**
 * @brief 获取系统时间的时间戳，单位微秒（us）
 *
 * @return xf_us_t 时间戳（微秒）
 */
xf_us_t xf_sys_get_us(void)
{
    xf_tick_t tick = s_get_tick();
    return xf_sys_tick_to_us(tick);
}

/**
 * @brief 获取系统时间的时间戳，单位 tick (单位为初始化时设置的 freq 的倒数)
 *
 * @return xf_tick_t 时间戳
 */
xf_tick_t xf_sys_get_tick(void)
{
    return s_get_tick();
}

// FIXME 以下运算均有溢出风险
/**
 * @brief 时间转换： tick 转 ms
 *
 * @return xf_ms_t 毫秒
 */
xf_ms_t xf_sys_tick_to_ms(xf_tick_t n_tick)
{
    if (unlikely(n_tick == 0)) {
        XF_LOGE(TAG, "n_tick could not be 0");
        return 1;
    }
    return (n_tick / (xf_tick_t)s_tick_of_ms);
}

/**
 * @brief 时间转换： ms 转 tick
 *
 * @return xf_tick_t tick
 */
xf_tick_t xf_sys_ms_to_tick(xf_ms_t n_ms)
{
    if (unlikely(n_ms == 0)) {
        XF_LOGE(TAG, "n_ms could not be 0");
        return 1;
    }
    return ((xf_tick_t)n_ms * (xf_tick_t)s_tick_of_ms);
}

/**
 * @brief 时间转换： tick 转 us
 *
 * @return xf_us_t 微秒
 */
xf_us_t xf_sys_tick_to_us(xf_tick_t n_tick)
{
    if (unlikely(s_tick_of_us == 0) || unlikely(n_tick == 0)) {
        XF_LOGE(TAG, "tick not support convert us");
        return 1;
    }
    return (n_tick / (xf_tick_t)s_tick_of_us);
}

/**
 * @brief 时间转换： us 转 tick
 *
 * @return xf_tick_t tick
 */
xf_tick_t xf_sys_us_to_tick(xf_us_t n_us)
{
    if (unlikely(s_tick_of_us == 0) || unlikely(n_us == 0)) {
        XF_LOGE(TAG, "us not support convert tick");
        return 1;
    }

    return ((xf_tick_t)n_us * (xf_tick_t)s_tick_of_us);
}

/* ==================== [Static Functions] ================================== */
