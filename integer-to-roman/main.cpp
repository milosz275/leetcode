#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    vector<pair<int, string>> roman;
public:
    Solution()
    {
        roman =
        {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
    }

    string intToRoman(int num)
    {
        string result = "";
        for (const auto& [value, symbol] : roman)
        {
            while (num >= value)
            {
                result.append(symbol);
                num -= value;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int num = 3749;
    std::cout << num << " to Roman is: " << solution.intToRoman(num) << std::endl;
    num = 58;
    std::cout << num << " to Roman is: " << solution.intToRoman(num) << std::endl;
    num = 1994;
    std::cout << num << " to Roman is: " << solution.intToRoman(num) << std::endl;
    return 0;
}
