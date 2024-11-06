
// define echo pin and trigger pin 
const int trigPin = 11;  
const int echoPin = 10; 

// define pins connected to LEDs 
const int redLEDpin = 5;
const int greenLEDpin = 7;
const int yellowLEDpin = 6;
const int potPin = A4; 
float duration, distance, potValue , adjustValue;  

void setup() {  
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);
    pinMode(redLEDpin, OUTPUT); 
    pinMode(greenLEDpin, OUTPUT); 
    pinMode(yellowLEDpin, OUTPUT); 
	Serial.begin(9600);  
}  

void loop() {  
	digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW); 

  	duration = pulseIn(echoPin, HIGH);  
  
 	distance = (duration*.0343)/2;
  
  	potValue = analogRead(potPin); 
  	adjustValue = map(potValue, 0, 1023, -8,8);
  
    float thresholdOne = 10 + adjustValue;
  	float thresholdTwo = 20 + adjustValue; 
    if (distance < 10 + adjustValue) {
    digitalWrite(redLEDpin, HIGH);
    digitalWrite(yellowLEDpin, LOW);
    digitalWrite(greenLEDpin, LOW);
  } else {
    if (distance <= 20 + adjustValue) {
      digitalWrite(redLEDpin, LOW);
      digitalWrite(yellowLEDpin, HIGH);
      digitalWrite(greenLEDpin, LOW);
    } else {
      digitalWrite(redLEDpin, LOW);
      digitalWrite(yellowLEDpin, LOW);
      digitalWrite(greenLEDpin, HIGH);
    }
  }
 
    Serial.print("Distance: ");  
	Serial.println(distance);  
  	Serial.println("Ranges: ");
  	Serial.print("RED: less than ");
  	Serial.println(thresholdOne); 
  	Serial.print("Yellow: between :");
  	Serial.println(String(thresholdOne) + " and " + String(thresholdTwo)); 
  	Serial.print("Green LED: greater than ");
  	Serial.println(thresholdTwo); 
  	
  
	delay(100);  
} 
