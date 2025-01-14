#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp((int)text1.size() + 1, vector<int>((int)text2.size() + 1, 0));
        for (int i = (int)text1.size() - 1; i >= 0; --i)
            for (int j = (int)text2.size() - 1; j >= 0; --j)
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        return dp[0][0];
    }
};

int main()
{
    // string text1 = "bl";
    // string text2 = "yby";
    string text1 = "abcde";
    string text2 = "ace";
    cout << "output: " << Solution().longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
