/*
** node_ops.c for TEST in /home/bender/tek1_2016_test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Tue Apr 11 10:14:40 2017 Bender_Jr
** Last update Tue Apr 11 18:57:01 2017 Bender_Jr
*/

# include <stdlib.h>
# include "tree.h"
# include "base.h"

/**
** @note: "rple" stand for replace
*/
void	rple_first_h0_node(t_tree *tree, t_node *n0)
{
  n0->next = tree->h0->next;
  tree->h0->next->prev = n0;
  free(tree->h0->prev);
  tree->h0 = n0;
}

void	rple_last_h0_node(t_tree *tree, t_node *n0)
{
  tree->t0->prev->next = n0;
  n0->prev = tree->t0->prev;
  free(tree->t0);
  tree->t0 = n0;
}

t_tree		*rple_middle_h0_node(t_tree *tree, t_node *n0, const char *to_replace)
{
  t_node	*head;

  head = tree->h0;
  while (tree->h0)
    {
      if (strn_cmp(tree->h0->str, to_replace, len(to_replace)))
	{
	  n0->prev = tree->h0->prev;
	  tree->h0->prev->next = n0;
	  n0->next = tree->h0->next;
	  tree->h0->next->prev = n0;
	  free(tree->h0);
	  tree->h0 = n0;
	}
      tree->h0 = tree->h0->next;
    }
  tree->h0 = head;
  return (tree);
}

t_tree		*replace_h0_node(t_tree *tree, const char *to_replace,
			      char *new_data)
{
  t_node	*n0;

  n0 = get_nodes(666, new_data);
  if (strn_cmp(tree->h0->str, to_replace, len(to_replace)))
    {
      rple_first_h0_node(tree, n0);
      return (tree);
    }
  else if (strn_cmp(tree->t0->str, to_replace, len(to_replace)))
    {
      rple_last_h0_node(tree, n0);
      return (tree);
    }
  else
    {
      rple_middle_h0_node(tree, n0, to_replace);
      return (tree);
    }
  return (tree);
}
