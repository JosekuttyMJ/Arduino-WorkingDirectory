/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 
 
 */


#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
#define m1 9
#define m2 10
#define m3 11
#define m4 12

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(m1, OUTPUT);
 pinMode(m2, OUTPUT);
 pinMode(m3, OUTPUT);
 pinMode(m4, OUTPUT);
 
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(LEDPin, HIGH); 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 digitalWrite(LEDPin, LOW); 
 //#####################################3333333333333#######################################
 if(distance<11)
 {
  digitalWrite(m1, HIGH); 
digitalWrite(m2, LOW); 
digitalWrite(m3, LOW); 
digitalWrite(m4, HIGH); 
delay(1000);
 }
 else
 
 
  {
  digitalWrite(m1, HIGH); 
digitalWrite(m2, LOW); 
digitalWrite(m3, HIGH); 
digitalWrite(m4, LOW); 
 }
 }
 

 delay(50);
}
