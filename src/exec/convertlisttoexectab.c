/*
** convertlisttoexectab.c for 42sh in /home/guigui/42sh
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Thu May 21 15:53:39 2015 guigui
** Last update Sat May 23 23:11:03 2015 guigui
*/

#include <stdlib.h>
#include "my_process.h"
#include "my_mem.h"
#include "my.h"
#include "shell.h"
#include "slist.h"
#include "parser.h"

int		count_cmdels(t_dlist *list)
{
  t_prs		*tmp;
  int		i;
  t_dlist	*cpy;

  i = 0;
  if ((cpy = list) == NULL)
    return (0);
  while (cpy != NULL && (tmp = list->data) != NULL)
    {
      if (tmp->argv == NULL)
	return (i);
      ++i;
      cpy = cpy->next;
    }
  return (i);
}

int		convertlisttoexectab2(t_pcs *tab, t_prs *tmp)
{
  if (tab == NULL || tmp == NULL)
    return (0);
  tab->pathn = my_strdup(tmp->argv[0]);
  tab->args = my_strtabdup(tmp->argv);
  if (tmp->stdout_path != NULL)
    {
      tab->filout = my_strdup(tmp->stdout_path);
      tab->redright = (tmp->stdout == SP_RIGHT) ? R_RIGHT : R_RRIGHT;
    }
  if (tmp->stdin_path != NULL)
    {
      tab->filin = my_strdup(tmp->stdin_path);
      tab->redleft = (tmp->stdin == SP_LEFT) ? R_LEFT : R_LLEFT;
    }
  if (tmp->piping)
    {
      if ((tab->pipedright = gbgc_calloc(sizeof(int) * 2)) == NULL ||
	  pipe(tab->pipedright) < 0)
	return (1);
    }
  return (1);
}

t_pcs		*convertlisttoexectab(t_dlist *list, int n)
{
  t_dlist	*cpy;
  t_pcs		*tab;
  int		i;
  t_prs		*tmp;

  i = -1;
  if ((cpy = list) == NULL ||
      (tab = gbgc_calloc(sizeof(t_pcs) * (n + 1))) == NULL)
    return (NULL);
  while (++i < n && cpy != NULL && (tmp = cpy->data) != NULL &&
	 tmp->argv != NULL)
    {
      if (!convertlisttoexectab2(&(tab[i]), tmp))
	return (NULL);
      if (i > 0 && tmp->piped && tab[i - 1].pipedright != NULL)
	{
	  tab[i].is_piped = 1;
	  tab[i].pipedleft = tab[i - 1].pipedright;
	}
      if (tmp->cond)
	tab[i].cdt = (tmp->cond == ANDAND) ? SCCDT : FLCDT;
      cpy = cpy->next;
    }
  tab[i].pathn = NULL;
  return (tab);
}
