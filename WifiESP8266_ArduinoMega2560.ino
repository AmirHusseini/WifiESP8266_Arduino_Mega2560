// TX from esp8266 to RX1 pin 19 on Arduino Mega 
// Rx from esp8266 to TX1 pin 18 on Arduino Mega 
// 3.3v from esp8266 to pin 3.3v on Arduino Mega 
// GND from esp8266 to pin GND on Arduino Mega 

// Include SoftwareSerial and Wifi library
#include "WiFiEsp.h"

// Declare and initialise global arrays for WiFi settings, put your wifi and pass inside ""!
char ssid[] = "";
char pass[] = "";

// Declare and initialise variable for radio status 
int status = WL_IDLE_STATUS;

void setup() {
  
  // Initialize serial for debugging
  Serial.begin(115200);
  
  // Initialize serial for ESP module
  Serial1.begin(9600);
  
  // Initialize ESP module
  WiFi.init(&Serial1);

  // Check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    
    // Don't continue
    while (true);
  }
  
  // Attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }

  Serial.println("You're connected to the network");
  printWifiStatus();
}

void loop() {

}


void printWifiStatus() {
  
  // Print the SSID of the network
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // Print the IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
