void ConfigResetWIFI(){
      /* ------------------- GENERAL -------------------- */
    strlcpy(id, "sistemaweb", sizeof(id));
    bootCount = 0;
    /* ------------------- CLIENTE -------------------- */
    wifi_staticIP = false;
    strlcpy(wifi_ssid, "Familia-Aguilar", sizeof(wifi_ssid));
    strlcpy(wifi_passw, "0706965621S", sizeof(wifi_passw));
    strlcpy(wifi_ip_static, "192.168.0.102", sizeof(wifi_ip_static));
    strlcpy(wifi_gateway, "192.168.0.1", sizeof(wifi_gateway));
    strlcpy(wifi_subnet, "255.255.255.0", sizeof(wifi_subnet));
    strlcpy(wifi_primaryDNS, "8.8.8.8", sizeof(wifi_primaryDNS));
    strlcpy(wifi_secondaryDNS, "8.8.4.4", sizeof(wifi_secondaryDNS));
    /* ------------------- ACCESS POINT ------------------------- */
    ap_accesPoint = true;
    strlcpy(ap_nameap, deviceID().c_str(), sizeof(ap_nameap));
    strlcpy(ap_passw, "adminesp32", sizeof(ap_passw));
    ap_canal = 9;         
    ap_hidden = false;        
    ap_connet = 4;
}
