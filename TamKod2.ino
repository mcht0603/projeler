int Aydinlatma1 = 4;
int Aydinlatma2 = 5;
int Aydinlatma3 = 6;
int Aydinlatma4 = 7;
int Bahceon = 12;
int Bahcearka = 13;
int Klima = 8;


int led = 11;                // the pin that the LED is atteched to
int sensor = 3;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)



#include <Servo.h>

Servo Perde;
Servo Garage;

#include <DHT.h>
#include "DHT.h"
#define DHTPIN 2     // pin for connecting dht11/dht22 sensor
#define DHTTYPE DHT11   // DHT 11 : type of sensor you are using
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input 
  
  Serial.begin(9600);
  pinMode(Aydinlatma1,OUTPUT);
   pinMode(Aydinlatma2,OUTPUT);
   pinMode(Aydinlatma3,OUTPUT);
   pinMode(Aydinlatma4,OUTPUT);
   pinMode(Bahceon,OUTPUT);
   pinMode(Bahcearka,OUTPUT);
pinMode(Klima,OUTPUT);

 Perde.attach(9);
 Garage.attach(10);
 
 dht.begin();
}

void loop() {
 {
  if(Serial.available()>0){
}
char GelenVeri = Serial.read();
delay(100);
if(GelenVeri == '1'){
digitalWrite(Aydinlatma1,HIGH);
}
if(GelenVeri == '2'){
digitalWrite(Aydinlatma1,LOW);
}
if(GelenVeri == '3'){
digitalWrite(Aydinlatma2,HIGH);
}
if(GelenVeri == '4'){
digitalWrite(Aydinlatma2,LOW);
}
if(GelenVeri == '5'){
digitalWrite(Aydinlatma3,HIGH);
}
if(GelenVeri == '6'){
digitalWrite(Aydinlatma3,LOW);
}
if(GelenVeri == '7'){
digitalWrite(Aydinlatma4,HIGH);
}
if(GelenVeri == '8'){
digitalWrite(Aydinlatma4,LOW);
}
if(GelenVeri == 'a'){
digitalWrite(Klima,HIGH);
}
if(GelenVeri == 'b'){
digitalWrite(Klima,LOW);
}
if(GelenVeri == 'c'){
   Perde.write(90);
   delay(15);
 }
if(GelenVeri == 'd'){
   Perde.write(0);
   delay(15);
}
if(GelenVeri == 'e'){
   Garage.write(90);
   delay(15);
 }
if(GelenVeri == 'f'){
   Garage.write(0);
   delay(15);
}
if(GelenVeri == 'g'){
digitalWrite(Bahceon,HIGH);
}
if(GelenVeri == 'h'){
digitalWrite(Bahceon,LOW);
}
if(GelenVeri == 'j'){
digitalWrite(Bahcearka,HIGH);
}
if(GelenVeri == 'k'){
digitalWrite(Bahcearka,LOW);
}
} 
  
  
  delay(100);// Wait a few seconds for sensor to measure

 val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    
    digitalWrite(led, HIGH);   // turn LED ON
    delay(20);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(50);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }


  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  float hif = dht.computeHeatIndex(f, h); //compute the heat index, must give temp in fahrenheit

  Serial.print("Nem: "); 
  Serial.print(h);
  Serial.print(" %\t");
  delay(10);
  Serial.print("Sıcaklık: "); 
  Serial.print(t);
  Serial.print(" santigrat derece ");
    delay(10);
}
