/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Thu Apr 23 14:04:19 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"

t_net		*init_network(char *name)
{
  t_net		*net;

  if ((net = gbgc_calloc(sizeof(t_net))) == NULL)
    {
      my_perror("init_network : malloc failed");
      return (NULL);
    }
  if (name)
    {
      if ((net->name = my_strdup(name)) == NULL)
	my_perror("init network : no more memory for setting its name");
    }
  return (net);
}
