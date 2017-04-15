/*
** get_keywrd.c for TEST in /home/bender/tek1_2016_test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Tue Apr 11 19:05:28 2017 Bender_Jr
** Last update Fri Apr 14 18:36:12 2017 Bender_Jr
*/

/*
** for free syscall
*/
# include <stdlib.h>
# include "dict.h"
# include "tree.h"
# include "base.h"
# include "get_next_line.h"

int		err_dicfile(char *tofree, int line_info, int ret_val)
{
  p_printf(2, "%s%s%s[%s]%s in line %d\n", ERR, ERR_DICT, BLD,
	   tofree, RST, line_info);
  free(tofree);
  return (ret_val);
}


int			check_keyword(char *bfr, int line, t_tree *tree,
				      t_keyword key_tab[])
{
  int			i;

  i = 1;
  while (key_tab[i].index != 0)
    {
      if (strn_cmp(bfr, key_tab[i].name, len(key_tab[i].name)))
	{
	  fill_node(tree, line, bfr, 0);
	  return (0);
	}
      i++;
    }
  return (1);
}

void		print_keyword(char *keyword, int index)
{
  keyword = keyword;
  index = index;
#ifdef DEBUG
  p_printf(1, "Data in dict :\n\tKeyword [%s], index [%d]\n",
	   keyword, index);
#endif
}

t_keyword	*fill_keyword(t_keyword *wrd_tab, int dict_fd)
{
  int		lines;
  char		*bfr;
  char		**wrd;

  lines = 0;
  while ((bfr = epurstr(get_next_line(dict_fd), ' ')))
    {
      if (len(bfr) > 2 && bfr[0] != CMT_CHAR)
	{
	  wrd = strto_wordtab(bfr, ",");
	  if (tab_len(wrd) == 2 && my_stringisnum(wrd[1]))
	    {
	      lines++;
	      my_strcpy(wrd_tab[lines].name, wrd[0]);
	      wrd_tab[lines].index = my_atoi(wrd[1]);
	      print_keyword(wrd_tab[lines].name, wrd_tab[lines].index);
	    }
	  freetab(wrd);
	}
      else if (!bfr || bfr[0] != CMT_CHAR || is_legitstr(bfr) == -1)
	return (err_dicfile(bfr, lines, 84), NULL);
      free(bfr);
    }
  return (close(dict_fd), wrd_tab);
}
