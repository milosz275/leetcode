#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> answer(n + 1, 0);
        
        for (int i = 0; i <= n; ++i)
            answer[i] = answer[i >> 1] + (i & 1);

        return answer;
    }
};

int main()
{
    int n = 5;
    vector<int> output = Solution().countBits(n);
    for (int el : output)
        cout << el << " ";
    cout << endl;
    return 0;
}

//  0 0     0
//  1 1     1
//  2 10    1
//  3 11    2
//  4 100   1
//  5 101   2
//  6 110   2
//  7 111   3
//  8 1000  1
//  9 1001  2
// 10 1010  2
// 11 1011  3
// 12 1100  2
// 13 1101  3
// 14 1110  3
// 15 1111  4
// 16 10000 1
