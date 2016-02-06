/*
** builtin.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:39:43 2015 Guillaume Pirou
** Last update Sun May 24 15:55:26 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "my_process.h"
#include "my_mem.h"

void		my_unsetenv(t_lnv *list, char *name)
{
  static t_lnv	*env;
  t_lnv		*cpy;

  env = (list != NULL) ? list : env;
  if (list == NULL && (env != NULL && name != NULL))
    {
      cpy = env;
      while (cpy != NULL && cpy->name != NULL && my_strcmp(name, cpy->name))
	cpy = cpy->next;
      if (cpy && cpy->name != NULL)
	del_envitem(cpy);
    }
}

void		my_setenv(t_lnv *list, char *name, char *value)
{
  static t_lnv	*env;
  t_lnv		*cpy;

  env = (list != NULL) ? list : env;
  if (list == NULL && (env != NULL && name != NULL))
    {
      cpy = env;
      if (cpy->name == NULL)
	{
	  cpy->name = my_strdup(name);
	  cpy->value = (value != NULL) ? my_strdup(value) : NULL;
	  return;
	}
      while (cpy->next != NULL && my_strcmp(cpy->name, name))
	cpy = cpy->next;
      if (cpy->next == NULL && my_strcmp(cpy->name, name))
	add_envitem(env, name, value);
      else
	{
	  if (cpy->value != NULL)
	    gbgc_free(NULL, cpy->value);
	  cpy->value = (value != NULL) ? my_strdup(value) : NULL;
	}
    }
}

void		my_env(t_lnv *list)
{
  static t_lnv	*env;
  char		**tab;

  env = (list != NULL) ? list : env;
  if (list == NULL && env != NULL && (tab = convert_envtotab(env)) != NULL)
    {
      my_putstrtab(tab);
      free_strtab(tab);
    }
}

char	**get_builtinstab()
{
  char	**tab;

  if ((tab = gbgc_malloc(NULL, sizeof(char *) * 8)) == NULL)
    return (NULL);
  tab[0] = "cd";
  tab[1] = "setenv";
  tab[2] = "unsetenv";
  tab[3] = "env";
  tab[4] = "exit";
  tab[5] = "echo";
  tab[6] = "camarchepas";
  tab[7] = NULL;
  return (tab);
}
