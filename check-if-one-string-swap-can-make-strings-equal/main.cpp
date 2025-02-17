#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
            return true;
        else if (s1.length() != s2.length())
            return false;
        
        queue<int> diff_indices;
        for (int i = 0; i < (int)s1.length(); ++i)
        {
            if (s1[i] != s2[i])
                diff_indices.push(i);
        }
        
        if (diff_indices.size() != 2)
            return false;
        
        int i = diff_indices.front();
        diff_indices.pop();
        int j = diff_indices.front();
        diff_indices.pop();
        swap(s1[i], s1[j]);
        
        return s1 == s2;
    }
};

int main()
{
    // cout << "output: " << Solution().areAlmostEqual("bank", "kanb") << '\n';
    cout << "output: " << Solution().areAlmostEqual("caa", "aaz") << '\n';
    return 0;
}
