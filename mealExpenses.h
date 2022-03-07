#ifndef MEALEXPENSES_H
#define MEALEXPENSES_H

void calculateMealCosts(int numDays, int departureTime, int arrivalTime, float *totalMealCost, float *allowableMealCost);
float promptBreakfast(int day);
float promptLunch(int day);
float promptDinner(int day);
float promptCost();

#endif