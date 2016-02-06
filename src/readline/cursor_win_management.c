/*
** cursor_win_management.c for 42sh in /home/bellia_n/rendu/Unix/Current/42sh/src
** 
** Made by 
** Login   <bellia_n@epitech.net>
** 
** Started on  Thu May 21 11:02:52 2015 
** Last update Sun May 24 15:15:18 2015 gwendal querat
*/

#include <sys/ioctl.h>
#include <stdio.h>
#include <term.h>
#include "readline.h"
#include "my.h"

int	get_winsize_x()
{
  struct winsize	w;

  ioctl(0, TIOCGWINSZ, &w);
  return (w.ws_col);
}

int	get_nb_char_line(t_line *rdl)
{
  struct winsize	w;
  int			nb_line;
  int			line_size;

  ioctl(0, TIOCGWINSZ, &w);
  line_size = my_strlen(rdl->prompt) + rdl->pos;
  nb_line = line_size / w.ws_col;
  return (line_size - (w.ws_col * nb_line) + 1);
}

void	go_down(t_line *rdl, int flag)
{
  struct winsize	w;
  int			c;

  ioctl(0, TIOCGWINSZ, &w);
  c = w.ws_col + 1;
  if (flag == 1)
    my_putchar(rdl->input);
  while (--c != 0)
    my_putstr(tgetstr("le", NULL));
  my_putstr(tgetstr("do", NULL));
}

void	go_up(t_line *rdl)
{
  struct winsize	w;
  int			c;

  (void)rdl;
  c = -1;
  ioctl(0, TIOCGWINSZ, &w);
  my_putstr(tgetstr("up", NULL));
  while (++c != w.ws_col)
    my_putstr(tgetstr("nd", NULL));
}

int	is_cursor_left(t_line *rdl)
{
  struct winsize	w;
  int			nb_line;
  int			line_size;
  int			nb_char_line;

  ioctl(0, TIOCGWINSZ, &w);
  line_size = my_strlen(rdl->prompt) + rdl->pos;
  nb_line = line_size / w.ws_col;
  nb_char_line = line_size - (w.ws_col * nb_line) + 1;
  if (nb_char_line > 1)
    return (0);
  return (1);
}
