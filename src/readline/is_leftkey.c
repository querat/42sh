/*
** is_leftkey.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:11:44 2015 gwendal querat
** Last update Sun May 24 12:07:52 2015 
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

int	is_leftkey(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == LEFT_KEY ? TRUE : FALSE);
}

int     move_cursor_left(t_line *rdl, void *data)
{
  (void)data;
  if (rdl->line == NULL)
    return (FALSE);
  if (rdl->pos > 0)
    {
      if (is_cursor_left(rdl))
	go_up(rdl);
      else
	my_putstr(tgetstr("le", NULL));
      --rdl->pos;
    }
  return (TRUE);
}
