#include <stdio.h>
#include "degree.h"


int main(){
int choose;
double celsius,fahrenheit,kelvin;
int flag=0;
while(1){
if(flag==1){
break;
}
printf("1.Convert to Fahrenheit (Enter Celsius degree)\n2.Convert to Celsius (Enter Fahrenheit degree)\n3.Convert to Kelvin (Enter Celsius degree)\n0.Choose if you want to exit\n");
printf("Choose an option (1,2,3 or 0 to exit):");
scanf("%d",&choose);

switch(choose){

case 1:
	printf("Enter Celsius degree:");
	scanf("%lf",&celsius);
	celsius_to_fah_kel(celsius, &fahrenheit,&kelvin);
	print_temperatures(celsius,fahrenheit,kelvin);
	break;
case 2:
	printf("Enter Fahrenheit degree:");
	scanf("%lf",&fahrenheit);
	fahrenheit_to_cel_kel(fahrenheit,&celsius,&kelvin);
	print_temperatures(celsius,fahrenheit,kelvin);
	break;
case 3:
	printf("Enter Kelvin degree:");
	scanf("%lf",&kelvin);
	kelvin_to_cel_fah(kelvin,&celsius,&fahrenheit);
	print_temperatures(celsius,fahrenheit,kelvin);
	break;
case 0:
	printf("Exiting programi...");
	flag=1;
	break;
default:
printf("Try again");
break;
}

}

return 0;
}
