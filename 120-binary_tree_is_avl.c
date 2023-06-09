#include "binary_trees.h"
#include <limits.h>

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure ht
 * Return: If tree is NULL, your function must return 0, ret ht
 */
size_t height(const binary_tree_t *tree)
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
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited currently.
 * @high: The value of the biggest node visited currently.
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int low, int high)
{
size_t lheight, rheight, diff;
if (tree != NULL)
{
if (tree->n < low || tree->n > high)
return (0);
lheight = height(tree->left);
rheight = height(tree->right);
diff = lheight > rheight ? lheight - rheight : rheight - lheight;
if (diff > 1)
return (0);
return (is_avl_helper(tree->left, low, tree->n - 1) &&
        is_avl_helper(tree->right, tree->n + 1, high));
}
return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
