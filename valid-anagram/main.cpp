#include "iostream"
#include "map"

using namespace std;

// class Solution
// {
// public:
//     bool isAnagram(string s, string t)
//     {
//         if(s.length() != t.length()) return false;
//         int n = s.length();
//         int count[26] = {0};
//         for(int i = 0; i < n; i++)
//         {
//             count[s[i]-'a']++;
//             count[t[i]-'a']--;
//         }
//         for(int i = 0; i < 26; i++)
//             if(count[i]) return false;
//         return true;
//     }
// };

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if ((int)s.length() != (int)t.length())
            return false;
        map<char, int> dictionary = {};
        for (char el: s)
        {
            if (dictionary.find(el) != dictionary.end())
                dictionary[el]++;
            else
                dictionary.insert(pair<char, int>{el, 1});
        }
        // for (pair<char, int> pair: dictionary)
        //     cout << "Char: " << pair.first << "; Count: " << pair.second << endl;
        for (char el: t)
        {
            if (dictionary.find(el) != dictionary.end())
                dictionary[el]--;
            else
                return false;
        }
        for (pair<char, int> pair: dictionary)
            if (pair.second != 0)
                return false;
        return true;
    }
};

int main()
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    // sol.isAnagram(s, t);
    cout << "Is " << s << " a valid anagram of " << t << "? Answer: " << sol.isAnagram(s, t) << endl;
    return 0;
}
