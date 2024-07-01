#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_SIZE 5

int find_maximum(int *array, int arraySize)
{
    if (arraySize <= 0)
        return INT_MIN;
    int max = array[0];
    for (int i = 1; i < arraySize; ++i)
        if (array[i] > max)
            max = array[i];
    return max;
}

int find_maximum_ignore(int *array, int arraySize, int ignoreValue)
{
    if (arraySize <= 0)
        return INT_MIN;
    int max = array[0];
    for (int i = 1; i < arraySize; ++i)
        if (array[i] > max && array[i] != ignoreValue)
            max = array[i];
    return max;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
    *returnSize = candiesSize;
    if (candiesSize <= 0)
        return NULL;
    bool *result = (bool*)malloc(candiesSize * sizeof(bool));
    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < candiesSize; ++i)
    {
        int *partial_candies = (int*)malloc((candiesSize - 1) * sizeof(int));
        for (int j = 0, k = 0; j < candiesSize; ++j)
        {
            if (j == i)
                continue;
            partial_candies[k++] = candies[j];
        }
        int max = find_maximum(partial_candies, candiesSize - 1);
        if (candies[i] + extraCandies >= max)
            result[i] = true;
        else
            result[i] = false;
    }
    return result;
}

int main()
{
    int candies[NUM_SIZE] = {2, 3, 5, 1, 3};
    int extra_candies = 3;
    int *return_size = (int*)malloc(sizeof(int));
    bool *result = kidsWithCandies(candies, NUM_SIZE, extra_candies, return_size);
    printf("Answer:");
    for (int i = 0; i < *return_size; ++i)
        printf("%d ", result[i]);
    putchar('\n');
    exit(EXIT_SUCCESS);
}
