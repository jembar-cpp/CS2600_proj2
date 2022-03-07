/*
 * CS 2600 Project 2 (Group) - Travel Expenses
 * miscExpenses.c: asks for and returns:
 *  - conference or seminar registration fees
 *  - total hotel expenses
*/

#include <stdio.h>



float getHotelExpenses()
{

    // Declare variables needed
    float totalHotelExpenses;
    float nights, hotelFee, totalHotelCost;
    float allowedHotelCost;
    float allowedPerNight = 90;
    
    
    printf("Enter hotel cost per night: $%.2f");
    scanf("%.2f", hotelFee);
    printf("Enter number of nights staying: ");
    scanf("%f", nights);

    // Calculates costs of both allowed total and total businessperson spent
    totalHotelCost = hotelFee * nights;
    allowedHotelCost = allowedPerNight * nights;

    // Checks for hotelFee only, so rest of calcs are easier to check 
    if (hotelFee <= 89.99)
    {
        totalHotelExpenses = (allowedHotelCost - totalHotelCost);
        return totalHotelExpenses;
    }
    else if (hotelFee >= 90.99)
    {
        totalHotelExpenses = fabs(totalHotelCost - allowedHotelCost);
        return totalHotelExpenses;
    }
    else
    {  
        totalHotelExpenses = 0;
        return totalHotelExpenses;
    }

}

float getSemFee()
{
    float semFee;
    printf("Enter seminar/conference fees: ");
    scanf("%.2f", semFee);
    return semFee;
}

