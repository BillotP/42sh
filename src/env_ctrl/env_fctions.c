/*
** env_fctions.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sun Apr 23 10:07:11 2017 Bender_Jr
** Last update Sun Apr 23 12:58:03 2017 Bender_Jr
*/

/*
** for free
*/
# include <stdlib.h>
# include "base.h"

int	        add_or_replace(t_environ *ptr, const char *var_tofind)
{
  unsigned long	sum;
  t_envar	*tmp;

  tmp = ptr->firstenvar;
  sum = get_sum((unsigned char *)var_tofind);
  while (tmp)
    {
      if (sum == tmp->hash)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

int		xsetenv(char **cmd, void *ptr)
{
  t_shell	*type;
  char		newvar[PATH_MAX];
  int		argc;

  type = ptr;
  argc = tab_len(cmd);
  xmemset(newvar, '\0', sizeof(*newvar));
  if (argc > 4)
    return (-1);
  else if (argc == 1)
    return (env(cmd, ptr));
  else if (argc >= 2)
    {
      my_strcpy(newvar, cmd[1]);
      my_strcatvs(newvar, "=");
      if (argc == 3)
	my_strcatvs(newvar, cmd[2]);
      else
	my_strcatvs(newvar, "XX");
      if (!add_or_replace(type->envlist, cmd[1]))
	type->envlist = fill_env(type->envlist, newvar);
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
