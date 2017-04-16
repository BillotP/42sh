/*
** termios.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 21:51:27 2017 Bender_Jr
** Last update Mon Apr 17 00:09:25 2017 Bender_Jr
*/

# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <termios.h>
# include <unistd.h>
# include "base.h"
# include "get_next_line.h"

int		 exec(char *buff)
{
  FILE		*pipe;
  char		ptr[4096];
  char		*tmp;

  if ((pipe = popen(buff, "r")) == NULL)
    return (p_printf(2, "%s%s", ERR, strerror(errno)) -1);
  while ((tmp = fgets(ptr, 4095, pipe)))
    p_printf(0, "%s", tmp);
  pclose(pipe);
  return (0);
}

int		set_cap(struct termios *new, int tty_fd)
{
  new->c_iflag &= ~(IGNBRK | BRKINT);
  new->c_lflag |= (ICANON | ECHOE | IEXTEN | ISIG);
  new->c_cc[VINTR] = 0x03;
  new->c_cc[VERASE] = 0x7F;
  new->c_cc[VQUIT] = 0x21;
  new->c_cc[VSUSP] = 0x1A;
  new->c_cc[VWERASE] = 0x17;
  new->c_cc[VEOF] = 0x04;
  if ((cfsetispeed(new, B38400) == -1) ||
      (tcflush(tty_fd, TCIFLUSH) == -1) ||
      (tcsetattr(tty_fd, TCSANOW, new)) == -1)
    return (p_printf(2, "%s%s", ERR, strerror(errno)) -1);
  return (0);
}

int	reset_cap(struct termios *save, int tty_fd)
{
  p_printf(1, "exit\n");
  if ((tcsetattr(tty_fd, TCSANOW, save)) == -1)
    return (p_printf(2, "%s%s", ERR, strerror(errno)) -1);
  return (0);
}

int	init_term(int tty_fd, struct termios *new, struct termios *save)
{
  if (isatty(tty_fd))
    {
      if ((tcgetattr(tty_fd, save)) == -1 ||
	  (tcgetattr(tty_fd, new)) == -1)
	return (p_printf(2, "%s%s", ERR, strerror(errno)) -1);
      else if ((set_cap(new, tty_fd)) == -1)
	return (-1);
      else
	return (0);
    }
  return (-1);
}

int			main()
{
  char			bfr[4096];
  static struct termios new;
  static struct termios save;
  ssize_t		rd;
  int			fd;


if ((fd = open(ttyname(STDIN_FILENO), O_RDWR)) == -1 ||
      (init_term(fd, &new, &save)) == -1)
    return (p_printf(2, "%s%s", ERR, "stty: 'standard input':\
Inappropriate ioctl for device\n"), 1);
  p_printf(0, "toto >> ");
  while ((rd = read(fd, bfr, 4095)))
    {
      bfr[rd] = 0;
      if (bfr[0] == '\f')
	exec("clear");
      if (rd > 1)
	{
	  if ((exec(bfr)) == -1)
	    return (reset_cap(&save, fd), 1);
	}
      p_printf(0, "toto >> ");
    }
  reset_cap(&save, fd);
  return (0);
}
