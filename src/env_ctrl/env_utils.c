/*
** env_utils.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 24 17:26:16 2017 Bender_Jr
** Last update Mon Apr 24 21:11:46 2017 Bender_Jr
*/

/*
** for free
*/
# include <stdlib.h>
# include "base.h"

int	        add_or_replace(t_environ *ptr, unsigned long var_sum)
{
  t_envar	*tmp;

  tmp = ptr->firstenvar;
  if (var_sum == tmp->hash)
    return (1);
  else if (var_sum == ptr->lastenvar->hash)
    return (2);
  while (tmp)
    {
      if (var_sum == tmp->hash)
	return (3);
      tmp = tmp->next;
    }
  return (0);
}

t_environ	*replace_lastnode(t_environ *ptr, char *fullvar)
{
  t_envar	*new;

  if ((new = get_envar(fullvar)) == NULL)
    return (NULL);
  ptr->lastenvar->prev->next = new;
  new->prev = ptr->lastenvar->prev;
  free(ptr->lastenvar->variable);
  free(ptr->lastenvar);
  ptr->lastenvar = new;
  return (ptr);
}

t_environ	*replace_firstnode(t_environ *ptr, char *fullvar)
{
  t_envar	*new;

  if ((new = get_envar(fullvar)) == NULL)
    return (NULL);
  new->next = ptr->firstenvar->next;
  ptr->firstenvar->next->prev = new;
  free(ptr->firstenvar->variable);
  free(ptr->firstenvar->prev);
  ptr->firstenvar = new;
  return (ptr);
}

t_environ	*replace_middlenode(t_environ *ptr, char *fullvar,
				    unsigned long var_sum)
{
  t_envar	*new;
  t_envar	*headptr;

  if ((new = get_envar(fullvar)) == NULL)
    return (NULL);
  headptr = ptr->firstenvar;
  headptr = headptr;
  var_sum = var_sum;
  free(new->variable);
  free(new);
  return (ptr);
}

unsigned long	get_newvar(int argc, char **av, char *bfr)
{
  unsigned long	sum;

  sum = get_sum((unsigned char *)av[1]);
  my_strcpy(bfr, av[1]);
  my_strcatvs(bfr, "=");
  (argc == 3) ? my_strcatvs(bfr, av[2]) : my_strcatvs(bfr, " ");
  return (sum);
}
