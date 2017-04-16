/*
** prompt.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 07:51:17 2017 Bender_Jr
** Last update Sat Apr 15 17:42:43 2017 Bender_Jr
*/

/*
** for strerror, errno
** free, and time funct.
*/
# include <string.h>
# include <errno.h>
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

int		set_hostname(char prompt_bfr[])
{
  char		*hostname;
  extern char	**environ;

  if (tab_len(environ))
    {
      if ((hostname = secure_getenv("HOSTNAME")) == NULL)
	{
#ifdef DEBUG
	  p_printf(2, "%sError prompt:%s\n\t%s%s%s\n",
		   BLD, RST, RED, "$HOSTNAME not set", RST);
#endif
	  return (1);
	}
      else if (len(hostname) < PROMPT_SIZE && is_legitstr(hostname))
	return (my_strcatvs(prompt_bfr, hostname), 1);
    }
  return (1);
}

int	set_username(char prompt_bfr[])
{
  char		*username;
  extern char	**environ;

  if (tab_len(environ))
    {
      username = secure_getenv("USER");
      if (username == NULL)
	{
#ifdef DEBUG
	  p_printf(2, "%sError prompt:%s\n\t%s%s%s\n",
		   BLD, RST, RED, "$USER not set", RST);
#endif
	  return (1);
	}
      else if (len(username) < PROMPT_SIZE && is_legitstr(username))
	return (my_strcatvs(prompt_bfr, username), 1);
    }
  return (1);
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
