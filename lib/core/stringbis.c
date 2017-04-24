/*
** stringbis.c for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:35:17 2017 Bender_Jr
** Last update Sun Apr 23 19:17:40 2017 Bender_Jr
*/

# include "base.h"
# include "printf.h"

ssize_t		tab_len(char  **bfr)
{
  ssize_t	i;

  i = 0;
  if (bfr[i])
    {
      while (bfr[i])
	i++;
    }
  return (i);
}

#ifdef STD_C_99
void		*my_memmove(void *dest, const void *src, size_t n)
{
  char		*char_src;
  char		*char_dest;
  char		tmp[n + 1];
  size_t	i;

  i = 0;
  char_src = (char *)src;
  char_dest = (char *)dest;
  xmemset(tmp, '\0', sizeof(tmp));
  while (i != n)
    {
      tmp[i] = char_src[i];
      i++;
    }
  i = 0;
  while (i != n)
    {
      char_dest[i] = tmp[i];
      i++;
    }
  return (char_dest);
}
#endif

char		*my_strncpy(char *dest, const char *src, size_t n)
{
  size_t	i;

  i = 0;
  while (i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  while (i < n)
    {
      dest[i] = '\0';
      i++;
    }
  return (dest);
}

void		*xmemset(void *s, int c, size_t n)
{
  size_t	i;

  i = 0;
  while (i != n)
    {
      ((unsigned char *)s)[i] = c;
      i++;
    }
  return (s);
}

char		*removespace(char *str)
{
  ssize_t	i;
  ssize_t	j;
  char		*new;

  new = str;
  i = 0;
  j = 0;
  if (str)
    {
      while (i != len(str))
	{
	  if (str[i] != ' ' && str[i] != '\t')
	    new[i] = str[i];
	  else
	    j -= 1;
	  i++;
	  j++;
	}
    }
  return (new);
}
