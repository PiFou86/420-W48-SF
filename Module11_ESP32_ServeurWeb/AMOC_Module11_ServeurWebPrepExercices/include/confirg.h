#define MONSERVEURINTERNET false 
#define SERVEURVEBIOT true

// reseau domestique
#if MONSERVEURINTERNET
    #define WIFI_SSID "Celui de votre domicile"
    #define WIFI_PASSWORD "et son mot de passe"

// reseau cegep
#elif SERVEURVEBIOT_1
    #define WIFI_SSID "iot"
    #define WIFI_PASSWORD "engagelejeuquejelegagne"

// Ponnt d'acces ESP32PERSONNEL
else 
    #define WIFI_SSID       "EspNoMATRICULE"
    #define WIFI_PASSWORD   "reseau12345678"
#endif
