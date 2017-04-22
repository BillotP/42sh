/*
** check.c for TEST in /home/bender/tek1_2016_test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Wed Apr 12 00:10:52 2017 Bender_Jr
** Last update Sat Apr 22 17:32:40 2017 Bender_Jr
*/

# include "base.h"

int	is_legitchar(char c, const char *reference)
{
  int	check;
  int	i;

  i = 0;
  check = 0;
  while (reference[i] != '\0')
    {
      if (c == reference[i])
	check += 1;
      i++;
    }
#ifdef DEBUG
  (check == 0) ? p_printf(1, "%sInvalid char %c%s\n", RED, c, RST) : (check);
#endif
  return ((check == 1) ? (check) : (-1));
}

int		is_legitstr(char *str, const char *reference)
{
  ssize_t	i;
  int		check;

  i = 0;
  check = 0;
  while (str[i])
    {
      if (is_legitchar(str[i], reference) == 1)
	check += 1;
      i++;
    }
  return ((check == i) ? (check) : (-1));
}

unsigned long	get_sum(unsigned char *bfr)
{
  unsigned long	sum;
  unsigned char *ptr;
  int		c;

  sum = 0;
  ptr = bfr;
  while ((c = *ptr++))
    sum =  c + (sum << 6) + (sum << 16) + sum;
  return (sum);
}
