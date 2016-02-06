/*
** is_ctrlu.c for  in /home/querat_g/lib42/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri May  1 10:09:53 2015 gwendal querat
** Last update Sat May 23 15:39:23 2015 
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

int	is_ctrlu(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == CTRL_U ? TRUE : FALSE);
}

int     kill_buffer_beg(t_line *rdl, void *data)
{
  int	i;
  int	c;

  (void)data;
  i = 0;
  if (rdl->pos < 0)
    return (TRUE);
  if (rdl->pos > 0)
    {
      if (rdl->kill)
	gbgc_free(NULL, rdl->kill);
      rdl->kill = (unsigned char*)my_strndup((char*)rdl->line, rdl->pos);
      if (rdl->kill == NULL)
	return (FALSE & my_perror("[critical] malloc failed !\n"));
    }
  c = rdl->pos;
  while (rdl->line[c])
    rdl->line[i++] = rdl->line[c++];
  rdl->line[i] = '\0';
  return_to_beg(rdl, data, 1);
  my_putstr((char*)rdl->line);
  rdl->pos = i;
  return_to_beg(rdl, data, 0);
  return (TRUE);
}
