#include "binary_trees.h"

/**
 * get_leaf_depth - checks the depth of a leaf
 * @tree: pointer to the root node of the tree
 * Return: depth of a leaf
 */
size_t get_leaf_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect_recusrive - checks for perfection
 * @tree: pointer to the root node of the tree
 * Return: 1 if perfect, otherwise 0
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, depth, level + 1) &&
		is_perfect_recursive(tree->right, depth, level + 1));
}

/**
 * binary_tree_is _perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = get_leaf_depth(tree);
	return (is_perfect_recursive(tree, depth, 0));
}
