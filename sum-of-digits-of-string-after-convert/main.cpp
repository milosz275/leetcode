#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution
{
public:
    ll sum_array_digits(const vector<ll>& array)
    {
        ll sum = 0;
        for (ll el : array)
        {
            while (el > 0)
            {
                sum += el % 10;
                el /= 10;
            }
        }
        return sum;
    }

    ll transform_sum(ll sum)
    {
        ll new_sum = 0;
        while (sum > 0)
        {
            new_sum += sum % 10;
            sum /= 10;
        }
        return new_sum;
    }

    int getLucky(string s, int k)
    {
        vector<ll> array(s.size());
        for (int i = 0; i < (int)s.size(); ++i)
            array[i] = s[i] - 'a' + 1;

        ll sum = sum_array_digits(array);

        for (int i = 0; i < k - 1; ++i)
            sum = transform_sum(sum);

        return (int)sum;
    }
};

int main()
{
    string s = "fleyctuuajsr";
    int k = 5;
    cout << "output: " << Solution().getLucky(s, k) << endl;
    return 0;
}
