/*
** my_listenv3.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:40:58 2015 Guillaume Pirou
** Last update Sun May 24 15:55:47 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_process.h"
#include "my_mem.h"

void	del_envitem2(t_lnv *item, t_lnv *cpy)
{
  if (item == NULL)
    return;
  if (item->next == NULL)
    {
      item = item->prev;
      gbgc_free(NULL, item->next->name);
      gbgc_free(NULL, item->next);
      item->next = NULL;
    }
  else
    {
      item->next->prev = item->prev;
      item->prev->next = item->next;
      gbgc_free(NULL, item->name);
      cpy = item;
      item = item->next;
      gbgc_free(NULL, cpy);
    }
}

void	del_envitem(t_lnv *item)
{
  if (item == NULL)
    return;
  if (item->prev == NULL && item->next == NULL)
    {
      gbgc_free(NULL, item->name);
      gbgc_free(NULL, item);
    }
  else if (item->prev == NULL)
    {
      item = item->next;
      gbgc_free(NULL, item->prev->name);
      gbgc_free(NULL, item->prev);
      item->prev = NULL;
    }
  else
    del_envitem2(item, NULL);
}

int	add_envitem(t_lnv *list, char *name, char *value)
{
  t_lnv	*cpy;

  if (list == NULL || name == NULL)
    return (0);
  cpy = list;
  while (cpy->next != NULL)
    cpy = cpy->next;
  if ((cpy->next = gbgc_malloc(NULL, sizeof(t_lnv))) == NULL ||
      (cpy->next->name = my_strdup(name)) == NULL)
    return (0);
  if (value != NULL)
    cpy->next->value = my_strdup(value);
  else
    cpy->next->value = NULL;
  cpy->next->prev = cpy;
  cpy->next->next = NULL;
  return (1);
}
