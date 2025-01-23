#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long gridGame(vector<vector<int>>& grid)
    {
        vector<vector<long long>> prefix((int)grid.size(), vector<long long>((int)grid[0].size()));
        for (int i = 0; i < (int)grid.size(); ++i)
            for (int j = 0; j < (int)grid[0].size(); ++j)
                if (j == 0)
                    prefix[i][j] = grid[i][j];
                else 
                    prefix[i][j] = grid[i][j] + prefix[i][j - 1];

        long long result = LLONG_MAX;
        for (int j = 0; j < (int)grid[0].size(); ++j)
        {
            long long top = (j != (int)grid[0].size() - 1) ? prefix[0][(int)grid[0].size() - 1] - prefix[0][j] : 0;
            long long bottom = (j != 0) ? prefix[1][j - 1] : 0;
            long long second_robot = max(top, bottom);
            result = min(result, second_robot);
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> grid = {{2,5,4}, {1,5,1}};
    cout << Solution().gridGame(grid) << '\n';
    return 0;
}
