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

/* ==================== [Static Prototypes] ================================= */

/* ==================== [Static Variables] ================================== */

static xf_us_t (*s_get_us)(void) = NULL;

/* ==================== [Macros] ============================================ */

/* ==================== [Global Functions] ================================== */

xf_err_t xf_sys_time_init(xf_us_t (*get_us)(void))
{
    if (unlikely(get_us == NULL)) {
        return XF_ERR_INVALID_ARG;
    }
    s_get_us = get_us;

    return XF_OK;
}

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

xf_err_t xf_delay_until(xf_us_t n_us)
{
    if (unlikely(n_us <= s_get_us())) {
        return XF_ERR_INVALID_ARG;
    }

    while (n_us > s_get_us());

    return XF_OK;
}

xf_s_t xf_sys_time_get_s(void)
{
    return s_get_us() / 1000 / 1000;
}

xf_ms_t xf_sys_time_get_ms(void)
{
    return s_get_us() / 1000;
}

xf_us_t xf_sys_time_get_us(void)
{
    return s_get_us();
}

/* ==================== [Static Functions] ================================== */
