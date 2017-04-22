/*
** builtins.h for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Tue Apr 18 17:34:43 2017 Bender_Jr
** Last update Thu Apr 20 14:31:36 2017 Bender_Jr
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

/*
** Builtins Macro and Typedef
*/
/*
** Set-unset-env
** (will follow)
*/
/*
** develloped then named
*/
#ifndef BLTS_NAMES
# define BLTS_NAMES "cd,echo,clear"
# endif /* !BLTS_NAMES */

typedef int	(*builtins)(char **bfr);
typedef struct	s_blts {
  char		**blts_names;
  builtins	btptr[6];
}		t_blts;

int	cd(char **cmd);
int	echo(char **cmd);

void	fill_builtins(t_blts *list);
int	is_builtins(char **cmd, t_blts *ptr);
#endif /* !BUILTINS_H_ */
