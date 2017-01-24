ArduboyMouse
============

Use your Arduboy as a 2-button mouse!

![Photo of Arduboy running ArduboyMouse](https://github.com/alxm/arduboy-mouse/raw/master/arduboymouse.png "Photo of Arduboy running ArduboyMouse")

Uses the [Arduboy2](https://github.com/MLXXXp/Arduboy2) and [Mouse](https://www.arduino.cc/en/Reference/MouseKeyboard) libraries, builds with Arduino IDE 1.8.1.

To generate `mousegfx.h`, run the included Python script:

```sh
$ python3 ArduboyImage.py mouse.png mouse > mousegfx.h
```

License
-------

Copyright 2017 Alex Margarit (alex@alxm.org)

* Code licensed under [GNU GPL3](https://www.gnu.org/licenses/gpl.html)
* Graphics licensed under [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/)
