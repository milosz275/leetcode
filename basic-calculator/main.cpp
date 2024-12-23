#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int evaluate(int current_value, int total_value, char operation)
    {
        switch (operation)
        {
        case '+':
            total_value += current_value;
            break;
        case '-':
            total_value -= current_value;
            break;
        default:
            break;
        }
        return total_value;
    }

    int calculate(string s)
    {
        int total_value = 0;

        stringstream str_st(s);
        bool contains_opening_bracket = false;
        char current_sign;
        str_st >> current_sign;
        if (current_sign == '+' || current_sign == ')')
            throw runtime_error(string("Invalid syntax: s string starts with ") + current_sign);
        while (str_st >> current_sign)
        {
            if (current_sign == ')')
                throw runtime_error("Invalid syntax: closing bracket appears before opening bracket");
            if (current_sign == '(')
            {
                contains_opening_bracket = true;
                break;
            }
        }

        // base case - no brackets
        if (!contains_opening_bracket)
        {
            stringstream str_st(s);
            bool is_first = true;
            char operation = '\0';
            int current_value = 0;
            int current_radix_value = 1;
            
            while (str_st >> current_sign)
            {
                if (isdigit(current_sign))
                {
                    current_value *= current_radix_value;
                    current_value += atoi(string(1, current_sign).c_str());
                    current_radix_value *= 10;
                }
                else // current sign is a new operation
                {
                    current_radix_value = 1;

                    if (is_first)
                    {
                        if (operation == '-')
                            total_value -= current_value;
                        else
                            total_value += current_value;
                        current_value = 0;
                        is_first = false;
                    }
                    else // handle operation before overwriting
                    {
                        total_value = evaluate(current_value, total_value, operation);
                        current_value = 0;
                    }

                    operation = current_sign;
                }
            }

            // last number was not evaluated due to stream end
            return evaluate(current_value, total_value, operation);
        }
        else // recursive case
        {
            stack<int> bracket_indices;
            for (int i = 0; i < (int)s.size(); ++i)
            {
                if (s[i] == '(')
                    bracket_indices.push(i);
                else if (s[i] == ')')
                {
                    if (bracket_indices.empty())
                        throw runtime_error("Invalid syntax: unmatched closing bracket");

                    int start = bracket_indices.top(); // matching opening bracket index
                    bracket_indices.pop();

                    string inner_expression = s.substr(start + 1, i - start - 1);
                    int inner_result = calculate(inner_expression);

                    // merge evaluated part into original s
                    string left_part = s.substr(0, start); // before opening bracket
                    string right_part = s.substr(i + 1); // after closing bracket
                    s = left_part + to_string(inner_result) + right_part;

                    // update location after merging result
                    i = start - 1;
                }
            }

            if (!bracket_indices.empty())
                throw runtime_error("Invalid syntax: unmatched opening bracket");

            return calculate(s);
        }

        return total_value;
    }
};

int main()
{
    Solution sol;
    string s = "(1+(4+5+2)-3)+(6+8)";
    // string s = " 21-1 + 28 - 8-2";
    try
    {
        sol.calculate(s);
        //cout << s << " = " << sol.calculate(s) << endl;
    }
    catch (const std::runtime_error& ex)
    {
        cout << ex.what() << endl;
    }
    return 0;
}
