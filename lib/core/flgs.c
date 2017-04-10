/*
** flgs.c for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:33:52 2017 Bender_Jr
** Last update Mon Apr 10 09:33:54 2017 Bender_Jr
*/

# include "base.h"
# include "printf.h"

int	flg_d(va_list list, int fd)
{
  int	nb;

  nb = va_arg(list, int);
  p_putnbr(nb, fd);
  return (nb);
}

int	flg_i(va_list list, int fd)
{
  int	nb;

  nb = va_arg(list, int);
  p_putnbr(nb, fd);
  return (0);
}

int	flg_c(va_list list, int fd)
{
  int	a;

  a = va_arg(list, int);
  if (write(fd, &a, 1) == -1)
    return (-1);
  return (0);
}

int		flg_s(va_list list, int fd)
{
  const	char	*s;

  s = va_arg(list, char *);
  if (s == NULL)
    pprint("(null)", fd);
  pprint(s, fd);
  return (0);
}
