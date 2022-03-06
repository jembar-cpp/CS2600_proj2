#ifndef VEHICLEEXPENSES_H
#define VEHICLEEXPENSES_H

float getAirfare(float airfare);
float getRental(float rental);
float getMiles(float miles, float Tmiles);
void getFees(float *totalFeeCost, float *owedFeeCost);
void getTaxi(float *totalTaxiCost, float *owedTaxiCost);

#endif