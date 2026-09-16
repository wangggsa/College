#include <stdio.h>
#include <math.h>

#define PERSONS_PER_TOILET 3.0
#define NEW_LITER_PER_FLUSH 2.0
#define EXISTING_LITER_PER_FLUSH 15.0
#define COST_OF_NEW_TOILET 150.0
#define AVERAGE_FLUSH_PER_DAY 14.0

int main () {

    double communityPopulation, litersSavedDay, litersSavedFlush, totalToilet, totalCost;

    printf("Enter the community population : ");
    scanf("%lf", &communityPopulation);

    totalToilet =  ceil(communityPopulation / PERSONS_PER_TOILET);

    litersSavedFlush = EXISTING_LITER_PER_FLUSH - NEW_LITER_PER_FLUSH;
    litersSavedDay = totalToilet * litersSavedFlush * AVERAGE_FLUSH_PER_DAY;

    totalCost = totalToilet * COST_OF_NEW_TOILET;

    printf("\nEstimated number of toilets : %.0f\n", totalToilet);
    printf("Water saved : %.0f liters/day\n", litersSavedDay);
    printf("Cost to install %.0f of low-flush toilet/s : %.0f$\n", totalToilet, totalCost);

    return 0;

}
