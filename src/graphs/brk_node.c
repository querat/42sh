/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Wed Apr 22 15:14:32 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

int		brk_node(t_net *g, size_t id)
{
  t_node	*delete;
  size_t	pos;

  if (g == NULL || g->nodes == NULL)
    return (FALSE);
  if ((!(delete = find_node(g, id))) ||
      (!(pos = find_node_slist_pos(g, id))))
    return (my_perror("brk_node couldnt find specified node"));
  brk_all_node_edges(g, delete);
  g->nodes = rm_slist_elem(g->nodes, pos, &free_nodes);
  --g->nb_links;
  return (TRUE);
}
