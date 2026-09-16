#include <stdio.h>

#define MASS_PER_CUBIC 1000.0
#define GRAVITY 9.80
#define EFFICIENCY 0.90
#define WATTS_PER_MEGAWATTS 1e6

int main () {
    double workForce, damHeight, mass, flowRate, massFlowRate, electricalMegawatt;

    printf("Enter the dam's height : ");
    scanf("%lf", &damHeight);

    printf("Enter the water flow rate : ");
    scanf("%lf", &flowRate);

    massFlowRate = flowRate* MASS_PER_CUBIC;

    workForce = massFlowRate * GRAVITY * damHeight;

    electricalMegawatt = (workForce * EFFICIENCY) / WATTS_PER_MEGAWATTS;

    printf("\nEstimated megawatts that will be generated : %.2f\n", electricalMegawatt);

    return 0;
}
