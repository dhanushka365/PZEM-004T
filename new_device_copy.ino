//http://localhost/PZEM-004T/pzem.php
#include <Arduino.h>
#include <PZEM004Tv30.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <U8x8lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, /* clock=*/ 14, /* data=*/ 13, /* CS=*/ 15);
char Val1 [5];
char Val2 [5];
char Val3 [5];
char Val4 [5];
char Val5 [5];
char Val6 [5];
char Val7 [5];
char Val8 [5];

static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;

int Led_OnBoard = 2;     
ESP8266WiFiMulti WiFiMulti;
String str;
const char* ssid     ="HUAWEI Y5 2019";
const char* password = "0123456789";

// const char *host = "us-cdbr-east-06.cleardb.net"; 
const char *host = "192.168.43.101"; 
PZEM004Tv30 pzem(D1, D2); // (RX,TX)connect to TX,RX of PZEM
//PZEM004Tv30 pzem2(D5, D6);  // (RX,TX) connect to TX,RX of PZEM
//PZEM004Tv30 pzem3(D7, D8);  // (RX,TX) connect to TX,RX of PZEM
float t_unit,t_KW=0;

void setup() {
  u8g2.begin();
  u8g2.enableUTF8Print();
  u8g2.setFont(u8g2_font_helvB10_tf); 
  u8g2.setColorIndex(1);
  // Print a message to the LCD.
  
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
    delay(250);
  }
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.println("Connected to Network/SSID");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
}

void loop() {
   HTTPClient http; 
   WiFiClient client;
  // wait for WiFi connection
  //main energy meter
   float voltage = pzem.voltage();
   float current = pzem.current();
   float power = pzem.power();
   float energy = pzem.energy();
   float frequency = pzem.frequency();
   float pf = pzem.pf();
   t_KW=t_KW+energy;
   t_unit=t_KW;
   
   String ValueSend1,ValueSend2,ValueSend3,ValueSend4,ValueSend5,ValueSend6,ValueSend7,postData;
   ValueSend1 = String(voltage);  
   ValueSend2= String(current);
   ValueSend3= String(power);
   ValueSend4= String(energy);
   ValueSend5= String(frequency);
   ValueSend6= String(pf);
   ValueSend7= String(t_unit);
   //postData = "flowrate="+ValueSend3;
    postData = "&voltage="+ValueSend1+ "&current="+ValueSend2+ "&power="+ValueSend3+ "&energy="+ValueSend4+ "&frequency="+ValueSend5+ "&pf="+ValueSend6;
   
  // http.begin("http://192.168.8.170/da/InsertDB.php");   
    //http.begin("http://192.168.8.170/da/InsertDB.php");   
  Serial.print("connecting to ");
  Serial.println(host);
/*
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  
  String url = "con/insert.php?voltage =" + ValueSend1 + "&current="+ ValueSend2 + "&power="+ ValueSend3 + "&energy="+ ValueSend4 + "&frequency="+ ValueSend5+ "&pf="+ ValueSend6;
 // String url = "con/insert.php?voltage =" + ValueSend1 + "&current="+ ValueSend2 ;
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(500);
  
   while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
 // Serial.println("closing connection");
  delay(1000);


 */ 


 // HTTPClient http;    //Declare object of class HTTPClient
//   http.begin("http://192.168.8.170/pasa/InsertDB.php");   

  //http.begin(client,"http://ceb-selfcare.000webhostapp.com/con/insert.php");
  //https://eleccare.000webhostapp.com/con/pzem.php
  // http.begin(client,"http://eleccare.000webhostapp.com/con/pzem.php");
  // http://localhost/PZEM-004T/pzem.php
  http.begin(client,"http://192.168.43.101/PZEM-004T/pzem.php");
  http.addHeader("Content-Type", "application/x-www-form-urlencoded"); 
   
   int httpCode = http.POST(postData);   //Send the request
   String payload = http.getString();    //Get the response payload

  //Serial.println("LDR Value=" + ldrvalue);
  Serial.println(httpCode);   //Print HTTP return code
  Serial.println(payload);    //Print request response payload




  u8g2.firstPage();
  do {   
    draw();
    // delay(2000);
   
  } while( u8g2.nextPage() );

  delay(2000);
  
    u8g2.firstPage();  
    do {
    } while( u8g2.nextPage() );

  u8g2.firstPage();  
  do {
     draw1();
  } while( u8g2.nextPage() );
    delay(2000);
   
    u8g2.firstPage();  
    do {
    } while( u8g2.nextPage() );

  u8g2.firstPage();  
  do {
     draw2();
  } while( u8g2.nextPage() );
  delay(3000);

    u8g2.firstPage();  
    do {
      draw3();
    } while( u8g2.nextPage() );

  // rebuild the picture after some delay
  delay(500);
    if( !isnan(voltage) ){
        Serial.print("Voltage: "); Serial.print(voltage); Serial.println("V");
        
      
    } else {
        Serial.println("Error reading voltage");
       
    }

 
    if( !isnan(current) ){
        Serial.print("Current: "); Serial.print(current); Serial.println("A");
         
    } else {
        Serial.println("Error reading current");
     
    }

    if( !isnan(power) ){
        Serial.print("Power: "); Serial.print(power); Serial.println("W");
        
    } else {
        Serial.println("Error reading power");
        
    }

    if( !isnan(energy) ){
       Serial.print("Energy: "); Serial.print(energy,3); Serial.println("kWh");
    } else {
        Serial.println("Error reading energy");
    }

 
    if( !isnan(frequency) ){
        Serial.print("Frequency: "); Serial.print(frequency, 1); Serial.println("Hz");
    } else {
        Serial.println("Error reading frequency");
    }

    if( !isnan(pf) ){
        Serial.print("PF: "); Serial.println(pf);
    } else {
        Serial.println("Error reading power factor");
    }

    
    if( !isnan(t_unit) ){
        Serial.print("total units: "); Serial.println(t_unit);
    } else {
        Serial.println("Error calcuating total consumed units");
    }

//  Serial.println();
   http.end();  

  delay(1000);  
  digitalWrite(Led_OnBoard, LOW);
  delay(2000);
  digitalWrite(Led_OnBoard, HIGH);

}

void draw3(){

  readCurrent();
  readVoltage();
  readPower();
  readEnergy();
  
  u8g2.drawFrame(0,0,128,31);         
  u8g2.drawFrame(0,33,128,31);           
  
  u8g2.drawStr( 5, 13, "Current");   
  u8g2.drawStr( 8, 28, Val8);   
  u8g2.drawUTF8(30, 28, "A");
 // u8g2.drawUTF8(76, 28, "A");

  u8g2.drawStr(5,46, "Volatge");         
  u8g2.drawStr(8, 61, Val2); 
  u8g2.drawStr(50,61, "V");  
        
  
  u8g2.drawStr( 71, 13, "Power");   
  u8g2.drawStr( 71, 28, Val4);   
  u8g2.drawUTF8(110, 28, "W");
 // u8g2.drawUTF8(76, 28, "w");

  u8g2.drawStr(71,46, "Energy");         
  u8g2.drawStr( 71, 61, Val5); 
  u8g2.drawStr(90,61, "KWH"); 
}

void draw(){

  readCurrent();
  readVoltage();
  
  u8g2.drawFrame(0,0,128,31);         
  u8g2.drawFrame(0,33,128,31);           
  
  u8g2.drawStr( 30, 13, "Current");   
  u8g2.drawStr( 45, 28, Val8);   
  u8g2.drawUTF8(70, 28, "A");
 // u8g2.drawUTF8(76, 28, "A");

  u8g2.drawStr(30,46, "Volatge");         
  u8g2.drawStr( 37, 61, Val2); 
  u8g2.drawStr(75,61, "V");  
}

void draw1(){

  readPower();
  readEnergy();
  
  u8g2.drawFrame(0,0,128,31);         
  u8g2.drawFrame(0,33,128,31);           
  
  u8g2.drawStr( 30, 13, "Power");   
  u8g2.drawStr( 35, 28, Val4);   
  u8g2.drawUTF8(74, 28, "W");
 // u8g2.drawUTF8(76, 28, "w");

  u8g2.drawStr(30,46, "Energy");         
  u8g2.drawStr( 37, 61, Val5); 
  u8g2.drawStr(58,61, "KWH"); 
}

void draw2(){

  readFrequency();
  readPf();
  
  u8g2.drawFrame(0,0,128,31);         
  u8g2.drawFrame(0,33,128,31);           
  
  u8g2.drawStr( 30, 13, "Frequency");   
  u8g2.drawStr( 35, 28, Val6);   
  u8g2.drawUTF8(70, 28, "Hz");
 // u8g2.drawUTF8(76, 28, "w");

  u8g2.drawStr(30,46, "Power factor");         
  u8g2.drawStr( 45, 61, Val7); 
  
}




void readVoltage()
{

  float v = pzem.voltage();
  dtostrf(v, 3, 1, Val2);
}

void readCurrent()
{

  float c = pzem.current();
  dtostrf(c, 3, 1, Val8);
}

void readPower()
{

  float p = pzem.power();
  dtostrf(p, 3, 1, Val4);
}


void readEnergy()
{

  float e = pzem.energy();
  dtostrf(e, 3, 1, Val5);
}

void readFrequency()
{

  float f = pzem.frequency();
  dtostrf(f, 3, 1, Val6);
}

void readPf()
{

  float pf = pzem.pf();
  dtostrf(pf, 3, 1, Val7);
}