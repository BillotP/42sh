/*
** putnbr.c for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:34:57 2017 Bender_Jr
** Last update Mon Apr 10 09:34:59 2017 Bender_Jr
*/

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "base.h"

int	p_putnbr(long nb, int fd)
{
  if (nb >= LONG_MAX || nb <= LONG_MIN)
    return (84);
  if (nb < 0)
    {
      pprint("-", fd);
      p_putnbr(nb * - 1, fd);
    }
  if (nb >= 0 && nb <= 9)
    {
      nb = nb + '0';
      pprint((const char*)&nb, fd);
    }
  else if (nb > 9)
    {
      p_putnbr(nb / 10, fd);
      nb = (nb % 10) + '0';
      pprint((const char*)&nb, fd);
    }
  return (0);
}
