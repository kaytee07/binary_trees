#include "binary_trees.h"


/**
 * binary_tree_is_full - check if tree is a full binary tree
 * @tree: pointer to root node
 * Return: 1 if it is full and 0 if not
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (1);

if (tree->left != NULL && tree->right != NULL)
return (binary_tree_is_full(tree->left) * binary_tree_is_full(tree->right));

return (0);
}
