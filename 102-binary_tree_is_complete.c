#include "binary_trees.h"
#include <stdbool.h>
#include <stddef.h>


/**
 * binary_tree_is_complete - Check if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise if NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

bool seen_null = false;
binary_tree_t *queue[1024];
size_t front = 0, rear = 0;
queue[rear++] = (binary_tree_t *)tree;

while (front < rear)
{
binary_tree_t *node = queue[front++];


if (node == NULL)
{
seen_null = true;
}
else
{
if (seen_null)
return 0;

queue[rear++] = node->left;
queue[rear++] = node->right;
}
}
return 1;
}

103

#include "binary_trees.h"
#include <stddef.h>


/**
 * binary_tree_rotate_left - Perform a left rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
if (tree == NULL || tree->right == NULL)
return (tree);

binary_tree_t *pivot = tree->right;
tree->right = pivot->left;

if (pivot->left != NULL)
pivot->left->parent = tree;

pivot->left = tree;
pivot->parent = tree->parent;
tree->parent = pivot;

return (pivot);
}
