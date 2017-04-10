/*
** strtowordtab.c for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:35:51 2017 Bender_Jr
** Last update Mon Apr 10 09:35:54 2017 Bender_Jr
*/

# include <stdlib.h>
# include "base.h"
# include "strtowordtab.h"

void	initcount(s_count *list)
{
  list->args = 0;
  list->i = 0;
  list->j = 0;
  list->line = 0;
  list->linesize = 0;
}

int	check_words(char a, const char *delim)
{
  int	i;

  i = 0;
  while (delim[i] != 0)
    {
      if (a == delim[i] || a == '\t')
	return (0);
      i++;
    }
  return (1);
}

int    	init_buffer(char *str, const char *delim, char ***tab)
{
  int	i;
  int	argss;

  i = 0;
  argss = 2;
  while (str[i] != 0)
    {
      if (check_words(str[i], delim) == 0)
	argss = argss + 1;
      i++;
    }
  if ((*tab = malloc(sizeof(char*) * argss)) == NULL)
    return (84);
  return (argss);
}

void	move_str(int *pos, int *linesize, char *str, const char *delim)
{
  *linesize = 0;
  while (str[*pos] != 0 && check_words(str[*pos], delim) != 0)
    {
      ++(*linesize);
      ++(*pos);
    }
  *pos = *pos - *linesize;
}

char		**strto_wordtab(char *str, const char *delim)
{
  char		**wordtab;
  s_count      	count;

  initcount(&count);
  count.args = init_buffer(str, delim, &wordtab);
  count.args = count.args;
  while (*str == ' ')
    str++;
  while (str[count.i] != 0)
    {
      count.j = 0;
      move_str(&count.i, &count.linesize, str, delim);
      if ((wordtab[count.line] = malloc(sizeof(char)
					* (count.linesize + 1))) == NULL)
	return (NULL);
      while (str[count.i] != 0 && check_words(str[count.i], delim) != 0)
	if (str[count.i++] != '\0')
	    wordtab[count.line][count.j++] = str[count.i - 1];
	  wordtab[count.line++][count.j] = 0;
	  if (str[count.i] != 0)
	    count.i++;
	}
  wordtab[count.line] = NULL;
  return (wordtab);
}
