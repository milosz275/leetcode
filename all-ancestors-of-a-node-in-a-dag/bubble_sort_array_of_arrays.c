/**
 * Bubble sort for an array of arrays. Sorts the array of arrays by the first element of each array.
 * 
 * @param array: the array of arrays to be sorted
 * @param size: the size of the array of arrays
 * @param col_size: the size of the arrays in the array of arrays
 */
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
