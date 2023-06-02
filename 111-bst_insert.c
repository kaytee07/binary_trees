#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"


/**
 * bst_insert - insert into the binary_search_tree
 * @tree: bst to insert the new node
 * @value: value to be inserted in the new node
 * Return: new node or NULL
 */
binary_tree_t *bst_insert(binary_tree_t **tree, int value)
{
if (tree == NULL)
return (NULL);

if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}

binary_tree_t *current = *tree;

while (1)
{
if (value < current->n)
{
if (current->left == NULL)
{
current->left = binary_tree_node(current, value);
return (current->left);
}
current = current->left;
}
else if (value > current->n)
{
if (current->right == NULL)
{
current->right = binary_tree_node(current, value);
return (current->right);
}
current = current->right;
}
else
{
return (NULL);
}
}
}
