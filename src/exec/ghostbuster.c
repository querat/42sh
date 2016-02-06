/*
** ghostbuster.c for 42sh in /home/guigui/working/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sun May 24 17:42:15 2015 guigui
** Last update Sun May 24 17:43:23 2015 guigui
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "my_process.h"

void    dezombificator(t_pcs cmd[], int n)
{
  int   i;

  i = -1;
  if (cmd == NULL || n <= 0)
    return;
  while (++i < n)
    {
      if (cmd[i].pid != 0)
        {
          if (waitpid(cmd[i].pid, &(cmd[i].retv), WNOHANG) != cmd[i].pid)
            kill(cmd[i].pid, SIGINT);
          if (WIFSIGNALED(cmd[i].retv))
            show_strsignal(WTERMSIG(cmd[i].retv));
        }
    }
}

t_dck           *get_ghosts(t_pcs cmd[], int n)
{
  static t_dck  ducks = { NULL, 0 };

  if (cmd != NULL)
    {
      ducks.ptr = cmd;
      ducks.n = n;
    }
  if (n == 0)
    ducks.ptr = NULL;
  return ((ducks.ptr != NULL) ? &ducks : NULL);
}

void    dezombificator2(int sig)
{
  t_dck *tmp;

  if ((tmp = get_ghosts(NULL, -1)) == NULL)
    return;
  dezombificator(tmp->ptr, tmp->n);
  if (sig == 0)
    get_ghosts(NULL, 0);
  else
    get_ghosts(NULL, 0);
}
