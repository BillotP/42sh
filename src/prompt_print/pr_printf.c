/*
** pr_printf.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 08:00:54 2017 Bender_Jr
** Last update Sat Apr 15 14:18:56 2017 Bender_Jr
*/

# include "prompt.h"
# include "base.h"

void		fill_ptr(flags_fct *ptr)
{
  ptr[0] = set_hostname;
  ptr[1] = set_username;
  ptr[2] = set_time;
  ptr[3] = set_cwd;
  ptr[4] = set_usertype;
}

int		fill_promptbfr(const char flg)
{
  int		i;
  int		k;
  flags_fct	ptr[5];
  char		flags[sizeof(PRPT_FLAGS) + 1];

  fill_ptr(ptr);
  my_strcpy(flags, PRPT_FLAGS);
  i = 0;
  k = 0;
  while (flags[i])
    {
      if (flg == flags[i])
	if ((ptr[i](g_prompt)) == 1)
	  k += 1;
      i++;
    }
  return (k);
}

int		pr_printf(const char *format)
{
  int		i;

  if (!(format))
    return (-1);
  i = 0;
  xmemset(g_prompt, '\0', PROMPT_SIZE);
  while (i != len(format) + 1)
    {
      p_printf(1, "prompt ? [%s]\n\n", g_prompt);
      if (format[i] == '%' && fill_promptbfr(format[i + 1]))
	i += 2;
      if (is_legitchar(format[i]))
	g_prompt[len(g_prompt)] =  format[i];
      i += 1;
    }
  return (0);
}
