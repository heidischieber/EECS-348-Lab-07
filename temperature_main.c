#include "temperature.h"
#include "temperature.c"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    float temp; // Initialize temp as a float value
    char original_scale[11]; // Initialize original_scale as an array of characters with size 10
    char conversion_scale[11]; // Initialize conversion_scale as an array of characters with size 10

    printf("Enter the temperature: ");//user inputs temp
    //to handle error of user inputting the wrong type i discovered throug chatGPT that
    //if scanf does not return a 1 then the correct type was not stored
    if (scanf("%f", &temp) != 1){ //stores user input in temp and if True then wrong type inputted by user
        printf("Invalid type.\n"); //display error
        return 0; //return to quit program
    }

    printf("Enter the temperature scale of the input value (Fahrenheit, Celsius, or Kelvin): ");//user inputs original scale
    if (scanf("%s", original_scale) != 1){ //stroes user input in orginal_scale and if True then wrong type inputted by user
        printf("Invalid type.\n"); //display error
        return 0; //return to quit program
    }

    printf("Enter the conversion scale of the input value (Fahrenheit, Celsius, or Kelvin): ");//user inputs conversion scale
    if (scanf("%s", conversion_scale) != 1){ //stores user input in conversion_scale and if True then wrong type inputted by user 
        printf("Invalid type.\n"); //display error
        return 0; //return to quit program
    }
    

    // error handling of possible invalid input for original_scale and conversion_scale
    if ((strcmp(original_scale, "Fahrenheit") != 0 && strcmp(original_scale, "Celsius") != 0 && strcmp(original_scale, "Kelvin") != 0) ||
        (strcmp(conversion_scale, "Fahrenheit") != 0 && strcmp(conversion_scale, "Celsius") != 0 && strcmp(conversion_scale, "Kelvin") != 0)) {
        printf("Invalid temperature scale.\n"); //display error
        return 0; // return 0 to exit program if error occurs
    }
    
    float result; //initializes result as a float value ~ this will store the result of the conversion
    int t; //temp variable for conversion when using Kelvin

    if (strcmp(original_scale, "Fahrenheit") == 0){ //evaluates as True if orignal_scale is equal to "Fahrenheit"
        if (strcmp(conversion_scale, "Celsius") == 0){ //evaluates as True if conversion_scale is equivalent to "Celsius"
            result = fahrenheit_to_celsius(temp); //performs conversion from Fahrenheit to Celsius and stores it in result
        } else if (strcmp(conversion_scale, "Kelvin") == 0){ //evaluates as True if orignal_scale is equal to "Kelvin"
            t = fahrenheit_to_celsius(temp); //performs conversion from Fahrenheit to Celsius and stores it in t
            result = celsius_to_kelvin(t); //performs conversion from Celsius to Kelvin and stores it in result
        } else{ //the following runs if none of the above if statements are True
            result = temp; //stores temp in result
        }
    } else if (strcmp(original_scale, "Celsius") == 0){ //evaluates as True if orignal_scale is equal to "Celsius"
        if (strcmp(conversion_scale, "Fahrenheit") == 0){ //evaluates as True if conversion_scale is equivalent to "Fahrenheit"
            result = celsius_to_fahrenheit(temp); //performs conversion from Celsius to Fahrenheit and stores it in result
        } else if (strcmp(conversion_scale, "Kelvin") == 0){ //evaluates as True if orignal_scale is equal to "Kelvin"
            result = celsius_to_kelvin(temp); //performs conversion from Celsius to Kelvin and stores it in result
        } else{ //the following runs if none of the above if statements are True
            result = temp; //stores temp in result
        }
    } else if (strcmp(original_scale, "Kelvin") == 0){ //evaluates as True if orignal_scale is equal to "Kelvin"
        if (strcmp(conversion_scale, "Fahrenheit") == 0){ //evaluates as True if conversion_scale is equivalent to "Fahrenheit"
            t = kelvin_to_celsius(temp); //performs conversion from Kelvin to Celsius and stores it in t
            result = celsius_to_fahrenheit(t); //performs conversion from Celsius to Fahrenheit and stores it in result
        } else if (strcmp(conversion_scale, "Celsius") == 0){ //evaluates as True if conversion_scale is equivalent to "Celsius"
            result = kelvin_to_celsius(temp); //performs conversion from Kelvin to Celsius and stores it in result
        } else{ //the following runs if none of the above if statements are True
            result = temp; //stores temp in result
        }
    }

    //the following code will display the temp and a weather advisory
    printf("The temp is %.2f in %s\n", result, conversion_scale); //prints the converted temp and it's new scale
    float in_celsius; //initalizes float variable in_celsius
    if (strcmp(conversion_scale, "Fahrenheit") == 0){ //True if conversion_scale is "Fahrenheit"
        in_celsius = fahrenheit_to_celsius(result); //in_celsius stores conversion from Fahrenheit to Celsius
    } else if (strcmp(conversion_scale, "Kelvin") == 0){ //True if conversion_scale is "Kelvin"
        in_celsius = kelvin_to_celsius(result); //in_celsius stores conversion from Kelvin to Celsius
    } else{ //True if already in Celsius
        in_celsius = result; //sets in_celsius equal to result
    }
    categorize_temperature(in_celsius); //calls categorize_temperature function with paramter in_celsius
    
    return 0; //return nothing
}
