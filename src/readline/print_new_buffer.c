/*
** print_new_buffer.c for 42sh in /home/bellia_n/rendu/Unix/Current/42sh/src/readline
** 
** Made by 
** Login   <bellia_n@epitech.net>
** 
** Started on  Thu May 14 17:30:26 2015 
** Last update Sat May 23 15:44:37 2015 
*/

#include <term.h>
#include "my.h"
#include "readline.h"

void	return_to_beg(t_line *rdl, void *data, int flag)
{
  while (rdl->pos > 0)
    move_cursor_left(rdl, data);
  if (flag == 1)
    my_putstr(tgetstr("cd", NULL));
}
