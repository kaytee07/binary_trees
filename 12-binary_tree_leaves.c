#include "binary_trees.h"


/**
 * binary_tree_leaves - count leaves in a binary tree
 * @tree: pointer to the root node to count the number of leaves
 * Return: 0 if root node is NULL and num of leaves if otherwise
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

if (tree->left == NULL || tree->right == NULL)
return (1);

return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
