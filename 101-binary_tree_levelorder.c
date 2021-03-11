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
 * process_level - aplies the given function to the data in all node at the
 * leve/depth specified.
 * @tree: root of the tree;
 * @level: desired level to visit/process
 * @func: function to apply to each node the specified level
 */
static void process_level(const binary_tree_t *tree, int level,
						  void (*func)(int))
{
	if (!tree)
		return;
	if (level == 1)
		func(tree->n);
	else
	{
		process_level(tree->left, level - 1, func);
		process_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * * @tree: pointer to the root of the tree to traverse
 * @func: pointer to a function to call for eah node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, height;

	height = bt_height(tree);

	for (i = 1; i <= height; i++)
		process_level(tree, i, func);
}
