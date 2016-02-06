/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Thu Apr 23 14:04:09 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

int		add_directed_edge(t_net *g, size_t id1, size_t id2)
{
  t_node	*node_a;
  t_node	*node_b;
  t_slist	*node_a_edges;

  node_a = NULL;
  node_b = NULL;
  if (!(node_a = find_node(g, id1)) || !(node_b = find_node(g, id2)))
    return (FALSE & my_perror("add_edge couldnt find specified node(s)"));
  if ((edge_exists(node_a, node_b)))
    return (TRUE);
  if ((node_a->edges = add_slist_elem(node_a->edges)) == NULL)
    return (FALSE & my_perror("malloc failed (add_slist_elem) !"));
  node_a_edges = goto_last_slist(node_a->edges);
  node_a_edges->data = node_b;
  g->nb_links++;
  return (TRUE);
}

int		add_edge(t_net *g, size_t id1, size_t id2)
{
  if (((add_directed_edge(g, id1, id2)) == FALSE)	||
      ((add_directed_edge(g, id2, id1)) == FALSE))
    return (FALSE);
  return (TRUE);
}

int		brk_directed_edge(t_net *g, size_t id1, size_t id2)
{
  t_node	*node_a;
  t_node	*node_b;
  t_slist	*cur;
  size_t	pos;

  node_a = NULL;
  node_b = NULL;
  pos = 1;
  if (!(node_a = find_node(g, id1)) || !(node_b = find_node(g, id2)))
    return (FALSE);
  if (((cur = node_a->edges) == NULL) || cur->data == NULL)
    return (FALSE);
  while (cur && cur->data && cur->data != node_b)
    {
      ++pos;
      cur = cur->next;
    }
  if (cur == NULL || cur->data == NULL)
    return (FALSE);
  node_a->edges = rm_slist_elem(node_a->edges, pos, NULL);
  g->nb_links--;

  return (TRUE);
}

int		brk_edge(t_net *g, size_t id1, size_t id2)
{
  if (((brk_directed_edge(g, id1, id2)) == FALSE)	||
      ((brk_directed_edge(g, id2, id1)) == FALSE))
    return (FALSE);
  return (TRUE);
}

int		brk_all_node_edges(t_net *g, t_node *node)
{
  size_t	i;

  i = 0;
  if (g == NULL || node == NULL)
    return (FALSE);
  while (++i <= g->assigned_ids)
    {
      brk_directed_edge(g, node->id, i);
      brk_directed_edge(g, i, node->id);
    }
  return (TRUE);
}
