#include "binary_trees.h"
#include <stddef.h>


/**
 * binary_tree_rotate_left - Perform a left rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
if (tree == NULL || tree->right == NULL)
return (tree);

binary_tree_t *pivot = tree->right;
tree->right = pivot->left;

if (pivot->left != NULL)
pivot->left->parent = tree;

pivot->left = tree;
pivot->parent = tree->parent;
tree->parent = pivot;

return (pivot);
}
