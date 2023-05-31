#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is root
 * @node: this is a pointer to the node to check
 * Return: return 1 if node is root and 0 if otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL)
return (0);

if (node->parent)
return (0);
else
return (1);
}
