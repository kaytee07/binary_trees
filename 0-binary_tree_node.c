#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_node - create a binary tree node
 * @parent: this is a pointer to the parent node of the new node
 * @value: this is the value to put in the new node
 * Return: return the newly created node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *newNode = malloc(sizeof(binary_tree_t));
if (newNode == NULL)
return (NULL);

if (parent == NULL)
newNode->parent = NULL;

newNode->parent = parent;

newNode->n = value;
newNode->left = NULL;
newNode->right = NULL;

return (newNode);
}
