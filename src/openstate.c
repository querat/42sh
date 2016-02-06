/*
** openstate.c for  in /home/querat_g/42sh/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May 22 16:02:58 2015 gwendal querat
** Last update Sun May 24 17:23:55 2015 guigui
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <term.h>
#include <ncurses/curses.h>
#include "my.h"
#include "my_mem.h"
#include "readline.h"
#include "shell.h"
#include "tokenizer.h"
#include "slist.h"
#include "format.h"
#include "parser.h"

int		is_open(int *ptr)
{
  static int	*state;

  if (ptr != NULL)
    state = ptr;
  return ((state != NULL) ? *state : 0);
}

void		set_openstate(int *ptr, int value)
{
  static int	*state;

  if (ptr != NULL)
    state = ptr;
  if (state != NULL)
    *state = value;
}

void		init_open()
{
  static int	val;
  static int	ret;

  val = 1;
  ret = 0;
  set_openstate(&val, 1);
  is_open(&val);
  set_exitstate(&ret, 0);
  get_exitstate(&ret);
  init_lastreturnvalue();
}

