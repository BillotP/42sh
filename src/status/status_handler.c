/*
** status_handler.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sun Apr 23 18:48:58 2017 Bender_Jr
** Last update Mon Apr 24 23:37:39 2017 Bender_Jr
*/

/*
** for waitpid macro and funct(s)
*/
# define _GNU_SOURCE
# include <sys/wait.h>
# include "base.h"

void	get_status(struct s_status *ptr, int *status)
{
  if (WCOREDUMP(*status))
    {
      my_strcpy((ptr[8]).msg, "Floating exception (core dumped)\n");
      my_strcpy((ptr[11]).msg, "Segmentation fault (core dumped)\n");
    }
  else
    {
       my_strcpy((ptr[8]).msg, "Floating exception\n");
       my_strcpy((ptr[11]).msg, "Segmentation fault\n");
    }
  ptr[8].rt = 136;
  ptr[11].rt = 139;
}

int			check_status(pid_t son, int *stat_loc)
{
  struct s_status	ptr[20];
  int			rt;

  rt = 0;
  while ((g_rt = (waitpid(son, stat_loc, WUNTRACED | WCONTINUED))))
    {
      if (g_rt == -1)
	return (g_rt);
      if (WIFEXITED(*stat_loc))
	{
	  rt = WEXITSTATUS(*stat_loc);
	  return (g_rt = rt);
	}
      else if (WIFSIGNALED(*stat_loc))
	{
	  g_rt = WTERMSIG(*stat_loc);
	  get_status(ptr, stat_loc);
	  return (p_printf(2, "%s", ptr[g_rt].msg), g_rt = ptr[g_rt].rt);
	}
      return (g_rt = 0);
    }
  return (g_rt = 0);
}
