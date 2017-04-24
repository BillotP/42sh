/*
** fprint.h for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 24 20:53:01 2017 Bender_Jr
** Last update Mon Apr 24 21:07:38 2017 Bender_Jr
*/

#ifndef FPRINT_H_
# define FPRINT_H_
/*
** for varag and FILE *stream def
*/
# include <stdio.h>
# include <stdarg.h>

typedef int	(*fpr)(FILE *stream, va_list list);

/*
** lib/core/fprintf.c
*/
void	init_ptr(fpr *tab);
int	flag_run(char c, fpr *tab, FILE *stream, va_list list);
int	xfprintf(FILE *stream, const char *format, ...);

/*
** lib/core/f_fction.c
*/
int	f_putnbr(long nb, FILE *stream);
int	f_str(FILE *stream, va_list list);
int	f_long(FILE *stream, va_list list);

#endif /* !FPRINT_H_ */
