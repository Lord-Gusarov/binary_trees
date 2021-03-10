#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of
 * another node
 * @parent: pointer to the node to insert the left-child
 * @value: value to store in the new node
 *
 * Return: Pointer to the new node, NULL on Failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t)), *tmp;

	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	if (parent)
	{
		tmp = parent->left;
		parent->left = new;
		if (tmp)
		{
			tmp->parent = new;
			new->left = tmp;
		}
	}

	return (new);
}
