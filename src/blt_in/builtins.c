/*
** builtins.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Tue Apr 18 17:32:51 2017 Bender_Jr
** Last update Tue Apr 25 11:24:21 2017 Bender_Jr
*/

/*
** for getenv
*/
# include "stdlib.h"
# include "builtins.h"
# include "base.h"

/*
** NOTE :
** Les gars glandez pas ya du boulot
** sur les builtins tipiquement celle du dessous
** qui est à moitié faite
*/
int	echo(char **cmd, UNUSED void *ptr)
{
  int	i;

  i = 1;
  while (i != tab_len(cmd))
    {
      p_printf(1, "%s ", cmd[i]);
      i++;
    }
  p_printf(1, "\n");
  return (1);
}

int		cd(char **cmd, UNUSED void *ptr)
{
  char		oldpath[PATH_MAX];

  if (tab_len(cmd) == 1)
    {
      xmemset(oldpath, '\0', sizeof(oldpath));
      if ((getcwd(oldpath, sizeof(oldpath))) == NULL ||
	  (chdir(getenv("HOME"))) == -1)
	return (-1);
      return (1);
    }
  else if (tab_len(cmd) == 2)
    {
      if (cmd[1][0] != '-')
	{
	  xmemset(oldpath, '\0', sizeof(oldpath));
	  if ((getcwd(oldpath, sizeof(oldpath))) == NULL)
	    return (-1);
	}
      else if (cmd[1][0] == '-' && !cmd[1][1])
	return ((chdir(oldpath) == -1) ? -1 : 1);
      return (chdir(cmd[1]) == -1 ? -1 : 1);
    }
  return (-1);
}

int		x_exit(char **cmd, UNUSED void *ptr)
{
  if (cmd[1])
    {
      if (!my_stringisnum(cmd[1]))
	return (p_printf(2, "%s: %s\n", cmd[0], SYNTX_ERR), 1);
      else if ((g_exit = my_atoi(cmd[1])) >= 0 && g_rt <= 255)
	return (g_exit = (g_exit == 0) ? 1 : g_exit);
    }
  return (g_exit = 1);
}

int		clear(UNUSED char **cmd, UNUSED void *ptr)
{
  if (write(1, "\033[H", len("\033[H")) == -1 ||
      write(1, "\033[2J", len("\033[2J")) == -1)
    return (-1);
  return (1);
}

/*
** the help cmd will...
** rape ur cat in every
** fcking hole (#saltylikepringle)
*/
int		help(UNUSED char **cmd)
{
  if (write(1, "RTFM!\n", len("RTFM!\n")) == -1)
    return (-1);
  return (0);
}
