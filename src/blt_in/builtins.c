/*
** builtins.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Tue Apr 18 17:32:51 2017 Bender_Jr
** Last update Sat Apr 22 13:37:19 2017 Bender_Jr
*/

# include "builtins.h"
# include "base.h"

/*
** NOTE :
** Les gars glandez pas ya du boulot
** sur les builtins tipiquement celui du dessous
** qui est à moitié faite
*/
int	echo(char **cmd)
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

int		cd(char **cmd)
{
  if (chdir(cmd[1]) == -1)
    return (-1);
  return (1);
}

int		x_exit(char **cmd)
{
  if (cmd[1])
    {
      if (!my_stringisnum(cmd[1]))
	return (p_printf(2, "%s: %s\n", cmd[0], SYNTX_ERR), 1);
      else if ((g_rt = my_atoi(cmd[1])) >= 0 && g_rt <= 255)
	return (g_rt);
    }
  return (2);
}

int		clear(UNUSED char **cmd)
{
  if (write(1, "\033[H", len("\033[H")) == -1 ||
      write(1, "\033[2J", len("\033[2J")) == -1)
    return (-1);
  return (1);
}

/*
** the help cmd will print
** a list of builtins funct
** and eventually the license
** with some georgeous ascii art
*/
int		help(UNUSED char **cmd)
{
  if (write(1, "RTFM!\n", len("RTFM!\n")) == -1)
    return (-1);
  return (0);
}
