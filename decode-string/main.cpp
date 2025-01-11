#include <bits/stdc++.h>

using namespace std;

class Solution 
{
public:
    string decodeString(string s) 
    {
        stack<pair<int, string>> pairs; // (multiplier, current_string)
        int multiplier = 0;
        string current_string = "";

        for (char el : s)
        {
            if (isdigit(el))
                multiplier = multiplier * 10 + (el - '0');
            else if (el == '[')
            {
                pairs.push({multiplier, current_string});
                multiplier = 0;
                current_string = "";
            }
            else if (el == ']')
            {
                auto [prev_multiplier, prev_string] = pairs.top();
                pairs.pop();
                string constructed = "";
                for (int i = 0; i < prev_multiplier; ++i)
                    constructed += current_string;
                current_string = prev_string + constructed;
            }
            else
                current_string += el;
        }
        return current_string;
    }
};

int main()
{
    string input("3[a2[k]]2[bc1[z]]");
    try
    {
        cout << "input: " << input << endl;
        cout << "output: " << Solution().decodeString(input) << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
