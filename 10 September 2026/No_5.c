#include <stdio.h>

#define MINUTES_PER_HOUR 60.0

int main () {
    double volumeMil, infuseDur, infusionRate;

    printf("Volume to be infused (ml) : ");
    scanf("%lf", &volumeMil);

    printf("Minutes over which to infuse : ");
    scanf("%lf", &infuseDur);

    infusionRate =  (volumeMil / infuseDur) * MINUTES_PER_HOUR;

    printf("\nVTBI: %.0f ml\n", volumeMil);
    printf("Rate: %.0f ml/hr\n", infusionRate);

    return 0;

}
