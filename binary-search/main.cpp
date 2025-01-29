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
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target < nums[mid]) // go left
                right = mid - 1;
            else // go right
                left = mid + 1;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {1, 4, 62, 87, 321, 456, 890, 900, 2025};
    cout << Solution().search(nums, 62) << '\n'; // 2
    cout << Solution().search(nums, 321) << '\n'; // 4
    cout << Solution().search(nums, 890) << '\n'; // 6
    cout << Solution().search(nums, 2025) << '\n'; // 8
    return 0;
}
