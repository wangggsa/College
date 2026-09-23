#include <stdio.h>

#define VI 200.0

int main() {

    double acceleration, vf, time, timeToStop;

    printf("Enter the value of VF : ");
    scanf("%lf", &vf);

    printf("Enter the value of T (in minutes): ");
    scanf("%lf", &time);

    acceleration = (vf - VI) / time;

    printf("The constant rate of acceleration is %.2f mi/hr per minute\n", acceleration);

    timeToStop = (0.0 - VI) / acceleration;

    printf("The train will take %.2f minutes to come to rest\n", timeToStop);

    return 0;
}
