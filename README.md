# RCTank

Tank platform for different utilities.

Parts:
  * 3D printed parts were inspired from https://www.thingiverse.com/thing:2414983. I used Creality Ender 3 Printer with black PLA and PET-G filament
  * Screws, nuts and lock nuts were bought from https://shop.rocast.ro/index.php
  * Bearings were bought from https://magazin.undatech.ro/
  * I used 2 Sunnysky A2212 980KV Brushless Motor (CW and CCW) and 2 Emax Simonk 20A ESC bought from https://www.aliexpress.com
  * Remote controler: Quanum 2.4Ghz 3ch Pistol Grip Tx & Rx System bought from https://hobbyking.com/
  * The tank is powered by Turnigy 1400mAh 3S 65C Lipo Pack bought from https://hobbyking.com/
  * Arduino Nano V3.0 controller bought from https://www.aliexpress.com

Used software (all opensource):
  * OpenSCAD version 2015.03-2 from https://www.openscad.org/
  * Ultimaker Cura version 3..6.0 from https://ultimaker.com/en/products/ultimaker-cura-software
  * Arduino IDE version 1.8.7 from https://www.arduino.cc/en/Main/Software
  
My contribution to project is that i used an Arduino Nano controller to convert Throttle and Steer commands from Pistol Remote Controller (the normal commands for a car) in two independent commands for left and right Electric Speed Controllers (a tank driver uses two levers to send different commands for each side tracks).
