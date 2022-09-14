#define trigPin 13            //Trig to arduino pin 13
#define echoPin 12            //echo to arduino pin 12

void setup() {
  Serial.begin (9600);        //serial communications at 9600 bps
  pinMode(trigPin, OUTPUT);   //set the trigPin as output
  pinMode(echoPin, INPUT);    // set the echoPun as input
}

void loop() {
  float duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //send out ultrasonicwave to 10s
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); //read the high pulse whose duration is the time in microseconds from the sending of the ping to the reception of its echo off an object

  distance = (duration/2) * 0.03435; //sound speed = 0.03435 cm/ct

  //prints data to the serial port as human readable ASCII text
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);
}
