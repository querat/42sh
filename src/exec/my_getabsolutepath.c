/*
** my_getabsolutepath.c for mysh in /home/pirou_g/minishell2/src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Feb  1 08:28:42 2015 Guillaume Pirou
** Last update Tue May  5 15:51:22 2015 guigui
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "my_process.h"

char	*my_getabsolutepath(char *str, char **env)
{
  char	*tmp;
  char	*out;
  char	**path;
  int	i;

  if (str == NULL || env == NULL || (path = my_getpath(env)) == NULL)
    return (NULL);
  i = -1;
  if (str[0] == '.' || str[0] == '/')
    return (my_strdup(str));
  while (path[++i] != NULL)
    {
      if ((tmp = my_strstick(path[i], "/")) == NULL ||
	  (out = my_strstick(tmp, str)) == NULL)
	return (NULL);
      if (!access(out, F_OK))
	{
	  gbgc_free(NULL, tmp);
	  return (out);
	}
      gbgc_free(NULL, tmp);
      gbgc_free(NULL, out);
    }
  free_strtab(path);
  return (NULL);
}
