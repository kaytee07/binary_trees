#include "binary_trees.h"
#include <stdio.h>

/**
 * check_height - this function find he max depth
 * @tree: this is the pointer to root of node
 * @n: this is the current height of tree
 * Return: return the height of the binary tree
 */

size_t check_height(const binary_tree_t *tree, int n)
{
if (tree->left || tree->right)
{
if (tree->left && tree->right)
{
check_height(tree->left, n++);
check_height(tree->right, n++);
}
else if (tree->left)
{
check_height(tree->left, n++);
}
else if (tree->right)
{
printf("%d:%d->\n", tree->n, n);
check_height(tree->right, n++);
}
}
return (n);
}

/**
 * binary_tree_height - this find the height of the binary tree
 * @tree: root of the node to which height is measured
 * Return: return the height if successful or 0 if otherwise
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (check_height(tree, 0));
}
