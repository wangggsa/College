#include <stdio.h>
#include <string.h>
#include <math.h>

/* Function prototypes */
int    get_problem(void);
void   get2_pt(double *x1p, double *y1p, double *x2p, double *y2p);
void   get_pt_slope(double *mp, double *xp, double *yp);
void   slope_intcpt_from2_pt(double x1, double y1, double x2, double y2,
                             double *mp, double *bp);
double intcpt_from_pt_slope(double x, double y, double m);
void   display2_pt(double x1, double y1, double x2, double y2);
void   display_pt_slope(double x, double y, double m);
void   display_slope_intcpt(double m, double b);

int main(void)
{
    int    choice;
    char   again;
    double x1, y1, x2, y2, m, b;

    do {
        choice = get_problem();

        if (choice == 1) {
            get2_pt(&x1, &y1, &x2, &y2);
            if (x1 == x2) {
                printf("\nThe points form a vertical line; "
                       "it has no slope-intercept form.\n");
            } else {
                display2_pt(x1, y1, x2, y2);
                slope_intcpt_from2_pt(x1, y1, x2, y2, &m, &b);
                display_slope_intcpt(m, b);
            }
        } else {
            get_pt_slope(&m, &x1, &y1);
            display_pt_slope(x1, y1, m);
            b = intcpt_from_pt_slope(x1, y1, m);
            display_slope_intcpt(m, b);
        }

        printf("\nDo another conversion (Y or N)=> ");
        scanf(" %c", &again);
        printf("\n");
    } while (again == 'Y' || again == 'y');

    return 0;
}

/* Displays the menu; returns 1 (two-point) or 2 (point-slope) */
int get_problem(void)
{
    int choice;

    do {
        printf("Select the form that you would like to convert to "
               "slope-intercept form:\n");
        printf("    1) Two-point form (you know two points on the line)\n");
        printf("    2) Point-slope form (you know the line's slope and "
               "one point)\n");
        printf("=> ");
        if (scanf("%d", &choice) != 1) {
            scanf("%*s");           /* discard bad input */
            choice = 0;
        }
    } while (choice != 1 && choice != 2);

    return choice;
}

/* Inputs two points through output parameters */
void get2_pt(double *x1p, double *y1p, double *x2p, double *y2p)
{
    printf("Enter the x-y coordinates of the first point separated "
           "by a space=> ");
    scanf("%lf %lf", x1p, y1p);
    printf("Enter the x-y coordinates of the second point separated "
           "by a space=> ");
    scanf("%lf %lf", x2p, y2p);
}

/* Inputs slope and one point through output parameters */
void get_pt_slope(double *mp, double *xp, double *yp)
{
    printf("Enter the slope=> ");
    scanf("%lf", mp);
    printf("Enter the x-y coordinates of the point separated by "
           "a space=> ");
    scanf("%lf %lf", xp, yp);
}

/* Computes slope m and y-intercept b from two points */
void slope_intcpt_from2_pt(double x1, double y1, double x2, double y2,
                           double *mp, double *bp)
{
    *mp = (y2 - y1) / (x2 - x1);
    *bp = y1 - (*mp) * x1;
}

/* Returns y-intercept given a point and the slope */
double intcpt_from_pt_slope(double x, double y, double m)
{
    return y - m * x;
}

/* Displays two-point form (the slope expressed as a fraction) */
void display2_pt(double x1, double y1, double x2, double y2)
{
    char num[40], den[40];
    int  width, i;

    snprintf(num, sizeof num, "(%.2f - %.2f)", y2, y1);
    snprintf(den, sizeof den, "(%.2f - %.2f)", x2, x1);
    width = (int)strlen(num) > (int)strlen(den) ? (int)strlen(num)
                                                : (int)strlen(den);

    printf("\nTwo-point form\n");
    printf("      %*s\n", -width, num);
    printf("  m = ");
    for (i = 0; i < width; i++)
        putchar('-');
    printf("\n      %*s\n", -width, den);
}

/* Displays point-slope form: y - y1 = m(x - x1) */
void display_pt_slope(double x, double y, double m)
{
    printf("\nPoint-slope form\n");
    printf("  y %c %.2f = %.2f(x %c %.2f)\n",
           y < 0 ? '+' : '-', fabs(y), m,
           x < 0 ? '+' : '-', fabs(x));
}

/* Displays slope-intercept form: y = mx + b */
void display_slope_intcpt(double m, double b)
{
    printf("\nSlope-intercept form\n");
    printf("  y = %.2fx %c %.2f\n", m, b < 0 ? '-' : '+', fabs(b));
}
