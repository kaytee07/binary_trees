#include <stdbool.h>
#include "binary_tree.h"


/**
 * Checks if the binary tree is complete.
 *
 * @param tree Pointer to the root node of the binary tree.
 * @return true if the binary tree is complete, false otherwise.
 */
bool is_complete_tree(const binary_tree_t* tree) {
    if (tree == NULL)
        return true;

    bool reached_end = false;

    binary_tree_t* queue[1000];
    int front = 0;
    int rear = 0;

    queue[rear++] = (binary_tree_t*)tree;

    while (front < rear) {
        binary_tree_t* current = queue[front++];

        if (current == NULL) {
            reached_end = true;
        } else {
            if (reached_end)
                return false;

            queue[rear++] = current->left;
            queue[rear++] = current->right;
        }
    }

    return true;
}

/**
 * Checks if the binary tree satisfies the max heap property.
 *
 * @param tree Pointer to the root node of the binary tree.
 * @return true if the binary tree satisfies the max heap property, false otherwise.
 */
bool is_max_heap(const binary_tree_t* tree) {
    if (tree == NULL)
        return true;

    int value = tree->n;

    if (tree->left != NULL && tree->left->n > value)
        return false;

    if (tree->right != NULL && tree->right->n > value)
        return false;

    return is_max_heap(tree->left) && is_max_heap(tree->right);
}

/**
 * Checks if a binary tree is a valid Max Binary Heap.
 *
 * @param tree Pointer to the root node of the binary tree to check.
 * @return 1 if the binary tree is a valid Max Binary Heap, 0 otherwise.
 *         If tree is NULL, returns 0.
 */
int binary_tree_is_heap(const binary_tree_t* tree) {
    if (tree == NULL)
        return 0;

    if (!is_complete_tree(tree))
        return 0;

    if (!is_max_heap(tree))
        return 0;

    return 1;
}
