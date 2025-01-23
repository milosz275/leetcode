#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> anagram_groups;

        for (string word : strs)
        {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            anagram_groups[sorted_word].push_back(word);
        }

        vector<vector<string>> answer;
        for (auto& group : anagram_groups)
            answer.push_back(group.second);

        return answer;
    }
};

int main()
{
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> answer = Solution().groupAnagrams(input);
    for (vector<string> array: answer)
    {
        cout << "[";
        for (string s: array)
            cout << s << " ";
        cout << "] ";
    }
    cout << endl;
    return 0;
}
