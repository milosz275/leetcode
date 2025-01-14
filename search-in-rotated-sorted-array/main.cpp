#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = (int)nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (target == nums[mid])
                return mid;

            if (nums[mid] >= nums[left]) // subarray to the left of mid is sorted, rotation may occur in the right side
            {
                if (target > nums[mid] || target < nums[left])
                    left = mid + 1; // go right
                else
                    right = mid - 1; // go left
            }
            else // subarray to the right of mid is sorted, rotation may occur in the left side
            {
                if (target < nums[mid] || target > nums[right])
                    right = mid - 1; // go left
                else
                    left = mid + 1; // go right
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << "output: " << Solution().search(nums, target) << endl;
    return 0;
}
