#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b)
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

int remove_duplicates_in_sorted_array(int *array, int size)
{
    if (size == 0)
        return 0;

    int j = 0;
    for (int i = 1; i < size; ++i)
    {
        if (array[j] != array[i])
        {
            j++;
            array[j] = array[i];
        }
    }
    return j + 1;
}

void bubble_sort_array_of_arrays(int **array, int size, int *col_size)
{
    *col_size = 2;
    for (int i = 0; i < size - 1; ++i)
    {
        if (array[i][0] > array[i + 1][0])
        {
            int *temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = -1;
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **getAncestors(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize, int **returnColumnSizes)
{
    // sorting input array of arrays by first element
    bubble_sort_array_of_arrays(edges, edgesSize, edgesColSize);
    for (int i = 0; i < edgesSize; ++i)
        printf("%d %d\n", edges[i][0], edges[i][1]);

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

    // handling edges one by one
    for (int i = 0; i < edgesSize; ++i)
    {
        // current path
        int ancestor = edges[i][0];
        int child = edges[i][1];

        // setting j to point after last member
        int j = 0;
        while (array[child][j] != -1 && j < n - 1) j++;
        if (j == n - 1)
        {
            fprintf(stderr, "Dir: Array is full, cannot add new ancestor\n");
            exit(EXIT_FAILURE);
        }

        // indirect ancestors
        if (array[ancestor])
            for (int k = 0; k < (*returnColumnSizes)[ancestor]; ++k)
            {
                bool skip = false;
                for (int l = 0; l < (*returnColumnSizes)[child]; ++l)
                    if (array[ancestor][k] == array[child][l])
                    {
                        skip = true;
                        break;
                    }
                if (skip)
                {
                    printf("Skipping ancestor %d for node %d\n", array[ancestor][k], child);
                    continue;
                }
                printf("Adding not-direct ancestor %d to node %d\n", array[ancestor][k], child);
                array[child][j] = array[ancestor][k];
                (*returnColumnSizes)[child]++;
                j++;
                if (j == n - 1)
                {
                    fprintf(stderr, "Indir: Array is full, cannot add new ancestor\n");
                    exit(EXIT_FAILURE);
                }
            }

        printf("Adding ancestor %d to node %d\n", ancestor, child);
        array[child][j] = ancestor;
        (*returnColumnSizes)[child]++;
    }

    // sort results
    for (int i = 0; i < n; ++i)
    {
        qsort(array[i], (*returnColumnSizes)[i], sizeof(int), compare);
        (*returnColumnSizes)[i] = remove_duplicates_in_sorted_array(array[i], (*returnColumnSizes)[i]);
    }

    printf("Successfully exited getting ancestors.\n");
    return array;
}

int main()
{
    // int n = 8;
    // int edges_size = 9;
    // int edge_list[9][2] = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};

    // int n = 5;
    // int edges_size = 10;
    // int edge_list[10][2] = {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};

    // int n = 6;
    // int edges_size = 13;
    // int edge_list[13][2] = {{0,3},{5,0},{2,3},{4,3},{5,3},{1,3},{2,5},{0,1},{4,5},{4,2},{4,0},{2,1},{5,1}};

    int n = 9;
    int edges_size = 13;
    int edge_list[13][2] = {{3,6},{2,4},{8,6},{7,4},{1,4},{2,1},{7,2},{0,4},{5,0},{4,6},{3,2},{5,6},{1,6}};

    int *edges[13] = {NULL};
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
