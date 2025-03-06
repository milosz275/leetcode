#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
    {
        // construct set of elements and find repeating value
        int n = (int)grid.size();
        vector<int> values(n * n + 1, 0);
        int a, b;
        for (const auto& row: grid)
        {
            for (int el: row)
            {
                if (values[el] != 0)
                    a = el;
                else
                    values[el] = 1;
            }
        }
        // find missing value
        for (int i = 1; i <= n * n; ++i)
        {
            if (i == a)
                continue;
            else if (values[i] == 0)
            {
                b = i;
                break;
            }
        }
        vector<int> answer = {a, b};
        return answer;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    vector<int> answer = Solution().findMissingAndRepeatedValues(grid);
    cout << "[" << answer[0] << ", " << answer[1] << "]\n";
    return 0;
}
