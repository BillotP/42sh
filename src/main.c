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
  t_shell		ta_mere;
  extern char		**environ;

  ta_mere.term.prompt_frmat = "\033[0m%U@%H \033[1m%~\033[0m >> ";
  fill_builtins(&(ta_mere).blts);
  if (!tab_len(environ))
    environ = strto_wordtab(SH_ENV, ",");
  ta_mere.environ = environ;
  if ((ta_mere.envlist = init_environ(environ)) == NULL ||
      (ta_mere.history = init_history()) == NULL ||
      (g_rt = init_term(&(ta_mere).term)) == -1 ||
      (ta_mere.pathlist = init_paths("/bin:/usr/bin")) == NULL ||
      (ta_mere.pathlist = fill_path(ta_mere.pathlist)) == NULL)
    return (1);
  run(&ta_mere);
  return (g_rt);
}
