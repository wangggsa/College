#include <stdio.h>

int main(void) {
    double w;

    printf("Masukkan wavelength dalam meter, 0 untuk berhenti.\n");

    while (1) {
        printf("\nWavelength: ");
        scanf("%lf", &w);

        if (w == 0)
            break;

        printf("Wavelength = %e m -> ", w);

        if (w <= 3E-11)
            printf("gamma ray\n");
        else if (w <= 3E-9)
            printf("X-ray\n");
        else if (w <= 4E-7)
            printf("ultraviolet\n");
        else if (w <= 7E-7)
            printf("visible\n");
        else if (w <= 1.4E-5)
            printf("infrared\n");
        else if (w <= 1.0E-1)
            printf("microwave\n");
        else
            printf("radio wave\n");
    }

    return 0;
}
