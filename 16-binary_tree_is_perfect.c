#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_height - finds the height of the binary tree
 * @tree: pointer to the root node of the tree
 * Return: height of the trr or 0 if root node is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

int left = binary_tree_height(tree->left);
int right = binary_tree_height(tree->right);

return (left > right ? left + 1 : right + 1);
}

/**
 * binary_tree_full - checks if the tree is a full binary tree
 * @tree: pointer to the root node of the tree
 * Return: 1 if its a full binary tree or 0 if not
 */

int binary_tree_full(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

if (tree->left == NULL && tree->right == NULL)
return (1);

if (tree->left != NULL && tree->right != NULL)
return (binary_tree_full(tree->left) && binary_tree_full(tree->right));

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

int full = binary_tree_full(tree);
printf("%d--", full);

int right_height = (int) binary_tree_height(tree->right);
printf("%d--", right_height);

int left_height = (int) binary_tree_height(tree->left);
printf("%d--", left_height);

return (full == 1 && left_height == right_height ? 1 : 0);
}
