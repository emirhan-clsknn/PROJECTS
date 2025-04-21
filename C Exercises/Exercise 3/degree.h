#include <stdio.h>

void celsius_to_fah_kel(double celsius, double *fahrenheit, double *kelvin) {
    *fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    
    *kelvin = celsius + 273.15;
    
}

void fahrenheit_to_cel_kel(double fahrenheit, double *celsius, double *kelvin) {
   
    *celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
   
    *kelvin = (*celsius) + 273.15;
}

void kelvin_to_cel_fah(double kelvin, double *celsius, double *fahrenheit) {
    
    *celsius = kelvin - 273.15;
    
    *fahrenheit = (*celsius) * 9.0 / 5.0 + 32.0;
}

void print_temperatures(double celsius, double fahrenheit, double kelvin) {
    printf("The degree in Celsius: %.2lf\n", celsius);
    printf("The degree in Fahrenheit: %.2lf\n", fahrenheit);
    printf("The degree in Kelvin: %.2lf\n", kelvin);
}


