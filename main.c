// #include <stdio.h>
// #include "pico/stdlib.h"
// #include "hardware/irq.h"
// #include "hardware/pwm.h"
// #include "hardware/clocks.h"
// #include "hardware/pio.h"
// #include "hardware/uart.h"
// #include "servoLib/makeshift_servo_library.h"
// #include "hardware/i2c.h"

// bool direction = true;
// float currentMillis = 400.f;
// const uint IR_SENSOR_PIN = 28;
// const uint TRIG_PIN = 19;
// const uint ECHO_PIN = 20;
// const uint MOTOR_PIN = 21;
// const uint SERVO_PIN = 12;
// const uint BUZZER_PIN = 16;
// int main()
// {
//    stdio_init_all();
//    gpio_init(TRIG_PIN);
//    gpio_init(ECHO_PIN);
//    gpio_init(MOTOR_PIN);
//    gpio_set_dir(MOTOR_PIN, GPIO_OUT);
//    gpio_init(SERVO_PIN);
//    gpio_set_dir(SERVO_PIN, GPIO_OUT);
//    gpio_init(IR_SENSOR_PIN);
//    gpio_set_dir(IR_SENSOR_PIN, GPIO_IN);
//    // Set Trigger to output, Echo to input
//    gpio_set_dir(TRIG_PIN, GPIO_OUT);
//    gpio_set_dir(ECHO_PIN, GPIO_IN);
//    // Initializing the GPIO pins
//    const uint LED_R_PIN = 15;
//    //const uint LED_G_PIN = 16;
//    const uint LED_B_PIN = 17;

//    gpio_set_dir(TRIG_PIN, GPIO_OUT);
//    gpio_set_dir(ECHO_PIN, GPIO_IN);

//    gpio_init(LED_R_PIN);
//    gpio_set_dir(LED_R_PIN, GPIO_OUT);

//    gpio_init(LED_B_PIN);
//    gpio_set_dir(LED_B_PIN, GPIO_OUT);

//    gpio_init(BUZZER_PIN);
//       gpio_set_dir(BUZZER_PIN, GPIO_OUT);

//    //   gpio_set_dir(BUZZER_PIN, GPIO_OUT);

//    // Set initial state to OFF for LEDs and Buzzer
//    gpio_put(LED_R_PIN, 0);
//    gpio_put(LED_B_PIN, 0);
//    gpio_put(BUZZER_PIN, 0);

//    // Initialize GPIO for PWM
//    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);

//    // Get the PWM slice for the GPIO pin
//    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);

//    // Set PWM frequency: 50Hz for standard servos
//    pwm_set_wrap(slice_num, 50000 - 1); // 20ms period (1/50Hz)
//    pwm_set_clkdiv(slice_num, 100);     // Set the clock divider

//    // Start PWM
//    pwm_set_enabled(slice_num, true);

//    while (true)
//    {
//       //         // Blink RED twice each is 0.5 sec with a gap 0.5 sec
//       //         gpio_put(LED_R_PIN, true);
//       //         sleep_ms(500);
//       //         gpio_put(LED_R_PIN, false);
//       //          sleep_ms(500);
//       //         gpio_put(LED_R_PIN, true);
//       //         sleep_ms(500);
//       //         gpio_put(LED_R_PIN, false);
//       //          sleep_ms(500);

//       //         // Blink GREEN twice each is 0.5 sec with a gap 0.5 sec
//       //         gpio_put(LED_G_PIN, true);
//       //         sleep_ms(500);
//       //         gpio_put(LED_G_PIN, false);
//       //         sleep_ms(500);

//       //          gpio_put(LED_G_PIN, true);
//       //         sleep_ms(500);
//       //         gpio_put(LED_G_PIN, false);
//       //         sleep_ms(500);

//       //         // Blink BLUE twice each is 0.5 sec with a gap 0.5 sec
//       //         gpio_put(LED_B_PIN, true);
//       //         sleep_ms(500);
//       //         gpio_put(LED_B_PIN, false);
//       //         sleep_ms(500);
//       //         gpio_put(LED_B_PIN, true);
//       //         sleep_ms(500);
//       //         gpio_put(LED_B_PIN, false);
//       //         sleep_ms(500);
//       // //BLINK WHITE twice
//       //         gpio_put(LED_B_PIN, true);
//       //         gpio_put(LED_R_PIN, true);
//       //         gpio_put(LED_G_PIN, true);
//       //         sleep_ms(500);
//       //         gpio_put(LED_B_PIN, false);
//       //         gpio_put(LED_R_PIN, false);
//       //         gpio_put(LED_G_PIN, false);
//       //         sleep_ms(500);
//       //         gpio_put(LED_B_PIN, true);
//       //         gpio_put(LED_R_PIN, true);
//       //         gpio_put(LED_G_PIN, true);
//       //         sleep_ms(500);
//       //         gpio_put(LED_B_PIN, false);
//       //         gpio_put(LED_R_PIN, false);
//       //         gpio_put(LED_G_PIN, false);
//       //         sleep_ms(500);

//          gpio_put(BUZZER_PIN, true);
//       //    sleep_ms(100000); // Buzzer on for 100ms
//       //    gpio_put(BUZZER_PIN, false);
//       //    sleep_ms(500); // Pause before next buzzer sound or LED blink

//       // Send a trigger pulse
//       //         gpio_put(TRIG_PIN, 1);
//       //         sleep_us(10);
//       //         gpio_put(TRIG_PIN, 0);

//       //         // Measure the length of the echo pulse
//       //         while (gpio_get(ECHO_PIN) == 0);
//       //         absolute_time_t start_time = get_absolute_time();

//       //         while (gpio_get(ECHO_PIN) == 1);
//       //         absolute_time_t end_time = get_absolute_time();

//       //         // Calculate distance
//       //         int64_t duration = absolute_time_diff_us(start_time, end_time);
//       //         float distance = (duration * 0.0343) / 2;
//       //  if(distance<10){
//       //         gpio_put(BUZZER_PIN, true);
//       //          sleep_ms(1000); // Buzzer on for 100ms
//       //        gpio_put(BUZZER_PIN, false);
//       //  sleep_ms(500);
//       //   }
//       //         printf("Distance: %.2f cm\n", distance);

//       //         // Wait before next measurement
//       //         sleep_ms(500);

//       //   gpio_put(MOTOR_PIN, 1); // Activate motor
//       //     sleep_ms(30000);         // Motor on for 1 second
//       //    gpio_put(MOTOR_PIN, 0); // Deactivate motor
//       //  sleep_ms(1000);         // Motor off for 1 second

//       // Example: Move servo to one position
//       //   pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), 1500); // 1.5ms pulse for 0 degrees
//       //   sleep_ms(1000);

//       //   // Move servo to another position
//       //   pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), 2000); // 2ms pulse for 90 degrees
//       //   sleep_ms(1000);

//       //   // Move servo back to start position
//       //   pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), 1000); // 1ms pulse for -90 degrees
//       //   sleep_ms(1000);

//       // if (gpio_get(IR_SENSOR_PIN) == 0)
//       // {
//       //    printf("Obstacle detected!\n");
//       // }
//       // else
//       // {
//       //    printf("Path is clear.\n");
//       // }
//       // sleep_ms(1000); // Pause before next measurement
//     }

//    return 0;
// }
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "hardware/uart.h"
#include "servoLib/makeshift_servo_library.h"
#include "hardware/i2c.h"

// Constants for GPIO Pins (replace with your actual GPIO pin numbers)
bool direction = true;
float currentMillis = 400.f;
const uint ULTRASONIC_SENSOR_PIN = 0;
const uint IR_SENSOR_PIN = 1;
const uint BUZZER_PIN = 2;
const uint SERVO_PIN = 3;
const uint LEFT_VIBRATION_MOTOR_PIN = 4;
const uint RIGHT_VIBRATION_MOTOR_PIN = 5;
const uint TRIG_PIN = 6;
const uint ECHO_PIN = 7;
const int LEFT_ANGLE = 0;
const int RIGHT_ANGLE = 180;
const float THRESHOLD = 30.0; // in centimeters

// Initialize system
void init()
{
   gpio_init(ULTRASONIC_SENSOR_PIN);
   gpio_init(IR_SENSOR_PIN);
   gpio_init(BUZZER_PIN);
   gpio_init(SERVO_PIN);
   gpio_init(LEFT_VIBRATION_MOTOR_PIN);
   gpio_init(RIGHT_VIBRATION_MOTOR_PIN);
   gpio_init(TRIG_PIN);
   gpio_init(ECHO_PIN);
   gpio_set_dir(IR_SENSOR_PIN, GPIO_IN);
   gpio_set_dir(ULTRASONIC_SENSOR_PIN, GPIO_IN);
   gpio_set_dir(BUZZER_PIN, GPIO_OUT);
   gpio_set_dir(SERVO_PIN, GPIO_OUT);
   gpio_set_dir(LEFT_VIBRATION_MOTOR_PIN, GPIO_OUT);
   gpio_set_dir(RIGHT_VIBRATION_MOTOR_PIN, GPIO_OUT);
   gpio_set_dir(TRIG_PIN, GPIO_OUT);
   gpio_set_dir(ECHO_PIN, GPIO_IN);
   gpio_put(TRIG_PIN, 0);
   gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
   uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
   pwm_set_wrap(slice_num, 20000 - 1); // 20ms period (assuming a clock of 1MHz)
   pwm_set_clkdiv(slice_num, 125.0);   // Set clock divider to run PWM at 1MHz
   pwm_set_enabled(slice_num, true);
}

float read_ultrasonic()
{ //  Send a trigger pulse
   gpio_put(TRIG_PIN, 1);
   sleep_us(10);
   gpio_put(TRIG_PIN, 0);

   // Measure the length of the echo pulse
   while (gpio_get(ECHO_PIN) == 0)
      ;
   absolute_time_t start_time = get_absolute_time();

   while (gpio_get(ECHO_PIN) == 1)
      ;
   absolute_time_t end_time = get_absolute_time();

   //     Calculate distance
   int64_t duration = absolute_time_diff_us(start_time, end_time);
   float distance = (duration * 0.0343) / 2;
   return distance;
}

// Read data from IR sensor
bool read_ir_sensor()
{
   return gpio_get(IR_SENSOR_PIN);
}

// Move the servo motor to a specific angle
void move_servo(int angle)
{
   // Calculate the duty cycle for the given angle
   // 1ms pulse for 0 degrees to 2ms pulse for 180 degrees
   uint duty_cycle = (angle * 1000 / 180) + 1000;

   // Apply the duty cycle to the PWM
   uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
   pwm_set_chan_level(slice_num, pwm_gpio_to_channel(SERVO_PIN), duty_cycle);
}
void try_ultrasonic()
{

   //  Send a trigger pulse
   gpio_put(TRIG_PIN, 1);
   sleep_us(10);
   gpio_put(TRIG_PIN, 0);

   // Measure the length of the echo pulse
   while (gpio_get(ECHO_PIN) == 0)
      ;
   absolute_time_t start_time = get_absolute_time();

   while (gpio_get(ECHO_PIN) == 1)
      ;
   absolute_time_t end_time = get_absolute_time();

   //     Calculate distance
   int64_t duration = absolute_time_diff_us(start_time, end_time);
   float distance = (duration * 0.0343) / 2;
   if (distance < 10)
   {
      gpio_put(BUZZER_PIN, true);
      sleep_ms(1000); // Buzzer on for 100ms
      gpio_put(BUZZER_PIN, false);
      sleep_ms(500);
   }
   printf("Distance: %.2f cm\n", distance);

   //  Wait before next measurement
   sleep_ms(500);
}

// Main logic
int main()
{
   init();

   while (true)
   {

      if (read_ir_sensor() == 0)
      {
         // Activate both vibration motors to signal a hole
         gpio_put(LEFT_VIBRATION_MOTOR_PIN, 0);
         gpio_put(RIGHT_VIBRATION_MOTOR_PIN, 0);
      }
      else
      {
         gpio_put(LEFT_VIBRATION_MOTOR_PIN, 1);
         gpio_put(RIGHT_VIBRATION_MOTOR_PIN, 1);
      }

      float distance = read_ultrasonic();
      if (distance < THRESHOLD)
      { // Define a suitable threshold
         // Activate buzzer
         gpio_put(BUZZER_PIN, 1);
         sleep_ms(1000);
         gpio_put(BUZZER_PIN, 0);
         // Check path to the left
         move_servo(LEFT_ANGLE); // Define LEFT_ANGLE
         sleep_ms(1500);         // Wait for the servo to move and sensor to stabilize
         float left_distance = read_ultrasonic();
         printf("Left Distance: %.2f cm\n", left_distance);
         // Check path to the right
         move_servo(RIGHT_ANGLE); // Define RIGHT_ANGLE
         sleep_ms(1500);          // Wait for the servo to move and sensor to stabilize
         float right_distance = read_ultrasonic();
         printf("Right Distance: %.2f cm\n", right_distance);

         // Compare distances and activate the corresponding vibration motor
         if (left_distance > right_distance)
         {
            gpio_put(LEFT_VIBRATION_MOTOR_PIN, 1);
            gpio_put(RIGHT_VIBRATION_MOTOR_PIN, 0);
            gpio_put(BUZZER_PIN, 1);
            sleep_ms(500);
            gpio_put(BUZZER_PIN, 0);
         }
          if (left_distance < right_distance)

         {
            gpio_put(LEFT_VIBRATION_MOTOR_PIN, 0);
            gpio_put(RIGHT_VIBRATION_MOTOR_PIN, 1);
            gpio_put(BUZZER_PIN, 1);
            sleep_ms(500);
            gpio_put(BUZZER_PIN, 0);
            sleep_ms(500);
            gpio_put(BUZZER_PIN, 1);

            sleep_ms(500);
            gpio_put(BUZZER_PIN, 0);
         }
         // else
         // {
         //    gpio_put(LEFT_VIBRATION_MOTOR_PIN, 1);
         //    gpio_put(RIGHT_VIBRATION_MOTOR_PIN, 1);
         // }
         move_servo(90);

         //  move_servo(0);

         // else
         // {
         //    // Deactivate all alert systems
         //    gpio_put(BUZZER_PIN, 0);
         //    gpio_put(LEFT_VIBRATION_MOTOR_PIN, 0);
         //    gpio_put(RIGHT_VIBRATION_MOTOR_PIN, 0);
         // }
      }

      sleep_ms(1000); // Main loop delay
      // }
      // while (true){
      //    if(read_ir_sensor()==  1){
      //   gpio_put (BUZZER_PIN, 0);
      //    }
      //    else{
      //       gpio_put (BUZZER_PIN, 1);
      //    }
      //    move_servo(-90);
      //    sleep_ms(500);   //    move_servo(90);
      // //   gpio_put (LEFT_VIBRATION_MOTOR_PIN, 1);
      // //    gpio_put (RIGHT_VIBRATION_MOTOR_PIN, 1);
      //   float distance = read_ultrasonic();
      //     if(distance<30){
      //              gpio_put(BUZZER_PIN, true);
      //            sleep_ms(1000);  //Buzzer on for 100ms
      //             gpio_put(BUZZER_PIN, false);
      //       sleep_ms(500);
      //        }
      //              printf("Distance: %.2f cm\n", distance);

      //          //  Wait before next measurement
      //              sleep_ms(500);
   }
}