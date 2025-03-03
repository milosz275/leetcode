#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        queue<int> left;
        queue<int> right;
        int pivot_count = 0;
        for (int i = 0; i < (int)nums.size(); ++i)
        {
            if (nums[i] < pivot)
                left.push(nums[i]);
            else if (nums[i] > pivot)
                right.push(nums[i]);
            else
                pivot_count++;
        }
        vector<int> answer;
        answer.reserve(nums.size());
        while (!left.empty())
        {
            answer.push_back(left.front());
            left.pop();
        }
        for (int i = 0; i < pivot_count; ++i)
            answer.push_back(pivot);
        while (!right.empty())
        {
            answer.push_back(right.front());
            right.pop();
        }
        return answer;
    }
};

int main()
{
    vector<int> nums = {9,12,5,10,14,3,10};
    // vector<int> nums = {-8,0,7,-7,19,15,6,-5,-10,11,-6,-5,20,3,-6,10,-2};
    vector<int> answer = Solution().pivotArray(nums, 10);
    for (int el: answer)
        cout << el << ' ';
    cout << '\n';
    return 0;
}
