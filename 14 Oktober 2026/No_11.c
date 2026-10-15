#include <stdio.h>
#include <math.h>

#define TAHUN_DASAR 1990

double annual_revenue(const int *t)
{
    return 471.621 * pow(1.063, *t);
}

int predict_year(const double *target)
{
    int t = 0;
    while (annual_revenue(&t) < *target)
        t++;
    return TAHUN_DASAR + t;
}

int main(void)
{
    const double satu_miliar = 1000000.0;
    int tahun_target, t;
    double rev;
    FILE *fp;

    tahun_target = predict_year(&satu_miliar);
    printf("Revenue diperkirakan melebihi $1 miliar pada tahun %d\n", tahun_target);

    fp = fopen("revenue.txt", "w");
    if (fp == NULL) {
        printf("Gagal membuat file output.\n");
        return 1;
    }
    fprintf(fp, "%-8s %20s\n", "Tahun", "Revenue (ribu $)");
    for (t = 0; t <= tahun_target - TAHUN_DASAR; t++) {
        rev = annual_revenue(&t);
        fprintf(fp, "%-8d %20.3f\n", TAHUN_DASAR + t, rev);
    }
    fclose(fp);
    printf("Tabel disimpan di revenue.txt\n");
    return 0;
}
