# esp32_disconnect_autoconnect
This code helping people to make ESP32 autoconnect to network, when ESP32 suddenly disconnected

# principle work of code
When ESP32 suddenly disconnected from network, ESP32 try to re-connect into the same network.
In this code, i using personal hotspot from smartphone to build network between ESP32 and browser
so i can simulate the code by turning off hotspot.
The code using 2 led to as output, and yap this featured inserted for testing ESP32's function

but, if last condition (before disconnected) is on "modeaa", 1 of LEDs is on

# Status callback
in Wifi section code, i using code for callback, here are translataion of status callback wifi esp32

![status call back wifi esp32](https://user-images.githubusercontent.com/63993989/218284787-c4e90413-83f7-4b75-9d2d-717e0197d767.png)

#Testimony

I already create video on YouTube for this program , so just visit here https://youtu.be/AbPoul6Q7_M
