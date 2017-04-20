/*
** builtins.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Tue Apr 18 17:32:51 2017 Bender_Jr
** Last update Thu Apr 20 14:57:00 2017 Bender_Jr
*/

# include "builtins.h"
# include "base.h"

volatile int tty_fd;

# define PATH_MAX (4096)

int	echo(char **cmd)
{
  int	i;

  i = 1;
  while (i != tab_len(cmd))
    {
      p_printf(1, "[%s]\n", cmd[i]);
      i++;
    }
  return (1);
}

int		cd(char **cmd)
{
  if (chdir(cmd[1]) == -1)
    return (-1);
  return (1);
}

# include <stdio.h>

int		clear(UNUSED char **cmd)
{
  /* int		i; */
  char		clear[5] ={27, '[', '2', '0'};

  i = 0;
  while (clear[i])
    {
      if (write(tty_fd, &clear[i], 1) == -1)
  	return (-1);
      i++;
    }
  /* printf("%s", clear); */
  return (1);
}
void		fill_builtins(t_blts *list)
{
  char		**tmp;

  tmp = strto_wordtab(BLTS_NAMES, ",");
  list->blts_names = tmp;
  list->btptr[0] = cd;
  list->btptr[1] = echo;
  list->btptr[2] = clear;
}

int		is_builtins(char **cmd, t_blts *ptr)
{
  int		i;
  int		j;
  int		rt;

  i = 0;
  rt = 0;
  j = tab_len(ptr->blts_names);
  while (i != j)
    {
      if (strn_cmp(cmd[0], ptr->blts_names[i], len(cmd[0])))
	if ((rt = ptr->btptr[i](cmd)))
	  return (freetab(cmd), rt);
      i++;
    }
  return (freetab(cmd), rt);
}