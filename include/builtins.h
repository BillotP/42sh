/*
** builtins.h for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Tue Apr 18 17:34:43 2017 Bender_Jr
** Last update Sun Apr 23 11:46:41 2017 Bender_Jr
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

# include "decl.h"

int	cd(char **cmd, void  *ptr);
int	echo(char **cmd, void *ptr);
int	x_exit(char **cmd, void *ptr);
int	clear(char **cmd, void *ptr);

void	fill_builtins(t_blts *list);
int	is_builtins(char **cmd, t_shell *addr, t_blts *ptr);

#endif /* !BUILTINS_H_ */
