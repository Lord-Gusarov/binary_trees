#include "binary_trees.h"

/**
 * bt_depth - measures the depth of a bt node to the absolute root node
 * @node: pointer to node whose depth is desired
 *
 * Return: [0, +) for depth , -1 if node is NULL
 */
static int bt_depth(const binary_tree_t *node)
{
	int depth = -1;

	while (node)
	{
		node = node->parent;
		depth++;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to lowest common ancestor node of the given nodes,
 * NULL if no common ascentos is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	int depth_f, depth_s, min_depth;

	if (!first || !second)
		return (NULL);

	depth_f = bt_depth(first);
	depth_s = bt_depth(second);
	min_depth = depth_f > depth_s ? depth_s : depth_f;

	/**
	 * lets get the nodes to the same depth and go up simulatanuosly checking
	 * at each dept if they pointing to the same node AKA The Common ANcestor
	 */
	while (depth_f > min_depth)
	{
		depth_f--;
		first = first->parent;
	}
	while (depth_s > min_depth)
	{
		depth_s--;
		second = second->parent;
	}
	while (min_depth >= 0)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
		min_depth--;
	}

	return (NULL);
}
