/*
 * Basic DIY Stream Deck, building from a project by Dave Madison ( https://github.com/dmadison )
 * MIT - Copyright (C) 2022  MTS Standish (Thurstan|mattKsp)
 * 
 *  Project     'Stream Cheap' Mini Macro Keyboard
 *  @author     David Madison
 *  @link       partsnotincluded.com/electronics/diy-stream-deck-mini-macro-keyboard
 *  @license    MIT - Copyright (c) 2018 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * 
 * https://github.com/mattThurstan/
 * 
 * Arduino compatible Pro Micro Atmega32U4 5V - USB powered (500mA max)
 * Cherry MX Blue keyboard switches
 * 
 */


/*----------------------------libraries-------------------------*/
#include "Keyboard.h"

/*----------------------------system----------------------------*/
const String _progName = "DIYStreamDeck";
const String _progVers = "0.21";              // Mode 0 - Glow
bool DEBUG_GEN = false;                       // general
bool DEBUG_USERINPUT = false;                 // user input 
bool DEBUG_BUTTON = false;                    // button input
bool DEBUG_TOUCH = false;                     // touch input
bool DEBUG_DISPLAY = false;                   // display output

/*----------------------------display---------------------------*/
//const uint8_t _ledPin = 17;                 // LED 0 - RX pin used as LED output

#define MODE0                                 // Only 1 mode active at a time. ever. savvy?
//#define MODE1
//#define MODE2

//#ifdef MODE1 || MODE2
#if defined(MODE1) || defined(MODE2)
const uint8_t _btLedNum = 4;                  // number of button LED's
const uint8_t _btLedPin[_btLedNum] = { 11, 12, 13, 14 };
uint8_t _loopBtLedNum = _btLedNum;            // The number of button LED's to cycle through during a main loop.
bool _btLedEnabled = true;                    // Button LEDs on/off override.
#endif

const uint8_t _glowLedPin = 10;               // bottom glow LED
//uint8_t _glowAmount = 128;                    // Glow amount. For now using single on/off resistor limited LEDs.
bool _glowEnabled = false;                    // Glow on/off override.


/*----------------------------buttons---------------------------*/
// Pin definitions
#define BUTTON_PIN1 2                         // board pin output numbers
#define BUTTON_PIN2 3
#define BUTTON_PIN3 4
#define BUTTON_PIN4 5

// Key definitions
#define BUTTON_KEY1 KEY_F13
#define BUTTON_KEY2 KEY_F14
#define BUTTON_KEY3 KEY_F15
#define BUTTON_KEY4 KEY_F16

/* 
 * Button helper class for handling press/release and debouncing. 
 */
class button {
  public:
  const char key;
  const uint8_t pin;
  boolean pressed = 0;
  boolean hasChanged = 0;

  button(uint8_t k, uint8_t p) : key(k), pin(p){}

  void press(boolean state){
    if(state == pressed || (millis() - lastPressed  <= debounceTime)){
      hasChanged = 0;
      return; // Nothing to see here, folks
    }

    lastPressed = millis();
    hasChanged = 1;

    state ? Keyboard.press(key) : Keyboard.release(key);    
    pressed = state;
  }

  void update(){
    press(!digitalRead(pin));
  }

  private:
  const unsigned long debounceTime = 30;
  unsigned long lastPressed = 0;
} ;

/* 
 *  Button objects, organized in array.
 */
button _buttons[] = {
  {BUTTON_KEY1, BUTTON_PIN1},
  {BUTTON_KEY2, BUTTON_PIN2},
  {BUTTON_KEY3, BUTTON_PIN3},
  {BUTTON_KEY4, BUTTON_PIN4}
};
const uint8_t _buttonNum = sizeof(_buttons) / sizeof(button);

/*----------------------------touch sensors---------------------*/


/*----------------------------main------------------------------*/
void setup() { 
  safetyCheck();
  setupUserInput();
  setupDisplay();
}

void loop() {
  loopUserInput();                            // User Input has to be before Display!
  loopDisplay();
}
