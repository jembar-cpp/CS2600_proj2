/*
 * CS 2600 Project 2 (Group) - Travel Expenses
 * miscExpenses.c: asks for and returns:
 *  - conference or seminar registration fees
 *  - total hotel expenses
 */

#include <stdio.h>

float getHotelExpenses()
{

    float hotelFee;

    printf("Enter hotel cost per night: $");
    scanf("%f", &hotelFee);

    while (hotelFee < 0)
    {
        printf("Enter valid cost: $");
        scanf("%f", &hotelFee);
    }

    return hotelFee;
}

float getSemFee()
{
    float semFee;
    printf("Enter seminar/conference fees: ");
    scanf("%f", &semFee);

    while (semFee < 0)
    {
        printf("Enter valid seminal/conference fees: $");
        scanf("%f", &semFee);
    }

    return semFee;
}