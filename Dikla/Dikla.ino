/*
 * Creation & Computation - Digital Futures, OCAD University
 * Kate Hartman / Nick Puckett
 * 
 *read 2 random values from PubNub on a timer, send new values on button press
 *  
 * 
 * 
 */
#include <ArduinoJson.h> 
#include <SPI.h>
#include "pitches.h"

#include <WiFi101.h>
#define PubNub_BASE_CLIENT WiFiClient
#include <PubNub.h>

static char ssid[] = "ocadu-embedded";      //SSID of the wireless network
static char pass[] = "internetofthings";    //password of that network
int status = WL_IDLE_STATUS;                // the Wifi radio's status

const static char pubkey[] = "pub-c-1644b35c-a221-4a73-911e-4ca9e938a490";  //get this from your PUbNub account
const static char subkey[] = "sub-c-13540314-c884-11e7-96a3-6a84acea123e";  //get this from your PubNub account

//const static char pubChannel[] = "Channel2"; //choose a name for the channel to publish messages to
const static char subChannel[] = "channel2"; //choose a name for the channel to publish messages to


int piezoPin = 12;



//int buttonPin = 12;
int buttonPrev = 1;
int buttonVal;


unsigned long lastRefresh = 0;
int publishRate = 2000;

//int sensorPin1 = A0; 

int State2;

int yourVal1;
//int yourVal2;

//int myVal1;
//int myVal2;


void setup() 
{
//  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(piezoPin, OUTPUT);  
  Serial.begin(9600);
  connectToServer();

}

void loop() 
{
  //Serial.println("loop");
  
//digitalWrite(piezoPin,yourVal1);

//buttonVal = digitalRead(buttonPin);


//myVal1 = analogRead(sensorPin1);
//myVal2 = random(100,200);
  Serial.println(yourVal1);
  if (yourVal1 == 0) {     //if you get true play this tune
    // turn speaker on:
       // play e4
  delay(600);
  tone(piezoPin, 329.63, 300);
  delay(350);
  // play d4# 
  tone(piezoPin, 311.13, 300);
  delay(350);
  // play e4
  tone( piezoPin, 329.63, 300);
  delay(350);
  // play d4# 
  tone( piezoPin,311.13, 300);
  delay(350);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(350);
  // play b3
  tone( piezoPin, 246.94, 300);
  delay(400);
  // play d4
  tone(piezoPin, 293.66,300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63,300);
  delay(400);
  // play a3
  tone(piezoPin, 220, 900);
  delay(1000);
  // play d3
  tone(piezoPin,146.83, 300);
  delay(350);
  //play f3
  tone(piezoPin, 174.61, 300);
  delay(400);
  //play a3
  tone(piezoPin, 220, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 900);
  delay(1000);
  // play f3
  tone(piezoPin, 174.61, 300);
  delay(400);
  // play a3#
  tone(piezoPin, 233.08, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63, 900);
  delay(1000);
  delay(300);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(400);
  // play d4#
  tone(piezoPin, 311.13, 300);
  delay(400);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(400);
  // play d4#
  tone(piezoPin, 311.13, 300);
  delay(400);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 300);
  delay(400);
  // play d4
  tone(piezoPin, 293.66, 300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63, 300);
  delay(400);
  // play a3
  tone(piezoPin, 220, 900);
  delay(1000);
  // play d3
  tone(piezoPin, 146.83, 300);
  delay(400);
  // play f3
  tone(piezoPin, 174.61, 300);
  delay(400);
  // play a3
  tone(piezoPin, 220, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 900);
  delay(1000);
  // play f3
  tone(piezoPin, 174.61, 300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 300);
  delay(400);
  // play a3
  tone(piezoPin, 220, 900);
  delay(1000);
  // play b3
  tone(piezoPin,246.94, 300);
  delay(400);
   // play c4
  tone(piezoPin, 261.63, 300);
  delay(400);
  // play d4
  tone(piezoPin, 293.66, 300);
  delay(400);
  // play e4
  tone(piezoPin, 329.63, 900);
  delay(1000);
  // play g3
  tone(piezoPin, 196, 300);
  delay(400);
  // play f4
  tone(piezoPin, 349.23, 300);
  delay(400);
  //play e4
  tone(piezoPin, 329.23, 300);
  delay(400);
  // play d4
  tone(piezoPin, 293.63, 900);
  delay(1000);
  // play e3
  tone(piezoPin,164.81, 300);
  delay(400);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(400);
  // play d4
  tone(piezoPin, 293.63, 300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63, 900);
  delay(1000);
  // play d3
  tone(piezoPin, 146.83, 300);
  delay(400);
    // play d4
  tone(piezoPin, 293.63, 300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 900);
  delay(1000);
  delay(400);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(400);
  // play d4# 
  tone(piezoPin, 311.13, 300);
  delay(350);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(350);
  // play d4# 
  tone(piezoPin,311.13, 300);
  delay(350);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(350);
  // play b3
  tone(piezoPin, 246.94, 300);
  delay(400);
  // play d4
  tone(piezoPin, 293.66,300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63,300);
  delay(400);
  // play a3
  tone(piezoPin, 220, 900);
  delay(1000);
  // play d3
  tone(piezoPin,146.83, 300);
  delay(350);
  //play f3
  tone(piezoPin, 174.61, 300);
  delay(400);
  //play a3
  tone(piezoPin, 220, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 900);
  delay(1000);
  // play f3
  tone(piezoPin, 174.61, 300);
  delay(400);
  // play a3
  tone(piezoPin, 233.08, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63, 900);
  delay(1000);
  delay(300);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(400);
  // play d4#
  tone(piezoPin, 311.13, 300);
  delay(400);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(400);
  // play d4#
  tone(piezoPin, 311.13, 300);
  delay(400);
  // play e4
  tone(piezoPin, 329.63, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 300);
  delay(400);
  // play d4
  tone(piezoPin, 293.66, 300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63, 300);
  delay(400);
  // play a3
  tone(piezoPin, 220, 900);
  delay(1000);
  // play d3
  tone(piezoPin, 146.83, 300);
  delay(400);
  // play f3
  tone(piezoPin, 174.61, 300);
  delay(400);
  // play a3
  tone(piezoPin, 220, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 900);
  delay(1000);
  // play f3
  tone(piezoPin, 174.61, 300);
  delay(400);
  // play c4
  tone(piezoPin, 261.63, 300);
  delay(400);
  // play b3
  tone(piezoPin, 246.94, 300);
  delay(400);
  // play a3
  tone(piezoPin, 220, 900);
  delay(2000);
  } else {
    // turn speaker off:
    noTone(piezoPin);
  }


  


//Serial.println(millis()-lastRefresh);
  if(millis()-lastRefresh>=publishRate)     //theTimer to trigger the reads 
  {
  readFromPubNub();
   
  Serial.print("State2 ");
  Serial.println(yourVal1);
   
  //Serial.print("randoVal2 ");
  // Serial.println(yourVal2);
 
  lastRefresh=millis();   
  }







buttonPrev = buttonVal; //store the value of this cycle to compare next loop

}


void connectToServer()
{
  WiFi.setPins(8,7,4,2); //This is specific to the feather M0
 
  status = WiFi.begin(ssid, pass);                    //attempt to connect to the network
  Serial.println("***Connecting to WiFi Network***");


 for(int trys = 1; trys<=10; trys++)                    //use a loop to attempt the connection more than once
 { 
    if ( status == WL_CONNECTED)                        //check to see if the connection was successful
    {
      Serial.print("Connected to ");
      Serial.println(ssid);
  
      PubNub.begin(pubkey, subkey);                      //connect to the PubNub Servers
      Serial.println("PubNub Connected"); 
      break;                                             //exit the connection loop     
    } 
    else 
    {
      Serial.print("Could Not Connect - Attempt:");
      Serial.println(trys);

    }

    if(trys==10)
    {
      Serial.println("I don't this this is going to work");
    }
    delay(1000);
 }

  
}


void readFromPubNub()
{
  Serial.println("read");
  StaticJsonBuffer<1200> inBuffer;                    //create a memory buffer to hold a JSON Object
  WiFiClient *sClient =PubNub.history(subChannel,1);

  if (!sClient) {
    Serial.println("message read error");
    delay(1000);
    return;
  }

  while (sClient->connected()) 
  {
    while (sClient->connected() && !sClient->available()) ; // wait
    char c = sClient->read();
    JsonObject& sMessage = inBuffer.parse(*sClient);
    
    if(sMessage.success())
    {
      //sMessage.prettyPrintTo(Serial); //uncomment to see the JSON message in the serial monitor
      yourVal1 = sMessage["State2"];  //
      Serial.print("State2");
      Serial.println(yourVal1);
      //yourVal2 = sMessage["randoVal2"];
      //Serial.print("randoVal2 ");
      //Serial.println(yourVal2);
      
    }
    
    
  }
  
  sClient->stop();

}

