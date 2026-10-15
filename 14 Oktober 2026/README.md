# Tugas Dasar Pemrograman - Buku Hanly, Hal. 123

Tanggal: 14 Oktober 2026

## No_4.c — Konversi ke Slope-Intercept Form

**Sample run:**

```
Select the form that you would like to convert to slope-intercept form:
    1) Two-point form (you know two points on the line)
    2) Point-slope form (you know the line's slope and one point)
=> 1
Enter the x-y coordinates of the first point separated by a space=> 1 2
Enter the x-y coordinates of the second point separated by a space=> 3 6

Two-point form
      (6.00 - 2.00)
  m = -------------
      (3.00 - 1.00)

Slope-intercept form
  y = 2.00x + 0.00

Do another conversion (Y or N)=> Y

Select the form that you would like to convert to slope-intercept form:
    1) Two-point form (you know two points on the line)
    2) Point-slope form (you know the line's slope and one point)
=> 2
Enter the slope=> 2
Enter the x-y coordinates of the point separated by a space=> 3 4

Point-slope form
  y - 4.00 = 2.00(x - 3.00)

Slope-intercept form
  y = 2.00x - 2.00

Do another conversion (Y or N)=> N
```

---

## No_6.c — Konduksi Panas (H = kA(T2 − T1) / X)

**Sample run:**

```
Respond to the prompts with the data known. For the
unknown quantity, enter a question mark (?).
Rate of heat transfer (watts)       >> 755.0
Coefficient of thermal conductivity (W/m-K) >> 0.8
Cross-sectional area of conductor (m^2) >> 0.12
Temperature on one side (K)         >> 298
Temperature on other side (K)       >> ?
Thickness of conductor (m)          >> 0.003

Temperature on the other side is 274 K.

          kA (T2 - T1)
     H = --------------
                X

H  = 755.0 W            T2 = 298 K
k  = 0.800 W/m-K        T1 = 274 K
A  = 0.120 m^2
X  = 0.0030 m
```

---

## No_11.c — Prediksi Revenue PQR Production Company

**Sample run:**

```
Revenue diperkirakan melebihi $1 miliar pada tahun 2116
Tabel disimpan di revenue.txt
```

**Isi revenue.txt :**
```
Tahun        Revenue (ribu $)
1990                  471.621
1991                  501.333
1992                  532.917
...
2114               919851.955
2115               977802.628
2116              1039404.194
```
