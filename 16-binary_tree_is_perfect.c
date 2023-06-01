#include "binary_trees.h"
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

left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
right = tree->right ? 1 + binary_tree_height(tree->right) : 1;
return ((left > right) ? left : right);
}
return (0);
}

/**
 * binary_tree_is_full - checks if the tree is a full binary tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if its a full binary tree or 0 if not
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

/**
 * binary_tree_is_perfect - check if tree is a perfect binary tree
 * @tree: point to the the root node of the tree
 * Return: 1 if perfect 0 if otherwise
 */

int binary_tree_is_perfect(const  binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return ((binary_tree_is_full(tree) == 1) && ((int) binary_tree_height(tree->left) == (int) binary_tree_height(tree->right)) ? 1 : 0);
}
