/*
** base.c for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:33:09 2017 Bender_Jr
** Last update Mon Apr 10 09:33:11 2017 Bender_Jr
*/

# include <unistd.h>
# include <stdlib.h>
# include "base.h"

int   		pprint(const char *str, int fd)
{
  ssize_t	wr;

  wr = 0;
  if ((wr = write(fd, str, len(str))) == -1)
    return (84);
  return (0);
}

char		**freetab(char **ptr)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (ptr[i])
    i++;
  while (j < i)
    {
      free(ptr[j]);
      ptr[j] = NULL;
      j++;
    }
  free(ptr);
  return (NULL);
}

char	*clean_free(char *ptr)
{
  if (ptr)
    {
      free(ptr);
      ptr = NULL;
    }
  return (NULL);
}

int	my_atoi(const char *str)
{
  int	nb;

  nb = 0;
  while (*str)
    {
      if (*str >= '0' && *str <= '9')
	{
	  nb *= 10;
	  nb += *str - 48;
	}
      else
	return (nb);
      str++;
    }
  return (nb);
}
