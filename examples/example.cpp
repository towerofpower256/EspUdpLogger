#ifdef ESP32
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

#include <EspLogUdp.h>

const char* ssid = "Your_WiFi_Name";
const char* password = "password";

const char* logPrefix = "[MyLog] ";
EspLogUdp logger;

void setup() {
  Serial.begin(115200);

  // Setup the logger
  //logger.init(IPAddress(192, 168, 29, 1), 8888); // logger.init(ip_address, port)
  logger.setPrefix(logPrefix);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(500);
    Serial.print('.');
  }
  Serial.println("Wifi connected "); Serial.println(WiFi.localIP());


  logger.send("Starting");
}

void loop() {
  // Send a quick message
  logger.send("Running");

  // > [MyLog] Running

  // Build and send a larger message
  logger.start();
  logger.print("Running for ");
  logger.print(millis());
  logger.print(" millis");
  logger.end();

  // > [MyLog] Running for 1234 millis

  // Wait, and then do it again
  delay(1000);
}