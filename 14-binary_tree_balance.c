#include "binary_trees.h"

/**
 * binary_tree_height_balance - function to measure height
 * Return: height of binary tree
 */
size_t binary_tree_height_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height =binary_tree_height_balance(tree->left);
	right_height=binary_tree_height_balance(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @: pointer to the root node of the tree
 * Return: balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = (tree->left) ? (int)binary_tree_height_balance(tree->left) : 0;
	right_height = (tree->right) ? (int)binary_tree_height_balance(tree->right) : 0;

	return (left_height - right_height);
}
