/*----------------------------display---------------------------*/
/* 
 *  Main display setup.
 *  Setup all the LED's, also used to reset all the LED's.
 */
  //TXLED0; // Prebuilt command to turn Off inbuilt LED 0 (TXLED1 to turn On).
  //RXLED0; // Prebuilt command to turn Off inbuilt LED 1 (RXLED1 to turn On).
  
void setupDisplay() {
  
#if defined(MODE1) || defined(MODE2)
  /* Setup button LED's. */
  //for(int i = 0; i < _btLedNum; i++) {
  for(int i = 0; i < 1; i++) {                // TEMP until more than 1 LED and array gets more entries.
    pinMode(_btLedPin[i], OUTPUT);            // Set LED's Off. Active low.
    digitalWrite(_btLedPin[i], HIGH);
  }

  if (_loopBtLedNum > _buttonNum) { _loopBtLedNum = _buttonNum; } // Catch out-of-bounds - LED number for main loop.
#endif
  
  if (_glowEnabled == true) {
    /* Setup bottom glow LED. */
    pinMode(_glowLedPin, OUTPUT);              // Set LED Off. Active low.
    digitalWrite(_glowLedPin, HIGH);
  }
  
}

/*---------------------------------------------------------------*/
/*
 * Main display loop.
 */
void loopDisplay() {
  
  /* Loop button LED's. */
#ifdef MODE1
  if (_btLedEnabled == true) {
    //for(int i = 0; i < _loopBtLedNum; i++){
    for(int i = 0; i < 1; i++) {     // TEMP until more than 1 LED and array gets more entries.
      if (_buttons[i].hasChanged == 1) {
        if (_buttons[i].pressed == 1) { 
          digitalWrite(_btLedPin[i], HIGH);       // turn Off
        } else { 
          digitalWrite(_btLedPin[i], LOW);        // turn On
        }
      }
    }
  }
#elif MODE2
  if (_btLedEnabled == true) {
    //for(int i = 0; i < _loopBtLedNum; i++){
    for(int i = 0; i < 1; i++) {     // TEMP until more than 1 LED and array gets more entries.
      if (_buttons[i].hasChanged == 1) {
        if (_buttons[i].pressed == 1) { 
          digitalWrite(_btLedPin[i], LOW);        // turn On
        } else { 
          digitalWrite(_btLedPin[i], HIGH);       // turn Off
        }
      }
    }
  }
#endif
  
  /* Loop bottom glow LED. */
  if (_glowEnabled = true;) {
    digitalWrite(_glowLedPin, LOW);        // turn On
  } else {
    digitalWrite(_glowLedPin, HIGH);       // turn Off
  }
  
}

/*---------------------------------------------------------------*/
void setGlowLedAmount(uint8_t amount) { }
