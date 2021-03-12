#include "binary_trees.h"
#include <limits.h>
/**
 * is_bst - helper recursive method to check for a valid BST
 * @tree: pointer to node tree;
 * @min: minumun value that data can be
 * @max: maximun value the data can assume
 *
 * Return: 1 if valid BST
 */
static int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
			is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Bnary Search Tree
 * @tree: pointer to the node of the tree to check
 *
 * Return: 1 if a valid Binary Search Tree
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
