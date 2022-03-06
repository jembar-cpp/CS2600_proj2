/**
 * @file VehicleExpenses.c
 * @author Conner Ramirez
 * 
 *  * vehicleExpenses.c: asks for and returns:
 *  - total amount spent on round-trip airfare
 *  - total amount of any car rentals
 *  - miles driven in a private vehicle (returns amount: miles * $0.27)
 *  - parking fees
 *  - taxi expenses
 */


#include <stdio.h>

int main() {

float airfare, rental, miles, fees, taxi; 


printf("Total Spent on Airfare: $");
scanf("%f",&airfare);

printf("Total Spent on Car Rental: $");
scanf("%f",&rental);

printf("Total Miles Driven: $");
scanf("%f",&miles);

printf("Total Spent on Parking: $");
scanf("%f",&fees);

printf("Total Spent on Taxi': $");
scanf("%f",&taxi);

//while(airfare < 0 )
  // printf("Please provide a positive value.");
  
float mTotal;

mTotal = miles * 0.27; 

printf("-------------------------------------------");

printf("Total Airfare: $%.2f",airfare);
printf("Total Car Rental: $%.2f",rental);
printf("Total Miles Cost: $%.2f",mTotal);
printf("Total Parking Fees: $%.2f",fees);
printf("Total Taxi Cost: $%.2f",taxi);

return 0;
}