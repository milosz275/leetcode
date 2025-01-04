#include <iostream>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        int prev1 = 2;
        int prev2 = 1;
        for (int i = 3; i <= n; ++i)
        {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};

int main()
{
    int n = 5;
    Solution sol;
    cout << sol.climbStairs(n) << endl;
    return 0;
}
