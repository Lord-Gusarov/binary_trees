#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/*---Functions for visualization---*/
void binary_tree_print(const binary_tree_t *);
/*---------------------------------*/

/* Task: 0. New node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/* Task: 1. Insert left */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/* Task: 2. Insert right */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/* Task: 3. Delete */
void binary_tree_delete(binary_tree_t *tree);
/* Task: 4. Is leaf */
int binary_tree_is_leaf(const binary_tree_t *node);
/* Task: 5. Is root */
int binary_tree_is_root(const binary_tree_t *node);
/* Task: 6. Pre-order traversal */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/* Task: 7. In-order traversal */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/* Task: 8. Post-order traversal */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/* Task: 9. Height */
size_t binary_tree_height(const binary_tree_t *tree);
/* Task: 10. Depth */
size_t binary_tree_depth(const binary_tree_t *tree);
/* Task: 11. Size */
size_t binary_tree_size(const binary_tree_t *tree);
/* Task: 12. Leaves */
size_t binary_tree_leaves(const binary_tree_t *tree);
/* Task: 13. Nodes */
size_t binary_tree_nodes(const binary_tree_t *tree);
/* Task: 14. Balance factor */
int binary_tree_balance(const binary_tree_t *tree);
/* Task: 15. Is full */
int binary_tree_is_full(const binary_tree_t *tree);
/* Task: 16. Is perfect */
int binary_tree_is_perfect(const binary_tree_t *tree);
/* Task 17. Sibling */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
/* task 18. Uncle */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);


/* Task: 19. Lowest common ancestor (AKA 100) */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
/* Task 20. Level-order traversal (AKA 101) */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
/* Task 21. Is complete (AKA 102) */
int binary_tree_is_complete(const binary_tree_t *tree);
/* Task 22. Rotate left (AKA 103) */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
/* Task 23. Rotate right (AKA 104) */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
/* Task 24. Is BST (AKA 105) */
int binary_tree_is_bst(const binary_tree_t *tree);
/* Task 25. BST - Insert (AKA 106) */
bst_t *bst_insert(bst_t **tree, int value);
/* Task 26. BST-Array to BST (AKA 107) */
bst_t *array_to_bst(int *array, size_t size);

/* Task 30. Is AVL */
int binary_tree_is_avl(const binary_tree_t *tree);
#endif /* _BINARY_TREES_H_ */
