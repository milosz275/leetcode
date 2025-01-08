#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int start = 0, end = 0, current_sum = nums[0], minimal_size = 0;
        while (start < nums.size() && end < nums.size())
        {
            // cout << "current window - start: " << start << "; end: " << end << "; sum: " << current_sum << endl;

            if (current_sum >= target)
            {
                if (minimal_size == 0)
                    minimal_size = end - start + 1;
                else
                    minimal_size = min(minimal_size, end - start + 1);

                // shrink the window
                current_sum -= nums[start];
                start++;
            }
            else // expand the window
            {
                end++;
                if (end < nums.size())
                    current_sum += nums[end];
            }
        }
        return minimal_size;
    }
};

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout << Solution().minSubArrayLen(target, nums) << endl;
    return 0;
}
