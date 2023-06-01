#include "binary_trees.h"

/**
 * binary_tree_height - this find the height of the binary tree
 * @tree: root of the node to which height is measured
 * Return: return the height if successful or 0 if otherwise
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree)
{
size_t left, right;
left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
return ((left > right) ? left : right);
}
return (0);
}
