/*
** pr_printf.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Sat Apr 15 08:00:54 2017 Bender_Jr
** Last update Thu Apr 20 10:31:41 2017 Bender_Jr
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
  if (len(format) > PROMPT_SIZE)
    return (p_printf(2, "%sSet prompt error:%s\n\t%s%s%s\n",
		     BLD, RST, RED, "Prompt too long (max 126)", RST), -1);
  while (i != len(format) + 1)
    {
      if (format[i] == '%' && fill_promptbfr(format[i + 1]))
	i += 2;
      g_prompt[len(g_prompt)] =  format[i];
      i += 1;
    }
  if (isatty(0))
    p_printf(1, "%s", g_prompt);
  return (0);
}
