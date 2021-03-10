#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of
 * another node. If parent already has a right-child, the new node will take
 * its place, and the old right-child will be set as the right-child of the
 * new node.
 * @parent: pointer to the node to insert the right-child
 * @value: value to store in the new node
 *
 * Return: Pointer to the new node, NULL on Failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *tmp;

	if (!parent)
		return (NULL);

	new  = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (new);

	new->n = value;
	new->parent = parent;
	new->left = NULL;

	tmp = parent->right;
	parent->right = new;
	if (tmp)
		tmp->parent = new;
	new->right = tmp; /*Works even if tmp points to NULL*/

	return (new);
}
