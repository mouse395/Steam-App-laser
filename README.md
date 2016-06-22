# Steam-App-laser

This Script is an Arduino based Laser Motion Sensor.

The way it works is that a photoresistor picks up an initial value of a laser pointing at it.
After 5 milliseconds, it starts to refresh a new value constantly. If the initial value and the new value are different,
then it will cause an LED to light up, and also print to the LCD screen that motion has been detected. It will continue to
print that there is motion detected until there is no longer obstruction between the laser and the photoresistor.

The program outputs the signal data to the console. It gets an analog read from 0 - 1024.