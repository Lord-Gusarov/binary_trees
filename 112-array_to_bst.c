#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: array to be converted
 * @size: number of elements in the array
 *
 * Return: pointer tot the root node of the created BST,
 * NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	do {
		bst_insert(&root, array[i]);
	} while (size > 0);

	return (root);
}
