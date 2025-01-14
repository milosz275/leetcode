#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        set<char> characters;
        for (char c: s)
        {
            if (characters.find(c) != characters.end())
                return c;
            else
                characters.insert(c);
        }
        return '\0';
    }
};

int main()
{

    return 0;
}
