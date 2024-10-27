#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "sdkconfig.h"
#include "driver/ledc.h"
#include "esp_err.h"

#include "epd.h"

#define BUTTON_GPIO 19
#define BUTTON_OUTPUT_GPIO (gpio_num_t)BUTTON_GPIO
#define OPEN_CLOSE_GPIO 35
#define OPEN_OUTPUT_GPIO (gpio_num_t)OPEN_CLOSE_GPIO

void app_main() {
  while (1) {
    pressed_button_hook();
    open_close_hook();
  }
}

void setup() {
  draw_setup();
  Serial.begin(115200);
  pinMode(BUTTON_GPIO, INPUT_PULLUP);
  pinMode(OPEN_CLOSE_GPIO, OUTPUT);
}

void loop() {
  app_main();
  
}
