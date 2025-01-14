#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        string output("");
        for (char c: s)
        {
            if (c == '*' && !output.empty())
                output.pop_back();
            else
                output.push_back(c);
        }
        return output;
    }
};

int main()
{
    string s("leet**cod*e");
    // string s("erase*****");
    cout << "output: " << Solution().removeStars(s) << endl;
    return 0;
}
