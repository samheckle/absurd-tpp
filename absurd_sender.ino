#include <Arduino.h>
#include <IRremote.h>

const int buttonPin = 2;
#define IR_SEND_PIN 12
const int led = 11;

uint16_t sAddress = 0x0102;
uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;

void setup()
{
  Serial.begin(115200);
  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("IR Sender Pin: ");
  Serial.println(IR_SEND_PIN);

  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    IrSender.sendNEC(sAddress, sCommand, sRepeats);
    Serial.println("print");
    digitalWrite(led, HIGH);
    delay(1000);
  }
}
