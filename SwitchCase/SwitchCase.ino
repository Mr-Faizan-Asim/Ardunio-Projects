int senMin = 0;
int senMax = 600;

void setup() {
  // put your setup code here, to run once:
  digitalWrite(1,HIGH);
}

void loop() {
  int reading = analogRead(A0);
  int range = map(reading,senMin,senMax,0,3);
  switch(range)
  {
    case 0:
    digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    break;
    case 1:
    digitalWrite(2,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    break;
    case 2:
    digitalWrite(3,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    break;
    case 3:
    digitalWrite(4,HIGH);
    digitalWrite(1,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    break;     
  }
  delay(1);
}
