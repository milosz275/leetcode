#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int, int>> locations(rows * cols + 1); // (unique val, (x, y))
        vector<int> counts_x(rows, 0); // (row, painted count)
        vector<int> counts_y(cols, 0); // (column, painted count)

        // construct dictionary for unique values and their locations
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                locations[mat[i][j]] = {i, j};
            }
        }

        // find first row or column that satisfies requirement
        for (int i = 0; i < (int)arr.size(); ++i)
        {
            auto [x, y] = locations[arr[i]];
            counts_x[x]++;
            counts_y[y]++;
            if (counts_x[x] == cols || counts_y[y] == rows)
                return i;
        }
        return -1;
    }
};

int main()
{
    
    return 0;
}
