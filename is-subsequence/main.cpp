#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if ((int)s.size() == 0)
            return true;

        int index = 0;
        for (char c: t)
        {
            if (c == s[index])
            {
                index++;
                if (index == (int)s.size())
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    cout << "is s a subsequence of t: " << Solution().isSubsequence("abc", "ahbgdc") << endl;
    return 0;
}
