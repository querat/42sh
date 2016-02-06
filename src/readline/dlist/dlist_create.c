/*
** llist.c for  in /home/querat_g/libmy/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Sat May  2 16:06:06 2015 gwendal querat
*/

#include <stdlib.h>
#include "my_mem.h"
#include "my.h"
#include "dlist.h"

t_dlist		*add_head_dlist_elem(t_dlist *list)
{
  t_dlist	*cur;

  if ((cur = list) == NULL)
    return (gbgc_calloc(sizeof(t_dlist)));
  if ((cur = gbgc_calloc(sizeof(t_dlist))) == NULL)
    return (NULL);
  cur->next = list;
  list->prev = cur;
  return (cur);
}

t_dlist		*add_dlist_elem(t_dlist *list)
{
  t_dlist	*cur;

  if ((cur = list) == NULL)
    return (gbgc_calloc(sizeof(t_dlist)));
  while (cur->next)
    cur = cur->next;
  if ((cur->next = gbgc_calloc(sizeof(t_dlist))) == NULL)
    return (NULL);
  cur->next->prev = cur;
  return (list);
}

t_dlist		*insert_dlist(t_dlist *list, size_t pos)
{
  t_dlist	*tmp;
  t_dlist	*prev;
  t_dlist	*new;

  if (pos <= 1 || list == NULL)
    return (add_head_dlist_elem(list));
  if (pos > count_dlist(list))
    return (add_dlist_elem(list));
  prev = list;
  prev = goto_pos_dlist(list, pos);
  if ((new = gbgc_calloc(sizeof(t_dlist))) == NULL)
    return (NULL);
  tmp = prev->next;
  prev->next = new;
  new->next = tmp;
  return (list);
}
