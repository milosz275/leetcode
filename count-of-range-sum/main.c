#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_SIZE 3
#define LOWER -2
#define UPPER 2

struct Sum
{
    long x;
    long y;
    long sum;
};

struct Sum *sums;
int currentSize = 0;

long getSum(long x, long y)
{
    for (int i = 0; i < currentSize; ++i)
        if ((sums[i].x == x && sums[i].y == y) || (sums[i].y == x && sums[i].x == y))
            return sums[i].sum;
    
    sums = (struct Sum *)realloc(sums, sizeof(struct Sum) * (currentSize + 1));
    if (sums == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    sums[currentSize].x = x;
    sums[currentSize].y = y;
    sums[currentSize].sum = x + y;
    currentSize++;
    return sums[currentSize - 1].sum;
}

int countRangeSum(int* nums, int numsSize, int lower, int upper)
{
    sums = (struct Sum *)malloc(sizeof(struct Sum) * 1);
    if (sums == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    sums[0].x = 0;
    sums[0].y = 0;
    sums[0].sum = 0;
    currentSize = 1;

    int rangeCount = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        long sum = 0;
        for (int j = i; j < numsSize; ++j)
        {
            sum = getSum(sum, nums[j]);
            if (sum >= lower && sum <= upper)
                rangeCount++;
        }
    }
    return rangeCount;
}

int init()
{
    int nums[NUM_SIZE] = { -2, 5, -1 };
    int result = countRangeSum(nums, NUM_SIZE, LOWER, UPPER);
    printf("Range sum count: %d\n", result);

    free(sums);
}
