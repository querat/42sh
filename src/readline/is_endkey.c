/*
** is_endkey.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:12:25 2015 gwendal querat
** Last update Sun May 24 15:12:43 2015 gwendal querat
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

int	is_endkey(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == END_KEY ? TRUE : FALSE);
}

int     cursor_end(t_line *rdl, void *data)
{
  (void)data;
  while (rdl->pos != my_strlen((char*)rdl->line))
    move_cursor_right(rdl, data);
  return (TRUE);
}
