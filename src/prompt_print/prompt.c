/*
** prompt.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 07:51:17 2017 Bender_Jr
** Last update Sat Apr 15 14:06:42 2017 Bender_Jr
*/

/*
** for strerror and errno
*/
# include <string.h>
# include <errno.h>
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

int	set_time(char prompt_bfr[])
{
  prompt_bfr = prompt_bfr;
  return (0);
}

int	set_cwd(char prompt_bfr[])
{
  prompt_bfr = prompt_bfr;
  return (0);
}

int	set_usertype(char prompt_bfr[])
{
  prompt_bfr = prompt_bfr;
  return (0);
}
