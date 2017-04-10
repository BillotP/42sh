/*
** base2.c for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:32:53 2017 Bender_Jr
** Last update Mon Apr 10 09:32:56 2017 Bender_Jr
*/

# include <stdlib.h>

# include "base.h"

char		*epurstr(char *str, int c)
{
  ssize_t	i;
  ssize_t	j;
  char		*clean;

  i = 0;
  j = 0;
  if ((clean = malloc(len(str) + 1)) == NULL ||
      !str || len(str) < 1)
    return (free(clean), str);
  while (str && (str[i] == ' ' || str[i] == '\t'))
    str++;
  while (str && str[i] != '\0')
    {
      while (!(str[i] > 32 && str[i] < 127)
	     && str[i] != '\0')
	i++;
      while (str[i] > 32 && str[i] < 127)
	clean[j++] = str[i++];
      clean[j++] = c;
    }
  free(str);
  return (clean[j - 1] = '\0', clean);
}

int	my_stringisnum(const char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if ((str[i] >= '0') && (str[i] <= '9'))
	j = j + 1;
      i++;
    }
  if (j == i)
    return (j);
  else
    return (0);
}

int	tab_size(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

char	*my_strcatvs(char *dest, const char *src)
{
  int	i;
  int	j;

  i = 0;
  j = len(dest);
  while (src[i])
    {
      dest[j + i] = src[i];
      i++;
    }
  dest[j + i] = '\0';
  return (dest);
}
