/*
** my_env.c for mysh in /home/pirou_g/minishell2/src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:28:10 2015 Guillaume Pirou
** Last update Fri May  8 17:57:18 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_mem.h"
#include "my_process.h"

int	my_getnbenvdata(char **tab)
{
  int	i;

  if (tab == NULL)
    return (0);
  i = -1;
  while (tab[++i] != NULL);
  return (i);
}

int	my_setenvdata(t_env *el, char *str)
{
  int	i;

  if (el == NULL || str == NULL)
    return (0);
  el->name = my_strdup(str);
  i = -1;
  while (el->name[++i] != '\0')
    {
      if (el->name[i] == '=')
	{
	  el->name[i] = '\0';
	  if (el->name[i + 1] != '\0')
	    el->value = el->name + i + 1;
	  else
	    el->value = NULL;
	  return (1);
	}
    }
  return (0);
}

t_env	**my_getenv(char **tab)
{
  t_env	**env;
  int	nb;
  int	i;

  if (tab == NULL || (nb = my_getnbenvdata(tab)) <= 0 ||
      (env = gbgc_malloc(NULL, sizeof(t_env *) * (nb + 1))) == NULL)
    return (NULL);
  i = -1;
  while (++i < nb)
    {
      if ((env[i] = gbgc_malloc(NULL, sizeof(t_env))) == NULL ||
	  !my_setenvdata(env[i], tab[i]))
	return (NULL);
    }
  env[i] = NULL;
  return (env);
}

void	my_disp_env(t_env **env)
{
  int	i;

  i = -1;
  if (env == NULL)
    return;
  while (env[++i] != NULL)
    {
      my_printf("%s=", env[i]->name);
      if (env[i]->value != NULL)
	my_printf("%s", env[i]->value);
      my_printf("\n");
    }
}

void	my_free_env(t_env **env)
{
  int	i;

  if (env == NULL)
    return;
  i = -1;
  while (env[++i] != NULL)
    gbgc_free(NULL, env[i]->name);
  gbgc_free(NULL, env);
}
