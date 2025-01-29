#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color)
    {
        if (color[node] > 0)
            return color[node] == 2;

        color[node] = 1; // mark as visiting
        for (int neighbor : graph[node])
        {
            if (color[neighbor] == 2)
                continue;
            if (color[neighbor] == 1 || !dfs(neighbor, graph, color))
                return false;
        }
        color[node] = 2; // mark as safe
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = (int)graph.size();
        vector<int> color(n, 0); // 0: unvisited, 1: visiting, 2: safe

        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            if (dfs(i, graph, color))
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> answer = Solution().eventualSafeNodes(graph);
    for (int el: answer)
        cout << el << " ";
    cout << '\n';
    return 0;
}
