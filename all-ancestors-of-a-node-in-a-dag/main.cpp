#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

/**
 * Depth-first search traversal of a directed acyclic graph. Function performs a DFS traversal of the graph starting from the given node.
 * @param graph Adjacency list of the graph.
 * @param node Current node.
 * @param ancestor Ancestor node.
 * @param visited Array to keep track of visited nodes.
 * @param ancestors Array to store ancestors of each node.
 */
void dfs(std::vector<std::vector<int>>& graph, int node, int ancestor, std::vector<bool>& visited, std::vector<std::vector<int>>& ancestors)
{
    visited[node] = true;
    if (node != ancestor)
        ancestors[node].push_back(ancestor);

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(graph, neighbor, ancestor, visited, ancestors);
        }
    }
}

class Solution
{
public:
    /**
     * Get all ancestors of each node in a directed acyclic graph. Member function returns a 2D vector where each row represents the ancestors of a node.
     */
    std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> ancestors(n);

        std::vector<std::vector<int>> graph(n);
        for (std::vector<int>& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++)
        {
            std::vector<bool> visited(n, false);
            dfs(graph, i, i, visited, ancestors);
        }

        return ancestors;
    }
};

int main()
{
    int n = 8;
    std::vector<std::vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};

    Solution solution;
    auto ancestors = solution.getAncestors(n, edges);

    for (int i = 0; i < n; i++)
    {
        std::cout << "Ancestors of node " << i << ": ";
        for (int ancestor : ancestors[i])
        {
            std::cout << ancestor << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
