/*
** errors.h for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:29:08 2017 Bender_Jr
** Last update Mon Apr 10 09:29:19 2017 Bender_Jr
*/

#ifndef ERRORS_H_
# define ERRORS_H_

#ifndef ERR
# define ERR		"\033[1m42sh, error\n\t\033[0m"
# endif /* !ERR */

#ifndef CMD_ERR
# define CMD_ERR	"\033[31mCommand not found\033[0m"
# endif /* !CMD_ERR */

#ifndef NO_DIR
# define NO_DIR		"\033[31mNo such file or directory\033[0m\n"
# endif /* !NO_DIR */

#ifndef CLOSE_ERR
# define CLOSE_ERR	"Failed to close fd\n"
# endif /* !CLOSE_ERR */

/*
** Format output macro
*/

#ifndef BLD
# define BLD		"\033[1m"
# endif /* !BLD */

#ifndef RST
# define RST		"\033[0m"
# endif /* !RST */

#endif /* !ERRORS_H_ */
