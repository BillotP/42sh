/*
** check.c for TEST in /home/bender/tek1_2016_test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Wed Apr 12 00:10:52 2017 Bender_Jr
** Last update Sat Apr 15 13:49:54 2017 Bender_Jr
*/

# include "base.h"

int	is_legitchar(char c)
{
  char	test[len(LEGIT_CHAR)];
  int	check;
  int	i;

  i = 0;
  check = 0;
  my_strcpy(test, LEGIT_CHAR);
  while (test[i])
    {
      if (c == test[i])
	check += 1;
      i++;
    }
#ifdef DEBUG
  (check == 0) ? p_printf(1, "%sInvalid char %c%s\n", RED, c, RST) : (check);
#endif
  return ((check == 1) ? (check) : (-1));
}

int		is_legitstr(char *str)
{
  ssize_t	i;
  int		check;

  i = 0;
  check = 0;
  while (str[i])
    {
      if (is_legitchar(str[i]) == 1)
	check += 1;
      i++;
    }
  return ((check == i) ? (check) : (-1));
}
