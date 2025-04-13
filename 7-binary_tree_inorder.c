#include "binary_trees.h"

/**
 * binary_tree_inorder - Parcourt un arbre binaire en ordre infixe
 * @tree: Pointeur vers la racine de l'arbre à parcourir
 * @func: Pointeur vers une fonction à appeler pour chaque nœud
 *
 * Description:
 * Si tree ou func est NULL, ne rien faire.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}

