#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    /**
     * Removes duplicates from input vector. Non-decreasing order is assumed. Performs in-place replacement with O(n) time complexity.
     * 
     * @param nums Input number vector
     * @return Overall sum of non-repeating elements (for 1,1,2,2,2,3 it will be 5)
     */
    int removeDuplicates(vector<int>& nums)
    {
        int size = (int)nums.size();
        if (size == 1)
            return 1;
        else if (size == 2)
            return 2;

        int current_num = nums[0];
        int current_count = 1;
        int overall_count = 0;
        int k = 0;
        for (int i = 1; i < size; ++i)
        {
            if (nums[i] != current_num)
            {
                if (current_count == 1)
                {
                    nums[k] = current_num;
                    k++;
                    overall_count++;
                }
                else if (current_count >= 2)
                {
                    nums[k] = nums[k + 1] = current_num;
                    k += 2;
                    overall_count += 2;
                }
                else
                    exit(1);
                current_num = nums[i];
                current_count = 0;
            }
            if (i + 1 == size)
            {
                current_count++;
                if (current_count == 1)
                {
                    nums[k] = current_num;
                    k++;
                    overall_count++;
                }
                else if (current_count >= 2)
                {
                    nums[k] = nums[k + 1] = current_num;
                    k += 2;
                    overall_count += 2;
                }
                else
                    exit(1);
            }
            if (nums[i] == current_num)
                current_count++;
        }
        return overall_count;
    }
};

void print_n_vector_elements(vector<int>& array, int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main()
{
    vector<int> nums = { 0,0,1,1,1,1,2,3,3 };
    print_n_vector_elements(nums, (int)nums.size());

    Solution solution;
    int k = solution.removeDuplicates(nums);
    std::cout << "k: " << k << std::endl;
    print_n_vector_elements(nums, k);

    return 0;
}
