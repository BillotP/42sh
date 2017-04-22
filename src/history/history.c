/*
** history.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 22 21:25:26 2017 Bender_Jr
** Last update Sat Apr 22 23:06:08 2017 Bender_Jr
*/

/*
** for time funct and struct
** free and open
*/
# include <time.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "base.h"

t_hist		*get_hist(const char *cmd)
{
  time_t	curr_time;
  t_hist	*new;
  static int	order = 0;

  if ((new = malloc(sizeof(*new))) == NULL ||
      (curr_time = time(NULL)) == ((time_t)-1))
    return (NULL);
  order += 1;
  new->cmd = my_strdup(cmd);
  new->timestamp = my_strdup(ctime(&curr_time));
  new->order = order;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

t_history	*init_history()
{
  t_history	*new;

  if ((new = malloc(sizeof(*new))) == NULL ||
      (new->histfilefd = open(HIST_FILE, HF_FLAG, HF_MODE)) == -1)
    return (NULL);
  new->histfirst = NULL;
  new->histlast = NULL;
  return (new);
}

int		write_histfile(t_history *ptr)
{
  if ((write(ptr->histfilefd, ptr->histlast->timestamp,
	     len(ptr->histlast->timestamp) - 1)) == -1 ||
      (write(ptr->histfilefd, ":", 1)) == -1 ||
      (write(ptr->histfilefd, ptr->histlast->cmd,
	     len(ptr->histlast->cmd))) == -1 ||
      (write(ptr->histfilefd, "\n", 1)) == -1)
    return (-1);
  return (0);
}

t_history	*fill_history(t_history *ptr, const char *cmd)
{
  t_hist	*new;

  if ((new = get_hist(cmd)) == NULL)
    return (NULL);
  if (ptr->histfirst == NULL)
    {
      ptr->histfirst = new;
      ptr->histlast = new;
    }
  else
    {
      new->prev = ptr->histlast;
      ptr->histlast->next = new;
      ptr->histlast = new;
    }
  return (write_histfile(ptr) == -1 ? NULL : ptr);
}
