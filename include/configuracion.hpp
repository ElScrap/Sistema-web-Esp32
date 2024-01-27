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
//Zona Otros
uint8_t ip[4];