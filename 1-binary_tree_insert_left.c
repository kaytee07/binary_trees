#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_insert_left - create a binary tree node to the left child
 * @parent: this is a pointer to the parent node of the new node
 * @value: this is the value to put in the new node
 * Return: return the newly created node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
binary_tree_t *newNode = NULL;
if (parent == NULL)
return (NULL);

newNode = binary_tree_node(parent, value);
if (newNode == NULL)
return (NULL);

if (parent->left != NULL)
{
newNode->left = parent->left;
parent->left->parent = newNode;
}

parent->left = newNode;
return (newNode);
}
