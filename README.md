# DIYStreamDeck
Basic DIY Stream Deck, building from a project by [Dave Madison](https://github.com/dmadison)

Building on the notion that although the Stream Deck is a very nice unit, it is expensive and far too over-speced for my needs. All I really require are a few buttons (and mabye some LED's to illuminate them). The starting point for this is a [post by Dave Madison](https://www.partsnotincluded.com/diy-stream-deck-mini-macro-keyboard/) showing how he built a basic 8-button keyboard in a 3d printed enclosure. The unit is powered by a small Arduino, connects to a PC via USB and when pressed send key presses to the operating system. The unit sends the funtion keys F13 to F20 which are normally not used on keyboards and can be easily mapped within the software (e.g. OBS).

I would like to add LED features in future revisions (glow lighting and feedback for keys) and also design a new case to fit one of the risers on my desk.


### Usage
#### Unit setup
- Connect to PC via USB (automatically recognised as a keyboard device - currently windows as have no mac to test)
- USB powered (500mA max)

#### OBS setup
- map the keys within ' Settings / Hotkeys '
- set the following ' Settings / Advanced / Hotkeys / Hotkey Focus Behaviour = Never disable hotkeys '

### Equipment
#### Hardware
- Arduino compatible Pro Micro (pretty sure this isn't genuine)
--ATmega32U4 running at 5V/16MHz<br>
18 available pins<br>
9x 10-bit ADC pins<br>
12x Digital I/Os (5 are PWM capable)<br>
Rx and Tx Hardware Serial Connections
- Cherry MX Blue keyboard switches (are these genuine? who knows?)
- Re-legendable MX compatible keycaps
- 3d printed enclosure
- Printed images for keys

#### Software
https://github.com/arduino/Arduino

### Licence
MIT - Copyright (C) 2022  MTS Standish (Thurstan|mattKsp).<br>
MIT Licence as specified in original code by Dave Madison (2018).

### Reference
https://www.partsnotincluded.com/diy-stream-deck-mini-macro-keyboard/
https://www.thingiverse.com/thing:2822140
https://github.com/dmadison

https://www.ebay.co.uk/itm/384272212145
https://www.ebay.co.uk/itm/154317278405
https://shop.pimoroni.com/products/relegendable-mx-compatible-keycaps-pack-of-16

https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide
