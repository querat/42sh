/*
** my_cd.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:40:07 2015 Guillaume Pirou
** Last update Sun May 24 18:55:42 2015 guigui
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_process.h"
#include "my_printf.h"
#include "my_mem.h"
#include "shell.h"

void	set_oldpwd(t_lnv *env, char **pwd, char **path, char **npath)
{
  set_value(env, "OLDPWD", (*pwd));
  if ((*path)[0] != '.' && (*path)[0] != '/' &&
      ((*path) = my_strstick("./", (*path))) == NULL)
    return;
  if ((*path)[0] == '.')
    {
      (*pwd) = my_strstick((*pwd), "/");
      if (*npath)
	(*npath) = my_strstick((*pwd), (*path));
    }
  else
    (*npath) = my_strdup((*path));
}

void	my_cd2(t_lnv *env, char *path, char *npath, char *pwd)
{
  if (env == NULL)
    return;
  pwd = get_value(env, "PWD");
  if (path == NULL)
    npath = get_value(env, "HOME");
  else if (pwd == NULL)
    npath = my_strdup(path);
  else if (!my_strcmp("-", path) && get_value(env, "OLDPWD") != NULL)
    {
      npath = get_value(env, "OLDPWD");
      set_value(env, "OLDPWD", pwd);
    }
  else
    {
      npath = "";
      set_oldpwd(env, &pwd, &path, &npath);
    }
  if (npath)
    {
      set_value(env, "PWD", npath);
      chdir(npath);
    }
  gbgc_free(NULL, npath);
}

void		my_cd(t_lnv *list, char *path)
{
  static t_lnv	*env;

  if (list != NULL)
    env = list;
  else if (list == NULL && env != NULL)
    {
      if (!is_cdpathdir(path) && my_strcmp("-", path))
	{
	  set_lastreturnvalue(NULL, 1);
	  my_putstr2("Error : the path given is not a directory\n");
	  return;
	}
      my_cd2(env, path, NULL, NULL);
    }
  set_lastreturnvalue(NULL, 1);
}
