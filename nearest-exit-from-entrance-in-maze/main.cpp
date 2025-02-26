#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        int m = (int)maze.size(), n = (int)maze[0].size();

        vector<vector<bool>> visited(m, vector(n, false)); // each field is not visited

        // x and y as entrance
        int x = entrance[0], y = entrance[1];
        visited[x][y] = true; // entrance is visited

        // add neighbors of the entrance to the processing queue
        queue<pair<int, int>> steps;
        if (x - 1 >= 0 && maze[x - 1][y] == '.')
            steps.push({x - 1, y});
        if (x + 1 < m && maze[x + 1][y] == '.')
            steps.push({x + 1, y});
        if (y - 1 >= 0 && maze[x][y - 1] == '.')
            steps.push({x, y - 1});
        if (y + 1 < n && maze[x][y + 1] == '.')
            steps.push({x, y + 1});
        if (steps.empty())
            return -1;
        
        // searching for the nearest exit in each direction
        int level = 1;
        while (!steps.empty())
        {
            int size = steps.size();
            for (int i = 0; i < size; ++i)
            {
                auto [x, y] = steps.front();
                steps.pop();
                // cout << "Current x: " << x << "; current y: " << y << endl;

                if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
                    return level;
                    
                if (x - 1 >= 0 && maze[x - 1][y] == '.' && !(visited[x - 1][y]))
                {
                    steps.push({x - 1, y});
                    visited[x - 1][y] = true;
                }
                if (x + 1 < m && maze[x + 1][y] == '.' && !(visited[x + 1][y]))
                {
                    steps.push({x + 1, y});
                    visited[x + 1][y] = true;
                }
                if (y - 1 >= 0 && maze[x][y - 1] == '.' && !(visited[x][y - 1]))
                {
                    steps.push({x, y - 1});
                    visited[x][y - 1] = true;
                }
                if (y + 1 < n && maze[x][y + 1] == '.' && !(visited[x][y + 1]))
                {
                    steps.push({x, y + 1});
                    visited[x][y + 1] = true;    
                }
            }
            // level is only incremented when whole level is handled
            level++;
        }
        return -1;
    }
};

int main()
{
    // vector<vector<char>> maze = {{'+','+','.','+'} ,{'.','.','.','+'}, {'+','+','+','.'}};
    // vector<int> entrance = {1, 2};
    vector<vector<char>> maze = {{'+','+','+'} ,{'.','.','.'}, {'+','+','+'}};
    vector<int> entrance = {1, 0};
    cout << "output: " << Solution().nearestExit(maze, entrance) << '\n';
    return 0;
}
