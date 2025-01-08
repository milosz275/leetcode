#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long continuousSubarrays(vector<int>& nums)
    {
        int n = (int)nums.size();
        int left = 0;
        long long count = 0;
        deque<int> max_deque, min_deque;

        for (int right = 0; right < n; ++right)
        {
            // add the current element to the max deque
            while (!max_deque.empty() && nums[max_deque.back()] < nums[right])
                max_deque.pop_back();
            max_deque.push_back(right);

            // add the current element to the min deque
            while (!min_deque.empty() && nums[min_deque.back()] > nums[right])
                min_deque.pop_back();
            min_deque.push_back(right);

            // shrink the window if the condition is violated
            while (nums[max_deque.front()] - nums[min_deque.front()] > 2)
            {
                ++left;
                if (!max_deque.empty() && max_deque.front() < left)
                    max_deque.pop_front();
                if (!min_deque.empty() && min_deque.front() < left)
                    min_deque.pop_front();
            }

            // count valid subarrays ending at 'right'
            count += (right - left + 1);
        }
        return count;
    }
};

int main()
{
    vector<int> array = {5,4,2,4};
    cout << Solution().continuousSubarrays(array) << endl;
    return 0;
}
