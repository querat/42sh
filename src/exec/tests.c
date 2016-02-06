/*
** tests.c for mysh in /home/pirou_g/minishell2/src/mysh
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:41:48 2015 Guillaume Pirou
** Last update Tue May  5 15:17:04 2015 guigui
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_process.h"
#include "my.h"
#include "my_mem.h"

int	is_cdpathdir(char *path)
{
  int	fd;

  if (path == NULL)
    return (1);
  else if ((fd = open(path, O_RDONLY | O_DIRECTORY)) >= 0)
    {
      close(fd);
      return (1);
    }
  return (0);
}

int	can_i_run_rel(char *name)
{
  if (name == NULL)
    return (0);
  if (!access(name, F_OK))
    {
      if (!access(name, X_OK))
	return (EXECUTABLE);
      return (EXIST);
    }
  return (NOT_FOUND);
}

int	can_i_run_it(char *name, char **path)
{
  char	*str;
  char	*str2;
  int	i;

  i = -1;
  if (name == NULL || path == NULL)
    return (0);
  if (name[0] == '.' || name[0] == '/')
    return (can_i_run_rel(name));
  while (path[++i] != NULL)
    {
      if ((str = my_strstick(path[i], "/")) == NULL ||
	  (str2 = my_strstick(str, name)) == NULL)
	return (0);
      if (!access(str2, F_OK))
	{
	  if (!access(str2, X_OK))
	    return (EXECUTABLE);
	  return (EXIST);
	}
    }
  return (NOT_FOUND);
}

int	is_built_in(char *name)
{
  char	**btins;
  int	found;

  if (name == NULL || (btins = get_builtinstab()) == NULL)
    return (0);
  found = 0;
  if (my_strtabsearch(btins, name))
    found = 1;
  else
    found = 0;
  gbgc_free(NULL, btins);
  return (found);
}
