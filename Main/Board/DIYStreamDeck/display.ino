/*----------------------------display----------------------------*/
/*
 * Setup all the LED's, also used to reset all the LED's.
 */
void setupLED() {
  //for(int i = 0; i < LED_NUM; i++) {
  for(int i = 0; i < 1; i++) {     // TEMP until more than 1 LED and array gets more entries.
    pinMode(_ledPin[i], OUTPUT);              // Set LEDs Off. Active low.
    digitalWrite(_ledPin[i], HIGH);
  }
  
  //TXLED0; // Prebuilt command to turn Off inbuilt LED 0 (TXLED1 to turn On).
  //RXLED0; // Prebuilt command to turn Off inbuilt LED 1 (RXLED1 to turn On).
}

void setupDisplay() {
  setupLED();
  if (_loopLedNum > _buttonNum) { _loopLedNum = _buttonNum; } // Catch out-of-bounds - LED number for main loop.
}


void loopDisplay() {
  //for(int i = 0; i < _loopLedNum; i++){
  for(int i = 0; i < 1; i++) {     // TEMP until more than 1 LED and array gets more entries.
    if (_buttons[i].hasChanged == 1) {
      if (_buttons[i].pressed == 1) { 
        digitalWrite(_ledPin[i], LOW);        // turn On
      } else { 
        digitalWrite(_ledPin[i], HIGH);       // turn Off
      }
    }
  }
}

/*---------------------------------------------------------------*/
//
