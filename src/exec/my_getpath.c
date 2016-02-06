/*
** my_getpath.c for mysh in /home/guigui
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Tue Jan 20 16:29:51 2015 guigui
** Last update Tue May  5 15:50:58 2015 guigui
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "my_mem.h"
#include "my_process.h"

char	**my_splitpaths(char *path)
{
  int	i;
  int	j;
  int	n_el;
  int	len;
  char	**tab;
  char	*str;

  if (path == NULL || (len = my_strlen(path)) <= 0 ||
      (n_el = my_countpaths(path)) <= 0 || (str = my_strdup(path)) == NULL ||
      (tab = gbgc_malloc(NULL, sizeof(char *) * (n_el + 1))) == NULL)
    return (NULL);
  i = -1;
  tab[j = 0] = str;
  my_setpathtrunc(str);
  while (++i < len)
    {
      if (str[i] == '\0')
	tab[++j] = str + i + 1;
    }
  tab[++j] = NULL;
  return (tab);
}

char	**null_path()
{
  char	**out;

  if ((out = gbgc_malloc(NULL, sizeof(char *) * 2)) == NULL)
    return (NULL);
  out[0] = NULL;
  out[1] = NULL;
  return (out);
}

char	**my_getpath(char **data)
{
  t_env	**env;
  char	**out;
  int	i;
  int	is_finished;

  if (data == NULL || (env = my_getenv(data)) == NULL)
    return (NULL);
  i = -1;
  is_finished = 0;
  while (env[++i] != NULL && !is_finished)
    {
      if (!my_strcmp(env[i]->name, "PATH"))
	{
	  out = my_splitpaths(env[i]->value);
	  ++is_finished;
	}
    }
  my_free_env(env);
  if (!is_finished)
    return (null_path());
  return (out);
}

void	my_freepath(char **path)
{
  if (path == NULL)
    return;
  gbgc_free(NULL, path[0]);
  gbgc_free(NULL, path);
}
