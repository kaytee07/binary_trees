#include "binary_trees.h"


/**
 * binary_tree_sibling - find the sibling of a node
 * @node: pointer to the root node of the tree
 * Return: node of sibling if exist otherwise NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
if (node == NULL)
return (NULL);

if (node->parent == NULL)
return (NULL);

if (node->parent->left == NULL || node->parent->right == NULL)
return (NULL);

return (node->parent->left != node ? node->parent->left : node->parent->right);
}
