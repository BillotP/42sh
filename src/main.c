/*
** main.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Fri Apr 14 21:35:39 2017 Bender_Jr
** Last update Tue Apr 18 10:40:04 2017 Bender_Jr
*/

/*
** for popen (will be removed)
** when scripting will do
** the exec job
*/
# include <stdio.h>
/*
** for strerror and errno
*/
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include "prompt.h"
# include "my_termios.h"
# include "base.h"
# include "get_next_line.h"

int		 exec(char *buff)
{
  FILE		*pipe;
  char		ptr[4096];
  char		*tmp;

  fflush(NULL);
  if ((pipe = popen(buff, "r")) == NULL)
    return (p_printf(2, "%s%s", ERR, strerror(errno)), -1);
  while ((tmp = fgets(ptr, 4095, pipe)))
    p_printf(1, "%s", tmp);
  return (pclose(pipe) == 0 ? 0 : 1);
}

int		main()
{
  t_termios	list;
  int		rt;
  char		*tmp;

  rt = 0;
  list.prompt_frmat = "\033[94m%U\033[0m@%H \033[1m%~\033[0m >> ";
  if ((rt = init_term(&list)) == -1)
    return (1);
  while ((tmp = get_next_line(list.tty_fd)))
    {
      if ((rt = exec(tmp)) == -1)
	return (reset_cap(&(list).save, list.tty_fd), rt);
      if (isatty(list.tty_fd))
	pr_printf(list.prompt_frmat);
      free(tmp);
    }
  reset_cap(&(list).save, list.tty_fd);
  return (rt);
}
