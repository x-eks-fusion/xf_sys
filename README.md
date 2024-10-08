# xf_sys

在一些场景中，应用层需要直接调用一些底层暴露的函数。这部分函数一方面很难使用软件实现。另一方面，几乎所有sdk也有实现。于是这部分被总结成 xf_sys 库。

##  xf_sys 库的函数

```c
/***
 * @brief 对接us级时间戳
 *
 * @param freq: 基准频率
 * @return 错误码
 */
xf_err_t xf_sys_init(uint32_t freq, xf_tick_t (*get_tick)(void));

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
xf_s_t xf_sys_get_s(void);

/**
 * @brief 获取系统时间的时间戳，单位毫秒（ms）
 *
 * @return xf_ms_t 时间戳（毫秒）
 */
xf_ms_t xf_sys_get_ms(void);

/**
 * @brief 获取系统时间的时间戳，单位微秒（us）
 *  @note 如果得到结果恒为 1 ，说明不支持
 *
 * @return xf_us_t 时间戳（微秒）
 */
xf_us_t xf_sys_get_us(void);

/**
 * @brief 获取系统时间的时间戳，单位 tick (单位为初始化时设置的 freq 的倒数)
 *
 * @return xf_tick_t 时间戳
 */
xf_tick_t xf_sys_get_tick(void);

/**
 * @brief 时间转换： tick 转 ms
 *
 * @return xf_ms_t 时间戳（毫秒）
 */
xf_ms_t xf_sys_tick_to_ms(xf_tick_t n_tick);

/**
 * @brief 时间转换： ms 转 tick
 *
 * @return xf_tick_t 时间戳
 */
xf_tick_t xf_sys_ms_to_tick(xf_ms_t n_ms);

/**
 * @brief 时间转换： tick 转 us
 *
 * @return xf_us_t 时间戳（微秒）
 */
xf_us_t xf_sys_tick_to_us(xf_tick_t n_tick);

/**
 * @brief 时间转换： us 转 tick
 *
 * @return xf_tick_t 时间戳
 */
xf_tick_t xf_sys_us_to_tick(xf_us_t n_us);

```

这部分通过对接底层的us级时间戳。实现了阻塞式delay等相关操作

```c
/**
 * @brief 系统软件重启（需对接）
 * 
 */
xf_sys_reset() 

/**
 * @brief 打开系统中断（需对接）
 * 
 */
xf_sys_interrupt_enable()

/**
 * @brief 关闭系统中断（需对接）
 * 
 */
xf_sys_interrupt_disable()

```

此外还有开关系统中断和软件重启等功能需要底层对接


```c
/**
 * @brief 开启看门狗
 * 
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_watchdog_enable(void);

/**
 * @brief 关闭看门狗
 * 
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_watchdog_disable(void);

/**
 * @brief 喂狗，防止看门狗超时叫
 * 
 * @return xf_err_t 返回 XF_OK 表示成功，否则表示失败
 */
xf_err_t xf_sys_watchdog_kick(void);

```

看门狗的相关操作也需要底层对接。

