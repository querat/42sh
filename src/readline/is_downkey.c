/*
** is_downkey.c for  in /home/querat_g/lib42/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri May  1 10:11:17 2015 gwendal querat
** Last update Sat May 23 15:57:23 2015 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_downkey(t_line *rdl, void *data)
{
  (void)data;
  (void)rdl;
  return (rdl->input == DOWN_KEY ? TRUE : FALSE);
}

int     hist_down(t_line *rdl, void *data)
{
  (void)data;
  if (rdl->cur_hist == NULL)
    return (TRUE);
  gbgc_free(NULL, rdl->cur_hist->data);
  if ((rdl->cur_hist->data =
       (unsigned char*)my_strdup((char*)rdl->line)) == NULL)
    return (my_perror(MALLOC_FAILED));
  rdl->cur_hist = rdl->cur_hist->prev;
  return_to_beg(rdl, data, 1);
  if (!(hist_down_management(rdl)))
    return (FALSE);
  my_putstr((char*)rdl->line);
  return (TRUE);
}

int	hist_down_management(t_line *rdl)
{
  if ((rdl->cur_hist->prev) == NULL)
    {
      gbgc_free(NULL, rdl->line);
      if ((rdl->line = (unsigned char*)my_strdup(rdl->cur_hist->data)) == NULL)
	return (my_perror(MALLOC_FAILED));
      rdl->pos = (my_strlen((char*)rdl->line));
      rdl->cur_hist = NULL;
      gbgc_free(NULL, rdl->hist->data);
      rdl->hist = rm_first_dlist(rdl->hist, NULL);
    }
  else
    {
      gbgc_free(NULL, rdl->line);
      if ((rdl->line = (unsigned char*)my_strdup(rdl->cur_hist->data)) == NULL)
	return (my_perror(MALLOC_FAILED));
      rdl->pos = (my_strlen((char*)rdl->line));
    }
  return (TRUE);
}
