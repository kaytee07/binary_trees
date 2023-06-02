#include "binary_trees.h"
#include <stdlib.h>


/**
 * binary_tree_levelorder - Perform level-order traversal on a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to call for each node.
 * Description: The value in each node is passed as a parameter to the function.
 * If tree or func is NULL, do nothing.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
if (queue == NULL)
return;

int front = 0, rear = 0;
queue[rear++] = (binary_tree_t *)tree;

while (front < rear)
{
binary_tree_t *node = queue[front++];
func(node->n);

if (node->left != NULL)
queue[rear++] = node->left;
if (node->right != NULL)
queue[rear++] = node->right;
}

free(queue);
}
