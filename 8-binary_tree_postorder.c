#include "binary_trees.h"

/**
 * binary_tree_postorder - use postorder traversal to treaverse tree
 * @tree: pointer to root node that is about to be traversed
 * @func: function that print node value
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);
func(tree->n);
}
