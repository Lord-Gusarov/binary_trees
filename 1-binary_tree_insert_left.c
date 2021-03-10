#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of
 * another node. If parent already has a left-child, the new node will take its
 * place, and the old left-child will be set as the left-child of the new node.
 * @parent: pointer to the node to insert the left-child
 * @value: value to store in the new node
 *
 * Return: Pointer to the new node, NULL on Failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *tmp;

	if (!parent)
		return (NULL);

	new  = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (new);

	new->n = value;
	new->parent = parent;
	new->right = NULL;

	tmp = parent->left;
	parent->left = new;
	if (tmp)
		tmp->parent = new;
	new->left = tmp; /*Works even if tmp points to NULL*/

	return (new);
}
