/*
** readline.c for  in /home/querat_g/lib42/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri May  1 10:15:14 2015 gwendal querat
** Last update Sun May 24 15:12:28 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses/curses.h>
#include <term.h>
#include "my.h"
#include "my_mem.h"
#include "dlist.h"
#include "readline.h"
#include "shell.h"

int		cast_buffer(unsigned char *buffer)
{
  int		input;
  int		i;

  input = 0;
  i = 0;
  if (buffer == NULL)
    return (FALSE);
  while (buffer[i])
    input += buffer[i++];
  return (input);
}

void		spaces(char *line)
{
  static int	len = 0;
  int		i;

  i = len;
  while (i > 0)
    {
      my_putchar('\b');
      i--;
    }
  while (i < len)
    {
      my_putchar(' ');
      ++i;
    }
  len = my_strlen(line);
  my_putchar('\r');
}

void		init_rdl(t_line *rdl)
{
  rdl->line = NULL;
  rdl->pos = 0;
}

unsigned char	*return_readline(t_line *rdl)
{
  if (rdl->cur_hist)
    {
      if (((rdl->hist->data =
	    (unsigned char*)my_strdup((char*)rdl->line)) == NULL))
	return (NULL);
      rdl->cur_hist = NULL;
    }
  else
    {
      if (((rdl->hist = add_head_dlist_elem(rdl->hist)) == NULL) ||
	  ((rdl->hist->data =
	    (unsigned char*)my_strdup((char*)rdl->line)) == NULL))
	return (NULL);
    }
  my_putchar('\n');
  return (rdl->line);
}

unsigned char	*readline(t_line *rdl)
{
  init_rdl(rdl);
  if ((rdl->line = gbgc_calloc(sizeof(char) * 1)) == NULL)
    return ((void*)(long)my_perror("malloc failed !"));
  while ((!0))
    {
      my_memset(rdl->buffer, '\0', READLINE_SZ);
      if ((read(0, rdl->buffer, READLINE_SZ)) == FAILURE)
	return (NULL);
      rdl->input = cast_buffer(rdl->buffer);
      if (rdl->input == CTRL_D && rdl->line[0] == '\0')
	return (rdl->line);
      if (rdl->input == ENTER && rdl->line[0] != '\0')
        {
          while (rdl->pos < my_strlen((char*)rdl->line))
            move_cursor_end(rdl);
          return (return_readline(rdl));
        }
      if ((call_func_by_keycode(rdl)) == FALSE)
	return (NULL);
    }
  return (rdl->line);
}
