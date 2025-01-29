#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit)
    {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<queue<int>> groups;
        queue<int> q;
        q.push(sorted_nums[0]);
        unordered_map<int, int> belongs_to_group; // (value, group)
        belongs_to_group[sorted_nums[0]] = 0; // initialize the first element's group index to 0
        for (int i = 1; i < (int)sorted_nums.size(); ++i)
        {
            if (sorted_nums[i] - sorted_nums[i - 1] <= limit)
            {
                q.push(sorted_nums[i]);
                belongs_to_group[sorted_nums[i]] = (int)groups.size();
            }
            else
            {
                groups.push_back(q);
                while (!q.empty())
                    q.pop();
                q.push(sorted_nums[i]);
                belongs_to_group[sorted_nums[i]] = (int)groups.size();
            }
        }
        if (!q.empty())
            groups.push_back(q);
        vector<int> answer;
        answer.reserve(nums.size());
        for (int el: nums)
        {
            int group_index = belongs_to_group[el];
            answer.push_back(groups[group_index].front());
            groups[group_index].pop();
        }
        return answer;
    }
};

int main()
{
    vector<int> nums = {6, 3, 5, 2, 1};
    vector<int> answer = Solution().lexicographicallySmallestArray(nums, 1);
    for (int el: answer)
        cout << el << ' ';
    cout << '\n';
    return 0;
}
