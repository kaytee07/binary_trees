#include "binary_trees.h"


/**
 * binary_tree_nodes -  count nodes with at least one child
 * @tree: pointer to the root node of tree
 * Return: number of node with atleast one child or 0 if failure
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->left) + 1);
}
