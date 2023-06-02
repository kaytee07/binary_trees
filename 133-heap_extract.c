#include "binary_trees.h"

/**
 * swap_values - Swaps the values of two binary tree nodes
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
int temp = node1->n;
node1->n = node2->n;
node2->n = temp;
}

/**
 * get_last_node - Retrieves the last level-order node of a heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the last level-order node, or NULL on failure
 */
heap_t *get_last_node(heap_t *root)
{
if (root == NULL)
return (NULL);
queue_t *queue = queue_create();
heap_t *last_node = NULL;
if (queue == NULL)
return (NULL);
queue_push(queue, root);
while (!queue_is_empty(queue))
{
last_node = queue_pop(queue);
if (last_node->left)
queue_push(queue, last_node->left);
if (last_node->right)
queue_push(queue, last_node->right);
}
queue_delete(queue);
return (last_node);
}

/**
 * heapify_down - Restores the Max Heap property by moving a node down
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
if (root == NULL)
return;

heap_t *largest = root;
heap_t *left = root->left;
heap_t *right = root->right;

if (left && left->n > largest->n)
largest = left;

if (right && right->n > largest->n)
largest = right;

if (largest != root)
{
swap_values(root, largest);
heapify_down(largest);
}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
if (root == NULL || *root == NULL)
return (0);
int extracted_value = (*root)->n;
heap_t *last_node = get_last_node(*root);
if (*root == last_node)
{
free(*root);
*root = NULL;
return (extracted_value);
}

(*root)->n = last_node->n;

if (last_node->parent->left == last_node)
last_node->parent->left = NULL;
else
last_node->parent->right = NULL;
free(last_node);
heapify_down(*root);
return (extracted_value);
}
