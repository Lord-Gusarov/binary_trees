#include "binary_trees.h"

/**
 * height - Meausures the high of a tree
 * @tree: pointer to root node of the tree
 *
 * Return: height, 0 is @tree is NULL
 */
int height(binary_tree_t *tree)
{
	int height_l = 1, height_r = 1;

	if (!tree)
		return (0);

	height_l += height(tree->left);
	height_r += height(tree->right);

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: balance factor, 0 if @tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (height(tree->left) - height(tree->right));
}
