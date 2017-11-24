/*
 * Creation & Computation - Digital Futures, OCAD University
 * Kate Hartman / Nick Puckett
 * 
 * publish 1 random value and 1 potentiometer value when a button is pressed
 *  
 * 
 * 
 */
#include <ArduinoJson.h> 
#include <SPI.h>

#include <WiFi101.h>
#define PubNub_BASE_CLIENT WiFiClient
#include <PubNub.h>

static char ssid[] = "ocadu-embedded";      //SSID of the wireless network
static char pass[] = "internetofthings";    //password of that network
int status = WL_IDLE_STATUS;                // the Wifi radio's status

const static char pubkey[] = "pub-c-1644b35c-a221-4a73-911e-4ca9e938a490";  //get this from your PUbNub account
const static char subkey[] = "sub-c-13540314-c884-11e7-96a3-6a84acea123e";  //get this from your PubNub account

const static char pubChannel[] = "channel2"; //choose a name for the channel to publish messages to


unsigned long lastRefresh = 0;
int publishRate = 5000;

//int sensorPin1 = A0;                  

int buttonPrev;
int buttonVal;
boolean numSend;

int myVal1;                       //variables to hold values to send
int myVal2;


int buttonPin = 10;  // the pin the + leg of the button is attached to
int buttonState;  //variable that will hold the On / Off state of the button.


void setup() 
{

  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  connectToServer();


}

void loop() 
{
  buttonVal = digitalRead(buttonPin);

 buttonState = digitalRead(buttonPin);  //read the value on the pin and store it in the variable

//  Serial.print("Button State is: ");     //print the value to the Serial Monitor
//    Serial.println(buttonState);




if((buttonState==0)&&(buttonPrev==1))  //trigger the feed update with a button, uses both current and prev value to only change on the switch
{
  numSend = !numSend;     //changing what it send to the opposite
  Serial.println("publishing...");
  publishToPubNub();

} 

//if(millis()-lastRefresh>=publishRate)
//{
//  publishToPubNub();
//
//  lastRefresh=millis();
//}


buttonPrev = buttonState; //store the value of this cycle to compare next loop


}


void connectToServer()
{
  WiFi.setPins(8,7,4,2); //This is specific to the feather M0
 
  status = WiFi.begin(ssid, pass);                    //attempt to connect to the network
  Serial.println("Connecting to WiFi Network");


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


void publishToPubNub()
{
  WiFiClient *client;
  StaticJsonBuffer<800> messageBuffer;                    //create a memory buffer to hold a JSON Object
  JsonObject& pMessage = messageBuffer.createObject();    //create a new JSON object in that buffer
  
 ///the imporant bit where you feed in values
  
  //Message["State1"] = myVal1;                      //add a new property and give it a value
      pMessage["State2"] = numSend;                     //add a new property and give it a value 
 


///                                                       //you can add/remove parameter as you like
  
  //pMessage.prettyPrintTo(Serial);   //uncomment this to see the messages in the serial monitor
  
  
  int mSize = pMessage.measureLength()+1;                     //determine the size of the JSON Message
  char msg[mSize];                                            //create a char array to hold the message 
  pMessage.printTo(msg,mSize);                               //convert the JSON object into simple text (needed for the PN Arduino client)
  
  client = PubNub.publish(pubChannel, msg);                      //publish the message to PubNub

  if (!client)                                                //error check the connection
  {
    Serial.println("client error");
    delay(1000);
    return;
  }
  
  if (PubNub.get_last_http_status_code_class() != PubNub::http_scc_success)  //check that it worked
  {
    Serial.print("Got HTTP status code error from PubNub, class: ");
    Serial.print(PubNub.get_last_http_status_code_class(), DEC);
  }
  
  while (client->available()) 
  {
    Serial.write(client->read());
  }
  client->stop();
  Serial.println("Successful Publish");


  
}
