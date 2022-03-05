/***************************************************
  This is an example for the HTU21D-F Humidity & Temp Sensor

  Designed specifically to work with the HTU21D-F sensor from Adafruit
  ----> https://www.adafruit.com/products/1899

  These displays use I2C to communicate, 2 pins are required to
  interface
 ****************************************************/

#include <Wire.h>

// <> librairie standard paramétrée d'après les chemins de librairie standard
// "" librairie présent dans le dossiers.
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_HTU21DF.h"
#include <Adafruit_I2CDevice.h>

#include "WiFiParameters.h"
#include "ESP8266WiFi.h"

// #include "WebAPI.h"


// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (A5 on UNO)
// Connect SDA to I2C data pin (A4 on UNO)

Adafruit_HTU21DF htu = Adafruit_HTU21DF();


void initWiFi() {
  Serial.println("connexion au WiFi");
  // Initialisation du WiFi en mode "STATION" 
  WiFi.mode(WIFI_STA);
  //Initialisation de la conextion
  WiFi.begin("nomduwifi", "motdepasse");
  while (!WiFi.isConnected()){
    delay(1000);
  }
  Serial.println("\nWifi connected!");
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

}

void setup() {
  Serial.begin(9600);
  Serial.println("HTU21D-F test encore un test");
  initWiFi();

  Wire.begin(2,0);
  if (!htu.begin()) {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
}
 
void loop() {
    float temp = htu.readTemperature();
    float rel_hum = htu.readHumidity();
    Serial.print("Temp: "); Serial.print(temp); Serial.print(" C");
    Serial.print("\t\t");
    Serial.print("Humidity: "); Serial.print(rel_hum); Serial.println(" \%");
    delay(500);
}
