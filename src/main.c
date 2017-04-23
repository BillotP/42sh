/*
** main.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Fri Apr 14 21:35:39 2017 Bender_Jr
** Last update Sun Apr 23 08:52:25 2017 Bender_Jr
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
  close(ptr->history->histfilefd);
  free_history(ptr->history);
  reset_cap(&(ptr)->term.save, ptr->term.tty_fd);
  g_rt = (g_rt == 2 ? (0) : (g_rt));
  return (g_rt);
}

int		check_status(pid_t son, int *stat_loc)
{
  while ((g_rt = (waitpid(son, stat_loc, WUNTRACED | WCONTINUED))))
    {
      if (g_rt == -1)
	return (g_rt);
      if (WIFEXITED(g_rt))
	return (g_rt = 0);
      else if (WIFSIGNALED(*stat_loc))
	{
	  if (WTERMSIG(*stat_loc) == 11)
	    return (p_printf(2, "Segmentation fault (core dumped)\n"), g_rt = -139);
	  else if (WTERMSIG(*stat_loc) == 8)
	    return (p_printf(2, "Floating exception (core dumped)\n"), g_rt = -136);
	}
      return (g_rt = 0);
    }
  return (g_rt = 0);
}

int		exec(char **argv, t_shell *ptr)
{
  t_exec	execl;

  g_rt = 0;
  xmemset(&execl, '\0', sizeof(execl));
  execl.cksum = get_sum((unsigned char *)argv[0]);
  if ((execl.cmdpath = is_proginlist(ptr->pathlist, execl.cksum)) == NULL &&
      (access(argv[0], X_OK)) == -1)
    return (-1);
  if  ((execl.parentpid = getpid()) == -1 ||
       (execl.child_pid = fork()) == -1)
    return (-1);
  else if (execl.child_pid == 0)
    {
      access(argv[0], X_OK) == 0 ? execl.cmdpath = argv[0] : execl.cmdpath;
      g_rt = ((execve(execl.cmdpath, argv, ptr->environ)) || (errno)) ? (-1) : (0);
    }
  else
    check_status(execl.child_pid, &(execl).status);
  freetab(argv);
  return (g_rt);
}

int		run(t_shell *ptr)
{
  char		*tmp;
  char		**bfr;

  while ((tmp = get_next_line(ptr->term.tty_fd)))
    {
      g_rt = 0;
      if (!(tmp[0] == '\033'))
	if (tmp && (is_legitstr(tmp = epurstr(tmp, ' '), LEGIT_CHAR)) >= 0)
	  {
	    bfr = strto_wordtab(tmp, " ");
	    if ((ptr->history = fill_history(ptr->history, tmp)) == NULL ||
		(g_rt = is_builtins(bfr, &(ptr)->blts)) == -1 ||
		(!g_rt && (g_rt = exec(bfr, ptr)) == -1))
	      p_printf(2, "%s%s\n", ERR, strerror(errno));
	    else if (g_rt > 1)
	      return (free(tmp), clean_exit(ptr));
	    else if (g_rt < -1)
	      g_rt *= -1;
	  }
      g_rt = (g_rt == 1 || g_rt == 0) ? 0 : g_rt == -1 ? 1 : g_rt;
      pr_printf(ptr->term.prompt_frmat);
      free(tmp);
    }
  return (g_rt = clean_exit(ptr));
}

int			main()
{
  t_shell		mescouilles;
  extern char		**environ;

  mescouilles.term.prompt_frmat = "\033[0m%U@%H \033[1m%~\033[0m >> ";
  fill_builtins(&(mescouilles).blts);
  mescouilles.environ = environ;
  if ((mescouilles.history = init_history()) == NULL ||
      (g_rt = init_term(&(mescouilles).term)) == -1 ||
      (mescouilles.pathlist = init_paths("/bin:/usr/bin")) == NULL ||
      (mescouilles.pathlist = fill_path(mescouilles.pathlist)) == NULL)
    return (1);
  run(&mescouilles);
  return (g_rt);
}
