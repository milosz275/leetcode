#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "compare.c"

#define NUMS1_SIZE 4
#define NUMS2_SIZE 2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    *returnSize = 0;
    if (nums1Size == 0 || nums2Size == 0 || nums1Size > 1000 || nums2Size > 1000)
        return NULL;

    int *intersecting_array = NULL;

    // make sure first is always the smaller array
    if (nums1Size > nums2Size)
    {
        int tmp = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tmp;
        int *tmp_array = nums1;
        nums1 = nums2;
        nums2 = tmp_array;
    }
    intersecting_array = (int *)malloc(sizeof(int) * nums1Size);

    // sort the arrays
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);

    printf("Sorted arrays:\n");
    for (int i = 0; i < nums1Size; ++i)
        printf("%d ", nums1[i]);
    printf("\n");
    for (int i = 0; i < nums2Size; ++i)
        printf("%d ", nums2[i]);
    printf("\n");

    for (int i = 0, j = 0, k = 0; i < nums1Size && j < nums2Size;)
    {
        if (nums1[i] == nums2[j])
        {
            intersecting_array[k++] = nums1[i];
            ++i;
            ++j;
            ++(*returnSize);
        }
        else if (nums1[i] < nums2[j])
            ++i;
        else
            ++j;
    }

    return intersecting_array;
}

int main()
{
    int *nums = (int *)malloc(sizeof(int) * NUMS1_SIZE);
    int *nums2 = (int *)malloc(sizeof(int) * NUMS2_SIZE);

    nums[0] = 1, nums[1] = 2, nums[2] = 2, nums[3] = 1;
    nums2[0] = 2, nums2[1] = 2;

    int *returnSize = (int *)malloc(sizeof(int));
    int *intersecting_array = intersect(nums, NUMS1_SIZE, nums2, NUMS2_SIZE, returnSize);

    printf("Intersecting array:\n");
    for (int i = 0; i < *returnSize; ++i)
    {
        printf("%d ", intersecting_array[i]);
    }
    printf("\n");

    free(nums);
    free(nums2);
    free(returnSize);
    free(intersecting_array);

    return 0;
}
