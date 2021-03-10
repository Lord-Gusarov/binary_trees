#include "binary_trees.h"

/**
 * bst_full - helps determine if a binary tree is full
 * @tree: pointer to the node to check
 *
 * Return: 1 if full or @tree is NULL, 0 otherwise
 */
static int bst_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else if (tree->left && tree->right)
		return (bst_full(tree->left) && bst_full(tree->right));
	else if (!tree->left && !tree->right)
		return (1);
	return (0);

}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if full, 0 if not or if @tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left || !tree->right)
		return (0);

	return (bst_full(tree->left) && bst_full(tree->right));
}
