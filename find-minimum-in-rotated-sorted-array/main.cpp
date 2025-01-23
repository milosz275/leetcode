#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int left = 0;
        int right = (int)nums.size() - 1;
        int minimum = INT_MAX;
        while (left <= right)
        {
            if (nums[left] < nums[right]) // array is already sorted
                return min(minimum, nums[left]);

            int mid = left + (right - left) / 2;
            minimum = min(minimum, nums[mid]);

            if (nums[mid] >= nums[left])
                left = mid + 1; // go right when left is sorted
            else
                right = mid - 1; // go left when right is sorted
        }
        return minimum;
    }
};

int main()
{

    return 0;
}
