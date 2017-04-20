/*
** init_tab.c for PSU_2016_42sh in /home/bender/42sh/work/PSU_2016_42sh
**
** Made by Bender_Jr
** Login   <@epitech.eu>
**
** Started on  Thu Apr 20 08:22:35 2017 Bender_Jr
** Last update Thu Apr 20 08:33:54 2017 Bender_Jr
*/

# include "base.h"

typedef struct s_path {
  char		namepath[MAXPATH];
  char		cksum;
  struct s_path	*prev;
  struct s_path *next;
}		t_path;
