/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Wed Apr 22 15:16:50 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"

t_slist		*rm_first_slist(t_slist *list, void(*freefunc)(void*))
{
  t_slist	*cur;

  if (list == NULL)
    return (NULL);
  cur = list->next;
  if (freefunc)
    freefunc(list->data);
  gbgc_free(NULL, list);
  return (cur);
}

t_slist		*rm_slist_elem(t_slist *list, size_t pos,
			       void(*freefunc)(void*))
{
  size_t	i;
  t_slist	*cur;
  t_slist	*tmp;

  if ((cur = list) == NULL)
    return (NULL);
  if (pos <= 1)
    return (rm_first_slist(list, freefunc));
  i = 1;
  while (cur->next && ++i < pos)
    cur = cur->next;
  tmp = cur;
  if ((cur = cur->next) == NULL)
    return (list);
  tmp->next = cur->next;
  if (freefunc)
    freefunc(cur->data);
  gbgc_free(NULL, cur);
  return (list);
}

t_slist		*destroy_slist(t_slist *list, void(*freefunc)(void*))
{
  while ((list))
    list = rm_first_slist(list, freefunc);
  return (NULL);
}
