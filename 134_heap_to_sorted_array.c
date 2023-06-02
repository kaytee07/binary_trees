#include "binary_trees.h"

/**
 * get_heap_size - Calculates the size of the heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Size of the heap
 */
size_t get_heap_size(const heap_t *root)
{
if (root == NULL)
return (0);
size_t left_size = get_heap_size(root->left);
size_t right_size = get_heap_size(root->right);
return (1 + left_size + right_size);
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers (in descending order),
 *         or NULL on failure or if the heap is empty
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
if (heap == NULL || size == NULL)
return (NULL);

*size = get_heap_size(heap);
int *sorted_array = malloc((*size) * sizeof(int));
if (sorted_array == NULL)
return (NULL);

size_t index = 0;
queue_t *queue = queue_create();

if (queue == NULL)
{
free(sorted_array);
return (NULL);
}
queue_push(queue, heap);
while (!queue_is_empty(queue))
{
heap_t *node = queue_pop(queue);
sorted_array[index++] = node->n;
if (node->left)
queue_push(queue, node->left);
if (node->right)
queue_push(queue, node->right);
}
queue_delete(queue);
return (sorted_array);
}
