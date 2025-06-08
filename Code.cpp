int motorPin = 3;
int pos = 0; 
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   pinMode(motorPin,OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(pingPin, OUTPUT);
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
  long duration,  cm;
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(pingPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(10);
  
  if(cm>0 && cm<=50){
    digitalWrite(motorPin, HIGH); //vibrate
    delay(100);  // delay one second
    digitalWrite(motorPin, LOW);
    delay(100);
  }
  if(cm>50 && cm<=100){
    digitalWrite(motorPin, HIGH); //vibrate
    delay(500);  // delay one second
    digitalWrite(motorPin, LOW);
    delay(500);
 }
 if(cm>100 && cm<=150){
   digitalWrite(motorPin, HIGH); //vibrate
   delay(1000);  // delay one second
   digitalWrite(motorPin, LOW);
   delay(1000);
 }
 if(cm>150 && cm<=200){
   digitalWrite(motorPin, HIGH); //vibrate
   delay(5000);  // delay one second
   digitalWrite(motorPin, LOW);
   delay(5000);
 }
 if(cm>200 && cm<=250){
   digitalWrite(motorPin, HIGH); //vibrate
   delay(10000);  // delay one second
   digitalWrite(motorPin, LOW);
   delay(10000);
}
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
