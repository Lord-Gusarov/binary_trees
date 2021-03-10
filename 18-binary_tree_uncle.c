#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pinter to the node whose sibling is desired
 *
 * Return: pointer to the uncle node, NULL if there is no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandpa;

	if (!node || !(node->parent) || !(node->parent->parent))
		return (NULL);

	parent = node->parent;
	grandpa = parent->parent;
	return (grandpa->left == parent ? grandpa->right : grandpa->left);
}
