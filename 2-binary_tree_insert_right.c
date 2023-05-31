#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_insert_right - create a binary tree node to the right child
 * @parent: this is a pointer to the parent node of the new node
 * @value: this is the value to put in the new node
 * Return: return the newly created node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
binary_tree_t *newNode = NULL;
if (parent == NULL)
return (NULL);

newNode = binary_tree_node(parent, value);
if (newNode == NULL)
return (NULL);

if (parent->right != NULL)
{
newNode->right = parent->right;
parent->right->parent = newNode;
}

parent->right = newNode;
return (newNode);
}
