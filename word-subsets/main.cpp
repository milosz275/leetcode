#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2)
    {
        vector<int> total_occurrences(26, 0);
        vector<string> answer;
        answer.reserve((int)words1.size());
        for (string& word: words2)
        {
            vector<int> occurrences(26, 0);
            for (char c: word)
                occurrences[c - 'a']++;
            for (int i = 0; i < 26; ++i)
                total_occurrences[i] = max(occurrences[i], total_occurrences[i]);
        }
        for (string& word: words1)
        {
            vector<int> occurrences(26, 0);
            for (char c: word)
                occurrences[c - 'a']++;
            bool accept = true;
            for (int i = 0; i < 26; ++i)
            {
                if (occurrences[i] < total_occurrences[i])
                {
                    accept = false;
                    break;
                }
            }
            if (accept)
                answer.push_back(word);
        }
        return answer;
    }
};

int main()
{

    return 0;
}
