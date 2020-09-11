/*
Matthew Bamford-King
11/9/2020
Making an LED blink using an output pin of the arduino uno.
*/


void setup() {

    //Select PIN 12
    pinMode(12, OUTPUT);
}

void loop(){
    digitalWrite(12, HIGH);
    delay(2000);
    digitalWrite(12, LOW);
    delay(2000);
}