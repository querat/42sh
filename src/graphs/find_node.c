/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Wed Apr 22 15:15:26 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

t_node		*find_node(t_net *g, size_t id)
{
  t_slist	*cur;
  t_node	*res;

  if (g == NULL || (cur = g->nodes) == NULL)
    return (NULL);
  while (cur)
    {
      if ((res = cur->data) == NULL)
	return (NULL);
      if (res->id == id)
	return (res);
      cur = cur->next;
    }
  return (NULL);
}

size_t		find_node_slist_pos(t_net *g, size_t id)
{
  t_slist	*cur;
  t_node	*res;
  size_t	i;

  i = 1;
  if (g == NULL || (cur = g->nodes) == NULL)
    return (0);
  while (cur)
    {
      if ((res = cur->data) == NULL)
	return (0);
      if (res->id == id)
	return (i);
      cur = cur->next;
      ++i;
    }
  return (0);
}
