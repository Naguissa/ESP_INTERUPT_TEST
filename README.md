## ESP8266 and ESP pin interrupt example ##

This Arduino sketch implements properly a simple pin change interrupt on any ESP microcontroller (ESP8266 and ESP32).

Note that it's not using any debouncing, for buttons it's better to use any dedicated library. It's only a correct implementation example.


### Configuration ###

You can change test pin changing BUTTON_PIN define.

It's configured as INPUT_PULLUP, so to trigger it you have to connect it to ground.


### Compilation ###

You can compile the sketch using Arduino IDE with ESP8266 or ESP32 support.


### Usage ###

Input pin is configured as INPUT_PULLUP, so to trigger it you have to connect it to ground.

It will differentiate between short and long press (> 1s pressed).



### Hardware ###

No extra hardware is needed, except for power supply and a cable to connect input pin to GND.


## Who do I talk to? ##

 * [Naguissa](https://github.com/Naguissa)
 * https://www.foroelectro.net/electronica-digital-microcontroladores-f8/sencillo-ejemplo-de-manejo-de-interrupciones-en-ar-t418.html
 * https://www.naguissa.com



## Contribute ##

Any code contribution, report or comment are always welcome. Don't hesitate to use GitHub for that.


 * You can sponsor this project using GitHub's Sponsor button: https://github.com/Naguissa/ESP_INTERUPT_TEST
 * You can make a donation via PayPal: https://paypal.me/foroelectro


Thanks for your support.


Contributors hall of fame: https://www.foroelectro.net/hall-of-fame-f32/contributors-contribuyentes-t271.html
