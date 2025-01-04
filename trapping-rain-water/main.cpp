#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int total_volume = 0;
        int left = 0; // left index
        int right = height.size() - 1; // right index
        int left_max = 0; // max height searching from left
        int right_max = 0; // max height searching from right

        // scan: left -->> <<-- right
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= left_max) // update maximum height on the left
                    left_max = height[left];
                else // add water volume
                    total_volume += left_max - height[left];
                left++;
            }
            else
            {
                if (height[right] >= right_max) // update maximum height on the right
                    right_max = height[right];
                else // add water volume
                    total_volume += right_max - height[right];
                right--;
            }
        }
        return total_volume;
    }
};

int main()
{
    vector<int> terrain = {1,3,2,4,1,3,1,4,5,2,2,1,4,2,2}; // expected 15
    // vector<int> terrain = {0,1,0,2,1,0,1,3,2,1,2,1}; // expected 6
    // vector<int> terrain = {4,2,0,3,2,5}; // expected 9
    Solution sol;
    cout << "Volume of the lakes: " << sol.trap(terrain) << endl;
    return 0;
}
