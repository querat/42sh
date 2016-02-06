/*
** dlist_len.c for  in /home/querat_g/42sh/src/tokenizer
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sat May 23 18:08:02 2015 gwendal querat
** Last update Sat May 23 18:10:15 2015 gwendal querat
*/

#include <stdlib.h>
#include "dlist.h"

int		dlist_len(t_dlist *list)
{
  int		i;
  t_dlist	*cur;

  if (list == NULL)
    return (0);
  i = 0;
  cur = list;
  while ((cur))
    {
      ++i;
      cur = cur->next;
    }
  return (i);
}
