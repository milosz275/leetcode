// [ ] Fix time exceed issue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "compare.c"
#include "bubble_sort_array_of_arrays.c"

/**
 * Node structure for the graph.
 * 
 * @param id: the id of the node
 * @param children_list: the list of children of the node
 * @param children_count: the count of children of the node
 */
struct Node
{
    int id;
    struct Node **children_list;
    int children_count;
};

/**
 * Creates a node with the given id.
 * 
 * @param id: the id of the node
 * @return: the created node
 */
struct Node *create_node(int id)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->id = id;
    node->children_list = NULL;
    node->children_count = 0;
    return node;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **getAncestors(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize, int **returnColumnSizes)
{
    // deal with empty edges array
    if (edgesSize == 0)
    {
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
        return array;
    }

    // sorting input array of arrays by first element
    bubble_sort_array_of_arrays(edges, edgesSize, edgesColSize);
    printf("Sorted edges array: [");
    for (int i = 0; i < edgesSize; ++i)
    {
        if (i == 0)
            printf("[%d %d]", edges[i][0], edges[i][1]);
        else
            printf(", [%d %d]", edges[i][0], edges[i][1]);
    }
    printf("]\n");

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

    // creating graph
    struct Node *graph[n];
    for (int i = 0; i < n; ++i)
        graph[i] = create_node(i);

    for (int i = 0; i < edgesSize; ++i)
    {
        int parent = edges[i][0];
        int child = edges[i][1];
        struct Node *node = graph[parent];
        if (node->children_list == NULL)
        {
            node->children_list = (struct Node **)malloc(sizeof(struct Node *) * n);
            for (int j = 0; j < n; ++j)
                node->children_list[j] = NULL;
        }
        node->children_list[child] = graph[child];
        node->children_count++;
        // printf("Node %d (%d) has child %d (%d)\n", parent, node->id, child, node->children_list[child]->id);
    }
    for (int i = 0; i < n; ++i)
    {
        struct Node *node = graph[i];
        if (node->children_list == NULL)
        {
            node->children_list = (struct Node **)malloc(sizeof(struct Node *) * n);
            for (int j = 0; j < n; ++j)
                node->children_list[j] = NULL;
        }
    }

    // control if the nodes work correctly
    printf("Graph nodes and its children:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("Node %d, children count %d\n", i, graph[i]->children_count);
        for (int j = 0; j < n; ++j)
            if (graph[i]->children_list[j] != NULL)
                printf("%d ", graph[i]->children_list[j]->id);
        putchar('\n');
    }
    
    // updating array with nodes' direct ancestors
    for (int i = 0; i < n; ++i)
    {
        struct Node *node = graph[i];
        for (int j = 0; j < n; ++j)
            if (node->children_list[j] != NULL)
            {
                int child = node->children_list[j]->id;
                for (int k = 0; k < n; ++k)
                    if (array[child][k] == -1)
                    {
                        array[child][k] = i;
                        (*returnColumnSizes)[child]++;
                        break;
                    }
            }
    }

    // adding ancestors of the ancestors
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                if (array[i][j] != -1)
                {
                    int ancestor = array[i][j];
                    for (int k = 0; k < n; ++k)
                        if (array[ancestor][k] != -1)
                        {
                            int ancestor_ancestor = array[ancestor][k];
                            bool exists = false;
                            for (int l = 0; l < n; ++l)
                                if (array[i][l] == ancestor_ancestor)
                                {
                                    exists = true;
                                    break;
                                }
                            if (!exists)
                                for (int l = 0; l < n; ++l)
                                    if (array[i][l] == -1)
                                    {
                                        array[i][l] = ancestor_ancestor;
                                        (*returnColumnSizes)[i]++;
                                        changed = true;
                                        break;
                                    }
                        }
                }
        }
    }

    // sorting ancestors
    for (int i = 0; i < n; ++i)
        qsort(array[i], (*returnColumnSizes)[i], sizeof(int), compare);

    printf("Successfully found ancestors.\n");
    for (int i = 0; i < n; ++i)
    {
        free(graph[i]->children_list);
        free(graph[i]);
    }
    return array;
}

int main()
{
    // int n = 8;
    // int edges_size = 9;
    // int edge_list[9][2] = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
    // int *edges[9] = {NULL};

    // int n = 5;
    // int edges_size = 10;
    // int edge_list[10][2] = {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
    // int *edges[10] = {NULL};

    // int n = 6;
    // int edges_size = 13;
    // int edge_list[13][2] = {{0,3},{5,0},{2,3},{4,3},{5,3},{1,3},{2,5},{0,1},{4,5},{4,2},{4,0},{2,1},{5,1}};
    // int *edges[13] = {NULL};

    int n = 9;
    int edges_size = 13;
    int edge_list[13][2] = {{3,6},{2,4},{8,6},{7,4},{1,4},{2,1},{7,2},{0,4},{5,0},{4,6},{3,2},{5,6},{1,6}};
    int *edges[13] = {NULL};

    // int n = 6;
    // int edges_size = 0;
    // int edge_list[0][0] = {{}};
    // int *edges[0] = {NULL};

    for (int i = 0; i < edges_size; ++i)
        edges[i] = edge_list[i];
    int edges_col_size = 2;
    int return_size = n;
    int *return_column_sizes = NULL;
    int **array = getAncestors(n, edges, edges_size, &edges_col_size, &return_size, &return_column_sizes);

    printf("\nArray of ancestors:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("Node %d:\n", i);
        for (int j = 0; j < return_column_sizes[i]; ++j)
            printf("%d ", array[i][j]);
        putchar('\n');
    }

    exit(EXIT_SUCCESS);
}
