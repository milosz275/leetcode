#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> occurrences; // (num, occurrences)
        for (int el: nums)
            occurrences[el]++;

        auto comparator = [](pair<int, int>& A, pair<int, int>& B)
        {
            return A.second > B.second; // min-heap by frequency
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> min_heap(comparator);

        for (const pair<const int, int>& occ: occurrences)
        {
            min_heap.push(occ);
            if ((int)min_heap.size() > k)
                min_heap.pop(); // remove the least frequent element if size exceeds k
        }

        vector<int> answer;
        while (!min_heap.empty())
        {
            answer.push_back(min_heap.top().first);
            min_heap.pop();
        }
        return answer;
    }
};


int main()
{

    return 0;
}
