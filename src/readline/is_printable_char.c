/*
** Is_printable_char.c for  in /home/querat_g/lib42/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri May  1 10:05:21 2015 gwendal querat
** Last update Sun May 24 15:13:09 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <glob.h>
#include <term.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int		is_printable_char(t_line *rdl, void *data)
{
  (void)rdl;
  (void)data;
  return (PRINTABLE_CHAR ? TRUE : FALSE);
}

int		concat_char(t_line *rdl, void *data)
{
  int		i;
  int		j;
  int		len;
  unsigned char	*res;

  (void)data;
  len = my_strlen((char*)rdl->line) + 2;
  i = -1;
  if ((res = gbgc_calloc(sizeof(char) * len)) == NULL)
    return (FALSE & my_perror("[critical] : malloc failed !\n"));
  while (++i < rdl->pos)
    res[i] = rdl->line[i];
  res[i++] = (char)rdl->input;
  j = rdl->pos;
  while (rdl->line[j])
    res[i++] = rdl->line[j++];
  gbgc_free(NULL, rdl->line);
  rdl->line = res;
  print_char_concat(rdl, data);
  return (TRUE);
}

void	print_char_concat(t_line *rdl, void *data)
{
  int		save;

  if ((get_nb_char_line(rdl)) == get_winsize_x())
    {
      go_down(rdl, 1);
      ++rdl->pos;
    }
  else
    {
      my_putstr(tgetstr("cd", NULL));
      save = rdl->pos + 1;
      my_putstr((char*)&rdl->line[rdl->pos]);
      rdl->pos = my_strlen((char*)rdl->line);
      while (rdl->pos > save)
	move_cursor_left(rdl, data);
    }
}
