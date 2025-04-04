#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2)
    {
        map<int, int> m;
        for (const auto& array: nums1)
            m[array[0]] += array[1];
        for (const auto& array: nums2)
            m[array[0]] += array[1];
        vector<vector<int>> result;
        result.reserve(m.size());
        for (const auto& [key, value]: m)
            result.push_back({key, value});
        return result;
    }
};
    
int main()
{
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> answer = Solution().mergeArrays(nums1, nums2);
    for (const auto& row: answer)
    {
        cout << "( ";
        for (int el: row)
            cout << el << " ";
        cout << ") ";
    }
    cout << '\n';
    return 0;
}
