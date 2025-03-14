#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long coloredCells(int n)
    {
        long long m = n;
        return (m * m) + ((m - 1) * (m - 1));
    }
};

int main()
{
    cout << "output: " << Solution().coloredCells(3) <<'\n';
    return 0;
}
