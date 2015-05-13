#include <X10Firecracker.h>

#define RTS_PIN     2                   // RTS line for C17A - DB9 pin 7
#define DTR_PIN     3                   // DTR line for C17A - DB9 pin 4
#define BIT_DELAY   1 

#define LIGHT 	13

int delayCount = 10000;
bool lightState = false;
int lightVal = HIGH;

void setup() {
	pinMode(LIGHT, OUTPUT);
	X10.init(RTS_PIN, DTR_PIN, BIT_DELAY);
	Serial.begin(115200);
}

void lightOn() {
	Serial.println("Turning light ON!");
	X10.sendCmd(hcA, 1, cmdOn);
	lightState = true;
}

void lightOff() {
	Serial.println("Turning light OFF!");
	X10.sendCmd(hcA, 1, cmdOff);
	lightState = false;
}

void toggleLight() {
	if (lightState) {
		lightOff();
	} else {
		lightOn();
	}
}

void loop() {
	digitalWrite(LIGHT, HIGH);
	lightOn();
	delay(10000);
	digitalWrite(LIGHT, LOW);
	lightOff();
	delay(10000);
}
