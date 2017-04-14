/*
** fill_tree.c for TEST in /home/bender/tek1_2016_test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Wed Apr 12 07:36:23 2017 Bender_Jr
** Last update Fri Apr 14 18:29:45 2017 Bender_Jr
*/

/*
** For open syscall
*/
# include <fcntl.h>
# include <sys/stat.h>
/*
** For free
*/
# include <stdlib.h>

# include "tree.h"
# include "dict.h"
# include "base.h"
# include "get_next_line.h"

void			clean_tree(t_tree *tofree)
{
  free(tofree->label);
  free(tofree);
}

int			clean_exit(char *bfr, t_tree *tree, int line)
{
  p_printf(2, "%s%sInvalid string%s : [%s] on line [%d]\n",
	   ERR, RED, RST, bfr, line);
  free(bfr);
  free_tree(tree);
  return (-1);
}

t_tree			*read_andfill(int fd, t_tree *tree)
{
  int			line;
  int			dict_fd;
  t_keyword		key_tab;
  char			*rd;

  line = 0;
  if ((dict_fd = open(D_FPATH, O_RDONLY)) == -1 ||
      (fill_keyword(&key_tab, dict_fd)) == NULL)
    return (clean_tree(tree), NULL);
  while ((rd = epurstr(get_next_line(fd), ' ')))
    {
      if ((is_legitstr(rd)) == -1 && rd[0] != CMT_CHAR)
	return (clean_exit(rd, tree, line), NULL);
      if ((check_keyword(rd, line, tree, &key_tab)))
	if (len(rd) > 1 && rd[0] != CMT_CHAR)
	  fill_node(tree, line, rd, 1);
      line += 1;
      free(rd);
    }
  return (tree);
}
