/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Wed Apr 22 15:14:50 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

int		edge_exists(t_node *a, t_node *b)
{
  t_slist	*a_edges;

  if ((a_edges = a->edges) == NULL)
    return (FALSE);
  while (a_edges)
    {
      if (a_edges->data == b)
	return (TRUE);
      a_edges = a_edges->next;
    }
  return (FALSE);
}

int		check_directed_edge(t_net *g, size_t id1, size_t id2)
{
  t_node	*a;
  t_node	*b;
  t_slist	*a_edges;

  if (((a = find_node(g, id1)) == NULL) ||
      ((b = find_node(g, id2)) == NULL) ||
      ((a_edges = a->edges) == NULL))
    return (FALSE);
  while ((a_edges))
    {
      if (a_edges->data == b)
	return (TRUE);
      a_edges = a_edges->next;
    }
  return (FALSE);
}

int		check_edge(t_net *g, size_t id1, size_t id2)
{
  if (((check_directed_edge(g, id1, id2)) == FALSE) ||
      ((check_directed_edge(g, id2, id1)) == FALSE))
    return (FALSE);
  return (TRUE);
}
