#include <stdio.h>
#include <stdlib.h>

#define NUM_SIZE 3
#define LOWER -2
#define UPPER 2

int reverse(int number)
{
    if (number == 0)
        return 0;
    int digits = snprintf(NULL, 0, "%d", number);
    if ((number > (1LL << 31) - 1) || (number < -(1LL << 31)))
        return 0;
    char* string_number = malloc(digits + 1);
    snprintf(string_number, digits + 1, "%d", number);

    char* reversed_string_number = malloc(digits + 1);
    for (int i = 0; i < digits; ++i)
        reversed_string_number[i] = string_number[digits - 1 - i];
    free(string_number);

    long reversed_number = strtol(reversed_string_number, NULL, 10);
    free(reversed_string_number);

    if ((reversed_number > (1LL << 31) - 1) || (reversed_number < -(1LL << 31)))
        return 0;
    if (number < 0)
        return -reversed_number;
    return reversed_number;
}

int main()
{
    int number = 1534236469;
    int reversed_number = reverse(number);
    printf("Reverse int: %d\n", reversed_number);
    exit(EXIT_SUCCESS);
}
