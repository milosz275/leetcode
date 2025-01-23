#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < (int)nums.size(); ++i)
            if (nums[i - 1] == nums[i])
                return true;
        return false;
    }
};

int main()
{
    vector<int> input = { 1, 2, 3, 1 };
    cout << "output: " << Solution().containsDuplicate(input) << '\n';
    return 0;
}
