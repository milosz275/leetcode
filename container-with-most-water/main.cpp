#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int left = 0;
        int right = (int)height.size() - 1;
        int volume = min(height[left], height[right]) * abs(right - left);
        while (left < right)
        {
            // move pointer that points to lower value
            if (height[left] < height[right])
                left++;
            else
                right--;
            
            // cout << "volume: " << volume << "; new_volume: " << new_volume << endl;
            volume = max(volume, min(height[left], height[right]) * abs(right - left));
        }
        return volume;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    // vector<int> height = {1,2,1};
    Solution sol;
    cout << sol.maxArea(height) << endl;
    return 0;
}
