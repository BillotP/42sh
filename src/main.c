/*
** main.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Fri Apr 14 21:35:39 2017 Bender_Jr
** Last update Sat Apr 15 17:43:31 2017 Bender_Jr
*/

# include <stdlib.h>
# include "prompt.h"
# include "base.h"
# include "get_next_line.h"

int		main()
{
  char		*tmp;
  const char	*prompt_frmat = "%C %T \033[94m%U\033[0m@%H \033[1m%~\033[0m >> ";

  if ((pr_printf(prompt_frmat)) == -1)
    return (84);
  while ((tmp = get_next_line(0)))
    {
      pr_printf(prompt_frmat);
      free(tmp);
    }
  p_printf(1, "exit\n");
  return (0);
}
