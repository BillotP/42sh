/*
1;4601;0c** base.h for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:28:48 2017 Bender_Jr
** Last update Sat Apr 22 19:49:32 2017 Bender_Jr
*/

#ifndef BASE_H_
# define BASE_H_

/*
** for debug and signal handler
*/
# define UNUSED __attribute__((unused))
/*
** for ssize_t  and uint8_t typedef
*/
# include <unistd.h>
# include <stdint.h>

/*
** strtowortab, p_printf
** and formating error msg
** inclusion
*/
# include "strtowordtab.h"
# include "printf.h"
# include "errors.h"

/*
** for termios and btptr typedef
*/
# include "my_termios.h"
# include "builtins.h"

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
** shell mains structs (to be moved later)
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

typedef struct		s_shell {
  t_termios		term;
  t_blts		blts;
  t_path		*pathlist;
}			t_shell;

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
** string*.c
*/
ssize_t	len(const char *str);
ssize_t	tab_len(char **tab);
int	strn_cmp(const char *s1, const char *s2, size_t n);
char	*my_strcat(char *dest, const char *src);
char	*my_strdup(const char *src);
char	*removespace(char *str);
char	*my_strcatvs(char *dest, const char *src);
char	*my_strcpy(char *dest, const char *src);
char	*my_strncpy(char *dest, const char *src, size_t n);
void	*xmemset(void *s, int c, size_t n);
void	*my_memmove(void *dest, const void *src, size_t n);

/*
** stdlib adapted
*/

int	my_stringisnum(const char *str);
int	my_atoi(const char *str);
int	pprint(const char *str, int fd);
char	**freetab(char **ptr);
char	*clean_free(char *ptr);
char	*epurstr(char *str, int c);

/*
** check.c
*/
int		is_legitchar(char c, const char *reference);
int		is_legitstr(char *str, const char *reference);
unsigned long	get_sum(unsigned char *bfr);

#endif /* !BASE_H_ */
