#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "sdkconfig.h"
#include "driver/ledc.h"
#include "esp_err.h"

void app_main() {
    // while (1) {
    //     pressed_button_hook();
    //     open_close_hook();
        display_picture();
    // }
}
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  app_main();
}

// #include <stdio.h>
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/gpio.h"
// #include "rom/gpio.h"
// #include "sdkconfig.h"
// #include "driver/ledc.h"
// #include "esp_err.h"

// #define BLINK_GPIO 23
// #define LEDC_CHANNEL LEDC_CHANNEL_0
// #define LEDC_TIMER LEDC_TIMER_0
// #define LEDC_MODE LEDC_HIGH_SPEED_MODE
// #define LEDC_OUTPUT_IO (gpio_num_t)BLINK_GPIO
// #define LEDC_DUTY_RES LEDC_TIMER_13_BIT // Set duty resolution to 13 bits
// #define LEDC_FREQUENCY 5000 // Frequency in Hertz. Set frequency at 5 kHz

// void app_main() {
//     // Configure the LEDC timer
//     ledc_timer_config_t ledc_timer = {
//         .speed_mode = LEDC_MODE,
//         .duty_resolution = LEDC_DUTY_RES,
//         .timer_num = LEDC_TIMER,
//         .freq_hz = LEDC_FREQUENCY,
//         .clk_cfg = LEDC_AUTO_CLK
//     };
//     ledc_timer_config(&ledc_timer);

//     // Configure the LEDC channel
//     ledc_channel_config_t ledc_channel = {
//         .gpio_num = LEDC_OUTPUT_IO,
//         .speed_mode = LEDC_MODE,
//         .channel = LEDC_CHANNEL,
//         .intr_type = LEDC_INTR_FADE_END,
//         .timer_sel = LEDC_TIMER,
//         .duty = 0, // Set duty to 0%
//         .hpoint = 0
//     };
//     ledc_channel_config(&ledc_channel);

//     while (1) {
//         // Increase the brightness
//         for (int duty = 0; duty <= (1 << LEDC_DUTY_RES) - 1; duty += 256) {
//             ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, duty);
//             ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
//             vTaskDelay(30 / portTICK_PERIOD_MS);
//         }
//         // Decrease the brightness
//         for (int duty = (1 << LEDC_DUTY_RES) - 1; duty >= 0; duty -= 256) {
//             ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, duty);
//             ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
//             vTaskDelay(30 / portTICK_PERIOD_MS);
//         }
//     }
// }
// void setup() {
//   // put your setup code here, to run once:
// }

// void loop() {
//   app_main();
// }