#include "temperature.h"
#include <stdio.h>
#include <string.h>

//function celsius_to_fahrenheit
// param: float celsius
// returns a float
float celsius_to_fahrenheit(float celsius){
    return ((celsius * (9.0/5.0)) + 32.0); //returns conversion from celsius to fahrenheit
}

//function fahrenheit_to_celsius
// param: float fahrenheit
// returns a float
float fahrenheit_to_celsius(float fahrenheit){
    return ((fahrenheit - 32.0) * (5.0/9.0)); //returns conversion from fahrenheit to celsius
}

//function celsius_to_kelvin
// param: float celsius
// returns a float
float celsius_to_kelvin(float celsius){
    return (celsius + 273.15); //returns conversion from celsius to kelvin
}

//function kelvin_to_celsius
// param: float kelvin
// returns a float
float kelvin_to_celsius(float kelvin){
    return (kelvin - 273.15); //returns conversion from kelvin to celsius
}

//function categorize_temperature
// param: float celsius
// returns nothing
void categorize_temperature(float celsius){
    if (celsius < 0.0){ //if True Freezing: Below 0°C (or equivalent in other scales)
        printf("It's freezing. Stay indoors!");
    } else if (celsius >= 0.0 && celsius < 10.0){ //if True Cold: 0°C to 10°C (or equivalent)
        printf("Wear a coat.");
    } else if (celsius >= 10.0 && celsius < 25.0){ //if True Comfortable: 10°C to 25°C (or equivalent)
        printf("Wear a jacket.");
    } else if (celsius >= 25.0 && celsius < 35.0){ //if True Hot: 25°C to 35°C (or equivalent)
        printf("Wear a t-shirt and shorts.");
    } else { //if True Extreme Heat: Above 35°C (or equivalent)
        printf("Go swimming or stay in the shade.");
    }
}
