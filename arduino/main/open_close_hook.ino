#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "sdkconfig.h"
#include "driver/ledc.h"
#include "esp_err.h"

#define OPEN_CLOSE_GPIO 35
#define OPEN_OUTPUT_GPIO (gpio_num_t)OPEN_CLOSE_GPIO

static bool open_close_action(bool input)
{
    static bool open = false;
    if (input == true && open == false) {
        open = true;
        return true;
    } else if (input == false && open == true) {
        open = false;
        return true;
    }
    return false;
}

void open_close_hook() {
    // 開く検知をしたら
    if (gpio_get_level(OPEN_OUTPUT_GPIO) == 1) {
        if (open_close_action(true)) {
            epd_clear();
            epd_set_color(BLACK, WHITE);
            epd_disp_string("Open", 0, 0);
            delay(3000);
            epd_clear();
        }
    } else {
        if (open_close_action(false)) {
            epd_set_color(BLACK, WHITE);
            epd_disp_string("Close", 0, 0);
            delay(3000);
            epd_clear();
        }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
}