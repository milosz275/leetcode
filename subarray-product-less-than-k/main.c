#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_SIZE 4
#define K 100

int numSubarrayProductLessThanK(int* nums, int numsSize, int k)
{
    int subarrayCount = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        int product = 1;
        for (int j = i; j < numsSize; ++j)
        {
            product *= nums[j];
            if (product < k)
                ++subarrayCount;
            else
                break;
        }
    }
    return subarrayCount;
}

int main()
{
    int nums[NUM_SIZE] = { 10, 5, 2, 6 };
    int result = numSubarrayProductLessThanK(nums, NUM_SIZE, K);
    printf("Subarray product less than k count: %d\n", result);
    return 0;
}
