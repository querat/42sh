/*
** subexecchild.c for 42sh in /home/guigui/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Thu May 21 10:58:06 2015 guigui
** Last update Sun May 24 17:52:05 2015 guigui
*/

#include <stdlib.h>
#include <signal.h>
#include "my_process.h"
#include "my.h"
#include "shell.h"

void	sh_exit(t_pcs *cmd)
{
  if (cmd == NULL || cmd->pathn == NULL)
    return;
  set_openstate(NULL, 0);
  set_exitstate(NULL, (cmd->args[1] != NULL) ? my_atoi(cmd->args[1]) : 0);
}

void    exec_shellin(t_pcs *cmd)
{
  set_lastreturnvalue(NULL, 0);
  if (cmd == NULL || cmd->pathn == NULL)
    return;
  if (!my_strcmp(cmd->pathn, "exit"))
    sh_exit(cmd);
  else if (!my_strcmp(cmd->pathn, "cd"))
    my_cd(NULL, cmd->args[1]);
  else if (!my_strcmp(cmd->pathn, "setenv") && tab_len(cmd->args) >= 2)
    my_setenv(NULL, cmd->args[1], cmd->args[2]);
  else if (!my_strcmp(cmd->pathn, "unsetenv"))
    my_unsetenv(NULL, cmd->args[1]);
}

void    exec_subpgrm(t_pcs *cmd)
{
  if (cmd == NULL || cmd->pathn == NULL)
    return;
  if (!my_strcmp(cmd->pathn, "echo"))
    echo_main(tab_len(cmd->args), cmd->args, cmd->env);
  else if (!my_strcmp(cmd->pathn, "env"))
    sh_env(cmd);
  else if (!my_strcmp(cmd->pathn, "camarchepas"))
    camarchepas_main(tab_len(cmd->args), cmd->args, cmd->env);
}

void    exec_builtin(t_pcs *cmd)
{
  if (cmd == NULL || cmd->pathn == NULL)
    return;
  if (is_shellin(cmd, get_shellins()))
    exec_shellin(cmd);
  else
    exec_subpgrm(cmd);
}
