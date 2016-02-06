/*
** is_ctrlk.c for  in /home/querat_g/lib42/src
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Fri May  1 10:09:02 2015 gwendal querat
** Last update Sat May 23 14:06:24 2015 
*/

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

int	is_ctrlk(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == CTRL_K ? TRUE : FALSE);
}

int     kill_buffer_end(t_line *rdl, void *data)
{
  int	len;
  int	i;

  (void)data;
  i = 0;
  len = my_strlen((char*)&rdl->line[rdl->pos]);
  if (rdl->kill && len > 0)
    gbgc_free(NULL, rdl->kill);
  if (len > 0)
    {
      if ((rdl->kill = gbgc_calloc(sizeof(char) * (len + 1))) == NULL)
	return (FALSE & my_perror("[critical] malloc failed !"));
      while (rdl->line[rdl->pos + i])
	{
	  rdl->kill[i] = rdl->line[rdl->pos + i];
	  i++;
	}
      rdl->kill[i] = '\0';
    }
  my_putstr(tgetstr("cd", NULL));
  rdl->line[rdl->pos] = '\0';
  return (TRUE);
}
