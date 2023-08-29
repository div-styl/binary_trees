#include "binary_trees.h"
/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0, sum = 0;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	sum = 1 + (left > right ? left : right);
	return (sum);
}
/**
 * binary_tree_balance - function that measures the balance factor
 * of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: balance factor of the tree
 * If tree is NULL, return 0 if not return balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int leftcount = 0, rightcount = 0, balancecount = 0;

	if (tree == NULL)
		return (0);
	leftcount = binary_tree_height(tree->left);
	rightcount = binary_tree_height(tree->right);

	balancecount = (leftcount - rightcount);

	return (balancecount);
}
