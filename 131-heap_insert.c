#include <stdlib.h>
#include "binary_trees.h"



/**
 * Swaps the values of two heap nodes.
 *
 * @param node1 Pointer to the first heap node.
 * @param node2 Pointer to the second heap node.
 */
void swap_nodes(heap_t* node1, heap_t* node2) {
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * Performs the heapify-up operation to restore the Max Heap property after node insertion.
 *
 * @param node Pointer to the inserted node.
 */
void heapify_up(heap_t* node) {
    while (node->parent != NULL && node->value > node->parent->value) {
        swap_nodes(node, node->parent);
        node = node->parent;
    }
}

/**
 * Creates a new heap node with the given value.
 *
 * @param value The value to store in the node.
 * @return Pointer to the created heap node.
 */
heap_t* create_heap_node(int value) {
    heap_t* new_node = (heap_t*)malloc(sizeof(heap_t));
    if (new_node != NULL) {
        new_node->n = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

/**
 * Inserts a value into a Max Binary Heap.
 *
 * @param root Double pointer to the root node of the heap.
 * @param value The value to insert.
 * @return Pointer to the created node, or NULL on failure.
 */
heap_t* heap_insert(heap_t** root, int value) {
    heap_t* new_node = create_heap_node(value);
    if (new_node == NULL)
        return NULL;

    if (*root == NULL) {
        *root = new_node;
    } else {
        // Insert the new node as the leftmost available position in the last level
        heap_t* current = *root;
        while (current->left != NULL && current->right != NULL) {
            if (current->left != NULL && current->right != NULL) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (current->left == NULL)
            current->left = new_node;
        else
            current->right = new_node;

        new_node->parent = current;
        heapify_up(new_node);
    }

    return new_node;
}
