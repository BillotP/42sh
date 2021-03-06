/*
1;4601;0c** prompt.h for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 08:03:08 2017 Bender_Jr
** Last update Sun Apr 23 11:15:00 2017 Bender_Jr
*/

#ifndef PROMPT_H_
# define PROMPT_H_

/*
** typdefs :
*/
# include "decl.h"

/*
** size_t typedef
*/
typedef unsigned long size_t;

/*
** max path len (to be moved
** in limits.h
*/
#ifndef PATH_SIZE
# define PATH_SIZE (4096)
# endif /* !PATH_SIZE */

/*
** prompt_printf flags list
*/
#ifndef PRPT_FLAGS
# define PRPT_FLAGS "HUT~C"
# endif /* !PRPT_FLAGS */

/*
** Flag '%H'
*/
int	set_hostname(char prompt_bfr[]);

/*
** Flag '%U'
*/
int	set_username(char prompt_bfr[]);

/*
** Flag '%T'
*/
int	set_time(char prompt_bfr[]);

/*
** Flag '%~'
** Note : this flag print the
** current working dir minus the /home/$user
** path (replaced by '~' char)
*/
int	set_cwd(char prompt_bfr[]);

/*
** Flag '%C' for setting special
** color when root shell
*/
int	set_usertype(char prompt_bfr[]);

/*
** src/prompt_print/
*/
void	fill_ptr(flags_fct ptr[]);
int	fill_promptbfr(const char flag);
int	pr_printf(const char *format);

/*
** Gnu fonction prototyping
*/
char	*secure_getenv(const char *name);
char	*getcwd(char *buf, size_t size);

#endif /* !PROMPT_H_ */
