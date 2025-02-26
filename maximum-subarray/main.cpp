#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int max_sum = nums[0];
        int cur_sum = 0;
        for (int el: nums)
        {
            cur_sum = max(cur_sum, 0);
            cur_sum += el;
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "output: " << Solution().maxSubArray(nums) << '\n';
    return 0;
}
