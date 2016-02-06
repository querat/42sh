/*
** is_tab.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:10:35 2015 gwendal querat
** Last update Sun May 24 18:37:51 2015 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_tab(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == TABULATION ? TRUE : FALSE);
}

int     autocomplete(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (TRUE);
}

