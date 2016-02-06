/*
** subexec.c for 42sh in /home/guigui/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Thu May 21 11:01:03 2015 guigui
** Last update Sun May 24 17:46:39 2015 guigui
*/

#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "my_process.h"

int     update_data(t_pcs *cmd)
{
  char  **path;

  if (cmd == NULL || cmd->env == NULL || cmd->pathn == NULL)
    return (0);
  if ((path = my_getpath(cmd->env)) == NULL)
    return (1);
  if (can_i_run_it(cmd->pathn, path) &&
      (cmd->pathn = my_getabsolutepath(cmd->pathn, cmd->env)) == NULL)
    return (0);
  return (1);
}

int     my_execparent(t_pcs cmd[], int i)
{
  if (cmd == NULL || !is_open(NULL) || cmd[i].pid <= 0)
    return (0);
  if (cmd[i].pipedright != NULL)
    close(cmd[i].pipedright[1]);
  if (cmd[i].pipedleft != NULL)
    close(cmd[i].pipedleft[1]);
  if (cmd[i + 1].is_piped == 0 || cmd[i + 1].pathn == NULL)
    {
      while (waitpid(cmd[i].pid, &(cmd[i].retv), WNOHANG) != cmd[i].pid);
      if (WIFEXITED(cmd[i].retv))
	{
	  cmd[i].ret = WEXITSTATUS(cmd[i].retv);
	  if (!cmd[i].cdt || (cmd[i].cdt && returncdt_checked(cmd, i)))
	    set_lastreturnvalue(NULL, cmd[i].ret);
	}
      if (WIFSIGNALED(cmd[i].retv))
        cmd[i].sig = WTERMSIG(cmd[i].retv);
    }
  if (is_built_in(cmd[i].pathn) && is_shellin(&(cmd[i]), get_shellins()))
    exec_shellin(&(cmd[i]));
  return (cmd[i].retv);
}

int     my_execone(t_pcs cmd[], int i)
{
  if (cmd == NULL || cmd[i].pathn == NULL || (cmd[i].pid = fork()) < 0)
    return (0);
  if (!cmd[i].pid)
    return (my_execchild(cmd, i));
  else if (cmd[i].pid > 0)
    return (my_execparent(cmd, i));
  return (-1);
}

void	show_strsignal2(int sig)
{
  if (sig == SIGFPE)
    my_putstr("Fatal arithmetic error\n");
  else if (sig == SIGBUS)
    my_putstr("Bus error\n");
  else if (sig == SIGQUIT)
    my_putstr("Quitted\n");
  else if (sig == SIGKILL)
    my_putstr("Killed\n");
  else if (sig == SIGHUP)
    my_putstr("Hanged-up\n");
  else if (sig == SIGPIPE)
    my_putstr("Broken pipe\n");
  else if (sig == SIGXCPU)
    my_putstr("CPU time limit exceeded\n");
  else if (sig == SIGXFSZ)
    my_putstr("File size limit exceeded\n");
}

void	show_strsignal(int sig)
{
  if (sig == SIGUSR1)
    my_putstr("Terminated by SIGUSR1\n");
  else if (sig == SIGUSR2)
    my_putstr("Terminated by SIGUSR2\n");
  else if (sig == SIGSEGV)
    my_putstr("Segmentation Fault\n");
  else if (sig == SIGTERM)
    my_putstr("Terminated\n");
  else if (sig == SIGINT)
    my_putstr("Completed\n");
  else if (sig == SIGILL)
    my_putstr("Invalid program image\n");
  else if (sig == SIGABRT)
    my_putstr("Aborted\n");
  else
    show_strsignal2(sig);
}
