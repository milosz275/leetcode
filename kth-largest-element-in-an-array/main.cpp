#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> max_heap(nums.begin(), nums.end());
        int kth = max_heap.top();
        max_heap.pop();
        for (int i = 1; i < k; ++i)
        {
            kth = max_heap.top();
            max_heap.pop();
        }
        return kth;
    }
};

int main()
{

    return 0;
}
