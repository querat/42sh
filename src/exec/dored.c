/*
** dored.c for 42sh in /home/guigui/42sh/src/exec
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Thu May 21 10:47:05 2015 guigui
** Last update Sun May 24 21:08:10 2015 guigui
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include "my.h"
#include "my_process.h"

void	do_doubleleftparent(t_pcs cmd[], int i, int net[2], pid_t pid)
{
  char	*tmp;
  char	*tmp2;
  int	status;

  if (cmd == NULL || net == NULL || (tmp = "") == NULL)
    return;
  while ((tmp2 = gnl_querat_g(0)) != NULL &&
	 strcmp(tmp2, cmd[i].filin))
    {
      if ((tmp = my_strstick(tmp, tmp2)) == NULL ||
	  (tmp = my_strstick(tmp, "\n")) == NULL)
	return;
    }
  close(net[0]);
  write(net[1], tmp, my_strlen(tmp));
  close_pipe(net);
  waitpid(pid, &status, WNOHANG);
}

int	do_doubleleftred(t_pcs cmd[], int i, int net[2], pid_t pid)
{
  if (cmd == NULL || net == NULL)
    return (0);
  if (!pid)
    {
      close(net[1]);
      dup2(net[0], 0);
      close_pipe(net);
    }
  else if (pid > 0)
    do_doubleleftparent(cmd, i, net, pid);
  return (0);
}

int     do_leftred(t_pcs cmd[], int i)
{
  int   fd;
  pid_t	pid;
  int	net[2];

  if (cmd == NULL || cmd[i].pathn == NULL || cmd[i].filin == NULL)
    return (0);
  if (cmd[i].redleft == R_LEFT)
    {
      if ((fd = open(cmd[i].filin, O_RDONLY)) < 0)
	return (0);
      dup2(fd, 0);
      close(fd);
    }
  else
    {
      if (pipe(net) < 0)
	return (-1);
      pid = fork();
      return (do_doubleleftred(cmd, i, net, pid));
    }
  return (1);
}

int     do_rightred(t_pcs cmd[], int i)
{
  int   fd;

  if (cmd == NULL || cmd[i].pathn == NULL || cmd[i].filout == NULL ||
      is_directory(cmd[i].filout))
    return (0);
  if (!exist_file(cmd[i].filout) && !my_creatfile(cmd[i].filout))
    return (0);
  if ((fd = open(cmd[i].filout, O_WRONLY |
                 ((cmd[i].redright == R_RIGHT) ? O_TRUNC : O_APPEND))) < 0)
    return (0);
  dup2(fd, 1);
  close(fd);
  return (1);
}

int     do_redirect(t_pcs cmd[], int i)
{
  if (cmd == NULL || cmd[i].pathn == NULL)
    return (0);
  if (cmd[i].filin != NULL)
    do_leftred(cmd, i);
  if (cmd[i].filout != NULL)
    do_rightred(cmd, i);
  if (cmd[i].pipedleft != NULL)
    {
      dup2(cmd[i].pipedleft[0], 0);
      close(cmd[i].pipedleft[0]);
    }
  if (cmd[i].pipedright != NULL)
    {
      dup2(cmd[i].pipedright[1], 1);
      close(cmd[i].pipedright[1]);
    }
  return (1);
}
