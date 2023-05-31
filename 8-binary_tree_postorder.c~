#include "binary_trees.h"

/**
 * binary_tree_inorder - use inorder traverse to treaverse tree
 * @tree: pointer to root node that is about to be traversed
 * @func: function that print node value
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

binary_tree_inorder(tree->left, func);
func(tree->n);
binary_tree_inorder(tree->right, func);
}
