#include "binary_trees.h"
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not perfect or tree is NULL
 */
size_t binary_size(const binary_tree_t *tree);
size_t binary_height(const binary_tree_t *tree);

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, size = 0, perfect_size = 0;

	if (tree == NULL)
		return (0);
	height = binary_height(tree);
	size = binary_size(tree);

	perfect_size = (2 << height) - 1;
	if (perfect_size == size)
		return (1);
	return (0);
}
/**
 * binary_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to check
 * Return: height of tree, 0 if tree is NULL
 */
size_t binary_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;


	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_height(tree->right) : 0;

	return ((left_height > right_height ? left_height : right_height));
}

/**
 * binary_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
*/
size_t binary_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_size(tree->left) + binary_size(tree->right));
}

