#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int compare(const void* a, const void* b)
{
    int int_a = *((int*) a);
    int int_b = *((int*) b);

    if (int_a == int_b)
        return 0;
    else if (int_a < int_b)
        return -1;
    else
        return 1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **getAncestors(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize, int **returnColumnSizes)
{
    // preallocation
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    int **array = (int **)malloc(sizeof(int *) * *returnSize);
    for (int i = 0; i < n; ++i)
    {
        array[i] = (int *)malloc(sizeof(int) * n);
        for (int j = 0; j < n; ++j)
            array[i][j] = -1;
        (*returnColumnSizes)[i] = 0;
    }

    int edge_list[9][2] = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};

    // handling edges one by one
    for (int i = 0; i < edgesSize; ++i)
    {
        assert(edges[i][0] == edge_list[i][0] && edges[i][1] == edge_list[i][1]);

        // current path
        int ancestor = edges[i][0];
        int child = edges[i][1];

        // setting j to point after last member
        int j = 0;
        while (array[child][j] != -1 && j < n - 1) j++;
        if (j == n - 1)
        {
            fprintf(stderr, "Array is full, cannot add new ancestor\n");
            exit(EXIT_FAILURE);
        }

        // indirect ancestors
        if (array[ancestor])
            for (int k = 0; k < (*returnColumnSizes)[ancestor]; ++k)
            {
                printf("Adding not-direct ancestor %d to node %d\n", array[ancestor][k], child);
                array[child][j] = array[ancestor][k];
                (*returnColumnSizes)[child]++;
                j++;
                if (j == n - 1)
                {
                    fprintf(stderr, "Array is full, cannot add new ancestor\n");
                    exit(EXIT_FAILURE);
                }
            }

        printf("Adding ancestor %d to node %d\n", ancestor, child);
        array[child][j] = ancestor;
        (*returnColumnSizes)[child]++;

        assert(edges[i][0] == edge_list[i][0] && edges[i][1] == edge_list[i][1]);
    }

    // sort results
    for (int i = 0; i < n; ++i)
        qsort(array[i], (*returnColumnSizes)[i], sizeof(int), compare);

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
    int *return_column_sizes = NULL;
    int **array = getAncestors(n, edges, edges_size, &edges_col_size, &return_size, &return_column_sizes);

    for (int i = 0; i < n; ++i)
    {
        printf("Node %d:\n", i);
        for (int j = 0; j < return_column_sizes[i]; ++j)
            printf("%d ", array[i][j]);
        putchar('\n');
    }

    exit(EXIT_SUCCESS);
}
