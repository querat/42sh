/*
** execfcts3.c for 42sh in /home/guigui/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Thu May 21 10:55:59 2015 guigui
** Last update Sun May 24 15:02:40 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_process.h"

void    raw_exec(t_pcs *cmd)
{
  if (cmd == NULL || cmd->pathn == NULL)
    return;
  if (is_built_in(cmd->pathn))
    return;
  else
    execve(cmd->pathn, cmd->args, cmd->env);
  set_openstate(NULL, 0);
}

int     is_executable(char *name)
{
  return ((is_built_in(name) || (can_i_run_rel(name))) ? 1 : 0);
}

void    sh_envdelete(t_pcs *cmd)
{
  if (cmd == NULL)
    return;
  cmd->filin = NULL;
  cmd->filout = NULL;
  cmd->pipedleft = NULL;
  cmd->pipedright = NULL;
  cmd->is_piped = 0;
  cmd->redright = 0;
  cmd->redleft = 0;
}

void	sh_env2(t_pcs *cmd, int i)
{
  if (cmd == NULL)
    return;
  cmd->pathn = cmd->args[i];
  cmd->args += i;
  sh_envdelete(cmd);
  raw_exec(cmd);
}

void    sh_env(t_pcs *cmd)
{
  int   i;
  int   j;

  i = -1;
  if (cmd == NULL)
    return;
  if (cmd->args != NULL && cmd->args[1] == NULL)
    my_putstrtab(cmd->env);
  else if (cmd->args != NULL)
    {
      while (cmd->args[++i] != NULL)
        {
          j = -1;
          while (cmd->args[i][++j])
            {
              if (cmd->args[i][0] == '-' && cmd->args[i][j] == 'n')
                cmd->env = NULL;
            }
          if (is_executable(cmd->args[i]))
	    sh_env2(cmd, i);
        }
    }
}
