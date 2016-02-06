/*
** hist_up.c for  in /home/querat_g/lib42/src
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Fri May  1 09:59:51 2015 gwendal querat
** Last update Sat May 23 15:44:28 2015 
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "my.h"
#include "my_mem.h"
#include "slist.h"
#include "readline.h"
#include "shell.h"

int	is_upkey(t_line *rdl, void *data)
{
  (void)data;
  return (rdl->input == UP_KEY ? TRUE : FALSE);
}

void		print_hist(t_dlist *hist, t_dlist *cur)
{
  char		*data;

  data = (hist ? hist->data : NULL);
  my_printf("printing dat history :\n");
  my_printf("history : %p\nadress :  %p\n", hist, cur);
  if (hist == NULL)
    {
      my_perror("NULL list");
      return ;
    }
  while ((hist->next))
    hist = hist->next;
  while ((hist))
    {
      my_printf("%p-> ", hist);
      my_printf("%s\t<- %p", hist->data ? hist->data : "NULL", hist->data);
      data = hist->data;
      if (data && !data[0])
	my_putstr("\033[1;32m\\0\033[0m");
      if (hist == cur)
	my_printf("\t[current]\n");
      else
	my_putchar('\n');
      hist = hist->prev;
    }
}

int	case_cur_hist(t_line *rdl, void *data)
{
  gbgc_free(NULL, rdl->cur_hist->data);
  if ((rdl->cur_hist->data =
       (unsigned char*)my_strdup((char*)rdl->line)) == NULL)
    return (my_perror(MALLOC_FAILED));
  if (rdl->cur_hist->next)
    rdl->cur_hist = rdl->cur_hist->next;
  gbgc_free(NULL, rdl->line);
  if ((rdl->line =
       (unsigned char*)my_strdup((char*)rdl->cur_hist->data)) == NULL)
    return (my_perror(MALLOC_FAILED));
  return_to_beg(rdl, data, 1);
  rdl->pos = my_strlen((char*)rdl->line);
  my_putstr((char*)rdl->line);
  return (TRUE);
}

int	case_not_cur_hist(t_line *rdl, void *data)
{
  if (((rdl->hist = add_head_dlist_elem(rdl->hist)) == NULL) ||
      ((rdl->hist->data =
	(unsigned char*)my_strdup((char*)rdl->line)) == NULL))
    return (my_perror(MALLOC_FAILED));
  rdl->cur_hist = rdl->hist->next;
  gbgc_free(NULL, rdl->line);
  if ((rdl->line =
       (unsigned char*)my_strdup((char*)rdl->cur_hist->data)) == NULL)
    return (my_perror(MALLOC_FAILED));
  return_to_beg(rdl, data, 1);
  rdl->pos = my_strlen((char*)rdl->line);
  my_putstr((char*)rdl->line);
  return (TRUE);
}

int     hist_up(t_line *rdl, void *data)
{
  (void)data;
  if (rdl->hist && rdl->cur_hist == NULL)
    {
      if ((case_not_cur_hist(rdl, data)) == FALSE)
	return (FALSE);
    }
  else if (rdl->hist && rdl->cur_hist)
    {
      if ((case_cur_hist(rdl, data)) == FALSE)
	return (FALSE);
    }
  return (TRUE);
}
