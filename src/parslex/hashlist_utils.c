/*
** hashlist_utils.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 22 19:40:47 2017 Bender_Jr
** Last update Sat Apr 22 19:43:30 2017 Bender_Jr
*/

# include <stdlib.h>
# include "base.h"

void		free_list(t_path *ptr)
{
  while (ptr->firstvar)
    {
      free(ptr->firstvar->bin_name);
      free(ptr->firstvar->prev);
      ptr->firstvar = ptr->firstvar->next;
    }
  free(ptr->path_var);
  free(ptr->lastvar);
  free(ptr);
}

t_path		*init_paths(const char *pathvar)
{
  t_path	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->path_var = my_strdup(pathvar);
  new->firstvar = NULL;
  new->lastvar = NULL;
  return (new);
}

char		*is_proginlist(const t_path *path, unsigned long checksum)
{
  t_vars	*tmp;
  char		*ptr;

  tmp = path->firstvar;
  ptr= NULL;
  while (tmp)
    {
      if (checksum == tmp->chksum)
	return (ptr = tmp->bin_path);
      tmp = tmp->next;
    }
  return (NULL);
}
