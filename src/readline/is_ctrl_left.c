/*
** is_leftkey.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:11:44 2015 gwendal querat
** Last update Sun May 24 14:11:42 2015 
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

int	is_ctrl_left(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == CTRL_LEFT ? TRUE : FALSE);
}

void	ectoplasme_a_roulette(t_line *rdl, void *data)
{
  if (rdl->pos > 0 && !is_alphanum(rdl->line[rdl->pos - 1]))
    {
      move_cursor_left(rdl, data);
      while (rdl->pos > 0 && !is_alphanum(rdl->line[rdl->pos]))
	move_cursor_left(rdl, data);
    }
  while (rdl->pos > 0 && is_alphanum(rdl->line[rdl->pos]))
    move_cursor_left(rdl, data);
}

void	canard_thermonucleaire(t_line *rdl, void *data)
{
 if (!is_alphanum(rdl->line[rdl->pos]))
    {
      while (rdl->pos > 0 && !is_alphanum(rdl->line[rdl->pos]))
	move_cursor_left(rdl, data);
      while (rdl->pos > 0 && is_alphanum(rdl->line[rdl->pos]))
	move_cursor_left(rdl, data);
    }
  else
    ectoplasme_a_roulette(rdl, data);
  if (!is_alphanum(rdl->line[rdl->pos]))
    move_cursor_right(rdl, data);
}

int     goto_word_left(t_line *rdl, void *data)
{
  (void)data;
  if (rdl->line == NULL)
    return (FALSE);
  canard_thermonucleaire(rdl, data);
  return (TRUE);
}
