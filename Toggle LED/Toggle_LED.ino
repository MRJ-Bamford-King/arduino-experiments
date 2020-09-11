/*
Matthew Bamford-King
11/9/2020
Making an LED Toggle on and off with a push button.
Using artificial rising edge pulse activation.

How it Works:
When the button is pressed a voltage is applied to the analog input.
When the max voltage is applied the UNO translates that to a number, 1024.
We only need more than half of that voltage to ativate the toggle, so 512.

To make the LED stop flashing when holding down the button, we make the toggle happen only once per button press.
To do this we make the toggle happen only when there is a rising edge of a pulse,
for example when the button is first pressed down, there is an increase in voltage and while the button is pressed the
voltage level isn't changing on the analog input so the LED will toggle only once in the whole press no matter how long
you hold the button down, it will only change when you first press down the button.
*/

//Prototype
bool risingEdge(int x1, int x2);

//Variables
int x1, x2, buttonDown = 0; // Analog Voltage Reading, and their Difference
bool state = 0;

//Setup
void setup()
{
    //Select PIN 12
    pinMode(12, OUTPUT);
}

//Main
void loop()
{
    
    x1 = analogRead(A0);

    if (risingEdge(x1, x2))
    {
        state = !state;

        if (state == 1)
        {
            digitalWrite(12, HIGH);
        }
        else
        {
            digitalWrite(12, LOW);
        }
    }
    x2 = x1;
}

//Functions
bool risingEdge(int x1, int x2)
{
    int risingEdge = 512;
    int buttonDown = x1 - x2; // Measures rising edge of a pulse
    bool result = buttonDown > risingEdge;
    return result;
}