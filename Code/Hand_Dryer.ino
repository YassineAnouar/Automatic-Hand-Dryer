// Automatic Hand Dryer
// Developed by Yassine Anouar

const int trigPin = 2;
const int echoPin = 3;
const int redLed = 5;
const int greenLed = 9;
const int relayPin = 4;

const int distanceThreshold = 10; 

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(relayPin, OUTPUT);

  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  digitalWrite(relayPin, LOW);
  
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance <= distanceThreshold) {
    digitalWrite(greenLed, HIGH); 
    digitalWrite(redLed, LOW);    
    digitalWrite(relayPin, HIGH); 
  } else {
    // إذا لم توجد يد:
    digitalWrite(greenLed, LOW);  
    digitalWrite(redLed, HIGH);   
    digitalWrite(relayPin, LOW);  
  }

  delay(100); 
}
