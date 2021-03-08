/*
** main.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Fri Apr 14 21:35:39 2017 Bender_Jr
** Last update Mon Apr 24 18:02:29 2017 Bender_Jr
*/

# include "base.h"

int			main()
{
  t_shell		shell;
  extern char		**environ;

  shell.term.prompt_frmat = "\033[0m%U@%H \033[1m%~\033[0m >> ";
  fill_builtins(&(shell).blts);
  if (!tab_len(environ))
    environ = strto_wordtab(SH_ENV, ",");
  shell.environ = environ;
  if ((shell.envlist = init_environ(environ)) == NULL ||
      (shell.history = init_history()) == NULL ||
      (g_rt = init_term(&(shell).term)) == -1 ||
      (shell.pathlist = init_paths("/bin:/usr/bin")) == NULL ||
      (shell.pathlist = fill_path(shell.pathlist)) == NULL)
    return (1);
  run(&shell);
  return (g_rt);
}
