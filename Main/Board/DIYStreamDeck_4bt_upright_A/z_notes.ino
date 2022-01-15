/*----------------------------notes-------------------------*---*/
/*
 * Mode 0:
 *   Button LEDs disabled.
 *   Only glow LED.
 * 
 * Mode 1: 
 *   The button LEDs and the glow LED are on by default.
 *   When a button is pressed the button LED turns off.
 *   Using Glow-In-The-Dark PLA should give a short glow effect in the case.
 *   
 * Mode 2: 
 *   The button LEDs are off by default. The glow LED is on.
 *   When a button is pressed the button LED turns on.
 *   When the button is released there should be a short glow effect in the case.
 */
 
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
