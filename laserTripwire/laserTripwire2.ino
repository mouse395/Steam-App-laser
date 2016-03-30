const int LEDPin = 4;

const int sensorPin = A0;

int value = 0;

int sensorValueInitial;
int sensorValue;

int pacer = 0;

void setup() {

	Serial.begin(9600);

	pinMode(LEDPin, OUTPUT);
}

void loop() {

	/*this establishes the value of the resistor when the
	laser hits it*/
	While (pacer < 5) {
		sensorValueInitial = analogRead(sensorPin);
		delay(100);
		pacer++;
	}
	
	delay(5);

	//This establishes the value of resistor in real time
	sensorValue = analogRead(sensorPin);

	//prints raw value
	Serial.println("inital sensor Value: " + sensorValueInitial);
	Serial.print("raw sensor value: ");
	Serial.println(sensorValue);

	//changing the raw value to a (0,255) value
	value = sensorValue / 4;

	Serial.print("Mapped sensor value: ")
	Serial.println(value);

	//if there is interferience the light will turn on
	if (sensorValue < sensorValueInitial - 10) {
		digtalWrite(LEDPin, HIGH);
	}

	else {digitalWrite(LEDPin, LOW);;}

	delay(10);
}
