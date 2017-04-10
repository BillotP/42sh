/*
** main.c for PSU_2016_42sh in /home/bender/LASTP/psu_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 09:28:10 2017 Bender_Jr
** Last update Mon Apr 10 09:39:49 2017 Bender_Jr
*/

# include "sh.h"
# include "printf.h"

int	main(int ac, char **av)
{
  if (ac && av)
    p_printf(1, "coucou 42!\n");
  return (0);
}
