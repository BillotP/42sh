/*
** main.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Fri Apr 14 21:35:39 2017 Bender_Jr
** Last update Sat Apr 22 08:57:47 2017 Bender_Jr
*/

/*
** for popen (will be removed)
** when scripting will do
** the exec job
*/
# include <stdio.h>
/*
** for sig handler
*/
#include <signal.h>
/*
** for strerror and errno
*/
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include "prompt.h"
# include "builtins.h"
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
    p_printf(1, "%s\033[M", tmp);
  return (pclose(pipe) == 0 ? 0 : 1);
}

int		run()
{
  t_termios	list;
  t_blts	ptr;
  int volatile	rt;
  char		*tmp;
  char		**bfr;

  rt = 0;
  list.prompt_frmat = "\033[0m%U@%H \033[1m%~\033[0m >> ";
  fill_builtins(&ptr);
  if ((rt = init_term(&list)) == -1)
    return (-1);
  while ((tmp = get_next_line(list.tty_fd)))
    {
      if (tmp && (is_legitstr(tmp = epurstr(tmp, ' '), LEGIT_CHAR)) >= 0)
	{
	  bfr = strto_wordtab(tmp, " ");
	  if ((rt = is_builtins(bfr, &ptr)) == -1 ||
	      (!rt && (rt = exec(tmp)) == -1))
	    p_printf(2, "%s%s\n", ERR, strerror(errno));
	}
      pr_printf(list.prompt_frmat);
      free(tmp);
    }
  freetab(ptr.blts_names);
  reset_cap(&(list).save, list.tty_fd);
  return (rt == 1 || rt == 0 ? 0 : -1);
}

void			sig_handler(int signum, siginfo_t *info, UNUSED void *context)
{
  if (signum)
    p_printf(1, "\nreceive signal %d from pid %d\n", signum,
	     info->si_pid);
}

int			main()
{
  int			rt;
  struct sigaction	new;

  new.sa_sigaction = sig_handler;
  sigemptyset(&new.sa_mask);
  new.sa_flags = SA_SIGINFO;
  sigaction(SIGINT, &new, NULL);
  sigaction(SIGQUIT, &new, NULL);
  return (((rt = run()) == -1) ? 1 : 0);
}
