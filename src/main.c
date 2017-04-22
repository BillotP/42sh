/*
** main.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Fri Apr 14 21:35:39 2017 Bender_Jr
** Last update Sat Apr 22 20:39:43 2017 Bender_Jr
*/

/*
** for wait
*/
# include <sys/wait.h>

/*
** for strerror and errno
*/
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include "prompt.h"
# include "base.h"
# include "get_next_line.h"

int		clean_exit(t_shell *ptr)
{
  freetab(ptr->blts.blts_names);
  free_list(ptr->pathlist);
  reset_cap(&(ptr)->term.save, ptr->term.tty_fd);
  g_rt = (g_rt == 2 ? (0) : (g_rt));
  return (g_rt);
}

int		exec(char **argv, t_shell *ptr)
{
  extern char	**environ;
  char		*cmdpath;
  int		child_pid;
  int		parentpid;
  int		status;

  g_rt = 0;
  if ((cmdpath =
       is_proginlist(ptr->pathlist, get_sum((unsigned char *)argv[0]))) == NULL
      || (parentpid = getpid()) == -1 ||
      (child_pid = fork()) == -1)
    return (-1);
  else if (child_pid == 0)
    {
      if ((execve(cmdpath, argv, environ)) || (errno))
	g_rt = -1;
    }
  else
    waitpid(child_pid, &status, 0);
  freetab(argv);
  return (g_rt);
}

int		run(t_shell *ptr)
{
  char		*tmp;
  char		**bfr;

  g_rt = 0;
  while ((tmp = get_next_line(ptr->term.tty_fd)))
    {
      if (!(tmp[0] == '\033'))
	if (tmp && (is_legitstr(tmp = epurstr(tmp, ' '), LEGIT_CHAR)) >= 0)
	  {
	    bfr = strto_wordtab(tmp, " ");
	    if ((g_rt = is_builtins(bfr, &(ptr)->blts)) == -1 ||
		(!g_rt && (g_rt = exec(bfr, ptr)) == -1))
	      p_printf(2, "%s%s\n", ERR, strerror(errno));
	    else if (g_rt > 1)
	      return (free(tmp), clean_exit(ptr));
	  }
      g_rt = (g_rt == 1 || g_rt == 0) ? 0 : 1;
      pr_printf(ptr->term.prompt_frmat);
      free(tmp);
    }
  return (g_rt = clean_exit(ptr));
}

int			main()
{
  t_shell		mescouilles;

  mescouilles.term.prompt_frmat = "\033[0m%U@%H \033[1m%~\033[0m >> ";
  fill_builtins(&(mescouilles).blts);
  if ((g_rt = init_term(&(mescouilles).term)) == -1 ||
      (mescouilles.pathlist = init_paths("/bin:/usr/bin")) == NULL ||
      (mescouilles.pathlist = fill_path(mescouilles.pathlist)) == NULL)
    return (1);
  run(&mescouilles);
  return (g_rt);
}
