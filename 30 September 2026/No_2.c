#include <stdio.h>

int main() {

    double weight, height;

    printf("Enter the weight in pounds : ");
    scanf("%lf", &weight);

    printf("Enter the height in inches : ");
    scanf("%lf", &height);

    double bmi = 703 * weight / (height * height);

    if (bmi > 30) {
        printf("Obese");
    } else if (bmi >= 25) {
        printf("Overweight");
    } else if (bmi >= 18.5) {
        printf("Normal");
    } else {
        printf("Underweight");
    }

    return 0;

}
