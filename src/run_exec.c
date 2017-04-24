/*
** run_exec.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sun Apr 23 10:17:57 2017 Bender_Jr
** Last update Mon Apr 24 23:41:20 2017 Bender_Jr
*/

/*
** for wait and xaccess stat
*/
# include <sys/wait.h>
# include <sys/stat.h>

/*
** for strerror, errno free, excve etc
*/
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include "base.h"
# include "get_next_line.h"

int		clean_exit(t_shell *ptr)
{
  freetab(ptr->blts.blts_names);
  free_list(ptr->pathlist);
  close(ptr->history->histfilefd);
  free_history(ptr->history);
  free_env(ptr->envlist);
  reset_cap(&(ptr)->term.save, ptr->term.tty_fd);
  p_printf(1, "valeur des gloables : g_rt %d , g_exit %d\n", g_rt, g_exit);
  return (g_rt = (g_rt == 1 && g_exit == 1) ? 0 : g_rt);
}

int			xaccess(const char *pathname, UNUSED int mode)
{
  struct stat		sb;

  if(!stat(pathname, &sb))
    {
      if(S_ISREG(sb.st_mode) && (sb.st_mode & 0111))
	return (0);
    }
  return (-1);
}

int		exec(char **argv, t_shell *ptr)
{
  t_exec	execl;

  g_rt = 0;
  xmemset(&execl, '\0', sizeof(execl));
  execl.cksum = get_sum((unsigned char *)argv[0]);
  if ((execl.cmdpath = is_proginlist(ptr->pathlist, execl.cksum)) == NULL &&
      (xaccess(argv[0], 1)) == -1)
    return (freetab(argv), -1);
  if  ((execl.parentpid = getpid()) == -1 ||
       (execl.child_pid = fork()) == -1)
    return (freetab(argv), -1);
  else if (execl.child_pid == 0)
    {
      !xaccess(argv[0], 1) ? execl.cmdpath = argv[0] : execl.cmdpath;
      g_rt = ((execve(execl.cmdpath, argv, ptr->environ)) || (errno)) ? (-1) : (0);
    }
  else
    check_status(execl.child_pid, &(execl).status);
  return (freetab(argv), g_rt);
}

/*
** le run prompt va bientot changer
** et ca va être un truc de malade
** (oui je sais pour le moment c'est degeu)
** Paul
*/

int		run(t_shell *ptr)
{
  char		*tmp;
  char		**bfr;
  char		err[PATH_MAX];


  g_exit = 0;
  while ((tmp = get_next_line(ptr->term.tty_fd)))
    {
      g_rt = 0;
      xmemset(err, '\0', sizeof(err));
      if (len(tmp) && (tmp[0] != '\033'))
	if ((is_legitstr(tmp = epurstr(tmp, ' '), LEGIT_CHAR)) >= 0)
	  {
	    bfr = strto_wordtab(tmp, " ");
	    (bfr[1]) ? my_strcpy(err, bfr[1]) : my_strcpy(err, bfr[0]);
	    if ((ptr->history = fill_history(ptr->history, tmp)) == NULL ||
		(g_rt = is_builtins(bfr, ptr, &(ptr)->blts)) == -1 ||
		(!g_rt && (g_rt = exec(bfr, ptr)) == -1))
	      (errno) ? p_printf(2, "%s: %s\n", err, strerror(errno)) :
		p_printf(2, "%s pointeur sur le message d'erreur des blts\n", ERR);
	    else if (g_exit >= 1)
	      return (free(tmp), clean_exit(ptr));
	  }
      g_rt = (g_rt == -1) ? 1 : g_rt;
      pr_printf(ptr->term.prompt_frmat);
      free(tmp);
    }
  return (g_rt = clean_exit(ptr));
}
