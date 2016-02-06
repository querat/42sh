/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Tue May 12 10:10:39 2015 gwendal querat
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "my_mem.h"
#include "my_colors.h"
#include "dlist.h"

size_t		count_dlist(t_dlist *list)
{
  t_dlist	*cur;
  size_t	i;

  if ((cur = list) == NULL)
    return (0);
  i = 1;
  while (cur)
    {
      ++i;
      cur = cur->next;
    }
  return (i);
}

void		print_dlist(t_dlist *list, void (*func)(void*))
{
  t_dlist	*cur;

  if ((cur = list) == NULL)
    {
      my_perror("print_dlist : null list");
      return ;
    }
  my_putstr(BLUE"--------------------------------------\n"WHITE);
  while ((cur))
    {
      my_printf(GREEN"element %p\n"WHITE, cur);
      if (func)
	func(cur->data);
      my_putstr(BLUE"--------------------------------------\n"WHITE);
      cur = cur->next;
    }
}

t_dlist	*goto_last_dlist(t_dlist *list)
{
  t_dlist	*cur;

  if ((cur = list) == NULL)
    return (NULL);
  while (cur->next)
    cur = cur->next;
  return (cur);
}

t_dlist	*goto_pos_dlist(t_dlist *list, size_t pos)
{
  t_dlist	*cur;
  size_t	i;

  i = 0;
  if ((cur = list) == NULL)
    return (NULL);
  while (cur->next && ++i < pos)
    {
      cur = cur->next;
    }
  return (cur);
}
