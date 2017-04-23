/*
** env_fctions.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sun Apr 23 10:07:11 2017 Bender_Jr
** Last update Sun Apr 23 11:32:45 2017 Bender_Jr
*/

/*
** for free
*/
# include <stdlib.h>
# include "base.h"

int		env(UNUSED char **cmd, void *ptr)
{
  t_shell	*test;
  t_envar	*tmp;

  test = ptr;
  tmp = test->envlist->firstenvar;
  while (tmp)
    {
      p_printf(1, "%s=%s\n", tmp->variable, tmp->value);
      tmp = tmp->next;
    }
  return (1);
}

void		free_env(t_environ *ptr)
{
  while (ptr->firstenvar)
    {
      free(ptr->firstenvar->variable);
      free(ptr->firstenvar->prev);
      ptr->firstenvar = ptr->firstenvar->next;
    }
  free(ptr->lastenvar);
  free(ptr);
}
