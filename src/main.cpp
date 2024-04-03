#include <Arduino.h>
// #include <Keyboard.h>
#include <Adafruit_NeoPixel.h>

#define BTN_PIN 27
#define LED_PIN 16

Adafruit_NeoPixel led = Adafruit_NeoPixel(1, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  led.begin();
  // Keyboard.begin();
  pinMode(BTN_PIN, INPUT_PULLUP);
}

int lastState;

void loop()
{
  int currentState = digitalRead(BTN_PIN);
  if (lastState != currentState)
  {
    if (currentState)
    {
      led.setPixelColor(0, led.Color(0, 0, 0));
      led.show();
    }
    else
    {
      led.setPixelColor(0, led.Color(255, 0, 0));
      led.show();
    }
    lastState = currentState;
  }
  delay(50);
}