#include "binary_trees.h"
#include <stdio.h>

/**
 * find_depth - this function finds the depth of a binary tree
 * @tree: the current node to which it's depth is being sort
 * @n: this is the depth from the node
 * Return: Depth of node
 */

size_t find_depth(const binary_tree_t *tree, int n)
{
if (tree->parent == NULL)
{
return (n);
}
return (find_depth(tree->parent, n + 1));
}


/**
 * binary_tree_depth - find the distance from node to root
 * @tree: this is the node to measure it's depth
 * Return: return 0 if tree is null or depth of node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);
return (find_depth(tree, 0));
}
