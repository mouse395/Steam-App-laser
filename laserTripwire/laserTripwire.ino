int ldr = A4;
int buzzer = 11;
//led is also a digitalWrite so we use pins from 0 to 12
int led = 4;
int laser = 1;
//no need for longs
int ldrV1, ldrV2;


void setup() {
  pinMode (buzzer, OUTPUT);
  pinMode (led, OUTPUT);
  pinMode (ldr, INPUT);
  pinMode (laser, OUTPUT);
 
}

void loop() {

    digitalWrite(laser, HIGH);

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


