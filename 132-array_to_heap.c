#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the input array
 * @size: Size of the array
 * Return: Pointer to the root node of the created Binary Heap,
 *         or NULL on failure or if the array is empty
 */
heap_t *array_to_heap(int *array, size_t size)
{
size_t i = 0;
bst_t *root = NULL;
if (!array)
return (NULL);
while (i < size)
{
heap_insert(&root, array[i]);
i++;
}
return (root);
}
