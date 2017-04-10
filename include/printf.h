/*
** printf.h for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:32:02 2017 Bender_Jr
** Last update Mon Apr 10 09:32:06 2017 Bender_Jr
*/

#ifndef PRINTF_H_
# define PRINTF_H_

# include <stdarg.h>
# include "base.h"

#ifndef FLAG
# define FLAG  "dcsi"
# endif /* !FLAG */

int	flag_match(const char c);
int	flg_d(va_list list, int fd);
int	flg_i(va_list list, int fd);
int	flg_c(va_list list, int fd);
int	flg_s(va_list list, int fd);

int	p_printf(int fd, const char *format, ...);
int	p_putnbr(long nb, int fd);
void	flag_funct(int (*ptr[4])(va_list list, int fd));

#endif /* !PRINTF_H_ */
