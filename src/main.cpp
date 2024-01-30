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
#include "esp32_mqtt.hpp"
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
  configuracionReadRelays();//leer los estados de los relays
  ledEncendidoApagado(RELAY1,Relay01_status);//Paso estados a los pines de rele
  ledEncendidoApagado(RELAY2,Relay02_status);//Paso estados a los pines de rele
  configuracionReadWIFI();//leer configuracion wifi
  WiFi.disconnect(true);//configuracion wifi
  delay(1000);
  wifi_setup();//setup del wifi
  //lee la configuracion mqtt
  settingsReadMQTT();
}
// Loop Pincipal Nucleo 0
void loop() {

    yield();
    // WIFI para que lea el modo
    if (wifi_mode == WIFI_STA){
        wifiLoop();
    }else if (wifi_mode == WIFI_AP){
        wifiAPLoop();
    }
    // MQTT para que lea el modo
    if ((WiFi.status() == WL_CONNECTED) && (wifi_mode == WIFI_STA)){
        if(mqtt_server != 0){
            mqttLoop();
            if (mqttclient.connected()){
                if (millis() - lastMsg > mqtt_time){
                    lastMsg = millis();
                    mqtt_publish();
                }
            }      
        }
    }

}