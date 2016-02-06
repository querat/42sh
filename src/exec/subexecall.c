/*
** subexecall.c for 42sh in /home/guigui/working/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sun May 24 17:43:31 2015 guigui
** Last update Sun May 24 17:46:29 2015 guigui
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include "my.h"
#include "my_process.h"
#include "readline.h"

int     my_execall(t_pcs cmd[], t_lnv *env)
{
  int   n;
  int   i;

  i = -1;
  init_lastreturnvalue();
  signal(SIGTTOU, SIG_IGN);
  if (cmd == NULL || (n = count_pcs(cmd)) <= 0)
    return (0);
  get_ghosts(cmd, n);
  while (++i < n && is_open(NULL) && cmd[i].pathn != NULL)
    {
      cmd[i].env = convert_envtotab(env);
      my_execone(cmd, i);
    }
  if (tcsetpgrp(0, getpgrp()) == -1 || !is_open(NULL))
    return (0);
  dezombificator(cmd, n);
  if (my_tty(1))
    rawmode();
  return (0);
}
