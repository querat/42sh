/*
** is_rightkey.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:12:06 2015 gwendal querat
** Last update Sun May 24 15:08:42 2015 
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

int	is_rightkey(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == RIGHT_KEY ? TRUE : FALSE);
}

int     move_cursor_right(t_line *rdl, void *data)
{
  (void)data;
  if (rdl->line == NULL)
    return (FALSE);
  if (rdl->line[rdl->pos])
    {
      if ((get_nb_char_line(rdl)) == get_winsize_x())
	go_down(rdl, 0);
      else
	my_putstr(tgetstr("nd", NULL));
      ++rdl->pos;
    }
  return (TRUE);
}

int     move_cursor_end(t_line *rdl)
{
  if (rdl->line == NULL)
    return (FALSE);
  if (rdl->line[rdl->pos])
    {
      if ((get_nb_char_line(rdl)) == get_winsize_x())
	go_down(rdl, 0);
      else
	my_putstr(tgetstr("nd", NULL));
      ++rdl->pos;
    }
  return (TRUE);
}
