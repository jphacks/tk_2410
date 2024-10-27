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

void app_main() {
  while (1) {
    pressed_button_hook();
    open_close_hook();
    display_picture();
  }
}

void setup() {
  draw_setup();

  Serial.begin(115200);
}

void loop() {
  app_main();
  
}
