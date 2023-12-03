#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    // Initializing the GPIO pins
    const uint LED_R_PIN = 15;
    const uint LED_G_PIN = 16;
    const uint LED_B_PIN = 17;

    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);

    gpio_init(LED_G_PIN);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);

    gpio_init(LED_B_PIN);
    gpio_set_dir(LED_B_PIN, GPIO_OUT);

    // Set initial state to OFF
    gpio_put(LED_R_PIN, 0);
    gpio_put(LED_G_PIN, 0);
    gpio_put(LED_B_PIN, 0);
   
   
 



       while (true) {
        // The 3 LEDs are Off for the 3secs
        sleep_ms(3000);

        // Red LED turns ON for 1 second then Off
        printf("Turning on red!");
        gpio_put(LED_R_PIN, true);
        sleep_ms(1000);
        gpio_put(LED_R_PIN, false);

        // Green LED turns ON for 1 second then Off
        printf("Turning on green!");
        gpio_put(LED_G_PIN, true);
        sleep_ms(1000);
        gpio_put(LED_G_PIN, false);

        // Blue LED LED turns ON for 1 second then Off
        printf("Turning on blue!");
        gpio_put(LED_B_PIN, true);
        sleep_ms(1000);
        gpio_put(LED_B_PIN, false);

        // Turn on all the three LEDs together for 2 Seconds then Turn off all the LEDs
        printf("Turning on all LEDs!");
       turn_on_all_leds();
        sleep_ms(2000);
        turn_off_all_leds();
        
    }

    return 0;
}