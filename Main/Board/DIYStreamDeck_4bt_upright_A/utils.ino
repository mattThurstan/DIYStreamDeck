/*----------------------------utils-----------------------------*/
/*
 * Check grounding via pin at startup to identiy if anything electrical has gone wrong.
 * Ground pin #1 (RX) to cancel keyboard inputs.
 */
void safetyCheck() {
  pinMode(1, INPUT_PULLUP);
  if(!digitalRead(1)){
    failsafe();
  }
}
/*
 * Failsafe infinite loop function, for use in case of hardware error.
 */
void failsafe() {
  panic();
  for(;;){}                                   // "Just going to hang out here for awhile :D"
}
/*
 * Stay calm and reset everything.
 */
 void panic() {
  Keyboard.releaseAll();
  setupLED();                                 // reset all LED's
 }
