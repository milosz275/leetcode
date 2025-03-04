#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while (n > 0)
        {
            int remainder = n % 3;
            if (remainder == 2)
                return false;
            n /= 3;
        }
        return true;
    }
};

int main()
{
    cout << "output: " << Solution().checkPowersOfThree(12) <<'\n';
    return 0;
}
