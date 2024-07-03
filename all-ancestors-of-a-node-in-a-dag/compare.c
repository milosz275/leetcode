/**
 * Compare function for qsort.
 * 
 * @param a: the first element to be compared
 * @param b: the second element to be compared
 * @return: 0 if the elements are equal, -1 if the first element is smaller than the second element, 1 if the first element is greater than the second element
 */
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
