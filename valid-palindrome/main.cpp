#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int length = (int)s.length();
        int left = 0;
        int right = length - 1;
        while (left < right)
        {
            while (left < right && (!isalpha(s[left]) && !isdigit(s[left])))
                left++;

            while (left < right && (!isalpha(s[right]) && !isdigit(s[right])))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string input = "A man, a plan, a canal: Panama";
    std::cout << "Input: " << input << "; is palindrome? " << solution.isPalindrome(input) << std::endl;

    return 0;
}
