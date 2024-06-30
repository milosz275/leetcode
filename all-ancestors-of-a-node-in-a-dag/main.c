#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **getAncestors(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = n;
    int **array = (int **)malloc(sizeof(int *) * *returnSize);
    for (int i = 0; i < n; ++i)
        array[i] = NULL;


    int edge_list[9][2] = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    for (int i = 0; i < edgesSize; ++i)
    {
        assert(edges[i][0] == edge_list[i][0] && edges[i][1] == edge_list[i][1]);
        int ancestor = edges[i][0];
        int child = edges[i][1];
        if (array[child] == NULL)
        {
            printf("Creating array for node %d\n", child);
            array[child] = (int *)calloc(n, sizeof(int));
            if (array[child] == NULL)
            {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            array[child][0] = ancestor;
        }
        else
        {
            printf("Adding ancestor %d to node %d\n", ancestor, child);
            int j = 0;
            while (array[child][j] != 0 && j < n - 1) j++;
            if (j == n - 1)
            {
                fprintf(stderr, "Array is full, cannot add new ancestor\n");
                exit(EXIT_FAILURE);
            }
            array[child][j] = ancestor;
        }

        assert(edges[i][0] == edge_list[i][0] && edges[i][1] == edge_list[i][1]);
    }
    printf("Successfully exited getting ancestors.\n");
    return array;
}

int main()
{
    int n = 8;
    int edges_size = 9;
    int edge_list[9][2] = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    int *edges[9] = {NULL};
    for (int i = 0; i < edges_size; ++i)
        edges[i] = edge_list[i];
    int edges_col_size = 2;
    int return_size = n;
    int *return_column_sizes = (int *)malloc(sizeof(int) * n);
    int **array = getAncestors(n, edges, edges_size, &edges_col_size, &return_size, &return_column_sizes);
    
    for (int i = 0; i < n; ++i)
        printf("Node %d - Return column size: %d\n", i, return_column_sizes[i]);

    exit(EXIT_SUCCESS);
}
