/*
** is_ctrl_right.c for  in /home/querat_g/lib42/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri May  1 17:31:50 2015 gwendal querat
** Last update Fri May 22 17:02:39 2015 
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

int	is_ctrl_right(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == CTRL_RIGHT ? TRUE : FALSE);
}

int     goto_word_right(t_line *rdl, void *data)
{
  (void)data;
  if (rdl->line == NULL)
    return (FALSE);
  if (!is_alphanum(rdl->line[rdl->pos]))
    {
      while (rdl->line[rdl->pos] && !is_alphanum(rdl->line[rdl->pos]))
	move_cursor_right(rdl, data);
      while (rdl->line[rdl->pos] && is_alphanum(rdl->line[rdl->pos]))
	move_cursor_right(rdl, data);
    }
  else
    while (rdl->line[rdl->pos] && is_alphanum(rdl->line[rdl->pos]))
      move_cursor_right(rdl, data);
  return (TRUE);
}
