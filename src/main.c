/*
** main.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Fri Apr 14 21:35:39 2017 Bender_Jr
** Last update Sat Apr 15 14:18:31 2017 Bender_Jr
*/

# include "prompt.h"
# include "base.h"

int		main()
{
  const char	*prompt_frmat = " %U@%H > ";

  pr_printf(prompt_frmat);
  p_printf(1, "\n\t\t[%s]\n", g_prompt);
  return (0);
}
