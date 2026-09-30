#include <stdio.h>

int main () {

    int tanggal, bulan, tahun;

    scanf("%d %d %d", &tanggal, &bulan, &tahun);

    int tanggalDiBulan[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
    int maxTanggal = tanggalDiBulan[bulan-1];

    if (bulan == 2 && ((tahun % 400 == 0) || (tahun % 4 == 0 && tahun % 100 != 0))) {
        maxTanggal = 29;
    }

    if (1 <= tanggal && tanggal <= maxTanggal && 1 <= bulan && bulan <= 12) {
        printf("1");
    } else {
        printf("0");
    }

    return 0;

}
