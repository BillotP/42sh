/*
** hash_path.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 22 13:45:32 2017 Bender_Jr
** Last update Sun Apr 23 19:14:22 2017 Bender_Jr
*/

/*
** for scandir
*/
# define _DEFAULT_SOURCE

/*
** for scandir
*/
# include <stdlib.h>
# include <dirent.h>
# include "base.h"

t_vars		*fill_vars(const char *bin_name, const char *dir_name)
{
  t_vars	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  xmemset(new, '\0', sizeof(*new));
  new->bin_name = my_strdup(bin_name);
  my_strcpy(new->bin_path, dir_name);
  my_strcatvs(new->bin_path, "/");
  my_strcatvs(new->bin_path, bin_name);
  new->chksum = get_sum((unsigned char *)new->bin_name);
  new->prev = NULL;
  new->next = NULL;
  return (new);
}

t_path		*get_vars(t_path *path, const char *bin_path, const char *dir_name)
{
  t_vars	*new;

  new = NULL;
  if ((new = fill_vars(bin_path, dir_name)) == NULL)
    return (NULL);
  if (path->firstvar == NULL)
    {
      path->firstvar = new;
      path->lastvar = new;
    }
  else
    {
      new->prev = path->lastvar;
      path->lastvar->next = new;
      path->lastvar = new;
    }
  return (path);
}

int		exec_filter(const struct dirent *entry)
{
  if ((strn_cmp(entry->d_name, ".", 1)) ||
      (strn_cmp(entry->d_name, "..", 2)))
    return (0);
  return (1);
}

t_path		*fill_path(t_path *path)
{
  int		i;
  int		rt;
  struct dirent	**namelist;
  char		**pathslist;

  i = 0;
  pathslist = strto_wordtab(path->path_var, ":");
  while (i != tab_len(pathslist))
    {
      if ((rt = scandir(pathslist[i], &namelist, &exec_filter, NULL)) == -1)
	return (NULL);
      else
	while (rt --)
	  {
	    if ((path = get_vars(path, namelist[rt]->d_name,
				 pathslist[i])) == NULL)
	      return (NULL);
	    free(namelist[rt]);
	  }
      free(namelist);
      i++;
    }
  return (freetab(pathslist), path);
}
