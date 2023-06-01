#include "binary_trees.h"

/**
 * binary_tree_height - this find the height of the binary tree
 * @tree: root of the node to which height is measured
 * Return: return the height if successful or 0 if otherwise
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

size_t left_height = binary_tree_height(tree->left);
size_t right_height = binary_tree_height(tree->right);

if (left_height > right_height)
return left_height + 1;
else
return right_height + 1;

return (0);
}
