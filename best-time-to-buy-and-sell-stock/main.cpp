#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int length = (int)prices.size();
        if (length <= 1)
            return 0;
        int maximal_profit = 0;
        int buy_price = prices[0];
        for (int i = 1; i < length; ++i)
        {
            if (prices[i] < buy_price)
                buy_price = prices[i];
            else if (prices[i] > buy_price)
                maximal_profit = max(maximal_profit, prices[i]);
        }
        return maximal_profit;
    }
};

int main()
{
    // vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    vector<int> prices = { 2, 1, 4 };
    Solution sol;
    cout << "output: " << sol.maxProfit(prices) << endl;
    return 0;
}
