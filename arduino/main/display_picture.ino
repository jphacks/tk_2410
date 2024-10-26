#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "sdkconfig.h"
#include "driver/ledc.h"
#include "esp_err.h"

/*********************************************************************************************************
*
* File                : Arduino-epd
* Hardware Environment: 
* Build Environment   : Arduino
* Version             : V1.6.1
* By                  : WaveShare
*
*                                  (c) Copyright 2005-2015, WaveShare
*                                       http://www.waveshare.net
*                                       http://www.waveshare.com
*                                          All Rights Reserved
*
*********************************************************************************************************/
#include <epd.h>



const int led = 13;                           //user led


/*******************************************************************************
* Function Name  : void base_draw(void)
* Description    :
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void base_draw(void)
{
  int i, j;

  /*
  draw pixel
  */
  epd_clear();
  for (j = 0; j < 600; j += 50)
  {
    for (i = 0; i < 800; i += 50)
    {
      epd_draw_pixel(i, j);
      epd_draw_pixel(i, j + 1);
      epd_draw_pixel(i + 1, j);
      epd_draw_pixel(i + 1, j + 1);
    }
  }
  epd_udpate();
  delay(3000);

  /*
  draw line
  */
  epd_clear();
  for (i = 0; i < 800; i += 100)
  {
    epd_draw_line(0, 0, i, 599);
    epd_draw_line(799, 0, i, 599);
  }
  epd_udpate();
  delay(3000);

  /*
  fill rect
  */
  epd_clear();
  epd_set_color(BLACK, WHITE);
  epd_fill_rect(10, 10, 100, 100);

  epd_set_color(DARK_GRAY, WHITE);
  epd_fill_rect(110, 10, 200, 100);

  epd_set_color(GRAY, WHITE);
  epd_fill_rect(210, 10, 300, 100);

  epd_udpate();
  delay(3000);

  /*
  draw circle
  */
  epd_set_color(BLACK, WHITE);
  epd_clear();
  for (i = 0; i < 300; i += 40)
  {
    epd_draw_circle(399, 299, i);
  }
  epd_udpate();
  delay(3000);




}

void draw_setup(void)
{
  /*
  user led init
  */
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  
  epd_init();
  epd_wakeup();
  epd_set_memory(MEM_NAND);
}

void display_picture(void)
{
  // char flag = 0;
  
  base_draw();
}
