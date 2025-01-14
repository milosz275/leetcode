#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, list<int>> prereq_map; // int - node, list<int> - the node's prerequisites
        for (vector<int>& node_prereq: prerequisites)
        {
            int node = node_prereq[0];
            for (int i = 1; i < (int)node_prereq.size(); ++i)
                (prereq_map[node]).push_back(node_prereq[i]);
        }
        
        set<int> visited;
        set<int> rec_stk; // recursion stack
        stack<int> node_stack;

        int n = numCourses;
        for (int i = 0; i < n; ++i)
        {
            if (visited.find(i) == visited.end())
            {
                node_stack.push(i);
                while (!node_stack.empty())
                {
                    int node = node_stack.top();
                    if (rec_stk.find(node) == rec_stk.end())
                    {
                        rec_stk.insert(node);
                        for (int neighbor : prereq_map[node])
                        {
                            if (rec_stk.find(neighbor) != rec_stk.end())
                                return false; // cycle detected
                            if (visited.find(neighbor) == visited.end())
                                node_stack.push(neighbor);
                        }
                    }
                    else
                    {
                        node_stack.pop();
                        rec_stk.erase(node);
                        visited.insert(node);
                    }
                }
            }
        }
        return true; // no cycle detected
    }
};
