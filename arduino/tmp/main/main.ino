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

#include <WiFi.h>
// const char* ssid = "bId2-guest";               //  アクセスポイントのSSID
// const char* pass = "MatsumotoWay";     
#define  SSID "bld2-guest"
#define  PASS "MatsumotoWay"    
//const char* password = "rk2docix";     


const int led_wifi = 33;                          //  定数ledを33と定義
const int led_wifi2 = 32;                          //  定数ledを33と定義

void setup() {                               //  以下最初に行われる処理
  pinMode(led_wifi, OUTPUT);                      //  ledの指すGPIO(33番)を出力ピンに設定
  pinMode(led_wifi2, OUTPUT);                      //  ledの指すGPIO(33番)を出力ピンに設定
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);                      //  PCとのシリアル通信を開始
  WiFi.begin(SSID, PASS);                //  アクセスポイントに接続
  while (WiFi.status() != WL_CONNECTED) {
  if (WiFi.status() == WL_NO_SSID_AVAIL) {
    digitalWrite(led_wifi2, HIGH);                   //  ledをHIGHに設定
    delay(500);                              //  接続完了するまでwhileで無限ループして待つ
    digitalWrite(led_wifi2, LOW);                    //  ledをLOWに設定
  } else {
    digitalWrite(led_wifi2, HIGH);                   //  ledをHIGHに設定
    digitalWrite(led_wifi, HIGH);                   //  ledをHIGHに設定
    delay(500);                              //  接続完了するまでwhileで無限ループして待つ
    digitalWrite(led_wifi2, LOW);                    //  ledをLOWに設定
    digitalWrite(led_wifi, LOW);                    //  ledをLOWに設定
  }
    Serial.println("retry");
    WiFi.disconnect();
    WiFi.reconnect();
  }
  // 終わったら20秒
      digitalWrite(led_wifi, HIGH);                   //  ledをHIGHに設定
      delay(20000);                                //  200ミリ秒待つ
      digitalWrite(led_wifi, LOW);                    //  ledをLOWに設定
}
                                             //  以下ループ処理(何もしない)
void loop() {
}


// // 以下コメントアウト
// void app_main() {
//     while (1) {
//         // pressed_button_hook();
//         // open_close_hook();
//         // display_picture();
//     }
// }

// // // WiFi
// // static void wifi_event_handler(void *event_handler_arg, esp_event_base_t event_base, int32_t event_id, void *event_data)
// // {
// //     switch (event_id)
// //     {
// //     case WIFI_EVENT_STA_START:
// //         Serial.println("WiFi connecting ... \n");
// //         break;
// //     case WIFI_EVENT_STA_CONNECTED:
// //         Serial.println("WiFi connected ... \n");
// //         break;
// //     case WIFI_EVENT_STA_DISCONNECTED:
// //         Serial.println("WiFi lost connection ... \n");
// //         break;
// //     case IP_EVENT_STA_GOT_IP:
// //         Serial.println("WiFi got IP ... \n\n");
// //         break;
// //     default:
// //         break;
// //     }
// // }

// // void wifi_connection()
// // {
// //     // 1 - Wi-Fi/LwIP Init Phase
// //     esp_netif_init();                    // TCP/IP initiation                     s1.1
// //     esp_event_loop_create_default();     // event loop                             s1.2
// //     esp_netif_create_default_wifi_sta(); // WiFi station                         s1.3
// //     wifi_init_config_t wifi_initiation = WIFI_INIT_CONFIG_DEFAULT();
// //     esp_wifi_init(&wifi_initiation); //                                         s1.4
// //     // 2 - Wi-Fi Configuration Phase
// //     esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, wifi_event_handler, NULL);
// //     esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, wifi_event_handler, NULL);
// //     wifi_config_t wifi_configuration = {
// //         .sta = {
// //             .ssid = SSID,
// //             .password = PASS}};
// //     esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_configuration);
// //     // 3 - Wi-Fi Start Phase
// //     esp_wifi_start();
// //     // 4- Wi-Fi Connect Phase
// //     esp_wifi_connect();
// // }

// void setup() {
//   bool bl = true;
//   // Serial.begin(11520);
//   draw_setup();
//   base_draw();

//   Serial.begin(115200);                      //  PCとのシリアル通信を開始(WiFiとは関係なし)
// //   WiFi.begin(ssid, pass);                //  アクセスポイントに接続
// //   while (WiFi.status() != WL_CONNECTED) {
// //     // if (bl == true){
// //     //   circle_draw();
// //     //   bl = false;
// //     // } else {
// //     //   line_draw();
// //     //   bl = true;
// //     // }
// //     delay(5000);                              //  接続完了するまでwhileで無限ループして待つ
// //   }

//     // wifi_connection();
//   base_draw();
//   // Serial.println("Connected");         

//   // TIMSK0 = 0;

// }

// void loop() {
//   // Serial.println("loop");
//   app_main();
  
// }

// // #include <stdio.h>
// // #include "freertos/FreeRTOS.h"
// // #include "freertos/task.h"
// // #include "driver/gpio.h"
// // #include "rom/gpio.h"
// // #include "sdkconfig.h"
// // #include "driver/ledc.h"
// // #include "esp_err.h"

// // #define BLINK_GPIO 23
// // #define LEDC_CHANNEL LEDC_CHANNEL_0
// // #define LEDC_TIMER LEDC_TIMER_0
// // #define LEDC_MODE LEDC_HIGH_SPEED_MODE
// // #define LEDC_OUTPUT_IO (gpio_num_t)BLINK_GPIO
// // #define LEDC_DUTY_RES LEDC_TIMER_13_BIT // Set duty resolution to 13 bits
// // #define LEDC_FREQUENCY 5000 // Frequency in Hertz. Set frequency at 5 kHz

// // void app_main() {
// //     // Configure the LEDC timer
// //     ledc_timer_config_t ledc_timer = {
// //         .speed_mode = LEDC_MODE,
// //         .duty_resolution = LEDC_DUTY_RES,
// //         .timer_num = LEDC_TIMER,
// //         .freq_hz = LEDC_FREQUENCY,
// //         .clk_cfg = LEDC_AUTO_CLK
// //     };
// //     ledc_timer_config(&ledc_timer);

// //     // Configure the LEDC channel
// //     ledc_channel_config_t ledc_channel = {
// //         .gpio_num = LEDC_OUTPUT_IO,
// //         .speed_mode = LEDC_MODE,
// //         .channel = LEDC_CHANNEL,
// //         .intr_type = LEDC_INTR_FADE_END,
// //         .timer_sel = LEDC_TIMER,
// //         .duty = 0, // Set duty to 0%
// //         .hpoint = 0
// //     };
// //     ledc_channel_config(&ledc_channel);

// //     while (1) {
// //         // Increase the brightness
// //         for (int duty = 0; duty <= (1 << LEDC_DUTY_RES) - 1; duty += 256) {
// //             ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, duty);
// //             ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
// //             vTaskDelay(30 / portTICK_PERIOD_MS);
// //         }
// //         // Decrease the brightness
// //         for (int duty = (1 << LEDC_DUTY_RES) - 1; duty >= 0; duty -= 256) {
// //             ledc_set_duty(LEDC_MODE, LEDC_CHANNEL, duty);
// //             ledc_update_duty(LEDC_MODE, LEDC_CHANNEL);
// //             vTaskDelay(30 / portTICK_PERIOD_MS);
// //         }
// //     }
// // }
// // void setup() {
// //   // put your setup code here, to run once:
// // }

// // void loop() {
// //   app_main();
// // }