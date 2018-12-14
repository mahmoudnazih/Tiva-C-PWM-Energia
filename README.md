# Tiva-C-PWM-Energia
Author: Mahmoud Zidan
Purpose: This Project is made to Setup and Control PWM pins of Tiva C (tm4c123gh6pm) With Energia

----------------------
|NOTE: Not tested yet|
----------------------

It is supposed to allow the user to do the following:

1- User can set the frequency and the desired duty ratio instead of the fixed frequency of the analogWrite() function in Energia
Check the top of the _BASE.h file for pin numbering

2- User can use a complement of PWM on two pins with deadband inserted

Usage:

Method 1
--------

    1- Downlaod _BASE.h file or Copy the code inside
    2- Add the file to your project directory   
    3- At the top of the project file add the following
        #include "_BASE.h"
      
Method 2
--------

      
      You Can Just copy the code and open a new tab in enegia, Past the code in the new tab, save it with any name you want
      then add #include "filename.h" to your working file
