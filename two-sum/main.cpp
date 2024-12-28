#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> answer(2);
        unordered_map<int, int> complements;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            int mapped = target - nums[i]; // mapped complement
            if (complements.find(mapped) != complements.end())
            {
                answer[0] = complements[mapped];
                answer[1] = i;
                break;
            }
            complements[nums[i]] = i;
        }
        for (auto el: complements)
            cout << "value: " << el.first << "; index: " << el.second << endl;
        return answer;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> answer = sol.twoSum(nums, target);
    for (int el: answer)
        cout << el << ", ";
    cout << endl;
    return 0;
}

