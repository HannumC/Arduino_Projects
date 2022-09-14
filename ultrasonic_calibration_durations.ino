#define trigPin1 13            //Trig1 to arduino pin 13
#define echoPin1 12            //echo1 to arduino pin 12
#define trigPin2 11            //trig2 to arduino pin 11
#define echoPin2 10            //echo2 to arduino pin 10

void setup() {
  Serial.begin (9600);         //serial communications at 9600 bps
  pinMode(trigPin1, OUTPUT);   //set the trigPin1 as output
  pinMode(echoPin1, INPUT);    // set the echoPin1 as input
  pinMode(trigPin2, OUTPUT);   // set the trigPin2 as output
  pinMode(echoPin2, INPUT);    // set the echoPin2 as input
}

void loop() {
  float duration1, distance1, duration2, distance2;
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH); //send out ultrasonicwave to 10s
  
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  duration1 = pulseIn(echoPin1, HIGH, 2000); //arduino will only wait 2000 microseconds for the pulse to be complete
  //distance1 = (duration1/2) * 0.03435; //sound speed = 0.03435 cm/ct
  
  //prints data to the serial port as human readable ASCII text
  Serial.print(duration1);
  Serial.print(" microseconds d1        ");
  delayMicroseconds(20);


  
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH); //send out ultrasonicwave to 10s
  
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  duration2 = pulseIn(echoPin2, HIGH, 2000); //arduino will only wait 2000 microseconds for the pulse to be complete
  //distance2 = (duration2/2) * 0.03435; //sound speed = 0.03435 cm/ct

  //prints data to the serial port as human readable ASCII text
  Serial.print(duration2);
  Serial.println(" microseconds d2");

  delay(100);
}
