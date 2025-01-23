#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }

    vector<string> simplifiedFractions(int n)
    {
        queue<pair<int, int>> to_process;
        for (int i = 1; i <= n - 1; ++i)
        {
            for (int j = 2; j <= n; ++j)
            {
                if (j <= i)
                    continue;
                to_process.push({i, j});
            }
        }
        
        vector<string> answer;
        answer.reserve(to_process.size());

        while (!to_process.empty())
        {
            if (gcd(to_process.front().first, to_process.front().second) == 1)
            {
                string str = to_string(to_process.front().first) + '/' + to_string(to_process.front().second);
                answer.push_back(str);
            }
            to_process.pop();
        }

        return answer;
    }
};

int main()
{
    vector<string> answer = Solution().simplifiedFractions(4);
    for (string& s: answer)
        cout << s << " ";
    cout << '\n';
    return 0;
}
