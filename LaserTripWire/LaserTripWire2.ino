
#include <LiquidCrystal.h>

//this is where the led pin
const int LEDPin = 7;

//the photoresistor pin
const int sensorPin = A0;

int sensorValueInitial;
int sensorValue;

//the pacer variable is used to set up the initial value.
int pacer = 0;

//setting up the lcd pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);

  lcd.begin(16,2);
}

//this function refreshes the lcd screen
void refresh() {
  lcd.setCursor(0, 0);
  lcd.print("             ");
  lcd.setCursor(0, 1);
  lcd.print("             ");
  lcd.setCursor(0, 0);
  }

void loop() {

  /*this establishes the value of the resistor when the
  laser hits it*/
  while (pacer < 5) {
    sensorValueInitial = analogRead(sensorPin);
    delay(100);
    pacer++;
    //the pacer variable starts at 0. Once it loops 5 times it will be .5 seconds
  }
  
  delay(5);

  //This establishes the value of resistor in real time
  sensorValue = analogRead(sensorPin);
 

  //prints raw value
  Serial.print("inital sensor Value: ");
  Serial.println(sensorValueInitial);
  Serial.print("new sensor value: ");
  Serial.println(sensorValue);


  //if there is interferience the light will turn on
  if (sensorValue < sensorValueInitial - 10) {
    digitalWrite(LEDPin, HIGH);
    refresh();

    //prints to the lcd screen
    lcd.print("MOTION");
    lcd.setCursor(0, 1);
    lcd.print("DETECTED!");
  }

  else {

    //prints to screen that there is no motion
    //this is what should be on when there is nothing blocking the way of the laser
    digitalWrite(LEDPin, LOW);
    refresh();
    lcd.print("No Motion");
    }

  delay(10);
}
