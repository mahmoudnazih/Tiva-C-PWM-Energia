/*
Author: Mahmoud Zidan
Date: 13/06/2018

Purpose: Contains Several Functions to Make it Easy to Program the Tiva C board (tm4c123gh6pm)
----------------------------------------------------------------------------------------------
Functions:
-----------------
1-  void clockFreq(int freq)
 $$$    
      Sets the system clock it takes the desired system frequency in MHZ
      as an intger and runs the system clock at that frequency. The function returns nothing
      
     ***** Example ******
     #include "_BASE.h"
     void setup() { clockFreq(80);}
     void loop() { }
$$$

2-  void singlePWMSetup(int pinNumber)
 $$$
      Configures a pin as PWM output
      It takes a single parameter
            pinNumber: 28-29-30-31-57-58-1-4   stands for pins PF0-PF1-PF2-PF3-PB4-PB5-PB6-PB7 Respectively
            

          ***** Example ******
               #include "_BASE.h"
               void setup() { clockFreq(80);
               singlePWMSetup(1);
               }
               void loop() { }
          
          
           $$$

2-  void writePWM(int pinNumber,int pwmfreq, duty)
 $$$
      Configures a pin as PWM output
      It takes three parameters
            pinNumber: 28-29-30-31-57-58-1-4   stands for pins PF0-PF1-PF2-PF3-PB4-PB5-PB6-PB7 Respectively
            pwmfreq: PWM Frequency in HZ example (5000)
            duty: Duty ratio 0-1 as floating point data type

          ***** Example ******
               #include "_BASE.h"
               void setup() { clockFreq(80);
               singlePWMSetup(1);
               }
               void loop() { 
               writePWM(1,5000,.5)
               }
          
          
           $$$

*/







#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"

void clockFreq(int freq);
void singlePWMSetup(int pinNumber);
void writePWM(int pinNumber,int pwmfreq,float duty);

void clockFreq(int freq) {    // Set System Clock and PWM freq matches the system frequency
  switch (freq) {
    case (80):
      SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_2_5);
      break;
    case (66):
      SysCtlClockSet(SYSCTL_SYSDIV_3 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_3);
      break;
    case (50):
      SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_4);
      break;
    case (40):
      SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_5);
      break;
    case (33):
      SysCtlClockSet(SYSCTL_SYSDIV_6 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_6);
      break;
    case (28):
      SysCtlClockSet(SYSCTL_SYSDIV_7 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_7);
      break;
    case (25):
      SysCtlClockSet(SYSCTL_SYSDIV_8 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_8);
      break;
    case (22):
      SysCtlClockSet(SYSCTL_SYSDIV_9 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_9);
      break;
    case (20):
      SysCtlClockSet(SYSCTL_SYSDIV_10 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_10);
      break;
    case (18):
      SysCtlClockSet(SYSCTL_SYSDIV_11 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_11);
      break;
    case (16):
      SysCtlClockSet(SYSCTL_SYSDIV_12 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_12);
      break;
    case (15):
      SysCtlClockSet(SYSCTL_SYSDIV_13 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_13);
      break;
    case (14):
      SysCtlClockSet(SYSCTL_SYSDIV_14 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_14);
      break;
    case (13):
      SysCtlClockSet(SYSCTL_SYSDIV_15 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_15);
      break;
    case (12):
      SysCtlClockSet(SYSCTL_SYSDIV_16 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_16);
      break;
    default:
      SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
      SysCtlPWMClockSet(SYSCTL_SYSDIV_2_5);
  }
}

void singlePWMSetup(int pinNumber) {
  
  switch (pinNumber) {
    case (28):
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);          //Enable Port F
      SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);           // Set PWM Module 1
      GPIOPinConfigure(GPIO_PF0_M1PWM4);                    //PF0
      GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0);        //Configure pin as PWM
      PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC); //Configure PWM Options
     
     
    case (29):
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);          //Enable Port F
      SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);           // Set PWM Module 1
      GPIOPinConfigure(GPIO_PF1_M1PWM5);                    //PF1
      GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1);
      PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
     
    case (30):
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);          //Enable Port F
      SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);           // Set PWM Module 1
      GPIOPinConfigure(GPIO_PF2_M1PWM6);
      GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);          //PF2
      PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
     
    case (31):
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);          //Enable Port  F
      SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);           // Set PWM Module 1
      GPIOPinConfigure(GPIO_PF3_M1PWM7);
      GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_3);          //PF3
      PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
     
    case (58):
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);          //Enable Port B
      SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);           // Set PWM Module 0
      GPIOPinConfigure(GPIO_PB4_M0PWM2);
      GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4);          //PB4
      PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
      
    case (57):
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);          //Enable Port B
      SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);           // Set PWM Module 0
      GPIOPinConfigure(GPIO_PB5_M0PWM3);
      GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_5);          //PB5
      PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
     
    case (1):
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);          //Enable Port B
      SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);           // Set PWM Module 0
      GPIOPinConfigure(GPIO_PB6_M0PWM0);
      GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);          //PB6
      PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
      

    case (4):
      SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);          //Enable Port
      SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);           // Set PWM Module 0
      GPIOPinConfigure(GPIO_PB7_M0PWM1);
      GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);          //PB7
      PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_NO_SYNC);
      
  }
}

void writePWM(int pinNumber,int pwmfreq, float duty){
  
  unsigned long ulPeriod = SysCtlClockGet() / pwmfreq;
  switch (pinNumber) {
    case (28):
     
     
      PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, ulPeriod);          //Set the frequency
      PWMPulseWidthSet(PWM1_BASE, PWM_OUT_4,duty * ulPeriod);   //Set PWM duty
      PWMGenEnable(PWM1_BASE, PWM_GEN_2);                     // Enable the PWM generator
      PWMOutputState(PWM1_BASE, PWM_OUT_4_BIT, true);         // Turn on the Output pins
    case (29):
     
      PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, ulPeriod);
      PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,duty * ulPeriod);
      PWMGenEnable(PWM1_BASE, PWM_GEN_2);
      PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, true);
    case (30):
     
      PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, ulPeriod);
      PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,duty * ulPeriod);
      PWMGenEnable(PWM1_BASE, PWM_GEN_3);
      PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, true);
    case (31):
     
      PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, ulPeriod);
      PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,duty * ulPeriod);
      PWMGenEnable(PWM1_BASE, PWM_GEN_3);
      PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT, true);
    case (58):
      
      PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, ulPeriod);
      PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,duty * ulPeriod);
      PWMGenEnable(PWM1_BASE, PWM_GEN_1);
      PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true);
    case (57):
     
      PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, ulPeriod);
      PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,duty * ulPeriod);
      PWMGenEnable(PWM1_BASE, PWM_GEN_1);
      PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, true);
    case (1):
      
      PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, ulPeriod);
      PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,duty * ulPeriod);
      PWMGenEnable(PWM1_BASE, PWM_GEN_0);
      PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);

    case (4):
     
      PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, ulPeriod);
      PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1,duty * ulPeriod);
      PWMGenEnable(PWM1_BASE, PWM_GEN_1);
      PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, true);
  }
  
  
  
  }
