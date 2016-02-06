/*
** is_delete.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:07:49 2015 gwendal querat
** Last update Sun May 24 17:50:04 2015 gwendal querat
*/

#include <stdbool.h>
#include <stdlib.h>
#include <term.h>
#include <unistd.h>
#include <glob.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_delete(t_line *rdl, void *data)
{
  (void)rdl;
  (void)data;
  return (rdl->input == DELETE_KEY ? TRUE : FALSE);
}

int     delete_char(t_line *rdl, void *data)
{
  int	i;
  int	save;
  int	save2;

  (void)data;
  if (!rdl->line[rdl->pos])
    return (true);
  i = rdl->pos;
  save = i;
  save2 = save;
  while (rdl->line[i])
    {
      rdl->line[i] = rdl->line[i + 1];
      ++i;
    }
  my_putstr(tgetstr("cd", NULL));
  my_putstr((char*)&rdl->line[save]);
  rdl->pos = my_strlen((char*)rdl->line);
  while (++save < i)
    move_cursor_left(rdl, data);
  rdl->pos = save2;
  return (TRUE);
}
