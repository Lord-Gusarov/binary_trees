#include "binary_trees.h"

/**
 * bt_height - calculates height of a binary tree
 * @tree: pointer to root node
 *
 * Meant to be use only as a helper mehtod for checking 'perfection'
 *
 * Return: height, 0 if NULL
 */
static int bt_height(binary_tree_t *tree)
{
	int height_l = 1, height_r = 1;

	if (!tree)
		return (0);

	height_l += bt_height(tree->left);
	height_r += bt_height(tree->right);

	return (height_l > height_r ? height_r : height_l);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is 'perfect'
 * @tree: pointer to root node
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (bt_height(tree->left) == bt_height(tree->right))
		return (binary_tree_is_perfect(tree->left) ==
				binary_tree_is_perfect(tree->right));

	return (0);
}
