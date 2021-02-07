## digispark
Attiny85/digispark payload, that uses Invoke-Mimikatz to dump credentials and exports the systems wifi-passwords. All data is sent to you via email. The payload is available for en/us and german keyboard layout.

### Change the digispark keyboard layout to german
#### This method of course applies to other layouts
By default digispark uses the en/us keyboard layout. The easiest way I found was to include a modified header file. 

* Download DigiKeyboard.h from this repo or https://github.com/adnan-alhomssi/DigistumpArduinoDe/blob/master/digistump-avr/libraries/DigisparkKeyboard/DigiKeyboardDe.h.
* Copy the file to _%localappdata%\Arduino15\packages\digistump\hardware\avr\1.6.7\libraries\DigisparkKeyboard\_.
* Replace _#include "DigiKeyboard.h"_ with _#include "DigiKeyboardDe.h" in your script_.
* Find and replace every instance of _DigiKeyboard.println_ with _DigiKeyboardDe.println_ (if required).
* Find and replace every instance of _DigiKeyboard.sendKeyStroke_ with _DigiKeyboardDe.sendKeyStroke_ (if required).

### Using gmail to send results
Go to your GoogleMail security settings and generate an app-password. You can use this password in the script.

Happy ducking!


#### Credits:

* @thecybermentor - https://youtu.be/uH-4btjE56E
* https://github.com/MTK911/Attiny85/tree/master/payloads
* https://github.com/adnan-alhomssi/DigistumpArduinoDe
