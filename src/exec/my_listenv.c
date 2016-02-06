/*
** my_listenv.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:40:39 2015 Guillaume Pirou
** Last update Sat May 23 16:28:55 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_process.h"
#include "my_printf.h"
#include "my_mem.h"

t_lnv	*convert_envtab(char **env)
{
  t_lnv	*list;
  t_lnv	*begin;
  int	i;

  if ((list = gbgc_calloc(sizeof(t_lnv))) == NULL)
    return (NULL);
  if (env == NULL || env[0] == NULL)
    return (list);
  i = -1;
  list->prev = NULL;
  begin = list;
  while (env[++i] != NULL)
    {
      set_envitem(list, env[i]);
      if ((list->next = gbgc_malloc(NULL, sizeof(t_lnv))) == NULL)
	return (NULL);
      list->next->prev = list;
      list = list->next;
    }
  list = list->prev;
  gbgc_free(NULL, list->next);
  list->next = NULL;
  list = begin;
  return (list);
}

int	my_getenvnbitems(t_lnv *list)
{
  int	i;
  t_lnv	*cpy;

  if ((cpy = list) == NULL)
    return (-1);
  i = 0;
  while (cpy != NULL)
    {
      ++i;
      cpy = cpy->next;
    }
  return (i);
}

char	**convert_envtotab(t_lnv *list)
{
  int	n;
  int	i;
  t_lnv	*cpy;
  char	**tab;
  char	*tmp;

  if (list == NULL || (n = my_getenvnbitems(list)) < 1 ||
      (tab = gbgc_malloc(NULL, sizeof(char *) * (n + 1))) == NULL)
    return (NULL);
  i = -1;
  cpy = list;
  while (cpy != NULL)
    {
      tmp = my_strstick(cpy->name, "=");
      if (cpy->value != NULL)
	tab[++i] = my_strstick(tmp, cpy->value);
      else
	tab[++i] = my_strdup(tmp);
      gbgc_free(NULL, tmp);
      cpy = cpy->next;
    }
  tab[++i] = NULL;
  return (tab);
}
