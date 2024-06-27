#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_SIZE 4
#define K 100

int num_subarray_product_less_than_k(int* nums, int nums_size, int k)
{
    int subarray_count = 0;
    for (int i = 0; i < nums_size; ++i)
    {
        int product = 1;
        for (int j = i; j < nums_size; ++j)
        {
            product *= nums[j];
            if (product < k)
                ++subarray_count;
            else
                break;
        }
    }
    return subarray_count;
}

int main()
{
    int nums[NUM_SIZE] = { 10, 5, 2, 6 };
    int result = num_subarray_product_less_than_k(nums, NUM_SIZE, K);
    printf("Subarray product less than k count: %d\n", result);
    return 0;
}
