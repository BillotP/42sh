/*
** base.h for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 22 20:50:23 2017 Bender_Jr
** Last update Mon Apr 24 23:18:23 2017 Bender_Jr
*/

#ifndef BASE_H_
# define BASE_H_

/*
** for ssize_t typedef
*/
# include <unistd.h>

/*
** strtowortab, p_printf, f_printf
** and formating macro error msg
** inclusion
** (for convenience that's bad I know that)
**  Paul
**  lead developer
*/
# include "decl.h"
# include "strtowordtab.h"
# include "fprint.h"
# include "printf.h"
# include "errors.h"

/*
** for termios and btptr typedef
*/
# include "my_termios.h"
# include "prompt.h"
# include "builtins.h"

/*
** src/parslex/hash_path.c
*/
t_vars		*fill_vars(const char *bin_name, const char *dir_name);
t_path		*get_vars(t_path *path, const char *bin_path, const char *dir_name);
t_path		*fill_path(t_path *path);

/*
** src/parslex/hashlist_utils.c
*/
t_path		*init_paths(const char *pathvar);
char		*is_proginlist(const t_path *path, unsigned long checksum);
void		free_list(t_path *ptr);

/*
** src/history/history.c
*/
t_history	*init_history();
t_hist		*get_hist(const char *cmd);
t_history	*fill_history(t_history *ptr, const char *cmd);
int		write_histfile(t_history *ptr);

/*
** src/history/hist_utils.c
*/
void		free_history(t_history *ptr);
void		print_history(t_history *ptr);

/*
** src/env_ctrl/envlist.c
*/
t_envar		*get_envar(char *fullenvar);
t_environ	*init_environ(char **environ);
t_environ	*fill_env(t_environ *ptr, char *newenvar);

/*
** src/env_ctrl/env_fctions.c
*/
int		env(char **cmd, void *ptr);
int		xsetenv(char **cmd, void *ptr);
void		free_env(t_environ *ptr);

/*
** src/env_ctrl/env_utils.c
*/
int		add_or_replace(t_environ *ptr, unsigned long var_sum);
unsigned long	get_newvar(int argc, char **av, char *bfr);
t_environ	*replace_lastnode(t_environ *ptr, char *fullvar);
t_environ	*replace_firstnode(t_environ *ptr, char *fullvar);
t_environ	*replace_middlenode(t_environ *ptr, char *fullvar,
				    unsigned long var_sum);

/*
** src/run_exec.c
*/
int		clean_exit(t_shell *ptr);
int		check_status(pid_t son, int *stat_loc);
int		exec(char **argv, t_shell *ptr);
int		run(t_shell *ptr);

/*
** src/status/status_handler.c
*/
void		get_status(struct s_status *ptr, int *status);
int		check_status(pid_t son, int *stat_loc);
/*
** lib/core/string*.c
*/
ssize_t		len(const char *str);
ssize_t		tab_len(char **tab);
int		strn_cmp(const char *s1, const char *s2, size_t n);
char		*my_strcat(char *dest, const char *src);
char		*my_strdup(const char *src);
char		*removespace(char *str);
char		*my_strcatvs(char *dest, const char *src);
char		*my_strcpy(char *dest, const char *src);
char		*my_strncpy(char *dest, const char *src, size_t n);
void		*xmemset(void *s, int c, size_t n);
void		*my_memmove(void *dest, const void *src, size_t n);

/*
** stdlib adapted
*/
int		my_stringisnum(const char *str);
int		my_atoi(const char *str);
int		pprint(const char *str, int fd);
char		**freetab(char **ptr);
char		*clean_free(char *ptr);
char		*epurstr(char *str, int c);

/*
** check.c
*/
int		is_legitchar(char c, const char *reference);
int		is_legitstr(char *str, const char *reference);
unsigned long	get_sum(unsigned char *bfr);

#endif /* !BASE_H_ */
