


const int echoPin = 2; // Echo Pin of Ultrasonic Sensor
const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 10
                    
void setup() 
{
  Serial.begin(9600); // Starting Serial Communication
  pinMode(pingPin, OUTPUT); // initialising pin 3 as output
  pinMode(echoPin, INPUT); // initialising pin 2 as input
  pinMode(LED1, OUTPUT); // initialising pin 13 as output
  pinMode(LED2, OUTPUT); // initialising pin 12 as output
  pinMode(LED3, OUTPUT); // initialising pin 11 as output
  pinMode(LED4, OUTPUT); // initialising pin 10 as output
}

void loop()
{
  long duration, inches, cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin, LOW);

  
  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
  cm = microsecondsToCentimeters(duration); // calling method

  Serial.print("Tinggi Air : ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();

  if(cm > 800){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }else if(cm > 600){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }else if(cm > 250){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
  }else if(cm > 20){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  }else{
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  
  delay(100);

}

long microsecondsToInches(long microseconds) // method to covert microsec to inches 
{
 return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
}
