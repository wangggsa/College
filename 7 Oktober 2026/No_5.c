#include <stdio.h>

int cariFPB(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    printf("Masukkan angka pertama: ");
    scanf("%d", &num1);

    printf("Masukkan angka kedua: ");
    scanf("%d", &num2);

    int fpb = cariFPB(num1, num2);

    printf("FPB dari %d dan %d adalah: %d\n", num1, num2, fpb);

    return 0;
}
