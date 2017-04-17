/*
** errors.h for CPE_2016_corewar in /home/bender/Repo/CPE/CPE_2016_corewar/asm
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Mar 20 19:08:06 2017 Bender_Jr
** Last update Mon Apr 17 15:09:01 2017 Bender_Jr
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
# define ERR		"\033[1mTekSh, error : \033[0m\n\t\t"
# endif /* !ERR */

#ifndef NAME_ERR
# define NAME_ERR	"\033[31mNo such file or directory\033[0m"
#endif /* NAME_ERR */

#ifndef CMT_ERR
#define CMT_ERR		"\033[31mInvalid comment\033[0m"
#endif /* CMT_ERR */

#endif /* ERRORS_H_ */
