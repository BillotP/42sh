/*
** prompt.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 07:51:17 2017 Bender_Jr
** Last update Thu Apr 20 10:50:54 2017 Bender_Jr
*/

/*
** for strerror, errno
** free, passwd def and time funct.
*/
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include "base.h"
# include "prompt.h"
/*
** this include is for
** the checkstring function
** but soon will be move
** to lib funct
*/
# include "dict.h"

int			set_username(char prompt_bfr[])
{
  struct passwd		*tmp;
  gid_t			uid;

  uid = getuid();
  tmp = getpwuid(uid);
  my_strcatvs(prompt_bfr, tmp->pw_name);
  return (1);
}

# define HOSTNAME "/etc/hostname"

int		set_hostname(char prompt_bfr[])
{
  char		tmp[MAX_NAME_LENGHT];
  int		host_fd;

  xmemset(tmp, '\0', MAX_NAME_LENGHT);
  if ((host_fd = open(HOSTNAME, O_RDONLY)) == -1 ||
      (read(host_fd, tmp, MAX_NAME_LENGHT)) == -1)
    return (p_printf(2, "%s%s\n", ERR, strerror(errno)), -1);
  else
    {
      my_strcatvs(prompt_bfr, tmp);
      return (close(host_fd), 1);
    }
  return  (1);
}

int		set_time(char prompt_bfr[])
{
  time_t	curr_time;
  char		tmp[PATH_SIZE];

  if ((curr_time = time(NULL)) == ((time_t)-1))
    return (-1);
  xmemset(tmp, '\0', PATH_SIZE);
  my_strncpy(tmp, ctime(&curr_time), 16);
  my_strcatvs(prompt_bfr, tmp);
  return (1);
}

int	set_cwd(char prompt_bfr[])
{
  int	pos;
  char	*bfr;
  char	*tmp;

  bfr = NULL;
  pos = 0;
  if ((bfr = getcwd(bfr, 0)) == NULL)
    return (0);
  tmp = bfr;
  if (strn_cmp(bfr, "/home/", len("/home/")))
    {
      pos += len("/home") + 1;
      while (bfr[pos] && bfr[pos] != '/')
	pos++;
      bfr[pos - 1] = '~';
      bfr[pos] = '/';
      bfr += pos - 1;
    }
  my_strcatvs(prompt_bfr, bfr);
  free(tmp);
  return (1);
}

int		set_usertype(char prompt_bfr[])
{
  uid_t		userid;

  userid = getuid();
  if (userid == 0)
    my_strcatvs(prompt_bfr, "\033[31m");
  return (1);
}
