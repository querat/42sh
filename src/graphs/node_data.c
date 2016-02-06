/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Wed Apr 22 15:16:10 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

void		*get_node_data(t_net *g, int id)
{
  t_node	*node;

  if ((g == NULL)			   ||
      ((node = find_node(g, id)) == NULL))
    return (NULL);
  return (node->data);
}

int		set_node_data(t_net *g, int id, void *data)
{
  t_node	*node;

  if ((g == NULL)			   ||
      (data == NULL)			   ||
      ((node = find_node(g, id)) == NULL))
    return (FALSE);
  node->data = data;
  return (TRUE);
}
