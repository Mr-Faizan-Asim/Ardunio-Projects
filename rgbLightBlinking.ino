void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(8, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(500);
  digitalWrite(6, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  delay(500);
  
}
