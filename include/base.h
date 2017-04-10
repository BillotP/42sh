/*
** base.h for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:28:48 2017 Bender_Jr
** Last update Mon Apr 10 09:28:50 2017 Bender_Jr
*/

#ifndef BASE_H_
# define BASE_H_

/*
** for ssize_t  typedef
*/

# include <unistd.h>

/*
** strtowortab inclusion
*/

# include "strtowordtab.h"

/*
** string*.c
*/

ssize_t	len(const char *str);
int	tab_size(char **tab);
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

#endif /* !BASE_H_ */
