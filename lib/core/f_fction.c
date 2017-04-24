/*
** f_fction.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 24 20:58:22 2017 Bender_Jr
** Last update Mon Apr 24 21:10:29 2017 Bender_Jr
*/

# include "base.h"

int		f_putnbr(long nb, FILE *stream)
{
  if (nb < 0)
    {
      fwrite("-", 1, 1, stream);
      f_putnbr(nb * - 1, stream);
    }
  if (nb >= 0 && nb <= 9)
    {
      nb = nb + '0';
      return (fwrite((const char*)&nb, 1, 1, stream) != 1 ?
	      -1 : 0);
    }
  else if (nb > 9)
    {
      f_putnbr(nb / 10, stream);
      nb = (nb % 10) + '0';
      if (fwrite((const char*)&nb, 1, 1, stream) != 1)
	return (-1);
    }
  return (0);
}

int		f_str(FILE *stream, va_list list)
{
  const char	*s;

  s = va_arg(list, const char *);
  if ((fwrite(s, len(s), 1, stream)) != 1)
    return (fwrite("(nill)", len("(nill)"), 1, stream), -1);
  return (0);
}

int	f_long(FILE *stream, va_list list)
{
  long nb;

  nb = va_arg(list, long );
  if ((f_putnbr(nb, stream)) == -1)
    return (-1);
  return (0);
}
