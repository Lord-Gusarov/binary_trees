#include "binary_trees.h"

/**
 * bt_height - calculates height of a binary tree
 * @tree: pointer to root node
 *
 * Meant to be use only as a helper mehtod for checking 'perfection'
 *
 * Return: height, 0 if NULL
 */
static int bt_height(const binary_tree_t *tree)
{
	int height_l = 1, height_r = 1;

	if (!tree)
		return (0);

	height_l += bt_height(tree->left);
	height_r += bt_height(tree->right);

	return (height_l > height_r ? height_r : height_l);
}
/**
 * process_depth - aplies the given function to the data in all node at the
 * depth specified.
 * @tree: root of the tree;
 * @depth: desired depth to visit/process
 * @func: function to apply to each node the specified depth
 */
static void process_depth(const binary_tree_t *tree, int depth,
						  void (*func)(int))
{
	if (!tree)
		return;
	if (depth == 1)
		func(tree->n);
	else if (depth > 1)
	{
		process_depth(tree->left, depth - 1, func);
		process_depth(tree->right, depth - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using depth-order
 * traversal
 * * @tree: pointer to the root of the tree to traverse
 * @func: pointer to a function to call for eah node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, height;

	if (!tree || !func)
		return;

	height = bt_height(tree);

	for (i = 1; i <= height; i++)
		process_depth(tree, i, func);
}
