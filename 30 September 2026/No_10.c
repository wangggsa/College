#include <stdio.h>
#include <ctype.h>

#define PRIMARY_KNEADING_W 15
#define PRIMARY_KNEADING_S 20
#define PRIMARY_RISING_W 60
#define PRIMARY_RISING_S 60
#define SECONDARY_KNEADING_W 18
#define SECONDARY_KNEADING_S 33
#define SECONDARY_RISING_W 20
#define SECONDARY_RISING_S 30
#define LOAF_SHAPING_SECONDS 2
#define FINAL_RISING_W 75
#define FINAL_RISING_S 75
#define BAKING_W 45
#define BAKING_S 35
#define COOLING_W 30
#define COOLING_S 30

int display_instruction(const char *operation, double amount, const char *unit);
double calc_baking_time(char bread, int is_double);
char get_bread_type();
int ask_yes_no(const char *prompt);

int main()
{
    char bread;
    int is_double, is_manual, w;

    printf("=== Bread Machine Controller ===\n\n");

    bread = get_bread_type();
    is_double = ask_yes_no("Loaf size is double");
    is_manual = ask_yes_no("Baking is manual");
    w = (bread == 'W');

    printf("\nStarting %s bread program...\n\n", w ? "White" : "Sweet");

    display_instruction("Primary kneading", w ? PRIMARY_KNEADING_W : PRIMARY_KNEADING_S, "minutes");
    display_instruction("Primary rising", w ? PRIMARY_RISING_W : PRIMARY_RISING_S, "minutes");
    display_instruction("Secondary kneading", w ? SECONDARY_KNEADING_W : SECONDARY_KNEADING_S, "minutes");
    display_instruction("Secondary rising", w ? SECONDARY_RISING_W : SECONDARY_RISING_S, "minutes");
    display_instruction("Loaf shaping", LOAF_SHAPING_SECONDS, "seconds");

    if (is_manual)
    {
        printf("\nLoaf shaping is complete. Please remove the dough from the "
               "machine for manual baking.\n");
        return 0;
    }

    display_instruction("Final rising", w ? FINAL_RISING_W : FINAL_RISING_S, "minutes");
    display_instruction("Baking", calc_baking_time(bread, is_double), "minutes");
    display_instruction("Cooling", w ? COOLING_W : COOLING_S, "minutes");

    printf("\nYour bread is ready. Enjoy!\n");
    return 0;
}

int display_instruction(const char *operation, double amount, const char *unit)
{
    printf("%-20s: %.1f %s\n", operation, amount, unit);
    return 0;
}

double calc_baking_time(char bread, int is_double)
{
    double time = (bread == 'W') ? BAKING_W : BAKING_S;

    if (is_double)
        time = time * 1.5;

    return time;
}

char get_bread_type()
{
    char c;

    while (1)
    {
        printf("Enter bread type (W for White, S for Sweet): ");
        if (scanf("%c", &c) != 1)
            continue;
        c = toupper((unsigned char)c);
        if (c == 'W' || c == 'S')
            return c;
        printf("Invalid choice. Please enter W or S.\n");
    }
}

int ask_yes_no(const char *prompt)
{
    char c;

    while (1)
    {
        printf("%s (Y/N): ", prompt);
        if (scanf(" %c", &c) != 1)
            continue;
        c = toupper((unsigned char)c);
        if (c == 'Y')
            return 1;
        if (c == 'N')
            return 0;
        printf("Invalid choice. Please enter Y or N.\n");
    }
}
