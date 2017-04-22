/*
** my_termios.h for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Tue Apr 18 09:56:53 2017 Bender_Jr
** Last update Sat Apr 22 08:36:58 2017 Bender_Jr
*/

#ifndef MY_TERMIOS_H_
# define MY_TERMIOS_H_
/*
** for struct termios typedef
*/
# include <termios.h>

/*
** note : the prompt format
** will be move in the conf file
** later on
*/
typedef struct		s_termios {
  struct termios	new;
  struct termios	save;
  const char		*prompt_frmat;
  int			tty_fd;
}			t_termios;

/*
** src/termios/termios.c
*/
int	set_cap(struct termios *new, int tty_fd);
int	reset_cap(struct termios *save, int tty_fd);
int	init_term(t_termios *list);

#endif /* !MY_TERMIOS_H_ */
