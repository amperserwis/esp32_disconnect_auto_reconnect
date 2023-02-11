 #include <WiFi.h>

#define led1    26
#define led2    4
#define led3    27
#define led4    14


const char* ssid     = "OPPO F7 128GB";
const char* password = "12345678";

unsigned long previousMillis = 0;
unsigned long interval = 5000;

WiFiServer server(80);

void startwifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  server.begin();
}

void setup() {
  Serial.begin(115200);
  

  //initiate pinmode
  pinMode(led1,OUTPUT);
  pinMode(led3,OUTPUT);
  startwifi();
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  WiFiClient client = server.available();
  String bufflogic;
   
  unsigned long currentMillis = millis();
  
  delay(500);
  // if WiFi is down, try reconnecting every CHECK_WIFI_TIME seconds
  if ((WiFi.status() != 3) && (currentMillis - previousMillis >=interval)) {
    Serial.print(millis());
    Serial.println("Wifi disconnected.");
    if (bufflogic.indexOf("modeaa") !=1) {
          digitalWrite(led1,HIGH);
          digitalWrite(led3,LOW);
    }
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    Serial.println("");
    WiFi.begin(ssid, password);
      while (WiFi.status() != 3) {
      Serial.print('.');
      delay(1000);
  }
  Serial.println(WiFi.localIP());
    previousMillis = currentMillis;
    server.begin();
  }

  
 if (!client) {
    return;
  }
  Serial.println("New Client."); 
  while(!client.available()) {
    delay(1);
    return;
  }

  String request = client.readStringUntil('\r');
  Serial.print(request);
  bufflogic = request;
  client.println(bufflogic);

  if(request.indexOf("modeaa") != -1 ) {
    digitalWrite(led1,HIGH);
    digitalWrite(led3,HIGH);
  } 
  
  if(request.indexOf("modebb") != -1 ) {
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
  }

}
