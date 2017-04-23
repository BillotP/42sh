/*
** decl.h for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sun Apr 23 11:01:17 2017 Bender_Jr
** Last update Sun Apr 23 12:14:59 2017 Bender_Jr
*/

#ifndef DECL_H_
# define DECL_H_

/*
** this header contain all the struct
** and typdef declaration of the shell
*/

/*
** for debug and signal handler context
*/
# define UNUSED __attribute__((unused))

/*
** check_str valid char
*/
#ifndef LEGIT_CHAR
# define LEGIT_CHAR "0123456789_ABCDEFGHIJKLMNOPQRSTUVWXYZ \
abcdefghijklmnopqrstuvwxyz\
!#,:`'*.=$-+/\\()?%~>\"@]["
# endif /* !LEGIT_CHAR */

#ifndef LEGIT_VARCHAR
#define  LEGIT_VARCHAR "0123456789_ABCDEFGHIJKLMNOPQRSTUVWXYZ \
-abcdefghijklmnopqrstuvwxyz"
# endif /* !LEGIT_VARCHAR */

/*
** Limits values
*/
#ifndef PATH_MAX
# define PATH_MAX (4096)
# endif /* !PATH_MAX */

/*
** return value volatile glob var
*/
int volatile	g_rt;

/*
**             =========
**        42sh mains structs
**         ****************
*/
typedef struct	s_vars {
  struct s_vars	*prev;
  struct s_vars	*next;
  char		*bin_name;
  char		bin_path[PATH_MAX];
  unsigned long	chksum;
}		t_vars;

typedef struct	s_path {
  char		*path_var;
  t_vars	*firstvar;
  t_vars	*lastvar;
}		t_path;

typedef struct	s_hist {
  char		*cmd;
  char		*timestamp;
  int		order;
  struct s_hist	*next;
  struct s_hist	*prev;
}		t_hist;

/*
** defines for histfile
*/
#ifndef HIST_FILE
# define HIST_FILE	".42history"
# endif /* !HIST_FILE */

#ifndef HF_FLAG
#define HF_FLAG		(O_RDWR | O_CREAT | O_APPEND)
# endif /* !HF_FLAG */

#ifndef HF_MODE
# define HF_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
# endif /* !HF_MODE */

typedef struct	s_history {
  t_hist	*histfirst;
  t_hist	*histlast;
  int		histfilefd;
}		t_history;

typedef struct		s_envar {
  char			*variable;
  char		        value[PATH_MAX];
  unsigned long		hash;
  struct s_envar	*prev;
  struct s_envar	*next;
}			t_envar;

typedef struct		s_environ {
  char			**environ;
  t_envar		*firstenvar;
  t_envar		*lastenvar;
}			t_environ;

/*
** for pid_t type
*/
typedef int		pid_t;
typedef struct		s_exec {
  char			*cmdpath;
  unsigned long		cksum;
  pid_t			child_pid;
  pid_t			parentpid;
  int			status;
}			t_exec;

/*
** for struct termios typedef
*/
# include <termios.h>

/*
** note : the prompt format
** will be move in the conf file
** later on
*/
typedef struct		s_termios {
  struct termios	new;
  struct termios	save;
  const char		*prompt_frmat;
  int			tty_fd;
}			t_termios;

/*
** Builtins Macro and Typedef
** develloped then named
*/
#ifndef BLTS_NAMES
# define BLTS_NAMES "cd,echo,exit,env,setenv,clear"
# endif /* !BLTS_NAMES */

typedef int		(*builtins)(char **bfr, void *ptr);
typedef struct		s_blts {
  char			**blts_names;
  builtins		btptr[6];
}			t_blts;

typedef struct		s_shell {
  t_termios		term;
  t_blts		blts;
  t_path		*pathlist;
  t_history		*history;
  t_environ		*envlist;
  char			**environ;
}			t_shell;

/*
** Prompt size define
*/
#ifndef PROMPT_SIZE
# define PROMPT_SIZE (126)
# endif /* !PROMPT_SIZE */

/*
** prompt glob_var
*/
char	g_prompt[PROMPT_SIZE];

/*
** prompt_printf(fction ptr)
*/
typedef int (*flags_fct)(char prompt_bfr[]);
extern flags_fct ptr[];

#endif /* !DECL_H_ */
