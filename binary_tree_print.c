#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _height - Mesure la hauteur d’un arbre binaire
 * @tree: Pointeur vers la racine de l’arbre
 * Return: Hauteur ou 0
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	left = tree->left ? 1 + _height(tree->left) : 0;
	right = tree->right ? 1 + _height(tree->right) : 0;

	return ((left > right) ? left : right);
}

/**
 * _print - Remplit le buffer de lignes avec les données de l’arbre
 * @tree: Noeud courant
 * @offset: Décalage horizontal
 * @depth: Profondeur du noeud
 * @s: Tableau de lignes de texte
 * Return: Largeur utilisée
 */
static int _print(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, i;
	int is_left = 0;

	if (!tree)
		return (0);

	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = _print(tree->left, offset, depth + 1, s);
	right = _print(tree->right, offset + left + width, depth + 1, s);

	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}

	return (left + width + right);
}

/**
 * binary_tree_print - Affiche un arbre binaire dans le terminal
 * @tree: Pointeur vers la racine de l’arbre
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;

	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;

	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(255);
		if (!s[i])
			return;
		memset(s[i], ' ', 254);
		s[i][254] = '\0';
	}

	_print(tree, 0, 0, s);

	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}

