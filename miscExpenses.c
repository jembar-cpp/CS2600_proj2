/*
 * CS 2600 Project 2 (Group) - Travel Expenses
 * miscExpenses.c: asks for and returns:
 *  - conference or seminar registration fees
 *  - total hotel expenses
*/

#include <stdio.h>


int main()
{

    // Declare variables needed
    float totalSaved, totalExcess;
    float nights, hotelFee, semFee, totalHotelCost;
    float allowedHotelCost;
    float allowedPerNight = 90;

    // Asks user for input of hotel fee per night, and total amount of nights at hotel
    printf("Enter the hotel fee per night: $");
    scanf("%f", &hotelFee);
    
    printf("Enter total nights at hotel: ");
    scanf("%f", &nights);

    printf("Enter total of seminar/conference fees: $");
    scanf("%f", &semFee);

    // Calculates costs of both allowed total and total businessperson spent
    totalHotelCost = hotelFee * nights;
    allowedHotelCost = allowedPerNight * nights;

    
    // Checks for hotelFee only, so rest of calcs are easier to check 
    if (hotelFee <= 89.99)
    {
        totalSaved = allowedHotelCost - totalHotelCost;
        printf("You saved: $%.2f\n", totalSaved);
        printf("Total Cost with seminar: $%.2f\n", (totalSaved + semFee));
    }
    else if (hotelFee >= 90.99)
    {
        totalExcess = fabs(totalHotelCost - allowedHotelCost);
        printf("total cost is more than allowed, so we over spent: $%.2f\n", totalExcess);
        printf("Total Cost with seminar: $%.2f\n", (totalExcess + semFee));
    }
    else
    {  
        printf("The company gave you the exact amount you needed! (for hotels)\n");
        printf("Total Cost for hotel and seminar: $%.2f\n", semFee);
    }
    
    
    return 0;
}
