/*
** string.c for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:35:33 2017 Bender_Jr
** Last update Mon Apr 10 09:35:35 2017 Bender_Jr
*/

# include <stdlib.h>
# include "base.h"

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char		*my_strdup(const char *src)
{
  char		*buffer;
  ssize_t	size;
  ssize_t	i;

  i = 0;
  size = len(src);
  if ((buffer = malloc(size + 1)) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      buffer[i] = src[i];
      i++;
    }
  buffer[i] = '\0';
  return (buffer);
}

char		*my_strcat(char *dest, const char *src)
{
  int		i;
  ssize_t	j;
  char		*buffer;

  i = 0;
  if ((!(src)) || (!(dest)))
    return (NULL);
  if ((buffer = malloc(sizeof(*buffer) * ((len(dest) + len(src)) + 1))) == NULL)
    return (NULL);
  buffer = my_strcpy(dest, buffer);
  j = len(buffer);
  while (src[i])
    {
      buffer[j + i] = src[i];
      i++;
    }
  buffer[j + i] = '\0';
  clean_free(dest);
  return (buffer);
}

int		strn_cmp(const char *s1, const char *s2, size_t n)
{
  size_t	i;

  i = 0;
  while (i != n && s1[i] == s2[i])
    i++;
  if (i == n)
    return (i);
  return (0);
}

ssize_t		len(const char *str)
{
  ssize_t	i;

  i = 0;
  if ((str))
    {
      while (str[i] != '\0')
	i++;
      return (i);
    }
  return (0);
}
