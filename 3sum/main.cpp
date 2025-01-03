#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length; ++i)
        {
            // skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int target = -nums[i]; // fixing ith element as target for two sum
            int left = i + 1;
            int right = length - 1;

            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;

                    // skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right - 1])
                        --right;

                    ++left;
                    --right;
                }
                else if (sum < target)
                    ++left;
                else // sum >= target
                    --right;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    Solution sol;
    vector<vector<int>> answer = sol.threeSum(nums);
    for (vector<int>& array: answer)
    {
        for (int el: array)
            cout << el << " ";
        cout << ". ";
    }
    cout << endl;
    return 0;
}
