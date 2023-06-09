#include <stdlib.h>
#iclude "binary_trees.h"


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
 * Performs the heapify-down operation to restore the Max Heap property after node extraction.
 *
 * @param node Pointer to the current node.
 */
void heapify_down(heap_t* node) {
    while (true) {
        heap_t* largest = node;
        if (node->left != NULL && node->left->n > largest->n)
            largest = node->left;

        if (node->right != NULL && node->right->n > largest->n)
            largest = node->right;

        if (largest != node) {
            swap_nodes(node, largest);
            node = largest;
        } else {
            break;
        }
    }
}

/**
 * Frees a heap node and its descendants recursively.
 *
 * @param node Pointer to the heap node to free.
 */
void free_heap_node(heap_t* node) {
    if (node != NULL) {
        free_heap_node(node->left);
        free_heap_node(node->right);
        free(node);
    }
}

/**
 * Extracts the root node of a Max Binary Heap.
 *
 * @param root Double pointer to the root node of the heap.
 * @return The value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t** root) {
    if (*root == NULL)
        return 0;

    int extracted_value = (*root)->n;

    heap_t* current = *root;
    while (current->left != NULL && current->right != NULL) {
        if (current->right != NULL)
            current = current->right;
        else
            current = current->left;
    }

    if (current != *root) {
        (*root)->value = current->n;

        if (current->parent->left == current)
            current->parent->left = NULL;
        else
            current->parent->right = NULL;

        free(current);

               heapify_down(*root);
    } else {
        free(*root);
        *root = NULL;
    }

    return extracted_value;
}

