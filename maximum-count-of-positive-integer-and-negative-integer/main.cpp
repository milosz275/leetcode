#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumCount(vector<int>& nums)
    {
        int size = (int)nums.size();

        // exclude all positives or all negatives
        if (nums[0] > 0 || (nums[0] < 0 && nums[size - 1] < 0))
            return size;
        else if (nums[0] == 0 && nums[size - 1] == 0)
            return 0;

        // we need to return maximum of (positives, negatives), but zeroes do not count to either, so we need to find both of last_negative and first_positive

        int left = 0;
        int right = size - 1;
        int mid_n; // last_negative
        while (left <= right)
        {
            mid_n = left + (right - left) / 2;
            if ((nums[mid_n] < 0 && mid_n + 1 >= size) || (nums[mid_n] < 0 && mid_n + 1 < size && nums[mid_n + 1] >= 0))
                break;
            if (nums[mid_n] >= 0)
                right = mid_n - 1; // go left
            else
                left = mid_n + 1; // go right
        }
        // cout << "First negative at index: " << mid_n << '\n';

        left = 0;
        right = size - 1;
        int mid_p; // first_positive
        while (left <= right)
        {
            mid_p = left + (right - left) / 2;
            if ((nums[mid_p] > 0 && mid_p - 1 < 0) || (nums[mid_p] > 0 && mid_p - 1 >= 0 && nums[mid_p - 1] <= 0))
                break;
            if (nums[mid_p] <= 0)
                left = mid_p + 1; // go right
            else
                right = mid_p - 1; // go left
        }
        // cout << "First positive at index: " << mid_p << '\n';

        return max(mid_n + 1, size - mid_p);
    }
};

int main()
{
    vector<int> nums = {-4, -3, -2, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4}; // 13 elements, 6 zeroes, 3 negatives, 4 positives
    cout << Solution().maximumCount(nums) << '\n'; // return 4
    return 0;
}
