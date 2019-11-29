#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

int ledPin = 12; // choose pin for the LED
int inputPin = 13; // choose input pin (for Infrared sensor) 
int val = 0;

int inputPin2 = 14;
int ledPin2 = 2;
int val2 = 0;

int inputPin3 = 4;
int ledPin3 = 5;
int val3 = 0;

void setup() {
Serial.begin(9600);

pinMode(ledPin, OUTPUT); // declare LED as output 
pinMode(inputPin, INPUT);

pinMode(ledPin2, OUTPUT);
pinMode(inputPin2, INPUT);

pinMode(ledPin3, OUTPUT);
pinMode(inputPin3, INPUT);
  
#define FIREBASE_HOST "car-parking-management-fdc5b.firebaseio.com"
#define FIREBASE_AUTH "SeDIjZHjAGF8376lZRh1WyB2cFG4mg2g9PPNKCmo"
#define WIFI_SSID "ALOK"
#define WIFI_PASSWORD "Alok0010"
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
Serial.println("Firebase Begined");
}
void loop() {

// Readimg the inputs from the sensors.
val = digitalRead(inputPin); // read input value 
val2 = digitalRead(inputPin2);
val3 = digitalRead(inputPin3);

// For Semsor1
   if (val == HIGH)
   { // check if the input is HIGH
      digitalWrite(ledPin, LOW); // turn LED OFF 
      Firebase.setInt("/Sensor1/status", 0);  
   } 
   else 
   { 
      digitalWrite(ledPin, HIGH); // turn LED ON 
      Firebase.setInt("/Sensor1/status", 1);
   } 
// For Sensor2
   if (val2 == HIGH)
   { // check if the input is HIGH
      digitalWrite(ledPin2, LOW); // turn LED OFF 
      Firebase.setInt("/Sensor2/status", 0);  
   } 
   else 
   { 
      digitalWrite(ledPin2, HIGH); // turn LED ON 
      Firebase.setInt("/Sensor2/status", 1);
   }

// For Sensor3
    if (val3 == HIGH)
   { // check if the input is HIGH
      digitalWrite(ledPin3, LOW); // turn LED OFF 
      Firebase.setInt("/Sensor3/status", 0);  
   } 
   else 
   { 
      digitalWrite(ledPin3, HIGH); // turn LED ON 
      Firebase.setInt("/Sensor3/status", 1); 
   }
    
}
