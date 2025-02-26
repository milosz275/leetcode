#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if ((int)edges.size() != n - 1)
            return false;

        // building adjacency list
        unordered_map<int, list<int>> adj;
        for (const auto& edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        stack<pair<int, int>> s; // stack to store (node, parent)
        s.push({0, -1}); // start DFS from node 0 with parent -1
        vector<bool> visited(n, false); // vector to track visited nodes
        int processed = 0;

        while (!s.empty())
        {
            auto [node, parent] = s.top();
            s.pop();

            if (visited[node])
                return false;

            visited[node] = true;
            processed++;

            for (int neighbor: adj[node])
            {
                if (!visited[neighbor])
                    s.push({neighbor, node});
                else if (neighbor != parent)
                    return false; // cycle detected
            }
        }

        return processed == n; // check if all nodes are visited
    }
};
    
int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << "output: " << Solution().validTree(5, edges) << '\n';
    return 0;
}
