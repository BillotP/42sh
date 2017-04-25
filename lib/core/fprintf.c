/*
** fprintf.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 24 20:49:21 2017 Bender_Jr
** Last update Tue Apr 25 12:52:13 2017 Bender_Jr
*/

# include "base.h"

void		init_ptr(fpr *tab)
{
  tab[0] = f_str;
  tab[1] = f_long;
}

int		flag_run(char c, fpr *tab, FILE *stream, va_list list)
{
  char		flag[2];
  int		i;

  flag[0] = 's';
  flag[1] = 'd';
  i = 0;
  while (i != 2)
    {
      if (c == flag[i])
	return (tab[i](stream, list));
      i++;
    }
  return (0);
}

int		xfprintf(FILE *stream, const char *format, ...)
{
  va_list	list;
  fpr		ptr[2];
  int		i;

  init_ptr(ptr);
  i = 0;
  va_start(list, format);
  while (format[i])
    {
      if (format[i] == '%')
	{
	  flag_run(format[i + 1], ptr, stream, list);
	  i += 1;
	}
      else
	fwrite(&format[i], 1, 1, stream);
      i++;
    }
  va_end(list);
  return (0);
}
