#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int num2_set_bits = __builtin_popcount(num2);
        int x = 0;

        for (int i = 31; i >= 0 && num2_set_bits > 0; --i)
        {
            if (num1 & (1 << i))
            {
                x |= (1 << i);
                num2_set_bits--;
            }
        }

        for (int i = 0; i < 32 && num2_set_bits > 0; ++i)
        {
            if ((x & (1 << i)) == 0)
            {
                x |= (1 << i);
                num2_set_bits--;
            }
        }

        return x;
    }
};

int main()
{
    // cout << Solution().minimizeXor(3, 5) << endl;
    cout << Solution().minimizeXor(1, 12) << endl;
    return 0;
}
