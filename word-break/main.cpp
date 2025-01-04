#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        // array to keep whether s can be segmented at each indices   l e e t c o d e   
        vector<bool> array(s.length() + 1, false); //               1 0 0 0 0 0 0 0 0 

        // empty array can always be segmented
        array[0] = true;
        
        for (int i = 0; i <= (int)s.length(); ++i)
        {
            // s[0...i - 1] cannot be segmented
            if (!array[i])
                continue;

            // finding all matching words (for input "leetcode", ["leet", "leets", "code"] we would have   l e e t s c o d e)
            for (string& word: wordDict) //                                                              1 0 0 0 1 1 0 0 0 1 
            {
                int end = i + (int)word.length();
                // new valid word is found if whole constructed string is matching a word from dictionary
                if (end <= (int)s.length() && s.substr(i, word.length()) == word)
                    array[end] = true;
            }
        }

        // // dp array check
        // for (bool el: array)
        //     cout << el << " ";
        // cout << endl;

        return array[s.length()];
    }
};

int main()
{
    // string input = "catsandog";
    // vector<string> dictionary = {"cats","dog","sand","and","cat"};
    string input = "leetcode";
    vector<string> dictionary = {"leet", "code"};
    Solution sol;
    cout << "output: " << sol.wordBreak(input, dictionary) << endl;
    return 0;
}
