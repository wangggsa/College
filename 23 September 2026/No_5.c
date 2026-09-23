#include <stdio.h>

int main() {

    double monthlyPayment, hourlyWage, hoursNeeded;

    printf("Enter the monthly payment : ");
    scanf("%lf", &monthlyPayment);

    printf("Enter the hourly wage : ");
    scanf("%lf", &hourlyWage);

    hoursNeeded = monthlyPayment / hourlyWage;

    printf("\nYou need to work %2.f of hours to cover this payment\n", hoursNeeded);

    return 0;

}
