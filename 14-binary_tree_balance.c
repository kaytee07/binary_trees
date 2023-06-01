  #include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the binary tree, or 0 if tree is NULL
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


/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: pointer to root node
 * Return: 0 if root is null or size of the tree if otherwise
 */

int binary_tree_balance(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
