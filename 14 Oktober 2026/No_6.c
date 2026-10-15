#include <stdio.h>

void calc_h (const double *k, const double *a, const double *t2, const double *t1, const double *x, double *hasil)
{ *hasil = (*k) * (*a) * (*t2 - *t1) / (*x); }

void calc_k (const double *h, const double *a, const double *t2, const double *t1, const double *x, double *hasil)
{ *hasil = (*h) * (*x) / ((*a) * (*t2 - *t1)); }

void calc_a (const double *h, const double *k, const double *t2, const double *t1, const double *x, double *hasil)
{ *hasil = (*h) * (*x) / ((*k) * (*t2 - *t1)); }

void calc_t2(const double *h, const double *k, const double *a, const double *t1, const double *x, double *hasil)
{ *hasil = (*h) * (*x) / ((*k) * (*a)) + *t1; }

void calc_t1(const double *h, const double *k, const double *a, const double *t2, const double *x, double *hasil)
{ *hasil = *t2 - (*h) * (*x) / ((*k) * (*a)); }

void calc_x (const double *h, const double *k, const double *a, const double *t2, const double *t1, double *hasil)
{ *hasil = (*k) * (*a) * (*t2 - *t1) / (*h); }

void baca(const char *prompt, double *nilai, int *tidak_diketahui)
{
    char c;
    printf("%s >> ", prompt);
    if (scanf("%lf", nilai) == 0) {
        scanf(" %c", &c);
        if (c == '?') { *tidak_diketahui = 1; *nilai = 0.0; return; }
    }
    *tidak_diketahui = 0;
}

int main(void)
{
    double H, k, A, T2, T1, X;
    int u[6];
    int jumlah, i;

    printf("Respond to the prompts with the data known. For the\n");
    printf("unknown quantity, enter a question mark (?).\n");
    baca("Rate of heat transfer (watts)      ", &H,  &u[0]);
    baca("Coefficient of thermal conductivity (W/m-K)", &k, &u[1]);
    baca("Cross-sectional area of conductor (m^2)", &A, &u[2]);
    baca("Temperature on one side (K)        ", &T2, &u[3]);
    baca("Temperature on other side (K)      ", &T1, &u[4]);
    baca("Thickness of conductor (m)         ", &X,  &u[5]);

    for (jumlah = 0, i = 0; i < 6; i++) jumlah += u[i];
    if (jumlah != 1) {
        printf("Harus tepat satu besaran yang tidak diketahui (?).\n");
        return 1;
    }

    if      (u[0]) { calc_h (&k,&A,&T2,&T1,&X,&H);  printf("\nRate of heat transfer is %.3f W.\n", H); }
    else if (u[1]) { calc_k (&H,&A,&T2,&T1,&X,&k);  printf("\nCoefficient of thermal conductivity is %.3f W/m-K.\n", k); }
    else if (u[2]) { calc_a (&H,&k,&T2,&T1,&X,&A);  printf("\nCross-sectional area is %.3f m^2.\n", A); }
    else if (u[3]) { calc_t2(&H,&k,&A,&T1,&X,&T2);  printf("\nTemperature on one side is %.0f K.\n", T2); }
    else if (u[4]) { calc_t1(&H,&k,&A,&T2,&X,&T1);  printf("\nTemperature on the other side is %.0f K.\n", T1); }
    else           { calc_x (&H,&k,&A,&T2,&T1,&X);  printf("\nThickness of conductor is %.4f m.\n", X); }

    printf("\n          kA (T2 - T1)\n     H = --------------\n                X\n\n");
    printf("H  = %.1f W\t\tT2 = %.0f K\n", H, T2);
    printf("k  = %.3f W/m-K\t\tT1 = %.0f K\n", k, T1);
    printf("A  = %.3f m^2\n", A);
    printf("X  = %.4f m\n", X);
    return 0;
}
