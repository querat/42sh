/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Wed May 13 09:57:02 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"

t_dlist		*rm_first_dlist(t_dlist *list, void(*freefunc)(void*))
{
  t_dlist	*cur;

  if (list == NULL)
    return (NULL);
  cur = list->next;
  if (freefunc)
    freefunc(list->data);
  gbgc_free(NULL, list);
  if ((cur))
    cur->prev = NULL;
  return (cur);
}

t_dlist		*rm_dlist_elem(t_dlist *list, size_t pos,
			       void(*freefunc)(void*))
{
  size_t	i;
  t_dlist	*cur;
  t_dlist	*tmp;

  if ((cur = list) == NULL)
    return (NULL);
  if (pos <= 1)
    return (rm_first_dlist(list, freefunc));
  i = 1;
  while (cur->next && ++i < pos)
    cur = cur->next;
  tmp = cur;
  if ((cur = cur->next) == NULL)
    return (list);
  tmp->next = cur->next;
  if (freefunc)
    freefunc(cur->data);
  cur->next->prev = tmp;
  gbgc_free(NULL, cur);
  return (list);
}

t_dlist		*destroy_dlist(t_dlist *list, void(*freefunc)(void*))
{
  while ((list))
    list = rm_first_dlist(list, freefunc);
  return (NULL);
}
