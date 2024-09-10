#include <beacon_defs.hpp>
#include <WiFi.h>       // standard library
#include <WebServer.h>  // standard library
#include "SuperMon.h"   // .h file that stores your html page code
#include <LittleFS.h>

// here you post web pages to your homes intranet which will make page debugging easier
// as you just need to refresh the browser as opposed to reconnection to the web server
SoftwareSerial mySerial(16, 17);
PortHandle hport(mySerial);


// once  you are read to go live these settings are what you client will connect to
#define AP_SSID "TestWebSite"
#define AP_PASS "023456789"
// Definitions and constants

uint8_t flag = 0;
String id;
String receivedMessage;

String sifonValue;
String pisuvarValue;
String sabunlukValue;
String zPeceteValue;
String ruloValue;


uint8_t sifonInt;
uint8_t pisuvarInt;
uint8_t sabunlukInt;
uint8_t zPeceteInt;
uint8_t ruloInt;

String message;



// the XML array size needs to be bigger that your maximum expected size. 2048 is way too big for this example
char XML[2048];

// just some buffer holder for char operations
char buf[32];



// definitions of your desired intranet created by the ESP32
// Set your Static IP address
IPAddress local_ip(192, 168, 4, 1);
// Set your Gateway IP address
IPAddress gateway(192, 168, 4, 1);
// Set your Subnet Mask
IPAddress subnet(255, 255, 255, 0);


// gotta create a server
WebServer server(80);

void setup() {

  // standard stuff here
  

  if (!LittleFS.begin()) {
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }

  disableCore0WDT();



  Serial.println("starting server");




#ifndef USE_INTRANET
  WiFi.softAP(AP_SSID, AP_PASS);
  // Set Static IP
  if (!WiFi.softAPConfig(local_ip, gateway, subnet)) {
      Serial.println("AP Config Failed");
  } else {
      Serial.println("AP Config Success");
  }
#endif
  Serial.println();
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());




  server.on("/", SendWebsite);
  

  server.on("/xml", SendXML);

  server.on("/logo", HTTP_GET, []() {
    File file = LittleFS.open("/logo.png", "r");  
    if (!file) {
      server.send(404, "text/plain", "File Not Found");
      return;
    }

    server.streamFile(file, "image/png");  
    file.close();
  });
  server.on("/back.jpg", HTTP_GET, []() {
    File file = LittleFS.open("/back.jpg", "r");  
    if (!file) {
      server.send(404, "text/plain", "File Not Found");
      return;
    }

    server.streamFile(file, "image/jpg");  
    file.close();
  });


  server.on("/veri.json", HTTP_GET, []() {
    File file = LittleFS.open("/veri.json", "r");  
    if (!file) {
      server.send(404, "text/plain", "File Not Found");
      return;
    }
    server.streamFile(file, "application/json");  
    file.close();
  });
  server.on("/BUTTON", p2pListen);
  server.on("/BUTTON_STOP", stop);
  server.begin();

}

void loop() {
  if(flag){
    receivedMessage = hport.listenRes();
    
    if(receivedMessage.indexOf(id) != -1){
      receivedMessage = receivedMessage.substring(receivedMessage.indexOf(id)+id.length());
      if(receivedMessage.length() == 10){
        decoder(receivedMessage);
        Serial.println("Received message: " + receivedMessage);
      }
      else {
        message="";
      }

    }
    
    
  }
 
  server.handleClient();

}



void SendWebsite() {
 
  if(flag){
    lora();
    p2p();
  }
  flag = 0;

  Serial.println("sending web page");
 
  server.send(200, "text/html", PAGE_MAIN);

}


void SendXML() {

  

  strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");
  if(flag && message != ""){
    sprintf(buf, "<id>%s</id>",message.c_str());
    strcat(XML,buf);
  }
  strcat(XML, "</Data>\n");
  
  server.send(200, "text/xml", XML);


}

void p2p() {  
 
  String B = hport.portSend("AT+NWM=0");
  
  while (B.indexOf("OK") == -1) {

    B = hport.portSend("AT+NWM=0");
    
  }
  
  

}
void lora(){
  
  String B = hport.portSend(String("AT+NWM=1"));
  
  while (B.indexOf("OK") == -1) {

    B = hport.portSend("AT+NWM=1");
    
  }
  
  
  
}
void p2pListen() {  
  
  lora();
  p2p();
  String config = server.arg("config");
  
  String B = hport.portSend("AT+P2P=" + String(config));
  
  while (B.indexOf("OK") == -1) {
    
    B = hport.portSend("AT+P2P=" + String(config));
  }

  String precv = server.arg("precv");
  
  String checkReturn = hport.portSend("AT+PRECV="+String(precv));
  delay(100);
  
  while(checkReturn.indexOf("OK") == -1){
    checkReturn = hport.portSend("AT+PRECV="+String(precv));
   
  }
  Serial.println("P2P Listen has opened.");

  
  id = server.arg("id");
  sifonValue = server.arg("sifon");
  pisuvarValue = server.arg("pisuvar");
  sabunlukValue = server.arg("sabunluk");
  zPeceteValue = server.arg("zPecete");
  ruloValue = server.arg("rulo");
  sifonInt = sifonValue.toInt();
  pisuvarInt = pisuvarValue.toInt();
  sabunlukInt = sabunlukValue.toInt();
  zPeceteInt = zPeceteValue.toInt();
  ruloInt = ruloValue.toInt();
  

  flag = 1;

  server.send(200, "text/xml", XML);
}
void stop(){
  flag = server.arg("stop").toInt();
  
  message="";
  server.send(200, "text/xml", XML);
}
void decoder(String msg) {
 
  int controlValue = msg.substring(2, 4).toInt();
  if (msg.substring(0, 2) == "41" && msg.substring(4, 6) == "41" && controlValue>=31 && controlValue<31+sabunlukInt) {

    message = String(msg.substring(0, 2))+String(msg.substring(2, 4)) +String(msg.substring(6, 10));

  }

  if (msg.substring(0, 2) == "42" && msg.substring(4, 6) == "42" && controlValue>=31 && controlValue<31+ zPeceteInt) {
    

    message = String(msg.substring(0, 2))+String(msg.substring(2, 4)) +String(msg.substring(6, 10));
    
  }

  if (msg.substring(0, 2) == "43" && msg.substring(4, 6) == "43" && controlValue>=31 && controlValue<31+ ruloInt) {
    
      
    message = String(msg.substring(0, 2))+String(msg.substring(2, 4)) +String(msg.substring(6, 10));
      
  }

  if (msg.substring(0, 2) == "44" && msg.substring(4, 6) == "44" && controlValue>=31 && controlValue<31+ pisuvarInt) {
    
    message = String(msg.substring(0, 2))+String(msg.substring(2, 4)) +String(msg.substring(6, 10));
      
  }

  if (msg.substring(0, 2) == "45" && msg.substring(4, 6) == "45" && controlValue>=31 && controlValue<31+ sifonInt) {
    
    message = String(msg.substring(0, 2))+String(msg.substring(2, 4)) +String(msg.substring(6, 10));
  
  }
}

