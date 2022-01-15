/*----------------------------user input------------------------*/
void setupUserInput() {
  for(int i = 0; i < _buttonNum; i++){
    pinMode(_buttons[i].pin, INPUT_PULLUP);
  }
  Keyboard.begin();                           // Initialize control over the keyboard - is this just setup or does it actually take over the keyboard???
}



/*---------------------------------------------------------------*/
void loopUserInput() {
  for(int i = 0; i < _buttonNum; i++){
    _buttons[i].update();
  }
}
