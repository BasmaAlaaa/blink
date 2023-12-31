#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/pwm.h"

void setPosition(uint servoPin, float millis)
{
    pwm_set_gpio_level(servoPin, (millis / 20000.f) * 39062.f);
}

void setServo(uint servoPin, float startPosition)
{
    // Set up PWM
    gpio_set_function(servoPin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(servoPin);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 64.f);
    pwm_config_set_wrap(&config, 39062.f);

    pwm_init(slice_num, &config, true);

    // Set initial position
    setPosition(servoPin, startPosition);
}