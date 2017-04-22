/*
** hist_utils.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 22 22:35:08 2017 Bender_Jr
** Last update Sat Apr 22 22:35:59 2017 Bender_Jr
*/

/*
** for free
*/
# include <stdlib.h>
# include "base.h"

void		print_history(t_history *ptr)
{
  t_hist	*tmp;

  tmp = ptr->histfirst;
  while (tmp)
    {
      p_printf(1, "[%s] order : %d\ntime : %s\n", tmp->cmd, tmp->order,
	       tmp->timestamp);
      tmp = tmp->next;
    }
}

void		free_history(t_history *ptr)
{
  while (ptr->histfirst)
    {
      free(ptr->histfirst->cmd);
      free(ptr->histfirst->timestamp);
      free(ptr->histfirst->prev);
      ptr->histfirst = ptr->histfirst->next;
    }
  free(ptr->histlast);
  free(ptr);
}
