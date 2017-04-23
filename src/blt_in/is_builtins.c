/*
** is_builtins.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 22 12:39:34 2017 Bender_Jr
** Last update Sun Apr 23 11:45:54 2017 Bender_Jr
*/

# include "base.h"
# include "builtins.h"


void		fill_builtins(t_blts *list)
{
  char		**tmp;

  tmp = strto_wordtab(BLTS_NAMES, ",");
  list->blts_names = tmp;
  list->btptr[0] = cd;
  list->btptr[1] = echo;
  list->btptr[2] = x_exit;
  list->btptr[3] = env;
  list->btptr[4] = clear;
}

int		is_builtins(char **cmd, t_shell *addr, t_blts *ptr)
{
  int		i;
  int		j;

  i = 0;
  j = tab_len(ptr->blts_names);
  while (i != j)
    {
      if (strn_cmp(cmd[0], ptr->blts_names[i], len(cmd[0])))
	if ((g_rt = ptr->btptr[i](cmd, addr)))
	  return (freetab(cmd), g_rt);
      i++;
    }
  return (g_rt);
}
