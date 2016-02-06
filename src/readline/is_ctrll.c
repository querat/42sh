/*
** is_ctrll.c for  in /home/querat_g/lib42/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri May  1 10:13:26 2015 gwendal querat
** Last update Sun May 24 18:34:16 2015 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_ctrll(t_line *rdl, void *data)
{
  (void)data;
  return ((rdl->input == CTRL_L) ? TRUE : FALSE);
}

int     my_clear(t_line *rdl, void *data)
{
  char	*termcap;

  termcap = tgetstr("cl", NULL);
  (void)data;
  (void)rdl;
  if (termcap)
    my_putstr(termcap);
  my_putstr(rdl->prompt);
  my_putstr((char*)rdl->line);
  return (TRUE);
}
