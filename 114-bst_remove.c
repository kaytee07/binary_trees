#include "binary_trees.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * bst_remove - remove value from binary search tree
 * @root: pointer to root node of bst
 * @value: value to be found and removed
 * Return: the new root node of tree
 */

binary_tree_t *bst_remove(binary_tree_t *root, int value)
{
if (root == NULL)
return (NULL);
binary_tree_t *current = root;
binary_tree_t *parent = NULL;
binary_tree_t *successor = NULL;
while (current != NULL && current->n != value)
{
parent = current;
if (value < current->n)
current = current->left;
else
current = current->right;
}
if (current == NULL)
return (root);
if (current->left == NULL && current->right == NULL)
{
if (parent != NULL)
{
if (parent->left == current)
parent->left = NULL;
else
parent->right = NULL;
}
else
{root = NULL;
}
free(current);
}
else if (current->left == NULL || current->right == NULL)
{
binary_tree_t *child = (current->left != NULL) ? current->left : current->right;
if (parent != NULL)
{
if (parent->left == current)
parent->left = child;
else
parent->right = child;
}
else
{
root = child;
}
free(current);
}
else
{
successor = current->right;
while (successor->left != NULL)
successor = successor->left;
current->n = successor->n;
current->right = bst_remove(current->right, successor->n);
}
return (root);
}
