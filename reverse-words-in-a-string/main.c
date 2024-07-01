#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* remove_leading_spaces(char* s)
{
    int s_length = (int)strlen(s);
    int new_start_index = 0;
    bool any_spaces = false;
    for (int i = 0; i < s_length; ++i)
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

    char *result = (char*)malloc(s_length - new_start_index + 1);
    if (!result)
        return NULL;

    for (int i = new_start_index; i < s_length; ++i)
        result[i - new_start_index] = s[i];

    result[s_length - new_start_index] = '\0';

    return result;
}

char* remove_trailing_spaces(char* s)
{
    int length = (int)strlen(s);
    int new_end_index = length - 1;
    while (new_end_index >= 0 && s[new_end_index] == ' ')
    {
        new_end_index--;
    }

    if (new_end_index == length - 1)
    {
        char* result = (char*)malloc(length + 1);
        strcpy(result, s);
        return result;
    }

    char* result = (char*)malloc(new_end_index + 2);
    strncpy(result, s, new_end_index + 1);
    result[new_end_index + 1] = '\0';
    return result;
}

char *remove_whitespace(char *s)
{
    int spaces = 0;
    int signs = 0;
    char prev = ' ';
    for (int i = 0; i < (int)strlen(s); ++i)
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

    int new_size = signs + spaces + 1;
    char *result = (char*)malloc(new_size);
    if (result == NULL)
        return NULL;

    int current_index = 0;
    prev = ' ';
    for (int i = 0; i < (int)strlen(s); ++i)
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
    result[current_index] = '\0';
    return result;
}

char* reverseWords(char* s)
{
    char *s1 = remove_leading_spaces(s);
    char *s2 = remove_trailing_spaces(s1);
    char *s3 = remove_whitespace(s2);
    free(s1); // Comment those in Leetcode as they automatically free the memory
    free(s2); // ---------------------------------------------------------------

    int len = (int)strlen(s3);
    char *result = (char*)malloc(len + 1);
    if (!result)
        return NULL;

    int word_start_index = 0;
    int word_end_index = len - 1;
    int current_result_index = 0;

    for (int i = len - 1; i >= 0; --i)
    {
        if (s3[i] == ' ' || i == 0)
        {
            if (i == 0)
                word_start_index = 0;
            else
                word_start_index = i + 1;
            for (int j = word_start_index; j <= word_end_index; ++j)
                result[current_result_index++] = s3[j];
            if (i != 0)
            {
                result[current_result_index++] = ' ';
                word_end_index = i - 1;
            }
        }
    }
    free(s3); // Comment this in Leetcode as they automatically free the memory
    result[current_result_index] = '\0';
    return result;
}

int main()
{
    char *s = " asdasd df f";
    char *reversed_s = reverseWords(s);
    printf("input\t\ts=%s\n", s);
    printf("reversed\ts=%s\n", reversed_s);
    free(reversed_s);
    exit(EXIT_SUCCESS);
}
