#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h> 
const char* ssid = "HUAWEI Y5 2019";
const char* password = "0123456789";

static const uint8_t D0   = 23;
static const uint8_t D1   = 22;
static const uint8_t D2   = 21;
static const uint8_t D3   = 19;
static const uint8_t D4   = 18;
static const uint8_t D5   = 5;
static const uint8_t D6   = 17;
static const uint8_t D7   = 16;
static const uint8_t D8   = 12;
static const uint8_t D9   = 13;
static const uint8_t D10  = 32;
static const uint8_t D11  = 33;
static const uint8_t D12  = 25;
static const uint8_t D13  = 26;
static const uint8_t D14  = 27;
static const uint8_t D15  = 14;



int rank=4;//THE RANK WHOSE DATA YOU WANT TO FETCH 
void setup () {
 
  Serial.begin(115200);

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);
  pinMode(D11, OUTPUT);
  pinMode(D12, OUTPUT);
  pinMode(D13, OUTPUT);
  pinMode(D14, OUTPUT);
  pinMode(D15, OUTPUT);
  

  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");
 
  }
 
}
 
void loop() {
 
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    HTTPClient http1,http2,http3,http4,http5,http6,http7,http8,http9,http10,http11,http12,http13,http14,http15,http16;  //Declare an object of class HTTPClient
    WiFiClient client1,client2,client3,client4,client5,client6,client7,client8 ,client9,client10,client11,client12,client13,client14,client15,client16;
    // http1.begin(client1 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=1");  //Specify request destinatio
    http1.begin(client1 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=1");  //Specify request destination
    int httpCode1 = http1.GET();                                  //Send the request
    // http2.begin(client2 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=2");  //Specify request destination
    http2.begin(client2 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=2");  //Specify request destination
    int httpCode2 = http2.GET();
    // http3.begin(client3 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=3");  //Specify request destination
    http3.begin(client3 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=3");  //Specify request destination
    int httpCode3 = http3.GET();
    // http4.begin(client4 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=4");  //Specify request destination
    http4.begin(client4 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=4");  //Specify request destination
    int httpCode4 = http4.GET();
    //http5.begin(client5 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=5");  //Specify request destination
    http5.begin(client5 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=5");  //Specify request destination
    int httpCode5 = http5.GET();
    //http6.begin(client6 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=6");  //Specify request destination
    http6.begin(client6 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=6");  //Specify request destination
    int httpCode6 = http6.GET();
    //http7.begin(client7 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=7");  //Specify request destination
    http7.begin(client7 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=7");  //Specify request destination
    int httpCode7 = http7.GET();
    //http8.begin(client8 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=8");  //Specify request destination
    http8.begin(client8 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=8");  //Specify request destination
    int httpCode8 = http8.GET();
    //http9.begin(client8 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=9");  //Specify request destination
    http9.begin(client9 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=9");  //Specify request destination
    int httpCode9 = http9.GET();
    //http10.begin(client10 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=10");  //Specify request destination
    http10.begin(client10 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=10");  //Specify request destination
    int httpCode10 = http10.GET();
    //http11.begin(client11 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=11");  //Specify request destination
    http11.begin(client11 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=11");  //Specify request destination
    int httpCode11 = http11.GET();
    //http12.begin(client12 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=12");  //Specify request destination
    http12.begin(client12 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=12");  //Specify request destination
    int httpCode12 = http12.GET();
    //http13.begin(client13 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=13");  //Specify request destination
    http13.begin(client13 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=13");  //Specify request destination
    int httpCode13 = http13.GET();
    //http14.begin(client14 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=14");  //Specify request destination
    http14.begin(client14 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=14");  //Specify request destination
    int httpCode14 = http14.GET();
    //http15.begin(client15 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=15");  //Specify request destination
    http15.begin(client15 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=15");  //Specify request destination
    int httpCode15 = http15.GET();
    //http16.begin(client16 ,"http://eleccare.000webhostapp.com/con/relay.php?Relay_ID=16");  //Specify request destination
    http16.begin(client16 ,"http://192.168.43.101/PZEM-004T/relay.php?Relay_ID=16");  //Specify request destination
    int httpCode16 = http16.GET();

    if (httpCode1 > 0 && httpCode2 > 0 && httpCode3 > 0 && httpCode4 > 0 && httpCode5 > 0 && httpCode6 > 0 && httpCode7 > 0 && httpCode8 > 0 && httpCode9 > 0&& httpCode10 > 0&& httpCode11 > 0&& httpCode12 > 0&& httpCode13 > 0&& httpCode14 > 0&& httpCode15 > 0 && httpCode16 > 0) { //Check the returning code
      String payload1 = http1.getString();   //Get the request response payload
      String payload2 = http2.getString();   //Get the request response payload
      String payload3 = http3.getString();   //Get the request response payload
      String payload4 = http4.getString();   //Get the request response payload
      String payload5 = http5.getString();   //Get the request response payload
      String payload6 = http6.getString();   //Get the request response payload
      String payload7 = http7.getString();   //Get the request response payload
      String payload8 = http8.getString();   //Get the request response payload
      String payload9 = http9.getString();   //Get the request response payload
      String payload10 = http10.getString();   //Get the request response payload
      String payload11 = http11.getString();   //Get the request response payload
      String payload12 = http11.getString();   //Get the request response payload
      String payload13 = http12.getString();   //Get the request response payload
      String payload14 = http13.getString();   //Get the request response payload
      String payload15 = http14.getString();   //Get the request response payload
      String payload16 = http15.getString();   //Get the request response payload
      

      Serial.println(payload1+","+payload2+","+payload3+","+payload4+","+payload5+","+payload6+","+payload7+","+payload8+","+payload9+","+payload10+","+payload11+","+payload12+","+payload13+","+payload14+","+payload15+","+payload16);             //Print the response payload
      // Serial.println(payload1+","+payload2+","+payload3+","+payload4);             //Print the response payload
      // Serial.println(payload5+","+payload6+","+payload7+","+payload8);             //Print the response payload

    if(payload1 == "1"){
        digitalWrite(D0, LOW);
        Serial.println("RELAY1 Current Flowing");        
      }
      else{
        digitalWrite(D0,HIGH);
        Serial.println("RELAY1 Current not Flowing");
      }
 
    

    if(payload2 == "1"){
        digitalWrite(D1, LOW);
        Serial.println("RELAY2 Current Flowing");        
      }
      else{
        digitalWrite(D1,HIGH);
        Serial.println("RELAY2 Current not Flowing");
      }
 
    

    if(payload3 == "1"){
        digitalWrite(D2, LOW);
        Serial.println("RELAY3 Current Flowing");        
      }
      else{
        digitalWrite(D2,HIGH);
        Serial.println("RELAY3 Current not Flowing");
      }
 
    

    if(payload4 == "1"){
        digitalWrite(D3, LOW);
        Serial.println("RELAY4 Current Flowing");        
      }
      else{
        digitalWrite(D3,HIGH);
        Serial.println("RELAY4 Current not Flowing");
      }
 
    


    if(payload5 == "1"){
        digitalWrite(D4, LOW);
        Serial.println("RELAY5 Current Flowing");        
      }
      else{
        digitalWrite(D4,HIGH);
        Serial.println("RELAY5 Current not Flowing");
      }
 
    

    if(payload6 == "1"){
        digitalWrite(D5, LOW);
        Serial.println("RELAY6 Current Flowing");        
      }
      else{
        digitalWrite(D5,HIGH);
        Serial.println("RELAY6 Current not Flowing");
      }
 
    

    if(payload7 == "1"){
        digitalWrite(D6, LOW);
        Serial.println("RELAY7 Current Flowing");        
      }
      else{
        digitalWrite(D6,HIGH);
        Serial.println("RELAY7 Current not Flowing");
      }
 
    

    if(payload8 == "1"){
        digitalWrite(D7, LOW);
        Serial.println("RELAY8 Current Flowing");        
      }
      else{
        digitalWrite(D7,HIGH);
        Serial.println("RELAY8 Current not Flowing");
      }

    if(payload9 == "1"){
        digitalWrite(D8, LOW);
        Serial.println("RELAY9 Current Flowing");        
      }
      else{
        digitalWrite(D8,HIGH);
        Serial.println("RELAY9 Current not Flowing");
      }


    if(payload10 == "1"){
        digitalWrite(D9, LOW);
        Serial.println("RELAY10 Current Flowing");        
      }
      else{
        digitalWrite(D9,HIGH);
        Serial.println("RELAY10 Current not Flowing");
      } 

    if(payload11 == "1"){
        digitalWrite(D10, LOW);
        Serial.println("RELAY11 Current Flowing");        
      }
      else{
        digitalWrite(D10,HIGH);
        Serial.println("RELAY11 Current not Flowing");
      }

    if(payload12 == "1"){
        digitalWrite(D11, LOW);
        Serial.println("RELAY12 Current Flowing");        
      }
      else{
        digitalWrite(D11,HIGH);
        Serial.println("RELAY12 Current not Flowing");
      }

    if(payload13 == "1"){
        digitalWrite(D12, LOW);
        Serial.println("RELAY13 Current Flowing");        
      }
      else{
        digitalWrite(D12,HIGH);
        Serial.println("RELAY13 Current not Flowing");
      }  

      if(payload14 == "1"){
        digitalWrite(D13, LOW);
        Serial.println("RELAY14 Current Flowing");        
      }
      else{
        digitalWrite(D13,HIGH);
        Serial.println("RELAY14 Current not Flowing");
      } 

    if(payload15 == "1"){
        digitalWrite(D14, LOW);
        Serial.println("RELAY15 Current Flowing");        
      }
      else{
        digitalWrite(D14,HIGH);
        Serial.println("RELAY15 Current not Flowing");
      }  
    }
 
    http1.end();   //Close connection
    http2.end();   //Close connection
    http3.end();   //Close connection
    http4.end();   //Close connection
    http5.end();   //Close connection
    http6.end();   //Close connection
    http7.end();   //Close connection
    http8.end();   //Close connection
    http9.end();   //Close connection
    http10.end();   //Close connection
    http11.end();   //Close connection
    http12.end();   //Close connection
    http13.end();   //Close connection
    http14.end();   //Close connection
    http15.end();   //Close connection
    http16.end();   //Close connection
 
  }
 
  delay(1);    //Send a request every 30 seconds
}