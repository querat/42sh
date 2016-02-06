/*
** my_exec_builtin.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:40:27 2015 Guillaume Pirou
** Last update Sat May 23 14:26:13 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_process.h"
#include "my_mem.h"

int	my_exec_built_in2(t_app *app)
{
  if (app == NULL)
    return (0);
  if (!my_strcmp(app->pathn, "env"))
    {
      my_env(NULL);
      return (1);
    }
  else if (!my_strcmp(app->pathn, "setenv"))
    {
      if (app->args != NULL && app->args[1] != NULL && app->args[2] != NULL)
	my_setenv(NULL, app->args[1], app->args[2]);
      return (1);
    }
  else if (!my_strcmp(app->pathn, "unsetenv"))
    {
      if (app->args != NULL && app->args[1] != NULL)
	my_unsetenv(NULL, app->args[1]);
      return (1);
    }
  return (0);
}

void		set_exitstate(int *ptr, int value)
{
  static int	*ret;

  if (ptr != NULL)
    ret = ptr;
  if (ret != NULL)
    *ret = value;
}

int		get_exitstate(int *ptr)
{
  static int	*ret;

  if (ptr != NULL)
    ret = ptr;
  return ((ret != NULL) ? *ret : 0);
}

void	my_exec_built_in(t_app *app)
{
  int	ret;

  if (app == NULL)
    return;
  if (!my_strcmp(app->pathn, "exit"))
    {
      ret = (app->args != NULL) ? my_atoi(app->args[1]) : 0;
      set_openstate(NULL, 0);
      set_exitstate(NULL, ret);
    }
  else if (!my_strcmp(app->pathn, "cd"))
    {
      if (app->args != NULL && app->args[1] != NULL)
	my_cd(NULL, app->args[1]);
      else
	my_cd(NULL, NULL);
    }
  else if (!my_exec_built_in2(app))
    my_putstr2("builtin not found\n");
}
