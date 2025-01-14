#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        int size = (int)nums.size();
        if (lower > upper || size == 0)
            return 0;

        int count = 0;

        vector<long long> prefix_sum(size + 1, 0);
        for (int i = 0; i < size; ++i)
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];

        for (int el: prefix_sum)
            cout << "sum: " << el << endl;

        return count;
    }
};

int main()
{
    vector<int> nums = {-2,5,-1};
    cout << "output: " << Solution().countRangeSum(nums, -2, 2) << endl;
    return 0;
}
