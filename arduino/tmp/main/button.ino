#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "sdkconfig.h"
#include "driver/ledc.h"
#include "esp_err.h"

// ボタンのピン番号
#define BUTTON_GPIO 19
#define BUTTON_OUTPUT_GPIO (gpio_num_t)BUTTON_GPIO

void add_favorite() {
    // お気に入りの処理
    Serial.println("Add favorite");
    epd_disp_string("Add favorite", 0, 0);
    
}

void reset() {
    // リセット処理
    Serial.println("Reset");
    epd_disp_string("Reset", 0, 0);
}

void    pressed_button_hook() {
    int count = 0;
    while (gpio_get_level(BUTTON_OUTPUT_GPIO) == 1) {
        count++;
        vTaskDelay(100 / portTICK_PERIOD_MS);
        if (count >= 20) {
            reset();
            break;
        }
    }
    if (5 <= count && count < 20) {
        add_favorite();
    }
}
