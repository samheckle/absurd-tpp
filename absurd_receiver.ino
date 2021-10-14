#include <Stepper.h>
#include <Arduino.h>
#include <IRremote.h>
#define IR_RECEIVE_PIN 2
#define IR_SEND_PIN 12

const int stepsPerRevolution = 200;  

Stepper myStepper(stepsPerRevolution, 9, 10, 8, 7);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(115200);

  IrSender.begin(IR_SEND_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("IR Sender Pin: ");
  Serial.println(IR_SEND_PIN);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print("IR Receiver Pin: ");
  Serial.println(IR_RECEIVE_PIN);
}

void loop() {

  if (IrReceiver.decode()) {
    Serial.print("received ");
    IrReceiver.printIRResultShort(&Serial);

    myStepper.step(-stepsPerRevolution / 2);
    delay(2000);
    IrReceiver.resume();
  }
}
