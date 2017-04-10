/*
** printf.c for PSU_2016_minishell2 in /home/bender/Repo/PSU_2016_minishell2/lib
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Wed Apr  5 19:58:10 2017 Bender_Jr
** Last update Thu Apr  6 10:27:56 2017 Bender_Jr
*/

# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

# include "printf.h"

int		p_printf(int fd, const char *format, ...)
{
  va_list	list;
  int		i;
  int		run;
  int		(*ptr[4])(va_list list, int fd);

  i = 0;
  run = 0;
  va_start(list, format);
  flag_funct(ptr);
  if (!(format))
    return (-1);
  while ((format[i]))
    {
      if (format[i] == '%' && (flag_match(format[i + 1]) != -1))
	{
	  run = flag_match(ptr[flag_match(format[i + 1])](list, fd));
	  i++;
	}
      else if (write(fd, &format[i], 1) == -1)
	return (-1);
      i++;
    }
  va_end(list);
  return (run);
}
