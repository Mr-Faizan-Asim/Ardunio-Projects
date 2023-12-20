void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(7, random(255)); // 0  to 255
  analogWrite(6, random(255));
  analogWrite(8, random(255));
  delay(500);
  
}
