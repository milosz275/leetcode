#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> chars;
        for (char el: s)
        {
            char top = '\0';
            if (!chars.empty())
                top = chars.top();
            switch (el)
            {
                case ')':
                    if (top != '\0' && top == '(')
                        chars.pop();
                    else
                        return false;
                    break;
                case ']':
                    if (top != '\0' && top == '[')
                        chars.pop();
                    else
                        return false;
                    break;
                case '}':
                    if (top != '\0' && top == '{')
                        chars.pop();
                    else
                        return false;
                    break;
                default:
                    chars.push(el);
                    break;
            }
        }
        if (!chars.empty())
            return false;
        return true;
    }
};

int main()
{
    
    return 0;
}
