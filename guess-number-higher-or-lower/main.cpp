#include <bits/stdc++.h>

#define N 10

using namespace std;

/** 
 * Guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num)
{
    // static int random = rand() % N;
    int random = 6;
    if (num > random)
        return -1;
    else if (num < random)
        return 1;
    else
        return 0;
}

class Solution
{
public:
    int guessNumber(int n)
    {
        int left = 1;
        int right = n;
        int mid = left + (right - left) / 2;
        cout << "guessing with " << mid << endl;
        int api_response = guess(mid);
        while (api_response != 0)
        {
            if (api_response == 1) // 1 - to small
                left = mid + 1;
            else if (api_response == -1) // -1 - to big
                right = mid - 1;
            else
                throw runtime_error("API response error");
            mid = left + (right - left) / 2;
            cout << "guessing with " << mid << endl;
            api_response = guess(mid);
        }
        return mid;
    }
};

int main()
{
    cout << Solution().guessNumber(10) << endl;
    return 0;
}
