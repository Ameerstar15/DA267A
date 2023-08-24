#include "pins.h"
#include "driver/gpio.h"
#include <esp32/rom//ets_sys.h>


/* initialises the 4 pins*/
#define LEDA 12;
#define LEDB 14;
#define ButtonA 26;
#define ButtonB 27;

void initPins()
{
    // init the 2 LEDs pins as output and the 2 buttons pins as input 
    // you will need to use gpio_config()

    gpio_config_t configLEDA;
    configLEDA.pin_bit_mask = (u_int64_t) 1 << LEDA;
    configLEDA.mode = GPIO_MODE_OUTPUT;
    configLEDA.pull_down_en = 0;
    configLEDA.pull_up_en = 0;
    gpio_config(&configLEDA);

    gpio_config_t configLEDB;
    configLEDB.pin_bit_mask = (u_int64_t)1 << LEDB;
    configLEDB.mode = GPIO_MODE_OUTPUT;
    configLEDB.pull_down_en = 0;
    configLEDA.pull_up_en = 0;
    gpio_config(&configLEDB);

    gpio_config_t configButtonA;
    configButtonA.pin_bit_mask = (u_int64_t) 1 << ButtonA;
    configButtonA.mode = GPIO_MODE_INPUT;
    configButtonA.pull_down_en = 0;
    configButtonA.pull_up_en = 1;
    gpio_config(&configButtonA);

    gpio_config_t configButtonB;
    configButtonB.pin_bit_mask = (u_int64_t)1 << ButtonB;
    configButtonB.mode = GPIO_MODE_INPUT; 
    configButtonB.pull_down_en = 0;
    configButtonB.pull_up_en = 1;
    gpio_config(&configButtonB);

}

// switches LEDA on if level!=0 and off if level=0 
void setLEDA(uint8_t level)
{
    if(level)
    {
       gpio_set_level(12, 1);  
    
    }
    else 
    {
        gpio_set_level(12, 0); 
    }
}

// switches LEDB on if level!=0 and off if level=0 
void setLEDB(uint8_t level)
{
    if(level)
    {
       gpio_set_level(14, 1);  

    }
    else 
    {
        gpio_set_level(14, 0); 
    }
}

// tells if button A is being pressed 
uint8_t isButtonAPressed()
{
   // int BUTTONA = gpio_get_level(26); 
    // read the value of button A
    // if using a pull up, the button is pressed when the pin is LOW
    if(gpio_get_level(26) == 0)
    {
        return 1; // button is pressed
    }
    else if(gpio_get_level(26) == 1)
    {
        return 0; // button isnt pressed
    }
}

// tells if button B is being pressed 
uint8_t isButtonBPressed()
{
    // read the value of button B
    //if using a pull up, the button is pressed when the pin is LOW 
    if(gpio_get_level(27)== 0) 
    {
        return 1; // button is pressed
    }
    else if(gpio_get_level(27) == 1)
    {
        return 0; // button isnt pressed
    }
}
