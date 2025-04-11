#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Supprime un arbre binaire entier
 * @tree: pointeur vers la racine de l'arbre à supprimer
 *
 * Cette fonction libère récursivement tous les nœuds de l'arbre binaire.
 * Si @tree est NULL, rien n'est fait.
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}

