/*
** is_backspace.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:06:33 2015 gwendal querat
** Last update Sun May 24 02:36:27 2015 
*/

#include <stdlib.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>
#include <term.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_backspace(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == BACKSPACE_KEY ? TRUE : FALSE);
}

int     backspace(t_line *rdl, void *data)
{
  (void)data;
  if (rdl->pos < 1)
    return (TRUE);
  move_cursor_left(rdl, data);
  delete_char(rdl, data);
  return (TRUE);
}
