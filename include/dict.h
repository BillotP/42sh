/*
** dict.h for TEST in /home/bender/Test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 21:07:29 2017 Bender_Jr
** Last update Sat Apr 15 13:51:53 2017 Bender_Jr
*/

#ifndef DICT_H_
# define DICT_H_

/*
** For t_tree typedef
*/
# include "tree.h"

#ifndef MAX_NAME_LENGHT
# define MAX_NAME_LENGHT (364)
# endif /* !MAX_NAME_LENGHT */

#ifndef MAX_KWD
# define MAX_KWD (200)
# endif /* !MAX_KWD */

typedef struct	s_keyword {
  char		name[MAX_NAME_LENGHT];
  int		index;
}		t_keyword;

#ifndef D_FPATH
# define D_FPATH "ressources/dict"
# endif /* !D_FPATH */

#ifndef END_DICT
# define END_DICT '!'
# endif /* !END_DICT */

#ifndef CMT_CHAR
# define CMT_CHAR '#'
# endif /* !CMT_CHAR */

/*
** srcs/get_keywrd.c
*/
int		check_keyword(char *bfr, int line, t_tree *tree, t_keyword keytab[]);
int		err_dictfile(char *tofree, int line_info, int ret_val);
t_keyword	*fill_keyword(t_keyword *ptr, int dict_fd);

/*
** error messages
*/
#ifndef ERR_DICT
# define ERR_DICT "\033[31mCorrupted dict file\033[0m, unknow keyword "
# endif /* !ERR_DICT */

#endif /* !DICT_H_ */
