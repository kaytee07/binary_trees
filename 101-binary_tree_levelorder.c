#include "binary_trees.h"
#include <stdlib.h>


/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure ht
 * Return: If tree is NULL, your function must return 0, ret ht
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree)
{
size_t left, right;
left = tree->left ? 1 + height(tree->left) : 1;
right = tree->right ? 1 + height(tree->right) : 1;
return ((left > right) ? left : right);
}
return (0);
}

/**
 * binary_tree_level - perform a function on a level
 * @tree: pointer to the root of the tree
 * @l: level of the tree to perform a function on
 * @func: function to perform
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree, size_t l, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (l == 1)
		func(tree->n);
	else if (l > 1)
	{
		binary_tree_level(tree->left, l - 1, func);
		binary_tree_level(tree->right, l - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverses a binary tree using lo trav
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (i = 1; i <= height; i++)
		binary_tree_level(tree, i, func);
}
