#include <bits/stdc++.h>

using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution
{
public:
    int minCost(vector<vector<int>>& grid)
    {
        unordered_map<int, pair<int, int>> direction; // direction num, (row, column)
        direction[1] = {0, 1}; 
        direction[2] = {0, -1};
        direction[3] = {1, 0};
        direction[4] = {-1, 0};

        int rows = (int)grid.size(), cols = (int)grid[0].size();
        deque<tuple<int, int, int>> q; // (row, column, cost)
        q.push_back({0, 0, 0}); // upper left corner
        
        unordered_map<pair<int, int>, int, pair_hash> min_cost;
        min_cost[{0, 0}] = 0;

        while (!q.empty())
        {
            auto [row, col, cost] = q.front();
            q.pop_front();

            if (row == rows - 1 && col == cols - 1)
                return cost;

            for (auto dir: direction) // dir is a (key, value), where key is 1-4 and value is (row, col)
            {
                auto [d_row, d_col] = dir.second;
                int n_row = d_row + row;
                int n_col = d_col + col;

                int n_cost = cost;
                if (dir.first != grid[row][col])
                    n_cost++;

                if (n_row < 0 || n_col < 0 || n_row >= rows || n_col >= cols || (min_cost.find({n_row, n_col}) != min_cost.end() && n_cost >= min_cost[{n_row, n_col}]))
                    continue;

                min_cost[{n_row, n_col}] = n_cost;
                if (dir.first == grid[row][col])
                    q.push_front({n_row, n_col, n_cost});
                else
                    q.push_back({n_row, n_col, n_cost});
            }
        }
        return min_cost[{rows - 1, cols - 1}];
    }
};

int main()
{
    vector<vector<int>> grid = {{1,1,1,1}, {2,2,2,2}, {1,1,1,1}, {2,2,2,2}};
    cout << Solution().minCost(grid) << '\n';
    return 0;
}
