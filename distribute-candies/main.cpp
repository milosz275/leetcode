#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int>& candyType)
    {
        unordered_set<int> candies(candyType.begin(), candyType.end());
        return min((int)candyType.size() / 2, (int)candies.size());
    }
};

int main()
{
    vector<int > candy_type = {1, 1, 2, 2, 3, 3};
    cout << "output:" << Solution().distributeCandies(candy_type) << '\n';
    return 0;
}
