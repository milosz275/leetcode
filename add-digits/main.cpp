#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        return 1 + (num - 1) % 9;        
    }
};

int main()
{
    cout << Solution().addDigits(12345) << endl;
    return 0;
}
