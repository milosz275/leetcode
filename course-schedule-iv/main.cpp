#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        unordered_map<int, list<int>> adj; // (course, its prerequisites)
        for (const auto& prereq : prerequisites)
            adj[prereq[1]].push_back(prereq[0]);

        unordered_map<int, unordered_set<int>> prereq_map; // map course -> hashset of indirect prerequisites

        function<void(int)> dfs = [&](int course) 
        {
            if (prereq_map.count(course))
                return;
            prereq_map[course] = unordered_set<int>();
            for (int prereq : adj[course])
            {
                dfs(prereq);
                prereq_map[course].insert(prereq);
                prereq_map[course].insert(prereq_map[prereq].begin(), prereq_map[prereq].end());
            }
        };

        for (int course = 0; course < numCourses; ++course)
            dfs(course);

        vector<bool> res;
        for (const auto& query : queries)
            res.push_back(prereq_map[query[1]].count(query[0]));

        return res;
    }
};

int main()
{

    return 0;
}
