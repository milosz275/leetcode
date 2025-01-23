#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int m = (int)isWater.size();
        int n = (int)isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (isWater[i][j] == 1)
                {
                    q.push({i, j});
                    height[i][j] = 0;
                }
        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            int val = height[i][j] + 1;
            if (i - 1 >= 0 && height[i - 1][j] == -1)
            {
                height[i - 1][j] = val;
                q.push({i - 1, j});
            }
            if (i + 1 < m && height[i + 1][j] == -1)
            {
                height[i + 1][j] = val;
                q.push({i + 1, j});
            }
            if (j - 1 >= 0 && height[i][j - 1] == -1)
            {
                height[i][j - 1] = val;
                q.push({i, j - 1});
            }
            if (j + 1 < n && height[i][j + 1] == -1)
            {
                height[i][j + 1] = val;
                q.push({i, j + 1});
            }
        }
        return height;
    }
};

int main()
{
    vector<vector<int>> water = {{0,0,1},{1,0,0},{0,0,0}};
    vector<vector<int>> height = Solution().highestPeak(water);
    for (vector<int>& row: height)
    {
        for (int c: row)
            cout << c << " ";
        cout << endl;
    }
    return 0;
}
