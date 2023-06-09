#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * bst_search - serach for a value in binary search tree
 * @tree: pointer to the root node of BST search
 * @value: value to search from BST
 * Return: return pointer to node if found and NULL if not found
 */

binary_tree_t *bst_search(const binary_tree_t *tree, int value)
{
if (tree == NULL)
return (NULL);

const binary_tree_t *current = tree;

while (current != NULL)
{
if (value == current->n)
{
return ((binary_tree_t *)current);
}
else if (value < current->n)
{
current = current->left;
}
else
{
current = current->right;
}
}
return (NULL);
}
