#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs)
    {
        string encoded("");
        for (const string& el: strs)
            encoded += el + ":;";
        return encoded;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str)
    {
        if (str.empty())
            return {};
        list<string> decoded_list;
        int start_index = 0;
        for (int i = 0; i < (int)str.length(); ++i)
        {
            if (str[i] == ';' && i >= 1 && str[i - 1] == ':')
            {
                decoded_list.push_back(str.substr(start_index, ((i - 1) - start_index)));
                start_index = i + 1;
            }
        }
        if (decoded_list.empty())
            return {str};
        return vector<string>(decoded_list.begin(), decoded_list.end());
    }
};

int main()
{
    vector<string> input = {"leet", "code", "love", "you"};
    cout << "input: " << '\n';
    for (string& s: input)
        cout << s << " ";
    cout << '\n';

    string encoded = Solution().encode(input);
    cout << "encoded: " << encoded << '\n';

    vector<string> output = Solution().decode(encoded);
    cout << "output: " << '\n';
    for (string& s: output)
        cout << s << " ";
    cout << '\n';

    return 0;
}
