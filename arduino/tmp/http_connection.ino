#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "sdkconfig.h"
#include "driver/ledc.h"
#include "esp_err.h"
#include "esp_http_client.h"

#define SERVER_URL "https//example.com"

void	http(void)
{

	char	buff[101];
	esp_http_client_config_t config_post = {
        .url = SERVER_URL
        // .method = HTTP_METHOD_POST,
        // .event_handler = client_event_get_handler,
        // .auth_type = HTTP_AUTH_TYPE_NONE,
        // .transport_type = HTTP_TRANSPORT_OVER_TCP
    };

    esp_http_client_handle_t client = esp_http_client_init(&config_post);
    
    // esp_http_client_set_post_field(client, payload, len);
    // esp_http_client_set_header(client, "Content-Type", "image/jpeg");

    // esp_http_client_perform(client);
	tesp_http_client_read(client, buff, 100);
	Serial.println(buff);
    esp_http_client_cleanup(client);

}

// #include <WiFi.h>
// const char* ssid = "aipon";               //  アクセスポイントのSSID
// const char* password = "rk2docix";        //  アクセスポイントのパスワード
//                                              //  以下最初に行われる処理
// void setup() {
//   Serial.begin(115200);                      //  PCとのシリアル通信を開始(WiFiとは関係なし)
//   WiFi.begin(ssid, password);                //  アクセスポイントに接続
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);                              //  接続完了するまでwhileで無限ループして待つ
//   }
//   Serial.println("Connected");               //  シリアルモニタに"Connected"を表示(WiFiとは関係なし)
// }
//                                              //  以下ループ処理(何もしない)
// void loop(){
// }
