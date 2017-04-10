/*
** sh.h for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:30:58 2017 Bender_Jr
** Last update Mon Apr 10 09:39:33 2017 Bender_Jr
*/

#ifndef SH_H_
# define SH_H_

/*
** for errno and sterror
** usage
*/

# include <string.h>
# include <errno.h>

/*
********  *******
*/

typedef struct	s_env {
  char		*envar;
  struct s_env	*prev;
  struct s_env	*next;
}		t_env;

typedef struct	s_chain {
  char		**env;
  char		**paths;
  t_env		*head;
  t_env		*tail;
}		t_chain;

/*
** mysh environ
*/

#ifndef ENV
# define ENV "PATH=/bin/:/usr/bin/,HOME=xxx,PWD=xxx,OLDPWD=xxx,\
TERM=xterm,USER=xxxx,SHELL=mysh"
# endif /* !ENV */

/*
** Builtins Macro and Typedef
*/

#ifndef BLTS_NAMES
# define BLTS_NAMES "cd,pwd,env,setenv,unsetenv,exit,clear,exit"
# endif /* !BLTS_NAMES */

typedef int	(*builtins)(t_chain *list, char **args);
extern builtins	btptr[];

typedef struct	s_blts {
  char		**blts_names;
  builtins	btptr[4];
}		t_blts;

/*
** Size Limits
*/

#ifndef PATH_MAX
# define PATH_MAX (4096)
# endif /* !PATH_MAX */

/*
** Funky Prompt
*/

char buffer[PATH_MAX];

#ifndef PROMPT
# define   PROMPT my_strcatvs(getcwd(buffer, PATH_MAX), "> ")
# endif /* !PROMPT */

/*
** Output formating macros
*/

#ifndef BLD
# define BLD		"\033[1m"
# endif /* !BLD */

#ifndef RST
# define RST		"\033[0m"
# endif /* !RST */

/*
** ERRORS Messages
*/

#ifndef ERR_NO
# define ERR_NO(errno) strerror(errno)
# endif /* !ERR_NO */

#ifndef CD_HLP
# define CD_HLP "Usage: cd [-plvn][-|<dir>]"
# endif /* !CD_HLP */

#ifndef PWD_ERR
# define PWD_ERR "ignoring non-option arguments"
# endif /* !PWD_ERR */

#ifndef SETENV_ERR
# define SETENV_ERR "Too many arguments."
# endif /* !SETENV_ERR */

#ifndef ENV_FCHAR
# define ENV_FCHAR "Variable name must begin with a letter."
# endif /* !ENV_FCHAR */

#ifndef ENV_INVCHAR
# define ENV_INVCHAR "Variable name must contain alphanumeric\
 characters."
# endif /* !ENV_INVCHAR */

/*
******* Function declarations ***
******* *****  ************** ***
** srcs/envlist/env_struct.c
*/

t_chain		*init_chain();
t_env		*new_envar(const char *data);
t_chain		*fill_chain(t_chain *chain, t_env *new);
void		free_chain(t_chain *chain);

/*
** srcs/envlist/env_utils.c
*/

int		dup_env(char **environ, t_chain *list);
int		print_env(t_chain *envlist);
char		*get_envdata(const char *tofind, t_chain *chain);

/*
** srcs/builtins/builtins_utils.c
*/

int		fill_builtin(t_blts *ptr);
int		is_builtin(t_blts *ptr, t_chain *envlist, char *bfr);

/*
** srcs/builtins/builtins.c
*/

int		my_pwd(t_chain *list, char **args);
int		my_cd(t_chain *list, char **args);
int		my_env(t_chain *list, char **args);
int		my_setenv(t_chain *list, char **args);

/*
** srcs/builtins/setenv.c
*/

int		my_env(t_chain *list, char **args);
int		my_setenv(t_chain *list, char **args);
int		check_envar(char *str);

/*
** srcs/exec/exec.c
*/

int		get_ui(t_chain *list, int *return_val);

#endif /* !42SH_H_ */
