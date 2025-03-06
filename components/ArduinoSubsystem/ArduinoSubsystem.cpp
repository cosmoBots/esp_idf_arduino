// C standard headers
// C++ standard headers

// ESP-IDF headers
#include <esp_log.h>

// ESP-IDF config header
#include <sdkconfig.h>

// Arduino.h header
#include <Arduino.h>

// Other modules / libraries includes

// Self-include
#include "ArduinoSubsystem.h"

const char TAG[] = "Arduino";

void setup(){
  log_i("setup");
  Serial.begin(115200);
  while(!Serial){
    ; // wait for serial port to connect
  }
  log_i("setup end");
}

// Loop will be executed every at CONFIG_ARDUINO_LOOP_HZ rate

void loop(){
  log_i("loop");
}

static TaskHandle_t arduino_task;

void arduino_main(void *pvParameter)
{
  ESP_LOGD(TAG, "Launching Arduino Loop");

  TickType_t xLastWakeTime = xTaskGetTickCount();
  const TickType_t xPeriodInTicks = (configTICK_RATE_HZ / CONFIG_ARDUINO_LOOP_HZ);

  while (true)
  {
    loop();
    // Wait 1/CONFIG_ARDUINO_LOOP_HZ before launching loop
    if (xTaskDelayUntil(&xLastWakeTime, xPeriodInTicks) != pdTRUE)
    {
        ESP_LOGW(TAG, "Real time issue!");
    }
  }

  vTaskDelete(NULL);
}

EXTERNC void ArduinoSubsystem_start(void)
{
  ESP_LOGD(TAG, "Launching Arduino");
  initArduino();
  ESP_LOGD(TAG, "Launching Arduino Setup");
  setup();
  ESP_LOGI(TAG, "ArduinoSubsystem_start launches arduino_main task");
  xTaskCreatePinnedToCore(&arduino_main, "arduino_main", CONFIG_ARDUINO_LOOP_STACK_SIZE, NULL, 5,  &arduino_task, CONFIG_ARDUINO_RUNNING_CORE);
}
