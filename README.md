# Hedgehog Bot
## Prerequisites

* [CH340 Drivers](http://www.nerdkits.com/usb-serial/ch341.php)

## Installation
### Windows or Mac OS X
1. Copy `hedgehog_blink`, `hedgehog_bot`, and `hedgehog_wifi` into your Arduino sketchbook folder
2. Copy the folders in `libraries` to the `libraries` folder in your Arduino
   sketchbook folder, if it doesn't already exist you can just copy and paste
   the `libraries` folder straight into the sketchbook folder.
3. Verify that when you run the Arduino IDE and click the menu options `File -> Sketchbook`
   you can now see:
   - `hedgehog_blink`
   - `hedgehog_bot`
   - `hedgehog_wifi`

### Raspberry Pi (Linux)

```sh
$ git clone --recursive git@github.com:MVSE-Outreach/arduino-hedgehog-bot.git hedgehog-bot
$ cd hedgehog-bot
$ ./install.sh <PATH-TO-ARDUINO-SKETCHBOOK>
```
## Known issues
- Arduino Nano not recognised: Have you installed CH340 drivers?
- WiFi not working: Test 9V battery
