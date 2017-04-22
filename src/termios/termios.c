/*
** termios.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 21:51:27 2017 Bender_Jr
** Last update Sat Apr 22 08:28:48 2017 Bender_Jr
*/

/*
** for strerror
*/
# include <string.h>
# include <errno.h>
# include <stdlib.h>
/*
** for open
*/
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
/*
** for isatty
*/
# include <unistd.h>
# include "prompt.h"
# include "my_termios.h"
# include "base.h"
# include "get_next_line.h"

int		set_cap(struct termios *new, int tty_fd)
{
  new->c_iflag &= ~(IGNBRK | BRKINT);
  new->c_lflag = (ICANON | IEXTEN | ISIG | ECHOE | ECHO);
  new->c_cc[VINTR] = 3;
  new->c_cc[VERASE] = 127;
  new->c_cc[VQUIT] = 0x21;
  new->c_cc[VSUSP] = 0x1A;
  new->c_cc[VWERASE] = 0x17;
  new->c_cc[VEOF] = 0x04;
  if ((cfsetispeed(new, B38400) == -1) ||
      (tcflush(tty_fd, TCIFLUSH) == -1) ||
      (tcsetattr(tty_fd, TCSANOW, new)) == -1)
    return (p_printf(2, "%s%s", ERR, strerror(errno)), -1);
  return (0);
}

int	reset_cap(struct termios *save, int tty_fd)
{
  if (isatty(tty_fd))
    {
      if ((tcsetattr(tty_fd, TCSANOW, save)) == -1)
	return (p_printf(2, "%s%s", ERR, strerror(errno)) -1);
      p_printf(1, "exit\n");
      return (0);
    }
  return (0);
}

int	init_term(t_termios *list)
{
  if (isatty(STDIN_FILENO))
    {
      if ((list->tty_fd = open(ttyname(STDIN_FILENO), O_RDWR)) == -1 ||
	  (tcgetattr(list->tty_fd, &(list)->save)) == -1 ||
	  (tcgetattr(list->tty_fd, &(list)->new)) == -1 ||
	  (set_cap(&(list)->new, list->tty_fd)) == -1)
	return (p_printf(2, "%s%s", ERR, strerror(errno)) -1);
      else if ((pr_printf(list->prompt_frmat)) == -1)
	return (-1);
      else
	return (0);
    }
  else
    list->tty_fd = STDIN_FILENO;
  return (0);
}
