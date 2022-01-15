/*----------------------------user input----------------------------*/
void setupUserInput() {
  for(int i = 0; i < _buttonNum; i++){
    pinMode(_buttons[i].pin, INPUT_PULLUP);
  }
  Keyboard.begin();                           // Initialize control over the keyboard - is this just setup or does it actually take over the keyboard???
}

/*
 * e.g. In OBS map the keys within ' Settings / Hotkeys '
 * In OBS set the following ' Settings / Advanced / Hotkeys / Hotkey Focus Behaviour - Never disable hotkeys '
 * 
 * Keyboard.write(KEY_RETURN); // This is for the Enter/Return key if ever needed. 'Write' emulates pressing and releasing a key.
 * 
 * Keyboard.press(F20);
 * Keyboard.press(KEY_LEFT_SHIFT);
 * 
 * ------e.g. Ctrl-Alt-Delete------
 * Keyboard.press(KEY_LEFT_CTRL);
 * Keyboard.press(KEY_LEFT_ALT);
 * Keyboard.press(KEY_DELETE);
 * delay(1000);
 * Keyboard.releaseAll();
 * 
 * delay(2000);
 * Keyboard.press(KEY_LEFT_ALT);
 * Keyboard.press('l');
 * Keyboard.releaseAll();
 * 
 */

void loopUserInput() {
  for(int i = 0; i < _buttonNum; i++){
    _buttons[i].update();
  }
}
