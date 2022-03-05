#ifndef MEALEXPENSES_H
#define MEALEXPENSES_H

void calculateMealCosts(int numDays, int departureTime, int arrivalTime, int *totalMealCost, int *allowableMealCost);
int promptBreakfast(int day);
int promptLunch(int day);
int promptDinner(int day);
int promptCost();

#endif