#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string getHappyString(int n, int k)
    {
        // if k is larger than possible combinations return ""
        int combinations = 3 * (int)pow(2, n - 1);
        if (k > combinations)
            return "";
        
        // for (a, b, c) as characters the is exactly combination/3 sequences starting with each char
        int starting_with_the_same_letter = combinations / 3;

        // build result from the first char
        string result("");
        if (k <= starting_with_the_same_letter)
            result += 'a';
        else if (k > starting_with_the_same_letter && k <= 2 * starting_with_the_same_letter)
            result += 'b';
        else
            result += 'c';

        // k is adjusted after first char is built
        k = k % starting_with_the_same_letter;
        if (k == 0)
            k = starting_with_the_same_letter;

        // iteratively construct the rest of the answer
        int half = starting_with_the_same_letter / 2;
        for (int i = 1; i < n; ++i)
        {
            char prev_char = result.back();
            char first_choice, second_choice;

            switch (prev_char)
            {
            case 'a':
                first_choice = 'b';
                second_choice = 'c';
                break;
            case 'b':
                first_choice = 'a';
                second_choice = 'c';
                break;
            default:
                first_choice = 'a';
                second_choice = 'b';
                break;
            }

            if (k <= half)
                result += first_choice;
            else
            {
                result += second_choice;
                k -= half;
            }
            half /= 2;
        }
        return result;
    }
};

int main()
{
    cout << "output: " << Solution().getHappyString(3, 9) << '\n';
    return 0;
}
