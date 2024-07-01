#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* remove_leading_spaces(char* s)
{
    int new_start_index = 0;
    bool any_spaces = false;
    for (int i = 1; i < strlen(s); ++i)
    {
        if (s[i] == ' ')
        {
            any_spaces = true;
            continue;
        }
        else
        {
            if (!any_spaces)
                return s;
            new_start_index = i;
            break;
        }
    }
    if (new_start_index == 0)
        return s;
    char *result = (char*)malloc(strlen(s) - new_start_index + 1);
    for (int i = new_start_index; i < strlen(s); ++i)
        result[i - new_start_index] = s[i];
    return result;
}

char* remove_trailing_spaces(char* s)
{
    int new_end_index = strlen(s) - 1;
    bool any_spaces = false;
    for (int i = strlen(s) - 2; i >= 0; --i)
    {
        if (s[i] == ' ')
        {
            any_spaces = true;
            continue;
        }
        else
        {
            if (!any_spaces)
                return s;
            new_end_index = i;
            break;
        }
    }
    if (new_end_index == strlen(s) - 1)
        return s;
    char *result = (char*)malloc(new_end_index + 1);
    for (int i = 0; i <= new_end_index; ++i)
        result[i] = s[i];
    return result;
}

char *remove_whitespace(char *s)
{
    s = remove_leading_spaces(s);
    s = remove_trailing_spaces(s);

    int spaces = 0;
    int signs = 0;
    char prev = ' ';
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == ' ')
        {
            if (prev != ' ')
                ++spaces;
        }
        else
            ++signs;
        prev = s[i];
    }
    int new_size = signs + spaces;
    char *result = (char*)malloc(new_size + 1);
    int current_index = 0;
    prev = ' ';
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == ' ')
        {
            if (prev != ' ')
                result[current_index++] = s[i];
        }
        else
            result[current_index++] = s[i];
        prev = s[i];
    }
    return result;
}

char* reverseWords(char* s)
{
    s = remove_whitespace(s);
    char *result = malloc(sizeof(char) * (strlen(s) + 1));
    if (!result)
        return NULL;
    int word_start_index = 0;
    int word_end_index = strlen(s) - 1;
    int current_result_index = 0;
    for (int i = strlen(s) - 1; i >= 0; --i)
    {
        if (s[i] == ' ' || i == 0)
        {
            if (i == 0)
                word_start_index = 0;
            else
                word_start_index = i + 1;
            for (int j = word_start_index; j <= word_end_index; ++j)
                result[current_result_index++] = s[j];
            if (i != 0)
            {
                result[current_result_index++] = ' ';
                word_end_index = i - 1;
            }
        }
    }
    return result;
}

int main()
{
    char *s = "   Keep calm     and code on   ";
    char *reversed_s = reverseWords(s);
    printf("Reversed words of s: %s\n", reversed_s);
    free(reversed_s);
    exit(EXIT_SUCCESS);
}
