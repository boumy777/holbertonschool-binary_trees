#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - insère un nœud à droite du parent
 * @parent: pointeur vers le nœud parent
 * @value: valeur à stocker dans le nouveau nœud
 *
 * Return: pointeur vers le nouveau nœud ou NULL en cas d’échec
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = parent->right;
	new_node->left = NULL;

	if (parent->right)
		parent->right->parent = new_node;

	parent->right = new_node;

	return (new_node);
}

