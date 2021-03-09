#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of
 * another node
 * @parent: pointer to the node to insert the right-child
 * @value: value to store in the new node
 *
 * Return: Pointer to the new node, NULL on Failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t)), *tmp;

	if (new == NULL)
		return (new);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	if (parent)
	{
		tmp = parent->right;
		parent->right = new;
		if (tmp)
		{
			tmp->parent = new;
			new->right = tmp;
		}
	}

	return (new);
}
