#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert left child node
 * @parent: parrent
 * @value: value to insert
 *
 * Return: return the new created node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (!parent)
        return (NULL);

    new_node = binary_tree_node(parent, value);
    if (!new_node)
        return (NULL);

    if (parent->left)
    {
        new_node->left = parent->left;
        new_node->left->parent = new_node;
    }

    parent->left = new_node;

    return (new_node);
}
