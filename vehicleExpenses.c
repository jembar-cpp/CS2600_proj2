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

do
{
 printf("Total Spent on Airfare: $");
scanf("%f",&airfare);

if (airfare < 0)
printf("Please enter a Positive Number!\n");

} while (airfare < 0);

do
{
 printf("Total Spent on Car Rental: $");
scanf("%f",&rental);

if (rental < 0)
printf("Please enter a Positive Number!\n");

} while (rental < 0);

do
{
 printf("Total Miles Driven: $");
scanf("%f",&miles);

if (miles < 0)
printf("Please enter a Positive Number!\n");

} while (miles < 0);

do
{
printf("Total Spent on Parking: $");
scanf("%f",&fees);

if (fees < 0)
printf("Please enter a Positive Number!\n");

} while (fees < 0);

do
{
printf("Total Spent on Taxi': $");
scanf("%f",&taxi);

if (taxi < 0)
printf("Please enter a Positive Number!\n");

} while (taxi < 0);

  
float mTotal;

mTotal = miles * 0.27; 

printf("-------------------------------------------\n");

printf("\nTotal Airfare: $%.2f",airfare);
printf("\nTotal Car Rental: $%.2f",rental);
printf("\nTotal Miles Cost: $%.2f",mTotal);
printf("\nTotal Parking Fees: $%.2f",fees);

if ( fees > 6 )
    printf( " Parking Fees over $6 a day you must pay out of pocket." );

printf("\nTotal Taxi Cost: $%.2f",taxi);

if ( taxi > 10 )
    printf( " Taxi Fees over $10 a day you must pay out of pocket." );

return 0;
}