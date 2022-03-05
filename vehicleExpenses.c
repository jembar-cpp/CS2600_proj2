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

//while(airfare < 0 )
  // printf("Please provide a positive value.");
  

printf("Total Airfare: $%.2f",airfare);
return 0;
