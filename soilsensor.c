#define AOUT_PIN 26 
#define THRESHOLD 2800 
#define MOTOR_PIN 27    
#define LIGHT_PIN 28   
void setup() {
  Serial.begin(9600);
  
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(AOUT_PIN); 
  if (value > THRESHOLD) { 
    Serial.println("The soil is DRY ");
    Serial.println("Motor ON");
    Serial.println("Light ON");
    
    digitalWrite(MOTOR_PIN, HIGH);
    digitalWrite(LIGHT_PIN, HIGH);
  } else { 
    Serial.println("The soil is WET ");
    Serial.println("Motor OFF");
    Serial.println("Light OFF");
    
    digitalWrite(MOTOR_PIN, LOW);
    digitalWrite(LIGHT_PIN, LOW);
  }
  
  delay(500); 
}
