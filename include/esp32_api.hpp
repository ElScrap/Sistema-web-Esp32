/* -------------------------------------------------------------------
 * Elaborado por: Leonardo Aguilar
 * Correo: leonardo-aguilar@hotmail.es
 * Plataforma ESP32-Web
 * Sistema Web para la gestion de dispositivos IoT y Moviles
 * V1.0.0-2024
 * -------------------------------------------------------------------
*/
#include "ESPAsyncWebServer.h"
// Instancia de AsyncWebServer puerto 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
AsyncEventSource events("/events");