/*
** tree_utils.c for TEST in /home/bender/Test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 22:37:39 2017 Bender_Jr
** Last update Tue Apr 11 10:22:08 2017 Bender_Jr
*/

# include <stdlib.h>
# include "tree.h"
# include "printf.h"

int		fatal_error(char *errmsg, int exitval)
{
  p_printf(2, "Myprog: %s\n", errmsg);
  exit (exitval);
}

int		count_occurence(t_tree *tree, const char *to_find)
{
  t_node	*tmp;
  int		occurence;

  tmp = tree->h0;
  occurence = 0;
  while (tmp)
    {
      if (strn_cmp(tmp->str, to_find, len(to_find)))
	occurence += 1;
      tmp = tmp->next;
    }
  if (occurence == 0)
    {
      tmp = tree->h1;
      while (tmp)
	{
	  if (strn_cmp(tmp->str, to_find, len(to_find)))
	    occurence += 1;
	  tmp = tmp->next;
	}
    }
  return (occurence);
}

void		print_tree(t_tree *tree)
{
  t_node	*tmp0;
  t_node	*tmp1;

  tmp0 = tree->h0;
  tmp1 = tree->h1;
  p_printf(1, "\tTree label : %s\n",tree->label);
  p_printf(1, "\t\tPrinting h0 branch\n\n");
  while (tmp0)
    {
      p_printf(1, "Data h0 : [%d] [%s]\n", tmp0->data,
	       tmp0->str);
      tmp0 = tmp0->next;
    }
  p_printf(1, "\n\n\t\tPrinting h1 branch\n\n");
  while (tmp1)
    {
      p_printf(1, "Data h1 : [%d] [%s]\n", tmp1->data,
	       tmp1->str);
      tmp1 = tmp1->next;
    }
  p_printf(1, "\n\t\t\tOK\n");
}

void			free_tree(t_tree *tree)
{
 while (tree->h0)
    {
      free(tree->h0->prev);
      tree->h0 = tree->h0->next;
    }
  while (tree->h1)
    {
      free(tree->h1->prev);
      tree->h1 = tree->h1->next;
    }
  free(tree->label);
  free(tree->t0);
  free(tree->t1);
  free(tree);
}
