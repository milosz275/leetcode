#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<int> temp_ind; // temperature indices - monotonic stack
        int size = (int)temperatures.size();
        vector<int> days(size, 0);
        for (int i = 0; i < size; ++i)
        {
            while (!temp_ind.empty() && temperatures[i] > temperatures[temp_ind.top()])
            {
                days[temp_ind.top()] = i - temp_ind.top();
                temp_ind.pop();
            }
            temp_ind.push(i);
        }
        return days;
    }
};

int main()
{

    return 0;
}
