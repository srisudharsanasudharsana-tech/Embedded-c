int TRIGGER_PIN = 26;  
int ECHO_PIN = 25;     
const float SPEED_OF_SOUND = 343.0;

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = (duration * 0.5 * SPEED_OF_SOUND) / 10000.0;

 
  Serial.print("Distance: ");
  Serial.print(distance, 2);  
  Serial.println(" cm");

  if (distance >= 80) {
    Serial.println("Motor ON");
  } else if (distance >= 60 && distance < 80) {
    Serial.println("Motor Midrange");
  } else if (distance <= 10) {
    Serial.println("Motor OFF");
  }

  delay(100);  // 100 milliseconds
}
