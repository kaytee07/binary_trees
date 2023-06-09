#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_bst - convert array to BST
 * @size: size of the array
 * @array: array to be converted
 * Return: BST or NULL on failure
 */

binary_tree_t *array_to_bst(int *array, size_t size)
{
if (array == NULL || size == 0)
return (NULL);

binary_tree_t *root = NULL;

for (size_t i = 0; i < size; i++)
{
bst_insert(&root, array[i]);
}
return (root);
}
