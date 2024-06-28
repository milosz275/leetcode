#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gcd_of_strings(char* str1, char* str2)
{
    if (strlen(str1) < strlen(str2))
        return gcd_of_strings(str2, str1);
    if (strlen(str2) == 0)
        return str1;
    if (strncmp(str1, str2, strlen(str2)))
        return "";
    return gcd_of_strings(str1 + strlen(str2), str2);
}

int main()
{
    char *str1 = "ABABAB";
    char *str2 = "AB";
    char *gcd = gcd_of_strings(str1, str2);
    printf("GCD of strings: %s\n", gcd);
    exit(EXIT_SUCCESS);
}
