#include "xf_sys.h"
#include "xf_utils.h"

#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define TAG "main"
#include "unistd.h"

xf_tick_t _port_xf_sys_get_tick(void)
{
    xf_tick_t tick = 0;
    uint32_t freq_ref = 1000 * 1000 * 1000;
    struct timespec current_time;
    clock_gettime(CLOCK_MONOTONIC, &current_time);

    xf_tick_t tick_of_freq_ref = (xf_tick_t)(1000 * 1000 * 1000) / (xf_tick_t)freq_ref;
    tick = (xf_tick_t)current_time.tv_nsec / (xf_tick_t)tick_of_freq_ref
           + (xf_tick_t)current_time.tv_sec * (xf_tick_t)freq_ref;

    return tick;
}

int main(void)
{
    XF_LOGI(TAG, "<xf_sys test>");
    xf_sys_time_init(1000 * 1000 * 1000, _port_xf_sys_get_tick);

    xf_ms_t ms_before = xf_sys_time_get_ms();
    xf_delay_ms(500);
    xf_ms_t ms_after = xf_sys_time_get_ms();

    xf_us_t us_before = xf_sys_time_get_us();
    xf_delay_us(10);
    xf_us_t us_after = xf_sys_time_get_us();

    XF_LOGI(TAG, "tick:ms_before:%lu\tms_after:%lu\tms_diff:%lu",
            ms_before, ms_after, ms_after - ms_before);

    XF_LOGI(TAG, "tick:us_before:%lu\tus_after:%lu\tus_diff:%lu",
            us_before, us_after, us_after - us_before);
    return 0;
}