/*
** errors.h for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 22 11:15:53 2017 Bender_Jr
** Last update Sat Apr 22 11:17:14 2017 Bender_Jr
*/

#ifndef ERRORS_H_
# define ERRORS_H_

#ifndef BLD
# define BLD "\033[1m"
# endif /* !BLD */

#ifndef RST
# define RST "\033[0m"
# endif /* !RST */

#ifndef RED
# define RED "\033[31m"
# endif /* !RED */

#ifndef ERR
# define ERR		"\033[1m42Sh, error : \033[0m\n\t\t"
# endif /* !ERR */

#ifndef NAME_ERR
# define NAME_ERR	"\033[31mNo such file or directory\033[0m"
# endif /* !NAME_ERR */

#ifndef CMT_ERR
#define CMT_ERR		"\033[31mInvalid comment\033[0m"
# endif /* !CMT_ERR */

#ifndef SYNTX_ERR
#define SYNTX_ERR	"Expression Syntax.\n"
# endif /* !SYNTX_ERR */

#endif /* !ERRORS_H_ */
