#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countServers(vector<vector<int>>& grid)
    {
        vector<int> row_count(grid.size(), 0);
        vector<int> col_count(grid[0].size(), 0);
        for (int i = 0; i < (int)grid.size(); ++i)
        {
            for (int j = 0; j < (int)grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        int counter = 0;
        for (int i = 0; i < (int)grid.size(); ++i)
        {
            for (int j = 0; j < (int)grid[0].size(); ++j)
            {
                if (grid[i][j] == 1 && (row_count[i] > 1 || col_count[j] > 1))
                    counter++;
            }
        }
        return counter;
    }
};

int main()
{
    vector<vector<int>> grid = {{1,1,0,0}, {0,0,1,0}, {0,0,1,0}, {0,0,0,1}};
    cout << Solution().countServers(grid) << '\n';
    return 0;
}
