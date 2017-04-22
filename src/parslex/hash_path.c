/*
** hash_path.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 22 13:45:32 2017 Bender_Jr
** Last update Sat Apr 22 18:01:33 2017 Bender_Jr
*/

/*
** for getenv and scandir
*/
# include <stdlib.h>
# include <dirent.h>
# include "base.h"

typedef struct	s_vars {
  struct s_vars	*prev;
  struct s_vars	*next;
  char		*bin_name;
  char		bin_path[PATH_MAX];
  unsigned long	chksum;
}		t_vars;

typedef struct	s_path {
  char		*path_var;
  t_vars	*firstvar;
  t_vars	*lastvar;
}		t_path;


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

void		print_list(const t_path *ptr)
{
  t_vars	*tmp;

  tmp = ptr->firstvar;
  while (tmp)
    {
      p_printf(1, "%s\n", tmp->bin_name);
      tmp = tmp->next;
    }
}

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

int		main(int ac, char **av)
{
  t_path	*path;

  if ((path = init_paths("/bin")) == NULL ||
      (path = fill_path(path)) == NULL)
    return (1);
  if (ac == 1)
    print_list(path);
  else if (ac == 2)
    p_printf(1, "==> where is [%s] ?\n\there => [%s]\n", av[1],
	     is_proginlist(path, get_sum((unsigned char *)av[1])));
  free_list(path);
  return (0);
}
