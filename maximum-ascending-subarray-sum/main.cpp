#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        int n = (int)nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];

        int sum = nums[0]; // current sum
        int maximal = nums[0]; // maximal sum or maximal single element
        for (int i = 1; i < n; ++i)
        {
            maximal = max(maximal, nums[i]);
            if (nums[i] > nums[i - 1])
                sum += nums[i];
            else
            {
                maximal = max(maximal, sum);
                sum = nums[i];
            }
        }
        return max(maximal, sum);
    }
};

int main()
{
    vector<int> nums = {100, 10, 1};
    cout << "output: " << Solution().maxAscendingSum(nums) << '\n';
    return 0;
}
