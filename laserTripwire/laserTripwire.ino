int ldr = A4;
int buzzer = 11;
int led = A0;
long ldrV1, ldrV2;


void setup() {
  pinMode (buzzer, OUTPUT);
  pinMode (led, OUTPUT);
  pinMode (ldr, INPUT);
 
}

void loop() {
    ldrV1 = analogRead(ldr);
    delay(10);
    ldrV2 = analogRead(ldr);
  if (ldrV1-ldrV2 > 20) {
  digitalWrite(buzzer, HIGH);
  digitalWrite(led, HIGH);
  }
    else{
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
    }
  }


