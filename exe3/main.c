#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_V = 28;
const int LED_PIN_V = 4;
const int BTN_PIN_G = 26;
const int LED_PIN_G = 6;


int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_V);
  gpio_set_dir(BTN_PIN_V, GPIO_IN);
  gpio_pull_up(BTN_PIN_V);

  gpio_init(LED_PIN_V);
  gpio_set_dir(LED_PIN_V, GPIO_OUT);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_PIN_V)) {
      int status = gpio_get(LED_PIN_V);
      if (status == 0) {
        gpio_put(LED_PIN_V, 1);
      }
      if (status == 1) {
        gpio_put(LED_PIN_V, 0);
      }
      while (!gpio_get(BTN_PIN_V)) {
      };
    }
    if (!gpio_get(BTN_PIN_G)) {
      int status = gpio_get(LED_PIN_G);
      if (status == 0) {
        gpio_put(LED_PIN_G, 1);
      }
      if (status == 1) {
        gpio_put(LED_PIN_G, 0);
      }
      while (!gpio_get(BTN_PIN_G)) {
      };
    }



  }
}
