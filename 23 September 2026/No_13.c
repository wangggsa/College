#include <stdio.h>

#define startingYear 1990
#define populationIn1990 52966

int main() {

    int yearAfter, result;

    printf("Enter a year after 1990 : ");
    scanf("%d", &yearAfter);

    result = populationIn1990 + 2184 * (yearAfter - 1990);

    printf("Predicted Gotham City population for 2015 (in thousands) : %d", result);

    return 0;

}
