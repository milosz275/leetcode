#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    if (matrixSize == 1 && *matrixColSize == 1)
        return matrix[0][0] == target;

    int left = 0;
    int right = matrixSize * *matrixColSize - 1;
    int middle;

    if (matrix[0][0] > target || matrix[matrixSize - 1][*matrixColSize - 1] < target)
        return false;

    while (left <= right)
    {
        // middle coords
        middle = left + (right - left) / 2;
        int x = middle / *matrixColSize;
        int y = middle % *matrixColSize;

        if (matrix[x][y] == target)
            return true;
        else if (matrix[x][y] > target)
            right = middle - 1; // go left
        else if (matrix[x][y] < target)
            left = middle + 1; // go right
    } 
    return false;
}

int main()
{
    int matrix[3][4] = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int* matrixPtrs[3] = {matrix[0], matrix[1], matrix[2]};
    int matrixColSize = 4;
    int target = 3;

    bool result = searchMatrix(matrixPtrs, 3, &matrixColSize, target);
    printf("Result: %s\n", result ? "true" : "false");

    return 0;
}
