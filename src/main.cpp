//libreria
#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>
// Archivos *hpp - Fragmentar el Codigo
#include "configuracion.hpp"
#include "functions.hpp"
#include "configuracionReset.hpp"
#include "configuracionRead.hpp"
#include "configuracionSave.hpp"
#include "esp32_wifi.hpp"
//Setup
void setup() {
  Serial.begin(115200);//velocidad
  setCpuFrequencyMhz(240);//frecuencia de CPU
  log("\nInfo: Iniciando Setup");//inicio del log por serial
  configPines();//configurar los pines
  if (!SPIFFS.begin(true))//chequeo incio de SPIFFS
  {
    log(F("Error: Falló la inicialización del SPIFFS"));
    while(true);
  }
  configuracionReadWIFI();//leer configuracion wifi
  WiFi.disconnect(true);//configuracion wifi
  delay(1000);
  wifi_setup();//setup del wifi
}
void loop() {// Loop Pincipal Nucleo 0

    yield();
    // WIFI para que 
    if (wifi_mode == WIFI_STA){
        wifiLoop();
    }else if (wifi_mode == WIFI_AP){
        wifiAPLoop();
    } 
}