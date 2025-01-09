#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int get_next_index(int index, int direction, vector<int>& nums)
    {
        int n = (int)nums.size();
        int next_index = (index + nums[index]) % n;
        while (next_index < 0)
            next_index += n; 
        int next_direction = 1;
        if (nums[next_index] < 0)
            next_direction = -1;

        // cycle is only valid when pointers move in the same direction; 1 element cycles do not count
        if (direction != next_direction || index == next_index)
            return -1;

        return next_index;
    }

public:
    bool circularArrayLoop(vector<int>& nums)
    {
        set<int> visited;
        int size = (int)nums.size();

        // start from each elements of nums
        for (int i = 0; i < size; ++i)
        {
            // do not check inclusive paths
            if (visited.find(i) != visited.end())
                continue;

            int slow = i, fast = i;
            int direction = 1;
            if (nums[i] < 0)
                direction = -1;

            while (1)
            {
                visited.insert(slow);
                visited.insert(fast);
                slow = get_next_index(slow, direction, nums);
                fast = get_next_index(fast, direction, nums);
                if (slow == -1 || fast == -1)
                    break;

                fast = get_next_index(fast, direction, nums);
                if (fast == -1)
                    break;

                if (slow == fast)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> array = {-1,-2,-3,-4,-5,6}; // expected false
    cout << "output: " << Solution().circularArrayLoop(array) << endl;
    return 0;
}
