/*
** env_fctions.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sun Apr 23 10:07:11 2017 Bender_Jr
** Last update Mon Apr 24 17:27:05 2017 Bender_Jr
*/

/*
** for free
*/
# include <stdlib.h>
# include "base.h"

int		xsetenv(char **cmd, void *ptr)
{
  t_shell	*type;
  char		newvar[PATH_MAX];
  unsigned long sum;
  int		argc;
  int		rt;

  type = ptr;
  argc = tab_len(cmd);
  xmemset(newvar, '\0', sizeof(*newvar));
  if (argc > 3)
    return (-1);
  else if (argc == 1)
    return (env(cmd, ptr));
  else if (argc >= 2)
    {
      sum = get_newvar(argc, cmd, newvar);
      if ((rt = add_or_replace(type->envlist, sum)) == 0)
	type->envlist = fill_env(type->envlist, newvar);
      type->envlist = (rt == 1) ? replace_firstnode(type->envlist, newvar) :
        (rt == 2 ) ? replace_lastnode(type->envlist, newvar) : (rt == 3) ?
	replace_middlenode(type->envlist, newvar, sum) : type->envlist;
    }
  return (1);
}

int		env(UNUSED char **cmd, void *ptr)
{
  t_shell	*type;
  t_envar	*tmp;

  type = ptr;
  tmp = type->envlist->firstenvar;
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
