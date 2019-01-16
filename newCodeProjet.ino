// avec 3 LEDs


// Basic Bluetooth sketch HC-05_03 Using the state pin 
// Connect the HC-05 module and communicate using the serial monitor
//
// The HC-05 defaults to communication mode when first powered on.
// The default baud rate for communication mode is 9600
//
 
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 
// Connect the HC-05 RX to Arduino pin 3
// Connect the HC-05 STATE pin to Arduino pin 4.
//
 
char c = ' ';
String cuvant ;
String on = "on";
String off = "off";
// BTconnected will = false when not connected and true when connected
boolean BTconnected = false;
 
// connect the STATE pin to Arduino pin D4
const byte BTpin = 4;
int ledV = 13;
int ledA = 12;
int ledR = 11;
 
 
void setup() 
{
    // set the BTpin for input
    pinMode(BTpin, INPUT);   
    pinMode(ledV,OUTPUT);
    pinMode(ledA,OUTPUT);
    pinMode(ledR,OUTPUT);
    
    // start serial communication with the serial monitor on the host computer
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    Serial.println("Connect the HC-05 to an Android device to continue");
 
    // wait until the HC-05 has made a connection
    while (!BTconnected)
    {
      if ( digitalRead(BTpin)==HIGH)  { BTconnected = true;};
    }
    Serial.println("HC-05 is now connected");
 
    // Start serial communication with the bluetooth module
    // HC-05 default serial speed for communication mode is 9600 but can be different
    BTserial.begin(9600); 
    BTserial.write('x'); 
}
 
void loop()
{
 
    // Keep reading from the HC-05 and send to Arduino Serial Monitor
    if (BTserial.available()){     
        c = BTserial.read();
        Serial.write(c);
        Serial.println("");
        switch(c){
          case 'v':
            digitalWrite(ledV,HIGH);
            //delay(1000);
            BTserial.write('A');
            BTserial.println("");
            Serial.println("ledV on");
            break;

          case 'r':
            digitalWrite(ledR,HIGH);
            break;
          case 'a':
            digitalWrite(ledA,HIGH);
            break;
          case 'i':
            digitalWrite(ledV,LOW);
            digitalWrite(ledA,LOW);
            digitalWrite(ledR,LOW);
            //delay(1000);
            BTserial.write('D');
            BTserial.println("");
            Serial.println("ledV off");
            break;
          }
    }

}