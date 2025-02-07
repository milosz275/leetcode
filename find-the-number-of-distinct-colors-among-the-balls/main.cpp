#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        vector<int> result;
        unordered_map<int, int> balls;
        unordered_map<int, int> colors;
        unordered_set<int> distinct_colors;
        
        for (const auto& query : queries)
        {
            int b = query[0], c = query[1];

            // ball already painted
            if (balls.count(b))
            {
                int old_color = balls[b];
                if (--colors[old_color] == 0)
                    distinct_colors.erase(old_color);
            }

            // assigning new color
            balls[b] = c;
            if (++colors[c] == 1)
                distinct_colors.insert(c);

            result.push_back(distinct_colors.size());
        }
        
        return result;
    }
};    

int main()
{
    // vector<vector<int>> queries = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};
    int limit = 4;
    vector<int> result = Solution().queryResults(limit, queries);
    for (int el: result)
        cout << el << ' ';
    cout << '\n';
    return 0;
}
