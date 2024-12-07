#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {
        // ban hash map
        unordered_set<int> ban_map(banned.begin(), banned.end());

        // set up counters
        int sum = 0;
        int count = 0;

        // count elements that are not banned
        for (int i = 1; i <= n; ++i)
        {
            if (ban_map.find(i) == ban_map.end()) // occurrence of n = i not found in banned
            {
                if (sum + i > maxSum)
                    return count;
                sum += i;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> banned = { 1, 6, 5 };
    int n = 5;
    int max_sum = 6;
    Solution solution;
    std::cout << "Max count: " << solution.maxCount(banned, n, max_sum) << std::endl;

    return 0;
}
