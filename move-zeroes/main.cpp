#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int index = 0;
        for (int el: nums)
            if (el != 0)
                nums[index++] = el;
        while (index < (int)nums.size())
            nums[index++] = 0;
    }
};

int main()
{
    vector<int> nums = {0,1,0,3,12};
    Solution().moveZeroes(nums);
    for (int el: nums)
        cout << el << " ";
    cout << '\n';
    return 0;
}
