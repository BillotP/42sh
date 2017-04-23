/*
** envlist.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sun Apr 23 09:40:19 2017 Bender_Jr
** Last update Sun Apr 23 10:48:49 2017 Bender_Jr
*/

/*
** for malloc
*/
# include <stdlib.h>
# include "base.h"

t_envar			*get_envar(char *fullenvar)
{
  t_envar		*new;
  char			**tmp;

  if ((new = malloc(sizeof(*new))) == NULL ||
      (tmp = strto_wordtab(fullenvar, "=")) == NULL)
    return (NULL);
  xmemset(new, '\0', sizeof(*new));
  new->variable = my_strdup(tmp[0]);
  my_strcpy(new->value, tmp[1]);
  new->hash = get_sum((unsigned char *)new->variable);
  new->next = NULL;
  new->prev = NULL;
  return (freetab(tmp), new);
}

t_environ		*init_environ(char **environ)
{
  int			i;
  t_environ		*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  i = 0;
  xmemset(new, '\0', sizeof(*new));
  if (tab_len(environ))
    new->environ = environ;
  else
    new->environ = NULL;
  new->firstenvar = NULL;
  new->lastenvar = NULL;
  while (i != tab_len(environ))
    {
      new = fill_env(new, environ[i]);
      i++;
    }
  return (new);
}

t_environ		*fill_env(t_environ *ptr, char *newenvar)
{
  t_envar		*new;

  if ((new = get_envar(newenvar)) == NULL)
    return (NULL);
  if (ptr->firstenvar == NULL)
    {
      ptr->firstenvar = new;
      ptr->lastenvar = new;
    }
  else
    {
      new->prev = ptr->lastenvar;
      ptr->lastenvar->next = new;
      ptr->lastenvar = new;
    }
  return (ptr);
}
