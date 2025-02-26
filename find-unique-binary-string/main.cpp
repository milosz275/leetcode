#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int binary_to_int(string& s)
    {
        return stoi(s, nullptr, 2);
    }

    string int_to_binary(int decimal, int length)
    {
        return bitset<32>(decimal).to_string().substr(32 - length);
    }

public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> decimals(nums.size());
        transform(nums.begin(), nums.end(), decimals.begin(), [this](string& s) { return binary_to_int(s); });
        
        // return 0 if the first is larger than 1
        if (decimals[0] > 0)
            return int_to_binary(0, nums[0].length());
        for (int i = 1; i < (int)decimals.size(); ++i)
        {
            if (decimals[i] > decimals[i - 1] + 1) // for 1, 3 - return 2
                return int_to_binary(decimals[i - 1] + 1, nums[0].length());
        }
        return int_to_binary(decimals[decimals.size() - 1] + 1, nums[0].length());
    }
};

int main()
{
    vector<string> nums = {"111", "011", "001"};
    cout << Solution().findDifferentBinaryString(nums) << '\n';
    return 0;
}
