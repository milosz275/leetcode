#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> occurrences; // key: element from array; value: number of occurrences
        for (int el: arr)
            occurrences[el]++;
            
        set<int> unique_occurrences;
        for (pair<int, int> pairs: occurrences)
        {
            int el = pairs.second;
            if (unique_occurrences.find(el) != unique_occurrences.end())
                return false;
            else
                unique_occurrences.insert(el);
        }
        return true;
    }
};

int main()
{
    
    return 0;
}
