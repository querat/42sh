/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Thu Apr 23 14:03:32 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

int		add_node(t_net *g)
{
  t_node	*node;
  t_slist	*cur;

  if (((g == NULL))					||
      ((node = gbgc_calloc(sizeof(t_node))) == NULL)	||
      ((g->nodes = add_slist_elem(g->nodes)) == NULL))
    return (FALSE);
  cur = goto_last_slist(g->nodes);
  node->id = ++g->assigned_ids;
  ++g->nb_nodes;
  cur->data = node;
  return (node->id);
}
