#include "binary_trees.h"

/**
 * bt_size - measures the size of a binary tree
 * @tree: pointer to the root node of th tree to measure
 *
 * Return: size, 0 if @tree is NULL
 */
static int bt_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + bt_size(tree->left) + bt_size(tree->right));
}

/**
 * is_complete - helps determine recursively is a binary tree
 * is complete
 * @tree: pointer to root node
 * @depth: current depth
 * @size: nodes in the initial tree
 *
 * Return: 1 if complete, 0 otherwise
 */
static int is_complete(const binary_tree_t *tree, int depth, int size)
{
	if (!tree)
		return (1);
	if (depth >= size)
		return (0);

	return (is_complete(tree->left, 2 * depth + 1, size) &&
			is_complete(tree->right, 2 * depth + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is 'complete'
 * @tree: pointer to root node
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_complete(tree, 0, bt_size(tree)));
}
