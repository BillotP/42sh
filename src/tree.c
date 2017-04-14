/*
** tree.c for TEST in /home/bender/Test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 22:31:45 2017 Bender_Jr
** Last update Fri Apr 14 11:12:36 2017 Bender_Jr
*/

# include <stdlib.h>
# include "tree.h"
# include "dict.h"
# include "base.h"

t_tree		*init_tree(char *label)
{
  t_tree	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    fatal_error("Memory allocation failed", 84);
  new->label = my_strdup(label);
  new->h0 = NULL;
  new->t0 = NULL;
  new->h1 = NULL;
  new->t1 = NULL;
  return (new);
}

void		get_h0(t_tree *tree, t_node *n0)
{
  if (tree->h0 == NULL)
    {
      tree->h0 = n0;
      tree->t0 = n0;
    }
  else
    {
      n0->prev = tree->t0;
      tree->t0->next = n0;
      tree->t0 = n0;
    }
}

void		get_h1(t_tree *tree, t_node *n1)
{
  if (tree->h1 == NULL)
    {
      tree->h1 = n1;
      tree->t1 = n1;
    }
  else
    {
      n1->prev = tree->t1;
      tree->t1->next = n1;
      tree->t1 = n1;
    }
}

t_node		*get_nodes(int data, char *str)
{
  t_node	*new;
  ssize_t	i;

  if ((new = malloc(sizeof(*new))) == NULL)
    fatal_error("Memory allocation failed", 84);
  new->data = data;
  i = 0;
  while (str[i] && str[i] != CMT_CHAR)
    {
      new->str[i] = str[i];
      i++;
    }
  new->str[i] = '\0';
  new->next= NULL;
  new->prev = NULL;
  return (new);
}

t_tree		*fill_node(t_tree *tree, int data, char *str,
			   int listtofeed)
{
  t_node	*n0;
  t_node	*n1;

  n0 = NULL;
  n1 = NULL;
  if (listtofeed == 0 || listtofeed == 2)
    {
      n0 = get_nodes(data, str);
      get_h0(tree, n0);
    }
  if (listtofeed == 1 || listtofeed == 2)
    {
      n1= get_nodes(data * 2, str);
      get_h1(tree, n1);
    }
  return (tree);
}
