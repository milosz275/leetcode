#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int sumBase(int n, int k)
    {
        if (k < 2 || k > 10)
            throw runtime_error("Wrong base");

        int sum = 0;
        while (n > 0)
        {
            sum += n % k;
            n /= k;
        }
        return sum;
    }
};

int main()
{
    int n = 34;
    int k = 6;
    try
    {
        cout << Solution().sumBase(n, k) << endl;
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}
