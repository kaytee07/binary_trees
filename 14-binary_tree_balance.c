#include "binary_trees.h"
#include <stdlib.h>


/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the binary tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

size_t left_height = binary_tree_height(tree->left);
size_t right_height = binary_tree_height(tree->right);

return (left_height > right_height ? left_height + 1 : right_height + 1);
}


/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: pointer to root node
 * Return: 0 if root is null or size of the tree if otherwise
 */

int binary_tree_balance(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

int left = binary_tree_height(tree->left);
int right = binary_tree_height(tree->right);

return (left - right);
}
