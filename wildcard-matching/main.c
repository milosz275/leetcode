#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Regular expression matching. Function checks if the string matches the pattern.
 * @param s Input string
 * @param p Input pattern
 * @return True if the string matches the pattern, false otherwise
 */
bool isMatch(char *s, char *p)
{
    int m = (int)strlen(s);
    int n = (int)strlen(p);

    bool **dp = (bool **)malloc((m + 1) * sizeof(bool *));
    for (int i = 0; i <= m; ++i)
    {
        dp[i] = (bool *)malloc((n + 1) * sizeof(bool));
        memset(dp[i], false, (n + 1) * sizeof(bool));
    }
    dp[0][0] = true;

    for (int j = 1; j <= n; j++)
    {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
        }
    }

    bool result = dp[m][n];
    for (int i = 0; i <= m; ++i)
        free(dp[i]);
    free(dp);
    
    return result;
}

int main()
{
    char *s = "abefcdgiescdfimde";
    char *p = "ab*cd?i*de";
    printf("Input: s = \"%s\", \"%s\"\nOutput: %d\n\n", s, p, isMatch(s, p));
    exit(EXIT_SUCCESS);
}
