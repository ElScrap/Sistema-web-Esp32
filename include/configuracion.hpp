// Definiciones
#define RELAY1 27
#define RELAY2 26
#define WIFILED 12
#define MQTTLED 13
// Version de Hardware
#define HW "ADMINESP32 v1"
// Zona WIFI
boolean wifi_staticIP;           // Uso de Ip Estatica
char wifi_ssid[30];              // Red Wifi
char wifi_passw[30];        // Contraseña WIFI
char wifi_ip_static[15];    // Ip Estatico
char wifi_gateway[15];      // Gateway
char wifi_subnet[15];       // Subred
char wifi_primaryDNS[15];   // DNS primario
char wifi_secondaryDNS[15]; // DNS secundario
// Zona Configuracion General
char id[30];   // ID del dispositivo
int bootCount; // Numero de reinicios
// Zona AP"Acces Point"
boolean ap_accesPoint;
char ap_nameap[31];
char ap_passw[63];
int ap_canal;
int ap_hidden;
int ap_connet;
// Zona MQTT
boolean mqtt_enable;                // Habilitar MQTT Broker
char    mqtt_user[30];              // Usuario MQTT Broker 
char    mqtt_id[30];                // ID MQTT Broker       
char    mqtt_passw[30];             // Password MQTT Broker 
char    mqtt_server[39];            // Servidor del MQTT Broker
int     mqtt_port;                  // Puerto servidor MQTT Broker
int     mqtt_time;                  // Tiempo de envio por MQTT
// Zona Otros
uint8_t ip[4];
float   temp_cpu;                   // Temperatura del CPU en °C
// Zona Reles
bool Relay01_status, Relay02_status; // Estados de los reles de salida