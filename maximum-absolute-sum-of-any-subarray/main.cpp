#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxAbsoluteSum(vector<int>& nums)
    {
        int max_sum = nums[0];
        int cur_sum = 0;
        for (int el: nums)
        {
            cur_sum = max(cur_sum, 0);
            cur_sum += el;
            max_sum = max(max_sum, cur_sum);
        }

        int min_sum = nums[0];
        cur_sum = 0;
        for (int el: nums)
        {
            cur_sum = min(cur_sum, 0);
            cur_sum += el;
            min_sum = min(min_sum, cur_sum);
        }
        
        return max(abs(max_sum), abs(min_sum));
    }
};

int main()
{
    vector<int> nums = {1, -3, 2, 3, -4};
    cout << "output: " << Solution().maxAbsoluteSum(nums) << '\n';
    return 0;
}
