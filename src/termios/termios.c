/*
** termios.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 21:51:27 2017 Bender_Jr
** Last update Sun Apr 16 11:20:10 2017 Bender_Jr
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

  if ((pipe = popen(buff, "r")) == NULL)
    return (p_printf(2, "%s%s", ERR, strerror(errno)) -1);
  while ((fgets(ptr, 4096, pipe)) != NULL)
    p_printf(0, "%s", ptr);
  p_printf(0, "\n");
  pclose(pipe);
  return (0);
}

int		set_cap(struct termios *new, int tty_fd)
{
  new->c_iflag &= ~IGNBRK;
  new->c_iflag |= BRKINT;
  new->c_lflag |= (ICANON | ECHOE | IEXTEN | ISIG);
  new->c_cc[VINTR] = 0x03;
  new->c_cc[VERASE] = 0x7F;
  new->c_cc[VQUIT] = 0x5C;
  new->c_cc[VEOF] = 0x04;
  if ((cfsetispeed(new, B38400) == -1) ||
      (tcflush(tty_fd, TCIFLUSH) == -1) ||
      (tcsetattr(tty_fd, TCSANOW, new)) == -1)
    return (p_printf(2, "%s%s", ERR, strerror(errno)) -1);
  return (0);
}

int	reset_cap(struct termios *save, int tty_fd)
{
  p_printf(1, "mode off \n");
  if ((tcsetattr(tty_fd, TCSANOW, save)) == -1)
    return (p_printf(2, "%s%s", ERR, strerror(errno)) -1);
  return (0);
}

int	init_term(int tty_fd, struct termios *new, struct termios *save)
{
  if (isatty(tty_fd))
    {
      p_printf(1, "mode on \n");
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


  if ((fd = open(ttyname(0), O_RDWR)) == -1 ||
      (init_term(fd, &new, &save)) == -1)
    return (84);
  p_printf(0, "toto >> ");
  while ((rd = read(fd, bfr, 4095)))
    {
      bfr[rd] = 0;
      if (rd > 1)
	if ((exec(bfr)) == -1)
	  return (reset_cap(&save, fd), 1);
      p_printf(0, "toto >> ");
    }
  reset_cap(&save, fd);
  return (0);
}
