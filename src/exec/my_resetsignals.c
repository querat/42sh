/*
** my_resetsignals.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:41:23 2015 Guillaume Pirou
** Last update Sat May 23 14:35:53 2015 guigui
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "my_process.h"
#include "my_printf.h"

void	my_builtinsinit(t_lnv *env)
{
  if (env == NULL)
    {
      my_printf("env is null\n");
      return;
    }
  my_env(env);
  my_setenv(env, NULL, NULL);
  my_unsetenv(env, NULL);
  my_cd(env, NULL);
}

void		my_exitshell(t_lnv *list)
{
  static t_lnv	*env;

  if (list != NULL)
    env = list;
  else if (list == NULL && env != NULL)
    my_printf("\n?> ");
}

void	my_defaultexit()
{
  my_exitshell(NULL);
}

void	my_resetsignals(t_lnv *list)
{
  if (list == NULL)
    return;
  my_exitshell(list);
  signal(SIGINT, my_defaultexit);
}
