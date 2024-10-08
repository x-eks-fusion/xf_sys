#include "xf_sys.h"
#include "xf_utils.h"

#include <stdio.h>
#include <sys/time.h>

#define TAG "main"

xf_us_t _port_xf_sys_get_us(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

int main(void)
{
    XF_LOGI(TAG, "<xf_sys test>");
    xf_sys_time_init(_port_xf_sys_get_us);

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