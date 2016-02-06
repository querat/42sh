/*
** my_listenv2.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:40:50 2015 Guillaume Pirou
** Last update Sat May 23 23:20:25 2015 guigui
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "my_process.h"
#include "my_printf.h"
#include "my_mem.h"

void	free_envlist(t_lnv *list)
{
  if (list == NULL)
    return;
  while (list->next != NULL)
    {
      list = list->next;
      gbgc_free(NULL, list->prev->name);
      gbgc_free(NULL, list->prev->value);
      gbgc_free(NULL, list->prev);
    }
  gbgc_free(NULL, list);
}

void	disp_envlist(t_lnv *list)
{
  if (list == NULL)
    return;
  while (list != NULL)
    {
      my_printf("Name = %s\n", list->name);
      if (list->value != NULL)
	my_printf("Value = %s\n", list->value);
      list = list->next;
    }
}

int	set_value(t_lnv *list, char *name, char *value)
{
  t_lnv	*cpy;

  if ((cpy = list) == NULL || name == NULL)
    return (0);
  while (cpy != NULL && my_strcmp(cpy->name, name))
    cpy = cpy->next;
  if (cpy == NULL)
    return (0);
  if (value != NULL)
    cpy->value = my_strdup(value);
  else
    cpy->value = NULL;
  return (1);
}

char	*get_value(t_lnv *list, char *name)
{
  t_lnv	*cpy;

  if ((cpy = list) == NULL || name == NULL)
    return (NULL);
  while (cpy != NULL && strcmp(cpy->name, name))
    cpy = cpy->next;
  if (cpy == NULL || cpy->value == NULL)
    return (NULL);
  return (my_strdup(cpy->value));
}

int	set_envitem(t_lnv *item, char *data)
{
  char	*cpy;
  int	i;
  int	ctn;

  if (item == NULL || data == NULL || (cpy = my_strdup(data)) == NULL)
    return (0);
  item->name = cpy;
  i = -1;
  ctn = 1;
  while (cpy[++i] != '\0' && ctn)
    {
      if (cpy[i] == '=')
	{
	  cpy[i] = '\0';
	  if (cpy[i + 1] != '\0')
	    item->value = my_strdup(cpy + i + 1);
	  else
	    item->value = NULL;
	  --ctn;
	}
    }
  return (1);
}
