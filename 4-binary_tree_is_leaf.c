#include "binary_trees.h"
/**
 * binary_tree_is_leaf - check if node is leaf
 * @node: node to check
 *
 *  Return: 1 if leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (!node)
        return 0;

    return (node->left == NULL && node->right == NULL);
}
