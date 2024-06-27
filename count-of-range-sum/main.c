#include <stdio.h>
#include <stdlib.h>

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
int current_size = 0;

long get_sum(long x, long y)
{
    for (int i = 0; i < current_size; ++i)
        if ((sums[i].x == x && sums[i].y == y) || (sums[i].y == x && sums[i].x == y))
            return sums[i].sum;

    sums = (struct Sum *)realloc(sums, sizeof(struct Sum) * (current_size + 1));
    if (sums == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    sums[current_size].x = x;
    sums[current_size].y = y;
    sums[current_size].sum = x + y;
    current_size++;
    return sums[current_size - 1].sum;
}

int count_range_sum(int* nums, int nums_size, int lower, int upper)
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
    current_size = 1;

    int rangeCount = 0;
    for (int i = 0; i < nums_size; ++i)
    {
        long sum = 0;
        for (int j = i; j < nums_size; ++j)
        {
            sum = get_sum(sum, nums[j]);
            if (sum >= lower && sum <= upper)
                rangeCount++;
        }
    }
    return rangeCount;
}

int main()
{
    int nums[NUM_SIZE] = { -2, 5, -1 };
    int result = count_range_sum(nums, NUM_SIZE, LOWER, UPPER);
    printf("Range sum count: %d\n", result);
    free(sums);
    exit(EXIT_SUCCESS);
}
