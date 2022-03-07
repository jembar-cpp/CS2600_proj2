/*
 * CS 2600 Project 2 (Group) - Travel Expenses
 * miscExpenses.c: asks for and returns:
 *  - conference or seminar registration fees
 *  - total hotel expenses
*/

#include <stdio.h>


void getHotelExpenses(float hotelFee, int nights, float semFee)
{

    // Declare variables needed
    float totalHotelExpenses;
    float nights, hotelFee, semFee, totalHotelCost;
    float allowedHotelCost;
    float allowedPerNight = 90;
    // Calculates costs of both allowed total and total businessperson spent
    totalHotelCost = hotelFee * nights;
    allowedHotelCost = allowedPerNight * nights;
    
    
    // Checks for hotelFee only, so rest of calcs are easier to check 
    if (hotelFee <= 89.99)
    {
        totalHotelExpenses = (allowedHotelCost - totalHotelCost) + semFee;
    }
    else if (hotelFee >= 90.99)
    {
        totalHotelExpenses = fabs(totalHotelCost - allowedHotelCost) + semFee;
    }
    else
    {  
        totalHotelExpenses = semFee;
    }
    return 0;
}
