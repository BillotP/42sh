/*
** tree.h for TEST in /home/bender/Test
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Mon Apr 10 22:32:04 2017 Bender_Jr
** Last update Sun Apr 23 10:30:30 2017 Bender_Jr
*/

#ifndef TREE_H_
# define TREE_H_

typedef struct s_tree {
  char		*label;
  struct s_node *h0;
  struct s_node *t0;
  struct s_node *h1;
  struct s_node *t1;
}		t_tree;

typedef struct s_node {
  int		data;
  char		str[4096];
  struct s_node *prev;
  struct s_node *next;
}		t_node;

/*
** srcs/tree_utils.c
*/
int		fatal_error(char *errmsg, int exitval);
int		count_occurence(t_tree *tree, const char *to_find);
void		print_tree(t_tree *tree);
void		free_tree(t_tree *tree);

/*
** srcs/node_ops.c
*/
t_tree		*replace_h0_node(t_tree *tree, const char *to_replace,
			      char *new_data);
void		rple_first_h0_node(t_tree *tree, t_node *n0);
void		rple_last_h0_node(t_tree *tree, t_node *n0);
t_tree		*rple_middle_h0_node(t_tree *tree, t_node *n0,
				    const char *to_replace);

/*
** srcs/tree.c
*/
t_tree		*init_tree(char *label);
void		get_h0(t_tree *tree, t_node *n0);
void		get_h1(t_tree *tree, t_node *n1);
t_node		*get_nodes(int data, char *str);
t_tree		*fill_node(t_tree *tree, int data, char *str,
			   int listtofeed);

/*
** srcs/fill_tree.c
*/
void		clean_tree(t_tree *tofree);
t_tree		*read_andfill(int fd, t_tree *tree);

#endif /* !TREE_H_ */
