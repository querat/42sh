/*
** subexecchild2.c for 42sh in /home/guigui/working/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sun May 24 17:51:07 2015 guigui
** Last update Sun May 24 19:47:28 2015 guigui
*/

#include <stdlib.h>
#include <signal.h>
#include "my_process.h"
#include "my.h"
#include "shell.h"

int     my_execchild2(t_pcs cmd[], int i)
{
  if (cmd == NULL || cmd[i].pid || cmd[i].pathn == NULL || cmd[i].args == NULL)
    return (0);
  if (is_built_in(cmd[i].pathn) && !is_shellin(&(cmd[i]), get_shellins()))
    {
      exec_subpgrm(&(cmd[i]));
      return (0);
    }
  else if (!can_i_run_rel(cmd[i].pathn))
    update_data(&(cmd[i]));
  if (cmd[i].pathn[0] != '.' && cmd[i].pathn[0] != '/')
    {
      set_exitstate(NULL, 1);
      my_printf("Unknown command %s\n", cmd[i].pathn);
      return (1);
    }
  if (cmd[i].pipedright != NULL)
    {
      setpgrp();
      signal(SIGTTOU, SIG_IGN);
      tcsetpgrp(0, getpgrp());
    }
  if (can_i_run_rel(cmd[i].pathn))
    execve(cmd[i].pathn, cmd[i].args, cmd[i].env);
  return (0);
}

void    my_sigint(int n)
{
  if (n != n)
    return;
  exit(0);
}

int     my_execchild(t_pcs cmd[], int i)
{
  if (cmd == NULL || !is_open(NULL) || cmd[i].pid || cmd[i].pathn == NULL ||
      cmd[i].args == NULL)
    return (0);
  set_openstate(NULL, 0);
  set_exitstate(NULL, 0);
  signal(SIGINT, my_sigint);
  if (cmd[i].cdt != NOCDT && !returncdt_checked(cmd, i))
    return (0);
  if (is_built_in(cmd[i].pathn) && is_shellin(&(cmd[i]), get_shellins()))
    return (0);
  if (my_tty(1))
    canonmode();
  do_redirect(cmd, i);
  return (my_execchild2(cmd, i));
}
