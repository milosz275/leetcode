#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int buy_price = prices[0];
        int profit = 0;
        for (int price: prices)
        {
            if (price > buy_price)
            {
                profit += price - buy_price;
                buy_price = price;
            }
            if (price < buy_price)
            {
                buy_price = price;
            }
        }
        return profit;
    }
};

int main()
{
    vector<int> prices = { 7,1,5,3,6,4 }; // expected profit: 7
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}
