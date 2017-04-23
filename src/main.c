/*
** main.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Fri Apr 14 21:35:39 2017 Bender_Jr
** Last update Sun Apr 23 10:42:46 2017 Bender_Jr
*/

# include "base.h"

int			main()
{
  t_shell		mescouilles;
  extern char		**environ;

  mescouilles.term.prompt_frmat = "\033[0m%U@%H \033[1m%~\033[0m >> ";
  fill_builtins(&(mescouilles).blts);
  mescouilles.environ = environ;
  if ((mescouilles.envlist = init_environ(environ)) == NULL ||
      (mescouilles.history = init_history()) == NULL ||
      (g_rt = init_term(&(mescouilles).term)) == -1 ||
      (mescouilles.pathlist = init_paths("/bin:/usr/bin")) == NULL ||
      (mescouilles.pathlist = fill_path(mescouilles.pathlist)) == NULL)
    return (1);
  run(&mescouilles);
  return (g_rt);
}
