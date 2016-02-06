/*
** execfcts.c for 42sh in /home/guigui/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Thu May 21 10:48:51 2015 guigui
** Last update Sun May 24 09:39:48 2015 guigui
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_mem.h"
#include "my_process.h"

int     returncdt_checked(t_pcs cmd[], int i)
{
  int	ret;

  ret = get_lastreturnvalue(NULL);
  if (cmd == NULL || cmd[i].pathn == NULL)
    return (0);
  if ((cmd[i].cdt == SCCDT && ret == 0) || (cmd[i].cdt == FLCDT && ret != 0))
    return (1);
  return (0);
}

void    close_pipe(int tab[2])
{
  if (tab != NULL)
    {
      close(tab[0]);
      close(tab[1]);
    }
}

char    **init_shellinstab()
{
  char  **tab;

  if ((tab = gbgc_malloc(NULL, sizeof(char *) * 5)) == NULL)
    return (NULL);
  tab[0] = "exit";
  tab[1] = "cd";
  tab[2] = "setenv";
  tab[3] = "unsetenv";
  tab[4] = NULL;
  return (tab);
}

char            **get_shellins()
{
  static char   **tab;

  if (tab == NULL && (tab = init_shellinstab()) == NULL)
    return (NULL);
  return (tab);
}

int     is_shellin(t_pcs *cmd, char **names)
{
  int   i;

  i = -1;
  if (cmd == NULL || cmd->pathn == NULL || names == NULL)
    return (0);
  while (names[++i] != NULL && my_strcmp(cmd->pathn, names[i]));
  return ((names[i] != NULL) ? 1 : 0);
}
