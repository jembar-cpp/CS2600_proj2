/*
 * CS 2600 Project 2 (Group) - Travel Expenses
 * miscExpenses.c: asks for and returns:
 *  - conference or seminar registration fees
 *  - total hotel expenses
 
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
    if (hotelFee < 90)
    {
        printf("total cost is less than allowed, so we saved: $%.2f", (allowedHotelCost - totalHotelCost));
    }
    else if (hotelFee > 90)
    {
        printf("total cost is more than allowed, so we over spent: $%.2f", (totalHotelCost - allowedHotelCost));
    }
    else
    {  
        printf("The company gave you the exact amount you needed! (for hotels)");
    }
    
    // Saves total saved/excess to variables for easy access
    totalSaved = allowedHotelCost - totalHotelCost;
    totalExcess = totalHotelCost - allowedHotelCost;
    
    printf("Total saved: $%.2f", totalSaved);
    printf("Total Excess = ")


    return 0;
}
