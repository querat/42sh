/*
** llist.c for  in /home/querat_g/libmy/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Wed Apr 22 15:16:39 2015 gwendal querat
*/

#include <stdlib.h>
#include "my_mem.h"
#include "my.h"
#include "slist.h"

t_slist		*add_head_slist_elem(t_slist *list)
{
  t_slist	*cur;

  if ((cur = list) == NULL)
    return (gbgc_calloc(sizeof(t_slist)));
  if ((cur = gbgc_calloc(sizeof(t_slist))) == NULL)
    return (NULL);
  cur->next = list;
  return (cur);
}

t_slist		*add_slist_elem(t_slist *list)
{
  t_slist	*cur;

  if ((cur = list) == NULL)
    return (gbgc_calloc(sizeof(t_slist)));
  while (cur->next)
    cur = cur->next;
  if ((cur->next = gbgc_calloc(sizeof(t_slist))) == NULL)
    return (NULL);
  return (list);
}

t_slist		*insert_slist(t_slist *list, size_t pos)
{
  t_slist	*tmp;
  t_slist	*prev;
  t_slist	*new;

  if (pos <= 1 || list == NULL)
    return (add_head_slist_elem(list));
  if (pos > count_slist(list))
    return (add_slist_elem(list));
  prev = list;
  prev = goto_pos_slist(list, pos);
  if ((new = gbgc_calloc(sizeof(t_slist))) == NULL)
    return (NULL);
  tmp = prev->next;
  prev->next = new;
  new->next = tmp;
  return (list);
}
