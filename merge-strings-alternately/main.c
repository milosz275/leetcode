#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *merge_alternately(char *word1, char *word2)
{
    char *merged = malloc(strlen(word1) + strlen(word2) + 1);
    int shorter_length = strlen(word1) < strlen(word2) ? strlen(word1) : strlen(word2);
    for (int i = 0; i < shorter_length; ++i)
    {
        merged[2 * i] = word1[i];
        merged[2 * i + 1] = word2[i];
    }
    sprintf(merged + 2 * shorter_length, "%s", strlen(word1) < strlen(word2) ? word2 + shorter_length : word1 + shorter_length);
    return merged;
}

int main()
{
    char *word1 = "abc";
    char *word2 = "pqr";
    char *merged = merge_alternately(word1, word2);
    printf("Merged str: %s\n", merged);
    exit(EXIT_SUCCESS);
}
