/*
1;4601;0c** prompt.h for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 08:03:08 2017 Bender_Jr
** Last update Sat Apr 15 11:23:00 2017 Bender_Jr
*/

#ifndef PROMPT_H_
# define PROMPT_H_

/*
** Prompt size define
*/
#ifndef PROMPT_SIZE
# define PROMPT_SIZE (126)
# endif /* !PROMPT_SIZE */

/*
** prompt glob_var
*/
char	g_prompt[PROMPT_SIZE];

/*
** prompt_printf(fction ptr)
*/
typedef int (*flags_fct)(char prompt_bfr[]);
extern flags_fct ptr[];
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
** current working dir minus the /home/toto
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

#endif /* !PROMPT_H_ */
