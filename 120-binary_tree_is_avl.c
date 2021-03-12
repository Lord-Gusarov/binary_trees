#include "binary_trees.h"
#include <limits.h>

/**
 * _height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, 0 if tree is NULL
 */
static int _height(const binary_tree_t *tree)
{
	int h_left = 0, h_right = 0;

	if (!tree)
		return (-1);

	h_left = tree->left ? 1 + _height(tree->left) : 0;
	h_right = tree->right ? 1 + _height(tree->right) : 0;
	return (h_left > h_right ? h_left : h_right);
}

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
 * bt_is_bst - checks if a binary tree is a valid Bnary Search Tree
 * @tree: pointer to the node of the tree to check
 *
 * Return: 1 if a valid Binary Search Tree
 */
static int bt_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl - helps determine if a binary tree is a valid AVL Tree
 * @tree: pointer to root of tree/subtree
 * 
 * Return: 1 if a valid AVL tree
 */
static int is_avl(const binary_tree_t *tree)
{
	int dif;

	if (!tree)
		return (1);

	dif = abs(_height(tree->left) - _height(tree->right));
	if (dif > 1)
		return (0);

	return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL TREE
 * @tree: pointer to root of tree
 *
 * Return: 1 if a valid AVL Tree
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (bt_is_bst(tree) && is_avl(tree));
}
