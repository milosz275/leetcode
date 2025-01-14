#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;

        int prev_prev = 0;
        int prev = 1;
        int current = 1;
        for (int i = 3; i <= n; ++i)
        {
            int sum = prev_prev + prev + current;
            prev_prev = prev;
            prev = current;
            current = sum;
        }
        return current;
    }
};

int main()
{
    cout << Solution().tribonacci(25) << endl;
    return 0;
}
