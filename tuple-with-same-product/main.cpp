#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int>& nums)
    {
        int size = (int)nums.size();
        if (size < 4)
            return 0;

        unordered_map<int, int> frequencies; // (product, count)
        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                int product = nums[i] * nums[j];
                frequencies[product]++;
            }
        }
        
        int distinct_tuples = 0;
        for (auto& [product, count] : frequencies)
            if (count > 1)
                distinct_tuples += (count * (count - 1) / 2) * 8; // for a four element tuple there are 2^3=8 combinations

        return distinct_tuples;
    }
};

int main()
{
    vector<int> nums = {1,2,4,5,10}; // expected 16
    cout << "output: " << Solution().tupleSameProduct(nums) << '\n';
    return 0;
}
