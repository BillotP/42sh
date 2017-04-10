/*
** strtowordtab.h for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:32:26 2017 Bender_Jr
** Last update Mon Apr 10 09:32:29 2017 Bender_Jr
*/

#ifndef STRTOWORDTAB_H_
# define STRTOWORDTAB_H_

typedef struct 	t_count {
  int		linesize;
  int		args;
  int		line;
  int		i;
  int		j;
}		s_count;

/*
** The mother function here :
** strtowordtab !
*/
int	init_buffer(char *str, const char *delim, char ***tab);
int	check_words(char c, const char *delim);
void	move_str(int *i, int *linesize, char *str, const char *delim);
char	**strto_wordtab(char *str, const char *delim);

#endif /* !STRTOWORDTAB_H_ */
