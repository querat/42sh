/*
** rm_cur.c for  in /home/querat_g/42sh/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun May 24 17:59:29 2015 gwendal querat
** Last update Sun May 24 18:00:11 2015 gwendal querat
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "readline.h"
#include "shell.h"
#include "tokenizer.h"
#include "dlist.h"
#include "format.h"
#include "parser.h"

t_dlist		*rm_cur(t_dlist *list, t_dlist **cur, int *rm)
{
  t_dlist	*tmp;

  if ((tmp = list) == NULL || cur == NULL || rm == NULL || (*cur) == NULL)
    return (list);
  if ((*cur) == list)
    {
      ++(*rm);
      (*cur) = (*cur)->next;
      return (rm_first_dlist(list, &free_t_prs));
    }
  else
    {
      (*rm) = 0;
      tmp = (*cur);
      free_t_prs((*cur)->data);
      tmp->prev->next = tmp->next;
      if (tmp->next)
	tmp->next->prev = tmp->prev;
      (*cur) = (*cur)->prev;
      gbgc_free(NULL, tmp);
    }
  return (list);
}
