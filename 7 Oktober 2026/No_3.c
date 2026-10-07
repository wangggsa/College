#include <stdio.h>
#include <math.h>

double pembulatanCent(double x) {
    return floor(x * 100.0 + 0.5) / 100.0;
}

double hitungPembayaran(double P, double i, int n) {
    return (i * P) / (1.0 - pow(1.0 + i, -n));
}

int main() {
    double pokok, bungaTahunan, bungaBulanan;
    double pembayaran, saldo, bunga, cicilanPokok;
    int n, k;
    FILE *out;

    printf("Jumlah pinjaman (principal): ");
    scanf("%lf", &pokok);
    printf("Bunga tahunan (%%): ");
    scanf("%lf", &bungaTahunan);
    printf("Jumlah pembayaran (n): ");
    scanf("%d", &n);

    bungaBulanan = bungaTahunan / 100.0 / 12.0;
    pembayaran = pembulatanCent(hitungPembayaran(pokok, bungaBulanan, n));

    out = fopen("table.txt", "w");
    if (out == NULL) {
        printf("Gagal membuat file output.\n");
        return 1;
    }

    fprintf(out, "Principal        $%.2f    Payment   $%.2f\n", pokok, pembayaran);
    fprintf(out, "Annual interest  %.1f%%       Term      %d months\n\n", bungaTahunan, n);
    fprintf(out, "%-10s %10s %12s %18s\n", "Payment", "Interest", "Principal", "Principal Balance");
    fprintf(out, "------------------------------------------------------\n");

    saldo = pokok;
    double pembayaranAkhir = pembayaran;

    for (k = 1; k <= n; k++) {
        bunga = pembulatanCent(saldo * bungaBulanan);

        if (k == n) {
            cicilanPokok = saldo;
            pembayaranAkhir = bunga + saldo;
        } else {
            cicilanPokok = pembulatanCent(pembayaran - bunga);
        }

        saldo = pembulatanCent(saldo - cicilanPokok);
        fprintf(out, "%-10d %10.2f %12.2f %18.2f\n", k, bunga, cicilanPokok, saldo);
    }

    fprintf(out, "\nFinal payment    $%.2f\n", pembayaranAkhir);
    fclose(out);

    printf("Tabel tersimpan di tabel.txt\n");
    return 0;
}
