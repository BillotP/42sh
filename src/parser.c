/*
** main.c for TEST in /home/bender/Test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 19:27:18 2017 Bender_Jr
** Last update Wed Apr 12 07:57:33 2017 Bender_Jr
*/

/*
** includes for open,
** and strerror funct
*/
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "tree.h"
# include "dict.h"
# include "base.h"
# include "get_next_line.h"

int			main(int ac, char **av)
{
  int			fd;
  t_tree		*tree;

  fd = -1;
  if (ac == 2)
    {
      if ((fd = open(av[1], O_RDONLY)) == -1)
	return(p_printf(2, "%s%s%s:\n\t\t%s : %s%s%s\n", BLD,
			av[0], RST, av[1], BLD, strerror(errno), RST), 84);
      else if ((tree = init_tree(av[1])) == NULL ||
	       (tree = read_andfill(fd, tree)) == NULL)
	return (84);
      /* tree = replace_h0_node(tree, "OBJS", "\t\tENFIIIIN!!!\t\t"); */
      print_tree(tree);
      free_tree(tree);
      return (0);
    }
  return (p_printf(2, "Wrong usage\n"), 84);
}
