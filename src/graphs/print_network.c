/*
** llist.c for  in /home/querat_g/libmy/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 19 10:26:43 2015 gwendal querat
** Last update Sun May 24 13:10:14 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "my_graph.h"
#include "my_colors.h"

void		print_network(t_net *g, void (*printfunc)(t_slist*))
{
  if (g == NULL)
    return;
  my_printf(L_CYAN"\n"
	    "-------------------------------------------------------------\n");
  my_printf(L_CYAN"printing graph network "L_GREEN"%s"L_CYAN"\n",
	    (g->name) ? g->name : "[UNDEFINED NAME]");

  if (g == NULL || g->nodes == NULL)
    return;
  my_printf("-------------------------------------------------------------\n"
	    WHITE);
  if (printfunc == NULL)
    return;
}
