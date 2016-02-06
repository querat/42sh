/*
** is_begkey.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:12:44 2015 gwendal querat
** Last update Sat May 23 16:30:34 2015 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <term.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_begkey(t_line *rdl, void *data)
{
  (void)data;
  return ((rdl->input == BEG_KEY || rdl->input == CTRL_A) ? TRUE : FALSE);
}

int     cursor_beg(t_line *rdl, void *data)
{
  (void)data;
  while (rdl->pos != 0)
    move_cursor_left(rdl, data);
  return (TRUE);
}
