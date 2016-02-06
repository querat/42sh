/*
** is_ctrlr.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:13:06 2015 gwendal querat
** Last update Sun May 24 15:16:07 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_ctrlr(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return ((rdl->input == CTRL_R) ? TRUE : FALSE);
}

int     hist_search(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (TRUE);
}
