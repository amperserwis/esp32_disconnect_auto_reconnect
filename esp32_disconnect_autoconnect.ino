 #include <WiFi.h>

#define led1    26
#define led2    27



const char* ssid     = "Ur network";
const char* password = "pass network";

unsigned long previousMillis = 0;
unsigned long interval = 5000;

String bufflogic;

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
  pinMode(led2,OUTPUT);
  startwifi();
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI());
}

void loop() {
  WiFiClient client = server.available();
  Serial.println(bufflogic);
  delay(1000);
  
   
  unsigned long currentMillis = millis();
  
  delay(500);
  // if WiFi is down, try reconnecting every CHECK_WIFI_TIME seconds
  if ((WiFi.status() != 3) && (currentMillis - previousMillis >=interval)) {
    Serial.print(millis());
    Serial.println("Wifi disconnected.");
    if (bufflogic.indexOf("modeaa") !=-1) {
          digitalWrite(led1,HIGH);
          digitalWrite(led2,LOW);
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
  client.println(request);
  
  if(request.indexOf("modeaa") != -1 ) {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    bufflogic = "modeaa";
    Serial.println(bufflogic);
  } 
  
  if(request.indexOf("modebb") != -1 ) {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    bufflogic = "modebb";
  }


}
