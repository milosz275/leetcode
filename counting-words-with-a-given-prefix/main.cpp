#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int prefixCount(vector<string>& words, string pref)
    {
        int count = 0;
        for (string& word: words)
        {
            for (int i = 0; i < (int)pref.size(); ++i)
            {
                if (pref[i] != word[i])
                    break;
                else
                    if (i + 1 == (int)pref.size())
                        count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<string> words = {"pay","attention","practice","attend"};
    string prefix = "at";
    cout << "output: " << Solution().prefixCount(words, prefix) << endl;
    return 0;
}
