/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Sun May 24 17:57:39 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

/*
** you'll need to call the function destined to free the node's data
** after the call to destroy_slist
*/

void		free_nodes(void *data)
{
  t_node	*node;

  if ((node = data) == NULL)
    return ;
  destroy_slist(node->edges, NULL);
  gbgc_free(NULL, node);
}

void		free_network(t_net *g, void(*freefunc)(void*))
{
  t_slist	*cur;

  if (g != NULL && (cur = g->nodes) != NULL)
    destroy_slist(g->nodes, freefunc);
  if (g && g->name)
    gbgc_free(NULL, g->name);
  gbgc_free(NULL, g);
}
