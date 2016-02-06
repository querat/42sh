/*
** my_setsignals.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:41:31 2015 Guillaume Pirou
** Last update Tue May  5 15:16:01 2015 guigui
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "my_process.h"

void		my_stoppcs(pid_t pcs)
{
  static pid_t	child;

  if (pcs != 0)
    child = pcs;
  else if (pcs == 0 && child != 0)
    kill(child, SIGINT);
}

void	my_stopchild()
{
  my_stoppcs(0);
}

void	my_setsignals(pid_t pid)
{
  signal(SIGINT, my_stopchild);
  my_stoppcs(pid);
}
